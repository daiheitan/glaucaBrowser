#include "GlaucaWebTab.h"

GlaucaWebTab::GlaucaWebTab(GlaucaTabWidget* parent/* =0 */):GlaucaTabPage(parent,true){
	_view=new GlaucaWebView(this);
	progressbar=new QProgressBar(this);
	progressbar->setFixedHeight(3);
	//progressbar->setStyleSheet("QProgressBar::chunk {border-width:3;}");
	progressbar->setTextVisible(false);
	progressbar->hide();

#pragma region connections
	//GlaucaWebView's load Start and Finish singals will be handled by its webtab class
	connect(_view,SIGNAL(loadStarted()),this,SIGNAL(loadStarted()));
	connect(_view,SIGNAL(loadFinished(bool)),this,SIGNAL(loadFinished(bool)));
	//fin.

	connect(_view, SIGNAL(loadProgress(int)), progressbar, SLOT(setValue(int)));//连接进度
	connect(this,SIGNAL(loadFinished(bool)), progressbar,SLOT(hide()));
	connect(this,SIGNAL(loadStarted()),parent,SLOT(initTabState()));
	connect(this,SIGNAL(loadFinished(bool)),parent, SLOT(finishLoading()));
	connect(_view,SIGNAL(iconChanged()),this,SLOT(loadIcon()));
	connect(_view->page(),SIGNAL(statusBarMessage(QString)),parent,SLOT(changeStatusMessageByPage(QString)));
	connect(_view->page(),SIGNAL(linkHovered(QString,QString,QString)),parent,SLOT(changeStatusMessageByLinkeHover(QString)));
	connect(this,SIGNAL(buffLoaded()),this,SLOT(createIcon()));
	connect(_view->page(),SIGNAL(downloadRequested(QNetworkRequest)),this,SLOT(downloadRequest(QNetworkRequest)));
	connect(_view->page(),SIGNAL(unsupportedContent(QNetworkReply*)),this,SLOT(unsupportedContent(QNetworkReply*)));
	connect(_view,SIGNAL(urlChanged(QUrl&)),this,SIGNAL(urlChanged(QUrl&)));
#pragma endregion connections
}
QUrl GlaucaWebTab::url()const{
	return _view->url();
}
GlaucaWebView* GlaucaWebTab::view(){
	return _view;
}
void GlaucaWebTab::loadIcon(){
	parent->getIconService()->tempIconRequest(iconBuffer,this);
}
void GlaucaWebTab::createIcon(){
	QPixmap pix;
	if(iconBuffer.isOpen())iconBuffer.close();
	pix.loadFromData(iconBuffer.data());
	icon.addPixmap(pix);
}
QIcon GlaucaWebTab::getIcon(){
	return icon;
}
QProgressBar* GlaucaWebTab::getProBar(){
	return progressbar;
}
void GlaucaWebTab::downloadRequest(QNetworkRequest request){
	parent->getServices()->download()->downloadRequest(request);
}
void GlaucaWebTab::unsupportedContent(QNetworkReply *reply){
	QUrl url=reply->url();
	reply->abort();
	QNetworkRequest request(url);
	parent->getServices()->download()->downloadRequest(request);
}