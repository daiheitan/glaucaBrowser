#include "GlaucaWikiEditor.h"
#include <QHBoxLayout>
#include <QWebElement>
#include <QSqlQuery>
#include <QtDebug>

GlaucaWikiEditor::GlaucaWikiEditor(QWidget* parent/* =0 */):p(parent)
{
	wid=NULL;
	tWid=NULL;
	view=NULL;
}
void GlaucaWikiEditor::showWikiWin(){
	if(wid==NULL){
		wid=new GlaucaTabPage(NULL,false);
		wid->setTitle("Glauca Local Wiki");
		wid->setUrl(QUrl("extensions::wiki"));
		QHBoxLayout *rootLayout=new QHBoxLayout;
		wid->setLayout(rootLayout);
		tWid=new QTreeWidget(wid);
		rootLayout->addWidget(tWid);
		view=new QWebView(wid);
		rootLayout->addWidget(view);
		view->load(QUrl("http://www.baidu.com/"));
	}
	MainWindow::instance()->getTabWidget()->addTabPage(wid);
}
bool GlaucaWikiEditor::initDB(){
	if(!db.isValid())db=QSqlDatabase::addDatabase("QSQLITE");
	if(db.connectionName().isEmpty())db.setDatabaseName(MainWindow::instance()->getAppRoamingDir()+"profile/wiki.db");
	if(!db.isOpen())
		if(!db.open())return false;
	if(db.tables().isEmpty()){
		QSqlQuery query(db);
		query.exec("create table wiki(title varchar(250) primary key,Element varchar");
	}
	return true;
}
bool GlaucaWikiEditor::addDoc(const QString& title,const QWebElement& element){
	if(initDB()==false)return false;
	QSqlQuery query(db);
	query.exec("INSERT INTO wiki(title,Element)"
		"VALUES('"+title+"','"+element.toPlainText()+"')");
	db.close();
	return true;
}