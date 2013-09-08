#include "GlaucaTabWidget.h"
#include <QtDebug>
#include <QPixmap>
#include <cookieJar.h>
#include <QWebFrame>

GlaucaTabWidget::GlaucaTabWidget(MainWindow *p){
    //QSettings sets;
    parent=p;
    statusBar=new QStatusBar(this);
    statusBar->setContentsMargins(0,0,0,0);
    statusBar->addPermanentWidget(parent->getService()->download()->getDownloadBar());
    statusBar->setSizeGripEnabled(false);
    isLinkHovered=false;
    tabBar=new GlaucaTabs(this);
    viewStack=new QStackedWidget(this);
    progressStack=new QStackedWidget(this);
    progressStack->setFixedHeight(3);
    tabBar->getTabBar()->setElideMode(Qt::ElideRight);
    viewStack->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    connect(tabBar->getTabBar(),SIGNAL(currentChanged(int)),this,SLOT(changeState(int)));
    connect(tabBar->getTabAddon()->getAddButton(),SIGNAL(released()),SLOT(addBlankTab()));
	connect(viewStack,SIGNAL(currentChanged(int)),this,SLOT(currentChangeSlot(int)));
	connect(this,SIGNAL(currentChanged(GlaucaTabPage*)),MainWindow::instance()->getService()->bookMark()->controller(),SLOT(setCurrentTab(GlaucaTabPage*)));
    //connect(viewStack,SIGNAL(currentChanged(int)),this,SLOT(changeState(int)));
    QWebSettings::globalSettings()->setAttribute(QWebSettings::PluginsEnabled,true);
    QWebSettings::globalSettings()->setAttribute(QWebSettings::JavascriptEnabled,true);
    netManager=new QNetworkAccessManager(this);
    netManager->setCookieJar(new cookieJar());
}
GlaucaTabWidget::~GlaucaTabWidget(){}

void GlaucaTabWidget::restoreTab(GlaucaWebTab* tab){
    tabList.append(tab);
    tabBar->addTab(tab->title());
    viewStack->addWidget(tab);
    progressStack->addWidget(tab->getProBar());
}

int GlaucaTabWidget::getIndex(GlaucaTabPage* page){
    return tabList.indexOf(page);
}
QStatusBar* GlaucaTabWidget::getStatusBar(){
    return statusBar;
}

QStackedWidget* GlaucaTabWidget::getStack(){
    return viewStack;
}

GlaucaTabs* GlaucaTabWidget::getTabBar(){
    return tabBar;
}
GlaucaTabPage* GlaucaTabWidget::getPage(int index){
    return tabList.at(index);
}
GlaucaTabPage* GlaucaTabWidget::getCurrentPage(){
    return tabList.at(tabBar->currentIndex());
}
GlaucaIconService* GlaucaTabWidget::getIconService(){
    return parent->getService()->iconSet();
}
QStackedWidget* GlaucaTabWidget::getProStack(){
    return progressStack;
}
MainWindow* GlaucaTabWidget::getMainWin(){
    return parent;
}
GlaucaServices* GlaucaTabWidget::getServices(){
    return parent->getService();
}
QNetworkAccessManager* GlaucaTabWidget::getNetworkManager(){
    return netManager;
}

void GlaucaTabWidget::setIcon(int index,const QIcon &icon){
    tabBar->getTabBar()->setTabIcon(index,icon);
}
void GlaucaTabWidget::setText(int index, const QString &text){
    tabBar->getTabBar()->setTabText(index,text);
}
void GlaucaTabWidget::setCornerWidget(QWidget *widget, bool flag){
    tabBar->setCornerWidget(widget,(flag==true?1:0));
}

void GlaucaTabWidget::tabCloseRequest(int index){
    if(tabBar->getTabBar()->count()==1)addBlankTab();
    GlaucaTabPage* page=tabList.at(index);
	if(page==0)return;
	tabBar->removeTab(index);
	tabList.removeAt(index);
	if(page->isWebView()){
		GlaucaWebTab* v=(GlaucaWebTab*)page;
		progressStack->removeWidget(v->getProBar());
		viewStack->removeWidget(v->view());
		parent->getService()->history()->addTabRestoreItem(v);
	}
	else{
		//to be added
	}
}
void GlaucaTabWidget::addTabPage(GlaucaTabPage* page){
	if(page==NULL||page->isWebView())return;
	progressStack->addWidget(new QProgressBar());
	tabList.append(page);
	viewStack->addWidget(page);
	tabBar->addTab(page->title());
}
void GlaucaTabWidget::setPageUrl(int index, QUrl *url){
	if(tabList.at(index)->isExtensionView())return;
    ((GlaucaWebTab*)tabList.at(index))->view()->setUrl(*url);
}
void GlaucaTabWidget::setPageUrl(GlaucaWebTab* tab,const QUrl& url){
    tab->view()->setUrl(url);
}
void GlaucaTabWidget::loadPage(const QUrl& url){
	GlaucaTabPage* page=this->getCurrentPage();
	GlaucaWebTab* tab=NULL;
	if(page->isExtensionView())tab=this->addBlankTab();
	else tab=(GlaucaWebTab*)page;
    tab->view()->setUrl(url);
}
void GlaucaTabWidget::loadPage(){
    if(getCurrentPage()->isExtensionView())return;
	((GlaucaWebTab*)getCurrentPage())->view()->reload();
}
//Slots
GlaucaWebTab* GlaucaTabWidget::addBlankTab(){
    GlaucaWebTab* view=new GlaucaWebTab(this);
    view->view()->page()->setNetworkAccessManager(netManager);
    progressStack->addWidget(view->getProBar());
    tabList.append(view);
    viewStack->addWidget(view->view());
    tabBar->addTab("New Tab");
    connect(view->view(),SIGNAL(urlChanged(QUrl)),parent,SLOT(changeBtnStates()));
    return view;
}
void GlaucaTabWidget::changeIcon(){
    GlaucaWebTab* view=(GlaucaWebTab*)sender();
    tabBar->getTabBar()->setTabIcon(this->getIndex(view),view->getIcon());
}
void GlaucaTabWidget::setCurrentPage(int index){
    tabBar->getTabBar()->setCurrentIndex(index);
    viewStack->setCurrentWidget(tabList.at(index));
}
void GlaucaTabWidget::moveTab(int from, int to){
    viewStack->removeWidget(tabList.at(from));
    viewStack->insertWidget(to,tabList.at(from));
	progressStack->removeWidget(tabList.at(from));
	progressStack->insertWidget(to,tabList.at(from));
    tabList.move(from,to);
}
void GlaucaTabWidget::currentChangeSlot(int index){
	emit currentChanged(tabList.at(index));
}
// void GlaucaTabWidget::removeView(GlaucaWebView *view){
//     delete view;
// }
void GlaucaTabWidget::initTabState(){
     GlaucaWebTab* tab=(GlaucaWebTab*)sender();
	 QUrl rurl=tab->view()->page()->currentFrame()->requestedUrl();
     if(rurl.isEmpty())tabBar->getTabBar()->setTabText(getIndex(tab),"New Tab");
     else tabBar->getTabBar()->setTabText(getIndex(tab),"Loading...");
     if(rurl.isEmpty())tab->view()->stop();
     tab->getProBar()->show();
     if(tab==getCurrentPage()){
        MainWindow::instance()->getService()->urlBar()->adjustLocation(rurl.toString());
     }
     parent->setStateBtnCurrentIndex(1);
 }
void GlaucaTabWidget::changeState(int index){
    viewStack->setCurrentIndex(index);
	if(tabList.at(index)->isExtensionView())return;
    //Change locationBar
    GlaucaWebView* view=((GlaucaWebTab*)tabList.at(index))->view();
    if(view->title()!="")setWindowTitle(view->title());
    else setWindowTitle("Glauca Alpha 0.1");
    MainWindow::instance()->getService()->urlBar()->setText(view->url().toString());
	/*
    //Change the BookMark Icon
    if(view->url().isEmpty()||!parent->getService()->bookMark()->getModel()->isPageSaved(view->url().toString()))
        parent->getService()->bookMark()->addBookmarkBtn()->setIcon(QIcon("./resources/001_17.png"));
    else parent->getService()->bookMark()->addBookmarkBtn()->setIcon(QIcon("./resources/001_15.png"));
	*/
    //Change the progress Bar
    if(progressStack->widget(index)->isHidden()){
    progressStack->setCurrentIndex(index);
    progressStack->currentWidget()->hide();
}
    else progressStack->setCurrentIndex(index);
    //change The State button
    if(view->pageAction(QWebPage::Reload)->isEnabled())parent->setStateBtnCurrentIndex(2);
    else parent->setStateBtnCurrentIndex(1);
}
void GlaucaTabWidget::adjustTitle()
{
    GlaucaWebTab* tab=(GlaucaWebTab*)sender();
    parent->setWindowTitle(tab->view()->title());
    if(tab->view()->title()!="")setText(getIndex(tab),tab->view()->title());
}
void GlaucaTabWidget::finishLoading()
{
    GlaucaWebTab* view=(GlaucaWebTab*)sender();
    adjustTitle();
    //view->loadIcon();
    //////////////////////////////Add this page to history
    if(view->title()!=""&&(!view->url().isEmpty()))
		parent->getService()->history()->addHistory(view->title(),view->url().toString(),view->getIcon());
    //view->page()->mainFrame()->evaluateJavaScript(jQuery);
    parent->setStateBtnCurrentIndex(2);
}
void GlaucaTabWidget::changeStatusMessageByPage(const QString &text){
    if(isLinkHovered)return;
    statusBar->showMessage(text);
}
void GlaucaTabWidget::changeStatusMessageByLinkeHover(const QString &text){
    if(text.isEmpty()){
        isLinkHovered=false;
        MainWindow::instance()->getService()->urlBar()->restore();
    }
    else{
        isLinkHovered=true;
       MainWindow::instance()->getService()->urlBar()->setText(text);
    }
}
