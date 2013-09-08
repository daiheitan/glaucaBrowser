#include "locationBar.h"
#include <QHBoxLayout>
#include <QtDebug>
locationBar::locationBar(QWidget *parent) :
    QWidget(parent){
    //this->setStyleSheet("QWidget{background:white;}");
    locationTextBar=new QComboBox(this);
    locationTextBar->setEditable(true);
    QWidget* leftWidget=new QWidget(this);
    //leftWidget->setStyleSheet("QWidget{background-color:white}");
    QWidget* rightWidget=new QWidget(this);
    leftLayout=new QHBoxLayout;
    rightLayout=new QHBoxLayout;
    leftLayout->setSpacing(0);
    leftLayout->setContentsMargins(0,0,0,0);
    rightLayout->setSpacing(0);
    rightLayout->setContentsMargins(0,0,0,0);
    leftWidget->setLayout(leftLayout);
    rightWidget->setLayout(rightLayout);
    QHBoxLayout *layout=new QHBoxLayout;
    layout->setSpacing(0);
    layout->setAlignment(this,Qt::AlignLeft);
    layout->addWidget(leftWidget);
    layout->addWidget(locationTextBar);
    locationTextBar->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    layout->addWidget(rightWidget);
    layout->setContentsMargins(0,0,0,0);
    setLayout(layout);
    connect(locationTextBar->lineEdit(),SIGNAL(returnPressed()),this,SLOT(changeLocation()));
}
QComboBox* locationBar::getLocationEdit(){
    return locationTextBar;
}

void locationBar::setRelatedTabWidget(GlaucaTabWidget* p){
    tabWidget=p;
}
void locationBar::setText(const QString &text){
    lastMessage=locationTextBar->lineEdit()->text();
    locationTextBar->lineEdit()->setText(text);
}
void locationBar::setCornerWidget(QWidget *wid, bool flag){
    if(flag)rightLayout->addWidget(wid);
    else leftLayout->addWidget(wid);
}
void locationBar::restore(){
    locationTextBar->lineEdit()->setText(lastMessage);
}

QString locationBar::text(){
    return locationTextBar->lineEdit()->text();
}

void locationBar::adjustLocation(const QString &url){
     locationTextBar->lineEdit()->setText(url);
}
void locationBar::changeLocation()
{
    locationTextBar->lineEdit()->setText(fill.getUrl(locationTextBar->lineEdit()->text()));
    tabWidget->loadPage(QUrl(locationTextBar->lineEdit()->text()));
}
