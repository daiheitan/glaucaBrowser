#include "GlaucaQuickPanel.h"

#include <QVBoxLayout>
#include <QPushButton>
#include <QHBoxLayout>
#include <MainWindow.h>
#include <QtDebug>

GlaucaQuickPanel::GlaucaQuickPanel(QWidget *parent) :
    QWidget(parent),
    historyBar(0),closedBar(0),
    bookmarkBar(0),toolsBar(0)
{
    this->setWindowFlags(Qt::Window|Qt::FramelessWindowHint);
    QVBoxLayout* mainLayout=new QVBoxLayout;
    QVBoxLayout* upLayout=new QVBoxLayout;
    QVBoxLayout* downLayout=new QVBoxLayout;
    QHBoxLayout* middleLayout=new QHBoxLayout;
    QHBoxLayout* leftLayout=new QHBoxLayout;
    QHBoxLayout* rightLayout=new QHBoxLayout;
    QHBoxLayout* btnLayout=new QHBoxLayout;
    QVBoxLayout* centerLayout=new QVBoxLayout;
    this->setLayout(mainLayout);
    mainLayout->addLayout(upLayout);
    mainLayout->addLayout(middleLayout);
    mainLayout->addLayout(downLayout);
    middleLayout->addLayout(leftLayout);
    middleLayout->addLayout(centerLayout);
    middleLayout->addLayout(rightLayout);
    centerLayout->addLayout(btnLayout);

    historyBar=new QToolBar(this);
    closedBar=new QToolBar(this);
    bookmarkBar=new QToolBar(this);
    toolsBar=new QToolBar(this);
    QPushButton* upBtn=new QPushButton(this);
    QPushButton* downBtn=new QPushButton(this);
    QPushButton* leftBtn=new QPushButton(this);
    QPushButton* rightBtn=new QPushButton(this);

    connect(upBtn,SIGNAL(released()),this,SLOT(upBarAction()));
    connect(downBtn,SIGNAL(released()),this,SLOT(downBarAction()));
    connect(leftBtn,SIGNAL(released()),this,SLOT(leftBarAction()));
    connect(rightBtn,SIGNAL(released()),this,SLOT(rightBarAction()));

    upLayout->addWidget(upBtn);
    upLayout->addWidget(bookmarkBar);
    leftLayout->addWidget(leftBtn);
    leftLayout->addWidget(toolsBar);
    downLayout->addWidget(historyBar);
    downLayout->addWidget(downBtn);
    rightLayout->addWidget(closedBar);
    rightLayout->addWidget(rightBtn);

    historyBar->hide();
    closedBar->hide();
    bookmarkBar->hide();
    toolsBar->hide();

    QPushButton* back=new QPushButton(this);
    QPushButton* forward=new QPushButton(this);
    QPushButton* mainPage=new QPushButton(this);
    QPushButton* stop=new QPushButton(this);
    QPushButton* refresh=new QPushButton(this);

    back->setObjectName("panel-backBtn");
    forward->setObjectName("panel-forwardBtn");
    mainPage->setObjectName("panel-homeBtn");
    stop->setObjectName("panel-stopBtn");
    refresh->setObjectName("panel-reloadBtn");

    connect(back,SIGNAL(released()),this,SIGNAL(back()));
    connect(forward,SIGNAL(released()),this,SIGNAL(forward()));
    connect(stop,SIGNAL(released()),this,SIGNAL(stop()));
    connect(refresh,SIGNAL(released()),this,SIGNAL(refresh()));
    connect (mainPage,SIGNAL(released()),this,SIGNAL(home()));

    btnLayout->addWidget(back);
    btnLayout->addWidget(forward);
    btnLayout->addWidget(stop);
    btnLayout->addWidget(refresh);
    btnLayout->addWidget(mainPage);
   // centerLayout->addWidget(MainWindow::instance()->getService()->urlBar());
    connect(qApp,SIGNAL(focusChanged(QWidget*,QWidget*)),this,SLOT(handleFocus(QWidget*,QWidget*)));
}
void GlaucaQuickPanel::upBarAction(){
    bookmarkBar->clear();
   //Editing ,because bookmark module has some problems(in-time update,etc)
    //this function could not complete right now
    //bookmarkBar->addActions(MainWindow::instance()->getService()->bookMark()->createMenu());
    bookmarkBar->show();
}
void GlaucaQuickPanel::downBarAction(){
    if(historyBar->isHidden()){
        historyBar->addActions(MainWindow::instance()->getService()->history()->getActionList());
        historyBar->show();
    }
    else{
        historyBar->hide();
        historyBar->clear();
    }
}
void GlaucaQuickPanel::leftBarAction(){
    //Editing
}
void GlaucaQuickPanel::rightBarAction(){
    closedBar->clear();
}
void GlaucaQuickPanel::handleFocus(QWidget *old, QWidget *now){
    if(old==this){
        bool flag=false;
        QObjectList list=this->children();
        foreach(QObject* obj,list){
            if(now==obj){
                flag=true;
                break;
            }
        }
        if(!flag)this->hide();
    }
}
