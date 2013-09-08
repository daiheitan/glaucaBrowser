#include "GlaucaWebView.h"
#include <QtDebug>
#include <QWebFrame>
#include <QMessageBox>
#include <GlaucaDownloadService.h>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <GlaucaServices.h>
#include <QWebElement>

GlaucaWebView::GlaucaWebView(QWidget* p){
	this->page()->setForwardUnsupportedContent(true);
}
GlaucaWebView::~GlaucaWebView(){
}
QWebView* GlaucaWebView::createWindow(QWebPage::WebWindowType type){
	emit createWindowRequest(type);
	return (QWebView*)this;
}

void GlaucaWebView::mouseDoubleClickEvent(QMouseEvent *event){
	GlaucaQuickPanel* panel=MainWindow::instance()->getService()->quickPanel();
	panel->move(event->pos());
	panel->setFocus();
	panel->show();
}
void GlaucaWebView::contextMenuEvent(QContextMenuEvent *event){
	QWebHitTestResult result=page()->mainFrame()->hitTestContent(event->pos());
	QMenu menu(this);
	if(result.isContentSelected()){
		menu.addAction(pageAction(QWebPage::Copy));
		menu.addAction("Search \""+this->selectedText()+"\"",this,SIGNAL(searchRequest(this->selectedText())));
		menu.addAction("Add selected items to local wiki",this,SLOT(addSelectedToWiki()));
		menu.addSeparator();
	}
	if(!result.linkUrl().isEmpty()){
		menu.addAction("Open Link in new tab",this,SIGNAL(urlChanged(result.linkUrl())));
		menu.addAction(pageAction(QWebPage::DownloadLinkToDisk));
		menu.addAction(pageAction(QWebPage::CopyLinkToClipboard));
		menu.addSeparator();
	}
	if(!result.imageUrl().isEmpty()){
		menu.addAction(pageAction(QWebPage::CopyImageToClipboard));
		menu.addSeparator();
	}
	menu.addAction(pageAction(QWebPage::Back));
	menu.addAction(pageAction(QWebPage::Forward));
	menu.addAction(pageAction(QWebPage::Reload));
	menu.addAction(pageAction(QWebPage::Stop));
	menu.addSeparator();
	menu.addAction("Add page to local WIKI",this,SLOT(addPageToWiki()));
	menu.addAction("View Page Source",this,SLOT(viewPageSource()));
	menu.exec(mapToGlobal(event->pos()));
}
void GlaucaWebView::viewPageSource(){
	QString text=this->page()->currentFrame()->toHtml();
	QWidget* wid=new QWidget(NULL);
	QVBoxLayout* layout=new QVBoxLayout;
	wid->setLayout(layout);
	QTextEdit *t=new QTextEdit(wid);
	t->setAcceptRichText(false);
	layout->addWidget(t);
	t->setPlainText(text);
	wid->setAttribute(Qt::WA_DeleteOnClose,true);
	wid->show();
}
void GlaucaWebView::addSelectedToWiki(){
	qDebug()<<this->page()->selectedText()<<endl;
}
void GlaucaWebView::addPageToWiki(){
	MainWindow::instance()->getService()->wiki()->addDoc(this->title(),this->page()->currentFrame()->documentElement());
	MainWindow::instance()->getService()->wiki()->showWikiWin();
}