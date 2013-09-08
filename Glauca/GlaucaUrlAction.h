#ifndef GLAUCAURLACTION_H
#define GLAUCAURLACTION_H

#include <QAction>
#include "MainWindow.h"
#include "GlaucaWebTab.h"
#include <QWidget>
/******************************************
  **This file contains some classes on
  **urls and menu actions
  **and a class handling urls
  *****************************************/
class MainWindow;
class GlaucaWebTab;
class specialMenu:public QMenu{
public:
    specialMenu(QWidget* p);
protected:
    void contextMenuEvent(QContextMenuEvent *event);
};

class MenuAction:public QAction{
    Q_OBJECT
public:
    MenuAction(const QString& title,const QString& u,const QIcon& icon=QIcon());

signals:
    void clicked(QString);
    void openInNewTabRequest();
    void deleteRequest();
public slots:
    void handle();
    void openMenu();
private slots:
    void handleMenuRequest(QAction* act);
private:
    QString url;
    QMenu menu;
};

/////////////////////////////////////////
class MenuRestoreAction:public QAction{
    Q_OBJECT
public:
    MenuRestoreAction(GlaucaWebTab* v);
public slots:
    void handle();
private:
    GlaucaWebTab* view;
};

#endif // GLAUCAURLACTION_H
