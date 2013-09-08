#include "GlaucaTabAddon.h"
#include <QtDebug>
GlaucaTabAddon::GlaucaTabAddon(GlaucaTabs* tab):tabBar(tab){
    tabBar->setTabAddon(this);
    this->setContentsMargins(0,0,0,0);
    layout=new QHBoxLayout(this);
    layout->setContentsMargins(0,0,0,0);
    newTabButton=new QToolButton(this);
    newTabButton->setText("  ");
    newTabButton->setIcon(QIcon("./resources/tabBar/newTab.png"));
    newTabButton->setStyleSheet("QToolButton{border-width:3 5 3 5;border-image:url(./resources/tabBar/tab-default.png)3 5 3 5;border-style:solid;width: 23 px;height:16 px;}");
    layout->addWidget(newTabButton,Qt::AlignLeft);
    this->setLayout(layout);
}
GlaucaTabAddon::~GlaucaTabAddon(){
}

QToolButton* GlaucaTabAddon::getAddButton(){
    return newTabButton;
}

void GlaucaTabAddon::contextMenuEvent(QContextMenuEvent *event, QMenu *popMenu){
    if(event){
        popMenu->addAction(new QAction("blank",this));
        popMenu->exec(QCursor::pos());
    }
}
QHBoxLayout* GlaucaTabAddon::Layout(){
    return layout;
}
void GlaucaTabAddon::dentifyParent(GlaucaTabWidget * p){
    parent=p;
}
