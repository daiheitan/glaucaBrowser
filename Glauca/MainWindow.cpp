#include "MainWindow.h"
#include "qnamespace.h"

#include <QFile>
#include <QToolBar>
#include <QWebFrame>
#include <QMenu>
#include <QMenuBar>
#include <QStyle>
#include <QVBoxLayout>
#include <QStackedWidget>
#include <QDebug>
#include <QWidget>
#include <Qt>
#include <QProgressBar>
#include <QToolButton>
#include <QDomNode>
#include <QDomNodeList>
#include <QBitmap>
#include <QTimer>
#include <QDesktopWidget>
#include "GlaucaPlugins.h"
#include <QDesktopServices>
#include <QDir>
#include <QFileInfo>
#include <QWebHistory>
#include <QLibrary>
MainWindow* MainWindow::_mainWin=0;
MainWindow* MainWindow::instance(){
    if(_mainWin==0)new MainWindow();
    return _mainWin;
}
MainWindow::MainWindow():QWidget()
{
    _mainWin=this;
    this->setWindowFlags(Qt::Window);
    this->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Minimum);
}
void MainWindow::buildWindow(){
    //this->setFixedSize(800,600);
    sets=new GlaucaSettings(this);
    connect(sets,SIGNAL(currentPageReuqest()),this,SLOT(setHomePageText()));
    service=new GlaucaServices(this);
    progress=0;
    /*QFile file;
    file.setFileName(":/jquery.min.js");
    file.open(QIODevice::ReadOnly);
    jQuery=file.readAll();
    file.close();*/

    QVBoxLayout *mainLabel=new QVBoxLayout(this);
    mainLabel->setContentsMargins(0,0,0,0);

    ////////////////////////////////
    //This Adds the left Dock
    leftDock=new GlaucaDocks("dock",this);
    mainLabel->addWidget(leftDock);
    QToolButton* config=leftDock->addActBtn("Config",QIcon("./resources/docks/spotlight.png"));
    connect(config,SIGNAL(clicked()),sets,SLOT(glaucaSettingsWindow()));
    QMenu* historyMenu=service->history()->getHistoryMenu();
    leftDock->addMenuBtn("history",QIcon("./resources/docks/Public.png"),historyMenu);
    QToolButton* downloadWin=leftDock->addActBtn("Download",QIcon("./resources/docks/ToolbarDownload.Png"));
    //connect(downloadWin,SIGNAL(clicked()),service->download(),SLOT(showGlaucaDownloadWindow()));
    QToolButton* pluginBtn=leftDock->addActBtn("Plugins",QIcon("./resources/docks/plugin.png"));
    connect(pluginBtn,SIGNAL(clicked()),this,SLOT(openPluginWin()));
    leftDock->setVisible(false);

    toolBarWidget=new QWidget(this);
    QVBoxLayout* tbLayout=new QVBoxLayout(toolBarWidget);
    tbLayout->setContentsMargins(0,0,0,0);
    tbLayout->setSpacing(0);
    QVBoxLayout *label=new QVBoxLayout(this);
    label->setContentsMargins(0,0,0,0);
    label->setAlignment(this,Qt::AlignTop);
    label->setSpacing(0);
	qDebug()<<"here?started debugging"<<endl;
    tabWidget=new GlaucaTabWidget(this);
    QUrl url("http://www.google.com");

    mainLabel->addLayout(label);

    locationBar* locationEdit = service->urlBar();
    locationEdit->setRelatedTabWidget(tabWidget);
    //locationEdit->setSizePolicy(QSizePolicy::Minimum, locationEdit->sizePolicy().verticalPolicy());

    ////////////////////////////
    //Add to Bookmark BTN
    ////////////////////////////
    bookMark=service->bookMark()->addBookmarkBtn();
    locationEdit->setCornerWidget(bookMark,false);
	qDebug()<<"hehe"<<endl;
    ////////////////////////////
    //Create 2 toolbars
    ////////////////////////////
    QToolBar *toolBar = new QToolBar(this);
    toolBar->setContentsMargins(0,0,0,0);
    toolBar->setStyleSheet("QToolBar{border-width:2 1 2 1;border-image:url(./resources/tabBar/nav-toolbox.png);}2 3 2 3");
    //toolBar->setFixedWidth(800);
    quickcon = service->bookMark()->bookmarkBar(this);
    quickcon->setStyleSheet("QToolBar{border-width:2 1 2 1;border-image:url(./resources/tabBar/nav-toolbox.png);}2 3 2 3");
    quickcon->setFixedHeight(28);
    //init Web Buttons
    back=new QPushButton(this);
    back->setObjectName("glauca-backBtn");
    forward=new QPushButton(this);
    forward->setObjectName("glauca-forwardBtn");
    reload=new QToolButton(this);
    reload->setObjectName("glauca-reloadBtn");
    stop=new QToolButton(this);
    stop->setObjectName("glauca-stopBtn");
    go=new QToolButton(this);
    go->setObjectName("glauca-goBtn");
    stateBtnStack=new QStackedWidget(this);
    stateBtnStack->setObjectName("glauca-tBtnStack");
    stateBtnStack->addWidget(go);
    stateBtnStack->addWidget(stop);
    stateBtnStack->addWidget(reload);

    GlaucaWebTab* tab=tabWidget->addBlankTab();
    tab->view()->load(url);
    //tabBar->getTabBar()->setCurrentIndex(0);

    //quickcon->setFixedWidth(800);
    tbLayout->addWidget(toolBar);
    label->addWidget(tabWidget->getTabBar());
    label->addWidget(toolBarWidget);

    connect(back,SIGNAL(clicked()),tabWidget->getCurrentPage(),SLOT(back()));
    connect(forward,SIGNAL(clicked()),tabWidget->getCurrentPage(),SLOT(forward()));
    toolBar->addWidget(back);
    toolBar->addWidget(forward);
    tbLayout->addWidget(quickcon);
    label->addWidget(tabWidget->getStack());


    QWidget *line = new QWidget(this);
      QVBoxLayout *vlayout = new QVBoxLayout(line);
      vlayout->setSpacing(0);
      vlayout->setContentsMargins(0,4,0,3);//设定四周宽度
      vlayout->addWidget(locationEdit);
      //vlayout->addWidget(tabWidget->getProStack());
      connect(locationEdit->getLocationEdit()->lineEdit(),SIGNAL(textEdited(QString)),this,SLOT(handleTextEdit()));
      toolBar->addWidget(line);
      toolBar->addWidget(stateBtnStack);
      ///////////////////////////////////
      //Add the BookMark button
      //toolBar->addWidget(service->bookMark()->bookmarkBtn());
      connect(reload,SIGNAL(clicked()),tabWidget->getCurrentPage(),SLOT(reload()));
      connect(stop,SIGNAL(clicked()),tabWidget->getCurrentPage(),SLOT(stop()));
      label->addWidget(tabWidget->getStatusBar());
      startTimer(1000);
      this->applyTheme();
}
GlaucaServices* MainWindow::getService(){
    return service;
}
QUrl MainWindow::getCurrentUrl(){
	return tabWidget->getCurrentPage()->url();
}
MainWindow::~MainWindow(){
    delete tabWidget;
    killTimer(1);
}
GlaucaTabWidget* MainWindow::getTabWidget(){
    return tabWidget;
}
QString MainWindow::getAppRoamingDir(){
    return QString(QDesktopServices::storageLocation(QDesktopServices::HomeLocation)+"/appDATA/roaming/"+QCoreApplication::organizationName()+"/");
}
QNetworkAccessManager* MainWindow::getNetworkManager(){
    return tabWidget->getNetworkManager();
}

/*void MainWindow::mouseMoveEvent(QMouseEvent *e){
    if(this->isMaximized()){
        int wid = this->width();
        this->showNormal();
        double temp = this->width()*last.x()/wid-50;
        int x = temp;
        last = e->globalPos();
        int y = e->pos().y();
        pos0 = e->globalPos()-QPoint(x,y);
        max->setIcon(QIcon("./resources/001_07.png"));
    }

    QPoint newpos = e->globalPos();
    QPoint upleft = pos0 + newpos - last;
    move(upleft);
    this->update();
}

void MainWindow::mousePressEvent(QMouseEvent *e){
    last = e->globalPos();
        pos0 = e->globalPos() - e->pos();
}*/
void MainWindow::timerEvent(QTimerEvent *event){
    if(event){
    QRect rect(this->geometry().x()-5,this->geometry().y()+178,15,300);
    if(rect.contains(QCursor::pos())){
        this->killTimer(1);
        leftDock->showDock();
    }
}
}

//Slots

 void MainWindow::changeText(int index){
     if(tabWidget->getCurrentPage()->title()!="")setWindowTitle(tabWidget->getCurrentPage()->title());
     else setWindowTitle("Glauca Alpha 0.1");
	 if(tabWidget->getCurrentPage()->isExtensionView())service->urlBar()->setText("");
     else service->urlBar()->setText(((GlaucaWebTab*)tabWidget->getCurrentPage())->url().toString());
 }
 void MainWindow::openLinkRequest(const QString &url){
     tabWidget->loadPage(QUrl(url));
 }
 void MainWindow::addSavedNewPage(){
     service->bookMark()->saveSelectWindow(tabWidget->getCurrentPage());
 }

 void MainWindow::setStateBtnCurrentIndex(int index){
     stateBtnStack->setCurrentIndex(index);
 }

 QPushButton* MainWindow::custButton(QString str,QString str1,QWidget* parent){
     QPushButton* pushButton=new QPushButton(parent);
         pushButton->clearMask();
         pushButton->setBackgroundRole( QPalette::Base);
         //QString path=getAppRoamingDir()+"/profile/themes/"+set.value("Default/currentTheme").toString()+"/browser/";
         QPixmap mypixmap;   mypixmap.load(str);

         pushButton->setFixedSize(mypixmap.size());
         pushButton->setMask(mypixmap.createHeuristicMask());
         pushButton->setIcon(mypixmap);
         pushButton->setIconSize(mypixmap.size());
         pushButton->setToolTip(str1);
         return pushButton;
 }

 void MainWindow::setHomePageText(){
     sets->homePageUrlCombo->setEditText(getTabWidget()->getCurrentPage()->url().toString());
 }
 void MainWindow::openPluginWin(){
     GlaucaPlugins::showPluginWindow(this);
 }
 void MainWindow::changeBtnStates(){
     //Change the buttons
     back->setDisabled(!((GlaucaWebTab*)tabWidget->getCurrentPage())->view()->page()->history()->canGoBack());
     forward->setDisabled(!((GlaucaWebTab*)tabWidget->getCurrentPage())->view()->page()->history()->canGoForward());
 }
 void MainWindow::handleTextEdit(){
     stateBtnStack->setCurrentIndex(0);
 }

 //Glauca Theme
 void MainWindow::applyTheme(){
     QSettings set;
     QString mainPath=getAppRoamingDir()+"profile/themes/"+set.value("Default/currentTheme").toString();
     QString path=mainPath+"/chrome";
     {
     QFile file(path+"/tabBar/tabBar.qss");
     QFileInfo fileinfo(file);
     file.open(QIODevice::ReadOnly);
     QString stylesheet=file.readAll();
     stylesheet.replace("url(.","url("+fileinfo.absolutePath(),Qt::CaseInsensitive);
     tabWidget->getTabBar()->setStyleSheet(stylesheet);
     file.close();
 }
     {
     QFile file(path+"/browser/browser.qss");
     QFileInfo fileinfo(file);
     file.open(QIODevice::ReadOnly);
     QString stylesheet=file.readAll();
     stylesheet.replace("url(.","url("+fileinfo.absolutePath(),Qt::CaseInsensitive);
     this->setStyleSheet(stylesheet);
     }
     {
     QFile pathIconFile(path+"/panel/panel.qss");
     QFileInfo fileinfo(pathIconFile);
     pathIconFile.open(QIODevice::ReadOnly);
     QString stylesheet=pathIconFile.readAll();
     stylesheet.replace("url(.","url("+fileinfo.absolutePath(),Qt::CaseInsensitive);
     service->quickPanel()->setStyleSheet(stylesheet);
 }
}

 void MainWindow::showToolBar(){
     toolBarWidget->show();
 }
 void MainWindow::hideToolBar(){
     toolBarWidget->hide();
 }
