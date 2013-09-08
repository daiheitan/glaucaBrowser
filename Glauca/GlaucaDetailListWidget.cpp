#include "GlaucaDetailListWidget.h"
#include <QVBoxLayout>

GlaucaDetailListWidget::GlaucaDetailListWidget(const QPixmap &icon, QWidget *parent):QWidget(parent){
    QHBoxLayout* mainLayout=new QHBoxLayout(this);
    QLabel iconLabel(this);
    iconLabel.setPixmap(icon.scaled(40,40));
    mainLayout->addWidget(&iconLabel);
    //QVBoxLayout* detailLayout=new QVBoxLayout(this);
    titleLabel=new QLabel(this);
    detailLabel=new QLabel(this);
    progressLayout=new QHBoxLayout(this);
    progress=new QProgressBar(this);
    progressLayout->addWidget(progress);
    progressLayout->addStretch(0);
    cancelButton=new QToolButton(this);
    stopButton=new QToolButton(this);
    continueButton=new QToolButton(this);
    progressLayout->addWidget(cancelButton,Qt::AlignRight);
    progressLayout->addWidget(stopButton,Qt::AlignRight);
    progressLayout->addWidget(continueButton,Qt::AlignRight);
    continueButton->hide();
    connect(stopButton,SIGNAL(clicked()),stopButton,SLOT(hide()));
    connect(stopButton,SIGNAL(clicked()),continueButton,SLOT(show()));
    connect(continueButton,SIGNAL(clicked()),continueButton,SLOT(hide()));
    connect(continueButton,SIGNAL(clicked()),stopButton,SLOT(show()));
}
QProgressBar* GlaucaDetailListWidget::progressBar(){
    return progress;
}
QToolButton* GlaucaDetailListWidget::cancelBtn(){
    return cancelButton;
}
QToolButton* GlaucaDetailListWidget::stopBtn(){
    return stopButton;
}
QToolButton* GlaucaDetailListWidget::continueBtn(){
    return continueButton;
}
void GlaucaDetailListWidget::setProgress(int prog){
    if(prog==100){
        progress->hide();
        stopButton->hide();
        continueButton->hide();
        cancelButton->hide();
        return;
    }
    progress->setValue(prog);
}
