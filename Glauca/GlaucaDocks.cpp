#include "GlaucaDocks.h"
#include <QAction>
#include <QWidget>
#include <QPainter>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QtDebug>
#include <QToolButton>
#include <QMenu>
#include <QCursor>
#include <QEvent>
#include <QBitmap>

GlaucaDockButton::GlaucaDockButton(QWidget *parent):QToolButton(parent){
    showNoti=false;
    showBal=false;
    enlarge=new QPropertyAnimation(this,"iconSize",this);
    enlarge->setDuration(190);
    enlarge->setStartValue(QSize(40,40));
    enlarge->setEndValue(QSize(60,60));
    shrink=new QPropertyAnimation(this,"iconSize",this);
    shrink->setDuration(190);
    shrink->setStartValue(QSize(60,60));
    shrink->setEndValue(QSize(40,40));
}
void GlaucaDockButton::paintEvent(QPaintEvent *event){
    QToolButton::paintEvent(event);
    if(showNoti){
        QPixmap pix("./resources/docks/noti.png");
        pix=pix.scaled(this->width()/2,this->height()/2);
        QPainter p(this);
        p.drawPixmap(this->width()/2,this->height()/2,pix);
    }
}
void GlaucaDockButton::enterEvent(QEvent *event){
    enlarge->start();
}
void GlaucaDockButton::leaveEvent(QEvent *event){
    shrink->start();
}

void GlaucaDockButton::showNotifier(){
    showNoti=true;
    this->repaint();
}
void GlaucaDockButton::clearNotifier(){
    showNoti=false;
    this->repaint();
}

GlaucaDocks::GlaucaDocks(const QString &title, QWidget *p, Qt::WindowFlags flags):QDockWidget(title,p){
    parent=p;
    QWidget* Widget=new QWidget(this);
    this->setWidget(Widget);
    this->setAllowedAreas(Qt::LeftDockWidgetArea);
    this->setFeatures(QDockWidget::DockWidgetFloatable);
    this->setFloating(true);
    this->setTitleBarWidget(new QWidget(this));
    this->setContentsMargins(0,0,0,0);
    //Firstly depart the widget to 2 Horizonal parts
    mainLayout=new QVBoxLayout(Widget);
    mainLayout->setContentsMargins(0,0,0,0);
    mainLayout->setSpacing(0);
    this->move(parent->geometry().x()+10,parent->geometry().y()+178);

    ///////////////////////set state values
    menuOpened=false;

    setBackgroundRole(QPalette::Window);
    this->setAttribute(Qt::WA_TranslucentBackground,true);
}
GlaucaDocks::~GlaucaDocks(){}
void GlaucaDocks::paintEvent(QPaintEvent *event){
    int t=this->height();
    QPixmap pix(40,t);
    pix.fill(Qt::transparent);
    QPainter painter(&pix);
    painter.drawPixmap(0,0,40,22,QPixmap("./resources/dock_up_corner.png"));
    painter.drawPixmap(0,22,40,t-44,QPixmap("./resources/dock_left_centre.png"));
    painter.drawPixmap(0,t-22,40,22,QPixmap("./resources/dock_buttom_corner.png"));
    painter.end();
    QPainter p(this);
    p.drawPixmap(0,0,pix);
    p.end();
}

QToolButton* GlaucaDocks::addMenuBtn(const QString &title, const QIcon &icon,QMenu* menu){
    GlaucaDockButton* btn=new GlaucaDockButton(this);
    btn->setMenu(menu);
    btn->setIcon(icon);
    btn->setText(title);
    btn->setIconSize(QSize(40,40));
    mainLayout->addWidget(btn,Qt::AlignTop);
    mainLayout->addStretch(0);
    connect(menu,SIGNAL(aboutToShow()),this,SLOT(changeMenuOpenState()));
    connect(menu,SIGNAL(aboutToHide()),this,SLOT(changeMenuOpenState()));
    btn->setPopupMode(QToolButton::InstantPopup);
    btn->setToolButtonStyle(Qt::ToolButtonIconOnly);
    btn->setStyleSheet("QToolButton{border:none;} QToolButton::menu-indicator{image:none;}");
    this->repaint();
    return btn;
}
QToolButton* GlaucaDocks::addActBtn(const QString &title, const QIcon &icon){
    GlaucaDockButton* btn=new GlaucaDockButton(this);
    btn->setText(title);
    btn->setIcon(icon);
    btn->setIconSize(QSize(40,40));
    mainLayout->addWidget(btn,Qt::AlignTop);
    mainLayout->addStretch(0);
    btn->setToolButtonStyle(Qt::ToolButtonIconOnly);
    btn->setStyleSheet("QToolButton{border:none;} QToolButton::menu-indicator:open{subcontrol-origin:padding-right;subcontrol-position: right center;}");
    this->repaint();
    return btn;
}

void GlaucaDocks::changeMenuOpenState(){
    if(menuOpened)if(QRect(0,178,10,300).contains(QCursor::pos()))return;
    menuOpened=!menuOpened;
}
void GlaucaDocks::showDock(){
    this->move(parent->geometry().x(),parent->geometry().y()+178);
    this->show();
}

/************************************
 *we will reimplement the leaveEvent
 *when mouse leaves the dock,the dock will hide and MainWindow timer be started
 *to check the mouse pos
 ************************************/
void GlaucaDocks::leaveEvent(QEvent *event){
    if(menuOpened)return;
    this->setVisible(false);
    parent->startTimer(500);
}
