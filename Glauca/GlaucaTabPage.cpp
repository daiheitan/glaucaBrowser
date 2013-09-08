#include "GlaucaTabPage.h"
#include "GlaucaWebView.h"
#include <QtDebug>
GlaucaTabPage::GlaucaTabPage(QWidget* parent /* = 0 */,bool ifWebView):QWidget(parent),_ifWebView(ifWebView)
{
	_title="";
}
bool GlaucaTabPage::isWebView(){
	return _ifWebView;
}
void GlaucaTabPage::setUrl(const QUrl& url){
	_url=url;
}
bool GlaucaTabPage::isExtensionView(){
	return !_ifWebView;
}
QString GlaucaTabPage::title(){
	qDebug()<<"wuwu"<<endl;
	qDebug()<<_title<<endl;
	return _title;
}
void GlaucaTabPage::setTitle(const QString& t){
	_title=t;
}
QUrl GlaucaTabPage::url()const{
	return _url;
}