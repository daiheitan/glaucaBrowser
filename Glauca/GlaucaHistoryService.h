#ifndef GLAUCAHISTORYSERVICE_H
#define GLAUCAHISTORYSERVICE_H

#include "GlaucaUrlAction.h"//We will use the MenuAction class
#include "GlaucaXMLService.h"
#include <QMenu>
#include <QDomElement>
#include <QDomDocument>
#include "GlaucaWebView.h"
#include <QList>
#include <QObject>
#include <QSqlDatabase>

class GlaucaWebTab;
class GlaucaWebView;
class GlaucaHistoryService:public QObject{
    Q_OBJECT
public:
    GlaucaHistoryService(MainWindow* p);
    ~GlaucaHistoryService();
    void createHistoryFile();
    void addHistory(const QString& title,const QString& url,const QIcon& icon);
    QMenu* getHistoryMenu();
    QMenu* getClosedMenu();
    QList<QAction*>& getActionList();
public slots:
    void addTabRestoreItem(GlaucaWebTab* view);
private:
    QMenu* initRecentClosedMenu();
    void addRecentClosedMenuItem(bool flag=false);
    int tabRestoreNum;
    QString path;
    QDomDocument doc;
    MainWindow* parent;
    QList<QAction*> actionList;
    QList<GlaucaWebTab*> *tabRestoreList;
    QMenu* historyMenu,*tabRestoreMenu;
    QSqlDatabase db;
};

#endif // GLAUCAHISTORYSERVICE_H
