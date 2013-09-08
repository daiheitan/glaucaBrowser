#include "GlaucaDownloadService.h"
#include <QDialog>
#include <QListWidget>
#include <QVBoxLayout>
#include <QFileInfo>
#include <QtDebug>
#include <QFileDialog>
#include <QPlastiqueStyle>
#include <QSettings>
#include<QHBoxLayout>
#include <QDesktopServices>
#include <QGroupBox>
#include <QClipboard>
#include <QDesktopServices>

downloadBarItem::downloadBarItem(QNetworkReply *Nreply, const QString& pathString):path(pathString),reply(Nreply),per(0),sp(0),byteSize(0){
    url=reply->url().toString();
    fileName=QFileInfo(url).fileName();
    size=downloadModel::getDownloadSpeedString(reply->size());
    pBar=new QProgressBar(this);

    itemGroup=new QGroupBox("File Details",this);
    QVBoxLayout* boxLayout=new QVBoxLayout;
    boxLayout->addWidget(new QLabel("Name: <b>"+fileName+"</b>",itemGroup));
    QHBoxLayout* fromLayout=new QHBoxLayout;
    fromLayout->addWidget(new QLabel("From: ",itemGroup));
    fromLayout->addWidget(new QLineEdit(url,itemGroup));
    boxLayout->addLayout(fromLayout);
    boxLayout->addWidget(new QLabel("Size: "+size,itemGroup));
    itemGroup->setLayout(boxLayout);
    QVBoxLayout* itemLayout=new QVBoxLayout;
    this->setLayout(itemLayout);
    itemLayout->addWidget(pBar);
    itemLayout->addWidget(itemGroup);
    itemGroup->hide();

    ifPaused=false;

    connect(this,SIGNAL(copyLink()),this,SLOT(copyLinkLocation()));
    connect(reply,SIGNAL(finished()),this,SIGNAL(finished()));
    connect(reply,SIGNAL(readyRead()),this,SIGNAL(readyRead()));
    connect(reply,SIGNAL(downloadProgress(qint64,qint64)),this,SIGNAL(downloadProgress(qint64,qint64)));
    outputFile=new QFile(path);
    outputFile->open(QFile::WriteOnly);
}
bool downloadBarItem::isHide(){
    return itemGroup->isHidden();
}
bool downloadBarItem::isFinished(){
    if(pBar->value()==100)return true;
    else return false;
}
bool downloadBarItem::isPaused(){
    return ifPaused;
}
QFile* downloadBarItem::getOutputFile(){
    return outputFile;
}
QNetworkReply* downloadBarItem::getReply(){
    return reply;
}
QTime& downloadBarItem::getTimer(){
    return timer;
}
double downloadBarItem::getPercent(){
    return per;
}
double downloadBarItem::getSpeed(){
    return sp;
}
qint64& downloadBarItem::getByteSize(){
    return byteSize;
}

void downloadBarItem::mouseReleaseEvent(QMouseEvent *event){
    if(event->button()==Qt::LeftButton){
        if(this->isHide())itemGroup->show();
      else itemGroup->hide();
  }
}
void downloadBarItem::mouseDoubleClickEvent(QMouseEvent *event){
    if(event){
    if(this->isPaused())emit conti();
    else emit pause();
}
}
void downloadBarItem::setPercent(double percent){
    per=percent;
    pBar->setValue(percent);
}
void downloadBarItem::setSpeed(double speed){
    sp=speed;
    pBar->setFormat(fileName+"  "+downloadModel::getDownloadSpeedString(speed));
}
void downloadBarItem::contextMenuEvent(QContextMenuEvent *event){
    QMenu menu;
    if(!this->isFinished()){
        if(!this->isPaused())menu.addAction("Pause");
        else menu.addAction("Continue");
        menu.addAction("Cancel");
    }
    else {
        menu.addAction("Open");
        menu.addAction("Open Folder");
        menu.addAction("Delete File");
    }
    menu.addSeparator();
    menu.addAction("Restart");
    menu.addAction("Copy Link Location");
    connect(&menu,SIGNAL(triggered(QAction*)),this,SLOT(menuTriggered(QAction*)));
    menu.exec(event->globalPos());
}
//slots
void downloadBarItem::menuTriggered(QAction *action){
    if(action->text()=="Pause")emit pause();
    else if(action->text()=="Continue")emit conti();
    else if(action->text()=="Open Folder")emit openFolder();
    else if(action->text()=="Restart")emit reDownload();
    else if(action->text()=="Cancel")emit cancel();
    else if(action->text()=="Open")emit openFile();
    else if(action->text()=="Copy Link Location")emit copyLink();
    else if(action->text()=="Delete File")emit delFile();
}

void downloadBarItem::copyLinkLocation(){
    QClipboard* clip=QApplication::clipboard();
    clip->setText(url);
}

/********************************DownloadBar(the view class)********************************/

downloadBar::downloadBar(QWidget *parent):QWidget(parent),fileNum(0){
    pBar=new QProgressBar(this);
    QVBoxLayout* barLayout=new QVBoxLayout(this);
    barLayout->setContentsMargins(0,0,0,0);
    barLayout->setSpacing(1);
    box=new QGroupBox(this);
    barLayout->addWidget(box);
    barLayout->addWidget(pBar);
    boxLayout=new QVBoxLayout;
    box->setLayout(boxLayout);
    box->hide();
}
void downloadBar::addNewDownloadBarItem(downloadBarItem *item){
    fileNum++;
    boxLayout->addWidget(item);
}
void downloadBar::delDownloadBarItem(downloadBarItem *item){
    boxLayout->removeWidget(item);
}

void downloadBar::setText(const QString &text){
    pBar->setFormat(text);
}
void downloadBar::setPercent(int percent){
    pBar->setValue(percent);
}
void downloadBar::mouseReleaseEvent(QMouseEvent *event){
    if(event){
        if(box->isHidden())box->show();
        else box->hide();
    }
}

/*********************************DownloadBarController(for bar and items)*******************************/

downloadBarController::downloadBarController(downloadBar *dBar):bar(dBar){}
void downloadBarController::setModel(downloadModel *dModel){
    model=dModel;
}
void downloadBarController::addNewDownloadBarItem(QNetworkReply *reply, const QString &path){
    downloadBarItem* item=new downloadBarItem(reply,path);
    bar->addNewDownloadBarItem(item);
    itemList.append(item);
    item->getTimer().start();
    updateBarPercent();
    updateBarSpeed();

    //connections
    connect(item,SIGNAL(cancel()),this,SLOT(abortBtnPressed()));
    connect(item,SIGNAL(conti()),this,SLOT(continueBtnPressed()));
    connect(item,SIGNAL(delFile()),this,SLOT(deleteFileBtnPressed()));
    connect(item,SIGNAL(openFile()),this,SLOT(openFileBtnPressed()));
    connect(item,SIGNAL(openFolder()),this,SLOT(openFilePathBtnPressed()));
    connect(item,SIGNAL(pause()),this,SLOT(pauseBtnPressed()));
    connect(item,SIGNAL(reDownload()),this,SLOT(restartBtnPressed()));

    //downloadBuffers connections
    connect(item,SIGNAL(finished()),model,SLOT(downloadFinished()));
    connect(item,SIGNAL(readyRead()),model,SLOT(readyReadContent()));
    connect(item,SIGNAL(downloadProgress(qint64,qint64)),model,SLOT(downloadProgressAction(qint64,qint64)));
}
void downloadBarController::updateBarPercent(){
    qint64 total=0,received=0;
    foreach(downloadBarItem* item,itemList){
        qint64 size=item->getReply()->size();
        total+=size;
        received+=(item->getPercent())*size;
    }
    if(!total)bar->setPercent(0);
    else bar->setPercent(received/total);
}
void downloadBarController::updateBarSpeed(){
    double speed=0;
    foreach(downloadBarItem* item,itemList){
        speed+=item->getSpeed();
    }
    bar->setText(itemList.count()+" Files "+model->getDownloadSpeedString(speed));
}

void downloadBarController::pauseBtnPressed(){
    //
}
void downloadBarController::continueBtnPressed(){
    //
}
void downloadBarController::abortBtnPressed(){
    downloadBarItem* item=(downloadBarItem*)sender();
    this->deleteDownloadItemBtnPressed(item);
}
void downloadBarController::openFileBtnPressed(){
    downloadBarItem* item=(downloadBarItem*)sender();
    QFile* file=item->getOutputFile();
    QDesktopServices::openUrl(QFileInfo(*file).absoluteFilePath());
}
void downloadBarController::openFilePathBtnPressed(){
    downloadBarItem* item=(downloadBarItem*)sender();
    QFile* file=item->getOutputFile();
    QDesktopServices::openUrl(QFileInfo(*file).absoluteFilePath());
}
void downloadBarController::deleteFileBtnPressed(){
    downloadBarItem* item=(downloadBarItem*)sender();
    QDir dir;
    dir.remove(QFileInfo(*(item->getOutputFile())).absoluteFilePath());
}
void downloadBarController::deleteDownloadItemBtnPressed(downloadBarItem *item){
    bar->delDownloadBarItem(item);
    itemList.removeOne(item);
    item->getOutputFile()->close();
    if(!item->isFinished()){
        item->getReply()->abort();
        delete item->getReply();
        QDir dir;
        dir.remove(QFileInfo(*(item->getOutputFile())).absoluteFilePath());
    }
    updateBarSpeed();
    updateBarPercent();
    delete item;
}
void downloadBarController::deleteAllItemBtnPressed(){
    foreach(downloadBarItem* item,itemList){
        bar->delDownloadBarItem(item);
        itemList.removeOne(item);
        delete item;
    }
}
void downloadBarController::restartBtnPressed(){
    downloadBarItem* item=(downloadBarItem*)sender();
    QUrl url=item->getReply()->url();
    QDir dir;
    QFile* file=item->getOutputFile();
    QString path=QFileInfo(*file).absoluteFilePath();
    dir.remove(QFileInfo(*file).absoluteFilePath());
    this->deleteDownloadItemBtnPressed(item);
    model->downloadProcess(path,url);
}

/************************DownloadModel***************************/

downloadModel::downloadModel(downloadBarController *con,downloadController *dCon):barController(con),totalController(dCon){}

//Though named speedString,this function returns a size string like 4.2MB
//fileSize func calls this to get a fileSize string as well as the speed funcs
QString downloadModel::getDownloadSpeedString(double v){
    int level=0;
    while(v>1024){
        v/=1024;
        level++;
    }
   QString speedString=QString::number(v,'f',1);
    if(level==0)speedString+="B";
    else if(level==1)speedString+="KB";
    else if(level==2)speedString+="MB";
    else if(level==3)speedString+="GB";
    else speedString+="..";
    return speedString;
}
double downloadModel::getDownloadPercent(qint64 received, qint64 total){
    return (double)received*100/(double)total;
}

//slots
void downloadModel::downloadRequest(const QUrl& url){
    if(downloadFileType::isFirstDonwload(url)){
        totalController->showDownloadPathWindow(url);
    }
    else{
        QString path=QFileInfo(url.path()).fileName();
        path=downloadFileType::getFilePath(QFileInfo(path).completeSuffix())+"/"+path;
        this->downloadProcess(path,url);
    }
}
void downloadModel::downloadProcess(const QString &path, const QUrl &url){
    QNetworkRequest request;
    request.setUrl(url);
    request.setRawHeader("User-Agent","Glauca 0.1");
    QNetworkReply* reply=MainWindow::instance()->getNetworkManager()->get(request);
    barController->addNewDownloadBarItem(reply,path);
}
void downloadModel::downloadFinished(){
    downloadBarItem* item=(downloadBarItem*)sender();
    if(item){
        item->getOutputFile()->close();
        item->getReply()->deleteLater();
    }
}
void downloadModel::readyReadContent(){
    downloadBarItem* item=(downloadBarItem*)sender();
    QByteArray bytes=item->getReply()->readAll();
    item->getOutputFile()->write(bytes);
    item->getByteSize()+=bytes.size();
    int time=item->getTimer().elapsed();
    if(time&&time>=1000){
       double v=double(item->getByteSize())*1000/(double)(time);
       item->getByteSize()=0;
       item->setSpeed(v);
       item->getTimer().restart();
       barController->updateBarPercent();
       barController->updateBarSpeed();
   }
}
void downloadModel::downloadProgressAction(qint64 got, qint64 total){
    downloadBarItem* item=(downloadBarItem*)sender();
    double v=(double)got*100/(double)total;
    item->setPercent(v);
}

/***********************downloadController***********************/

downloadController::downloadController(downloadView *dView):view(dView){
}
void downloadController::setModel(downloadModel *dModel){
    model=dModel;

}
downloadModel* downloadController::getModel(){
    return model;
}
void downloadController::showDownloadPathWindow(const QUrl &url){
    view->showDownloadPathWindow(url);
}
void downloadController::pathWinConfirmAction(){
    QDialog* dialog=(QDialog*)sender();
    QLabel* label=dialog->findChild<QLabel*>("pathLabel");
    QCheckBox* checkbox=dialog->findChild<QCheckBox*>("ifRemember");
    QLabel* urlSaver=dialog->findChild<QLabel*>("urlSaver");
    QUrl url(urlSaver->text());
    if(checkbox->isChecked())downloadFileType::changePath(QFileInfo(url.path()).completeSuffix(),label->text());

    model->downloadProcess(label->text(),url);
    dialog->close();
}
void downloadController::pathBtnPressed(){
    QPushButton* btn=(QPushButton*)sender();
    QDialog* dialog=qobject_cast<QDialog*>(btn->parentWidget());
    QLabel* label=dialog->findChild<QLabel*>("urlSaver");
    QString temp=QFileDialog::getSaveFileName(dialog,"Open Directory","/home/"+QFileInfo(QUrl(label->text()).path()).fileName(),"All files(*.*)",0);
    if(temp=="")return;
    label=dialog->findChild<QLabel*>("pathLabel");
    label->setText(temp);
}

/**************************downloadView******************************/
downloadView::downloadView(QObject *parent):QObject(parent){
    bar=new downloadBar(MainWindow::instance());
    bar->setFixedWidth(200);
    downloadBarController* barController=new downloadBarController(bar);
    controller=new downloadController(this);
    downloadModel* model=new downloadModel(barController,controller);
    controller->setModel(model);
    barController->setModel(model);
}

QDialog* downloadView::showDownloadPathWindow(const QUrl &url){
    QDialog* fileDialog=new QDialog(MainWindow::instance());
    fileDialog->setMinimumSize(350,250);
    QString fileType=QFileInfo(url.path()).completeSuffix();
    fileDialog->setWindowTitle("File Download Dialog");
    QLabel* urlSaver=new QLabel(fileDialog);
    urlSaver->setText(url.toString());
    urlSaver->setObjectName("urlSaver");
    QLabel* noti=new QLabel(fileDialog);
    noti->setText("<b>You have chosen to download:<br><font color='red'>"+QFileInfo(url.path()).fileName()+"</color><br>It will be saved to :</b><br>");
    QLabel* defaultFilePathLabel=new QLabel(fileDialog);
    defaultFilePathLabel->setObjectName("pathLabel");
    defaultFilePathLabel->setText(downloadFileType::getFilePath(fileType)+"/"+QFileInfo(url.path()).fileName());
    QPushButton* selectBtn=new QPushButton("Select",fileDialog);
    connect(selectBtn,SIGNAL(released()),controller,SLOT(pathBtnPressed()));
    QCheckBox*  ifRemember=new QCheckBox("Remember my path for this format");
    ifRemember->setObjectName("ifRemember");
    QVBoxLayout* layout=new QVBoxLayout();
    fileDialog->setLayout(layout);
    layout->addWidget(noti);
    QHBoxLayout* vLayout=new QHBoxLayout();
    vLayout->addWidget(defaultFilePathLabel);
    vLayout->addWidget(selectBtn);
    layout->addLayout(vLayout);
    layout->addWidget(ifRemember);
    QPushButton* okBtn=new QPushButton(fileDialog);
    okBtn->setText("Comfirm");
    connect(okBtn,SIGNAL(released()),fileDialog,SIGNAL(accepted()));
    QPushButton* cancelBtn=new QPushButton(fileDialog);
    cancelBtn->setText("Cancel");
    connect(cancelBtn,SIGNAL(released()),fileDialog,SLOT(close()));
    QHBoxLayout* btnLayout=new QHBoxLayout();
    btnLayout->addWidget(okBtn);
    btnLayout->addWidget(cancelBtn);
    layout->addLayout(btnLayout);
    fileDialog->setModal(true);
    fileDialog->setAttribute(Qt::WA_DeleteOnClose,true);
    fileDialog->show();
    connect(fileDialog,SIGNAL(accepted()),controller,SLOT(pathWinConfirmAction()));
    return fileDialog;
}
downloadBar* downloadView::getDownloadBar(){
    return bar;
}
void downloadView::downloadRequest(const QNetworkRequest &request){
    controller->getModel()->downloadRequest(request.url());
}

bool downloadFileType::isFirstDonwload(const QUrl& url){
    QSettings set;
    QString path=set.value("FileType/"+QFileInfo(url.path()).completeSuffix()).toString();
    if(path=="")return true;
    else return false;
}
bool downloadFileType::changePath(const QString &fileType, const QString &newPath){
    QSettings set;
    set.setValue("FileType/"+fileType,newPath);
    return true;
}
bool downloadFileType::changeAllPath(const QString &newPath){
    QSettings set;
    QStringList stringList=set.allKeys();
    //Rules needed
    //uncompleted
    foreach(QString key,stringList){
        set.setValue("FileType/"+key,newPath);
    }
    return true;
}
QString downloadFileType::getFilePath(const QString &fileType){
    QSettings set;
    if(set.value("FileType/"+fileType).isNull())return set.value("FileType/default").toString();
    else return set.value("FileType/"+fileType).toString();
}
