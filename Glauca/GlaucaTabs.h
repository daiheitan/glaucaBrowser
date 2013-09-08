#ifndef GLAUCATABS_H
#define GLAUCATABS_H

#include <QWidget>
#include <QTabBar>
#include <QMenu>
#include <QMouseEvent>
#include "GlaucaTabAddon.h"
#include <QHBoxLayout>
#include "GlaucaTabWidget.h"

/*This class inherits QWidget,including a
  QTabBar and a add-on widget
  */
class GlaucaTabAddon;
class GlaucaTabWidget;
class GlaucaTabPrivate:public QTabBar{
    Q_OBJECT
public:
    GlaucaTabPrivate(GlaucaTabWidget* p=0);
protected:
    void mouseDoubleClickEvent(QMouseEvent * event);
    void contextMenuEvent(QContextMenuEvent *event);
private slots:
    void handleMenuRequest(QAction* action);
private:
    GlaucaTabWidget* parent;
    QPoint pos;
};

class GlaucaTabs:public QWidget
{
    Q_OBJECT
public:
    GlaucaTabs(GlaucaTabWidget * p=0);
    ~GlaucaTabs();
    void addTab(const QIcon &icon, const QString &text);
    void addTab(const QString &text);
    int tabTotalWidth();
    QTabBar* getTabBar();
    QWidget* getCornerWidget(int pos);
    int currentIndex();
    void setCornerWidget(QWidget* widget,int pos);
    GlaucaTabAddon* getTabAddon();
    void setTabAddon(GlaucaTabAddon*);
    void removeTab(int index);
/*public slots:
    void contextMenuEvent(QContextMenuEvent * event,QMenu* menu);*/
protected:
    void mouseDoubleClickEvent(QMouseEvent * event);
private:
    QMenu* tabMenu;//Only one Menu could exit on a TabBar
    GlaucaTabPrivate* tabBar;
    GlaucaTabAddon* tabAddon;
    QWidget* leftCorner,*rightCorner,*tabExtra;
    QHBoxLayout* layout;
    GlaucaTabWidget* parent;
};

#endif // GLAUCATABS_H
