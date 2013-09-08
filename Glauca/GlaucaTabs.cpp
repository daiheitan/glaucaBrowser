#include "GlaucaTabs.h"
#include <QtDebug>
#include <QPushButton>
#include <QHBoxLayout>
#include <QWidget>
#include <QAction>
#include <QMenu>
#include "GlaucaUrlAction.h"

GlaucaTabPrivate::GlaucaTabPrivate(GlaucaTabWidget *p):QTabBar(p){
    parent=p;
    connect(this,SIGNAL(tabMoved(int,int)),parent,SLOT(moveTab(int,int)));
}
void GlaucaTabPrivate::mouseDoubleClickEvent(QMouseEvent *event){
    int index=this->tabAt(event->pos());
    parent->tabCloseRequest(index);
}
void GlaucaTabPrivate::contextMenuEvent(QContextMenuEvent* event){
    pos=event->pos();
    QMenu menu(this);
    menu.addAction(new QAction("Add to Bookmark",&menu));
    menu.addAction(new QAction("Never write to History",&menu));
    menu.addAction(new QAction("Close Tab",&menu));
    connect(&menu,SIGNAL(triggered(QAction*)),this,SLOT(handleMenuRequest(QAction*)));
    menu.exec(QCursor::pos());
}
void GlaucaTabPrivate::handleMenuRequest(QAction *action){
    int tabIndex=this->tabAt(pos);
    if(action->text()=="Add to Bookmark"){
        parent->getMainWin()->getService()->bookMark()->saveSelectWindow(parent->getPage(tabIndex));
    }
    else if(action->text()=="Close Tab")parent->tabCloseRequest(tabIndex);
}

GlaucaTabs::GlaucaTabs(GlaucaTabWidget *p):parent(p){
    layout=new QHBoxLayout(this);
    layout->setContentsMargins(0,0,0,0);
    tabBar=new GlaucaTabPrivate(parent);
    tabBar->setObjectName("tabBar");
    tabAddon=new GlaucaTabAddon(this);

    tabExtra=new QWidget(this);
    tabExtra->setLayout(new QHBoxLayout());
    tabExtra->layout()->addWidget(tabBar);
    tabExtra->layout()->addWidget(tabAddon);
    tabExtra->layout()->setContentsMargins(0,0,0,0);

    layout->addWidget(tabExtra,1,Qt::AlignLeft);
    this->setLayout(layout);
    layout->setAlignment(this,Qt::AlignTop);

    QSettings sets;
    tabBar->setMovable(sets.value("Tabs/movable").toBool());
    tabBar->setTabsClosable(sets.value("Tabs/showCloseBtn").toBool());

    tabMenu=0;
    leftCorner=0;
    rightCorner=0;

}
GlaucaTabs::~GlaucaTabs(){
}

void GlaucaTabs::addTab(const QIcon &icon, const QString &text){
    this->tabBar->addTab(icon,text);
}
void GlaucaTabs::addTab(const QString &text){
    this->tabBar->addTab(text);
}
void GlaucaTabs::removeTab(int index){
    tabBar->removeTab(index);
}

QTabBar* GlaucaTabs::getTabBar(){
    return tabBar;
}
GlaucaTabAddon* GlaucaTabs::getTabAddon(){
    return tabAddon;
}

void GlaucaTabs::setCornerWidget(QWidget *widget, int pos){
    if(pos)rightCorner=widget;
    else leftCorner=widget;
    if(pos)layout->addWidget(widget,Qt::AnchorRight);
    else layout->insertWidget(0,widget,Qt::AlignLeft);
}
QWidget* GlaucaTabs::getCornerWidget(int pos){
    if(pos)return rightCorner;
    else return leftCorner;
}
int GlaucaTabs::currentIndex(){
    return tabBar->currentIndex();
}
void GlaucaTabs::setTabAddon(GlaucaTabAddon * p){
    tabAddon=p;
}
void GlaucaTabs::mouseDoubleClickEvent(QMouseEvent *event){
    if(event) parent->addBlankTab();
}
