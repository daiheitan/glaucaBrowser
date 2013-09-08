#include "GlaucaIconService.h"
#include <QHttp>
#include <QDataStream>
#include <QtDebug>
#include <QWebFrame>
#include <QWebElement>
#include <QSqlDatabase>
#include <QFileInfo>
#include <Qpixmap>
GlaucaIconService::GlaucaIconService(MainWindow* p){
    parent=p;
    bookMarkIconPath="./favIcon/";
    /*********************************
     *To be modified!
     *********************************
    QSqlDatabase db=QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./data/bookmark/websiteIcons.db");
    db.open();
    db.close();
    **********************************/
}
/**********************************
  this func will create a new file of icon
  and add its ID&url to the string list
  *********************************/
void GlaucaIconService::saveIcon(GlaucaWebTab* tab){
	if(tab==NULL)return;
	QFileInfo info(bookMarkIconPath+tab->url().host()+".ico");
	if(info.exists())return;
    tab->getIcon().pixmap(0).save(info.fileName(),"ico");
}
GlaucaIconService::~GlaucaIconService(){
    if(file!=0)delete file;
    if(http!=0)delete http;
}

void GlaucaIconService::loadFinished(int id,bool error){
    file->close();
    emit fileSucceed();
}
void GlaucaIconService::tempIconRequest(QBuffer& buff,GlaucaWebTab* tab){
	GlaucaWebView* view=tab->view();
    if(view->url().isEmpty())return ;
    buff.open(QIODevice::WriteOnly);
    QWebElement doc=view->page()->mainFrame()->documentElement();

    doc=doc.firstChild().firstChild();

    while(!doc.isNull()){
        if(doc.hasAttribute("rel")&&doc.attribute("rel").toLower()=="shortcut icon")break;
        else doc=doc.nextSibling();
    }

    QUrl url;
    if(doc.isNull())url=view->url();
    else url.setUrl(doc.attribute("href"));
    http=new QHttp;
    if(url.host().isEmpty())url.setUrl("http://"+view->url().host());
    http->setHost(url.host());
    http->get("/favicon.ico",&buff);
    connect(http,SIGNAL(requestFinished(int,bool)),tab,SIGNAL(buffLoaded()));
    connect(tab,SIGNAL(buffLoaded()),parent->getTabWidget(),SLOT(changeIcon()));
}
