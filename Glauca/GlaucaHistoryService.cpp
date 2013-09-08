#include "GlaucaHistoryService.h"

#include <QDate>
#include <QSettings>
#include <QSqlQuery>
#include <QPixmap>
#include <QSqlError>
#include <QDebug>
#include <QtSql>
GlaucaHistoryService::GlaucaHistoryService(MainWindow* p):parent(p),
                      tabRestoreList(0),
                      historyMenu(0),
                      tabRestoreMenu(0){
    QSettings sets;
    tabRestoreNum=sets.value("Storage/History/tabRestoreMaxNumber").toInt();
    if(tabRestoreNum)tabRestoreList=new QList<GlaucaWebTab*>();
    //updatePath();
    db=QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(MainWindow::instance()->getAppRoamingDir()+"profile/history.db");
    if(!db.open())return;
    QSqlQuery query(db);

        query.exec("create table history(time int primary key,title varchar(4000),url varchar(4000),icon varchar)");
    query.clear();
}
GlaucaHistoryService::~GlaucaHistoryService(){
    db.removeDatabase("defaultConnection");
    GlaucaXMLService::write(path,doc);
    delete tabRestoreList;
}
void GlaucaHistoryService::createHistoryFile(){
    //old
    doc.clear();
    QDomElement root=doc.createElement("root");
    root.setAttribute("month",QDate::currentDate().month());
    doc.appendChild(root);

    QDomNode node=doc.createProcessingInstruction("xml", "version=\"1.0\" encoding=\"UTF-8\"");
    doc.insertBefore(node,root);
    GlaucaXMLService::write(path,doc);
}

void GlaucaHistoryService::addHistory(const QString &title, const QString &u,const QIcon& icon){
    const QString url=u.toLower();
    QSqlQuery query(db);
    QByteArray ba;
    QBuffer buf(&ba);
    QPixmap pix=icon.pixmap(16);
    buf.open(QIODevice::WriteOnly);
    pix.save(&buf,"ICO");
    query.exec("INSERT INTO history(time,title,url,icon) "
               "VALUES("+QString::number(QDate::currentDate().day())+QTime::currentTime().toString("hhmmss")+','+"'"+title+"','"+url+"','"+QString(buf.buffer().toBase64())+"')");
    MenuAction *action=new MenuAction(title,u,icon);
    //qDebug()<<"INSERT INTO history(time,title,url,icon) "
    //        "VALUES("+QString::number(QDate::currentDate().day())+QTime::currentTime().toString("hhmmss")+','+"'"+title+"','"+url+"','"+QString(buf.buffer().toBase64())+"')"<<endl;
    //the first item is recent closed menu,so we insert the new item after it.
    if(icon.isNull())qDebug()<<"NULL ICON"<<endl;
    historyMenu->insertAction(historyMenu->actions().at(2),action);
    QSettings set;
    if(actionList.count()>set.value("Storage/History/menuHistoryNumber").toInt())
    {
        QAction* act=actionList.last();
        historyMenu->removeAction(act);
        actionList.removeLast();
        delete act;
    }
}
QMenu* GlaucaHistoryService::initRecentClosedMenu(){
    tabRestoreMenu=new QMenu("Recently Closed",parent);
    tabRestoreMenu->setAttribute(Qt::WA_DeleteOnClose,true);
    if(tabRestoreNum==0){
        tabRestoreMenu->setEnabled(false);
        return tabRestoreMenu;
    }
    foreach(GlaucaWebTab* view,*tabRestoreList){
        MenuRestoreAction* act=new MenuRestoreAction(view);
        tabRestoreMenu->addAction(act);
    }
    return tabRestoreMenu;
}
void GlaucaHistoryService::addRecentClosedMenuItem(bool flag){
    tabRestoreMenu->addAction(new MenuRestoreAction(tabRestoreList->first()));
    if(flag){
        QAction* act=tabRestoreMenu->actions().last();
        tabRestoreMenu->removeAction(act);
        delete act;
    }
}
QList<QAction*>& GlaucaHistoryService::getActionList(){
    return actionList;
}

QMenu* GlaucaHistoryService::getHistoryMenu(){
    if(!historyMenu){
    QSettings sets;
    int count=sets.value("Storage/History/menuHistoryNumber").toInt();
    historyMenu=new QMenu(parent);
    historyMenu->setAttribute(Qt::WA_DeleteOnClose,true);

    historyMenu->addMenu(initRecentClosedMenu());
    historyMenu->addSeparator();
    QSqlQuery query(QSqlDatabase::database());
    query.exec("SELECT * FROM history");
    while(query.next()&&count--){
        QPixmap pic;
        pic.loadFromData(QByteArray::fromBase64(query.value(3).toByteArray()));
        MenuAction *act=new MenuAction(query.value(1).toString(),query.value(2).toString(),QIcon(pic));
        actionList.append(act);
        historyMenu->addAction(act);
    }
    query.clear();
}
    return historyMenu;
}
QMenu* GlaucaHistoryService::getClosedMenu(){
    if(!tabRestoreMenu)initRecentClosedMenu();
    return tabRestoreMenu;
}

//Slots
void GlaucaHistoryService::addTabRestoreItem(GlaucaWebTab* view){
    if(view->url().isEmpty())return;
    if(tabRestoreList==0){
        delete view;
        return;
    }
    tabRestoreList->prepend(view);
    if(tabRestoreList->count()>tabRestoreNum){
        GlaucaWebTab* temp=tabRestoreList->last();
		tabRestoreList->removeLast();
		delete temp;
        addRecentClosedMenuItem(true);
    }
   else addRecentClosedMenuItem(false);
}
