#include "GlaucaDropInDialog.h"
#include <QtDebug>
//#include <libraries/quazip.h>
//#include <libraries/quazipfile.h>
#include <QLibrary>
#include <QFile>
#include <MainWindow.h>
#include <GlaucaXMLService.h>
#include <QFile>
GlaucaDropInDialog::GlaucaDropInDialog(QWidget *p):QWidget(p){
    this->setWindowFlags(Qt::Window);
}
void GlaucaDropInDialog::dragEnterEvent(QDragEnterEvent *event){
    if(event->mimeData()->hasFormat("text/uri-list"))event->acceptProposedAction();
}
void GlaucaDropInDialog::dropEvent(QDropEvent *event){
    QLibrary* libQuazip=new QLibrary("archive");
    if(!libQuazip->load()){
        qDebug()<<libQuazip->fileName()<<endl;
        qDebug()<<libQuazip->errorString()<<endl;
    }
    /*QList<QUrl> urls = event->mimeData()->urls();
    if(urls.isEmpty())return;
    QString fileName = urls.first().toLocalFile();
    if (fileName.isEmpty())return;
    QuaZip zipFile(fileName);
    zipFile.open(QuaZip::mdUnzip);
    QuaZipFile file(&zipFile);
    QString path=MainWindow::getAppRoamingDir()+"profile/themes/";
    //uncompress files 1 by 1
    bool zipFlag;
    for(zipFlag=zipFile.goToFirstFile();zipFlag;zipFlag=zipFile.goToNextFile()){
        if(file.getActualFileName()!="install.ini")break;
    }
    if(zipFlag==true){
        QMessageBox* mes=new QMessageBox(QMessageBox::Warning,"Glauca Plugin Window","This is not a correct theme/plugin file,or it is damaged.",QMessageBox::Ok);
        mes->show();
        return;
    }
    for(zipFlag=zipFile.goToFirstFile();zipFlag;zipFlag=zipFile.goToNextFile()){
        QString fileName=file.getActualFileName();
        if(fileName.at(fileName.length()-1)==QChar('/')){//This is a DIR
            QDir dir(path+"temp/"+fileName);
            if(!dir.exists())dir.mkpath(path+fileName);
        }
        else{
        QFile out;
        file.open(QIODevice::ReadOnly);
        out.setFileName(path+file.getActualFileName());
        if(!out.open(QIODevice::WriteOnly))qDebug()<<file.getActualFileName()<<endl;
        char c;
        while(file.getChar(&c)) out.putChar(c);
        out.close();
        file.close();
    }
    QSettings setTemp(path+"temp/install.ini");
    QString dirName=setTemp.value("pluginName").toString()+"@"+setTemp.value("author").toString();
    QDir dir;
    dir.rename(path+"temp/",path+dirName+"/");
    installTheme(path+dirName+"/");
}
    zipFile.close();*/
}
void GlaucaDropInDialog::installTheme(const QString &path){
    QSettings set(path+"install.ini");
    QDomDocument dom=GlaucaXMLService::read(MainWindow::getAppRoamingDir()+"profile/theme.xml");
    QDomElement domE=dom.createElement("theme");
    domE.setAttribute("name",set.value("pluginName").toString());
    domE.setAttribute("author",set.value("author").toString());
    domE.setAttribute("des",set.value("desciption").toString());
    dom.documentElement().appendChild(domE);
    GlaucaXMLService::write(MainWindow::getAppRoamingDir()+"profile/theme.xml",dom);
}
