#include "GlaucaSettings.h"
#include <QStringList>
#include <QtCore>
#include <QDialog>
#include <QListWidget>
#include <QListWidgetItem>
#include <QVBoxLayout>
#include <QPushButton>
#include <QStackedWidget>
#include <QLabel>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QGroupBox>
#include <QCheckBox>
#include <QFile>
#include <QtDebug>
#include <QDialogButtonBox>

GlaucaSettings::GlaucaSettings(QWidget* parent):QWidget(parent){
    QSettings::setDefaultFormat(QSettings::IniFormat);
    QSettings s;
    if(!s.childGroups().count())initSettings();
}
GlaucaSettings::~GlaucaSettings(){
}

void GlaucaSettings::initSettings(){
    QSettings s;
    s.clear();
    /*********************************
     *Init a lot of options
    **********************************/
    s.beginGroup("Default");
    s.setValue("currentTheme","default@GlaucaProject");
    s.endGroup();
    s.beginGroup("Main");
    s.setValue("useGlaucaHomePage",true);
    s.setValue("homePageUrl","http://www.g.cn");
    s.beginGroup("Downloads");
    s.setValue("showProgressInDock",false);
    s.setValue("showQuickBar",false);
    s.setValue("createFolders",false);
    s.endGroup();
    s.beginGroup("Dock");
    s.setValue("mouseSensibility",100);
    s.setValue("sortIconBehavior",1);
    s.setValue("showSlider",true);
    s.endGroup();
    s.endGroup();
    s.beginGroup("Glauca");
    s.beginGroup("SurfPanel");
    s.setValue("enabled",true);
    s.setValue("hideControlBar",false);
    s.endGroup();
    s.beginGroup("WebNotifier");
    s.setValue("enabled",true);
    s.setValue("position","right-buttom");
    s.setValue("notiWhenStarted",false);
    s.setValue("notiWhenLoadingFinished",false);
    s.setValue("currentTabIncluded",false);
    s.endGroup();
    s.endGroup();
    /*********************************
     *Init tab-related items
    **********************************/
    s.beginGroup("Tabs");
    s.setValue("width",130);
    s.setValue("height",25);
    s.setValue("showCloseTabBtn",false);
    s.setValue("double-click","close tab");
    s.setValue("movable",true);
    s.setValue("atLeastOneTab",true);
    s.setValue("showNewTabBtn",true);
    s.setValue("showAllTabsButton",false);
    s.setValue("inactivedDarker",false);
    s.setValue("autoResize",false);
    s.endGroup();
    s.beginGroup("Storage");
    s.beginGroup("History");
    s.setValue("menuHistoryNumber",10);
    s.setValue("historyClickBehave","NewTab");
    s.setValue("tabRestoreMaxNumber",2);
    s.endGroup();
    s.endGroup();
}
void GlaucaSettings::glaucaSettingsWindow(){
    QDialog* setDialog=new QDialog(this->parentWidget());
    setDialog->setModal(true);
    setDialog->setAttribute(Qt::WA_DeleteOnClose, true);
    setDialog->resize(500,500);
    setDialog->setWindowTitle("Glauca Config");

    QListWidget* list=new QListWidget(setDialog);
    list->setIconSize(QSize(60,60));
    list->setViewMode(QListView::IconMode);
    list->setMovement(QListView::Static);
    list->setMaximumWidth(70);
    list->addItem(new QListWidgetItem(QIcon("./resources/config/iconcs_006.png"),"Main",list));
    list->addItem(new QListWidgetItem(QIcon("./resources/config/iconcs_008.png"),"Glauca",list));
    list->addItem(new QListWidgetItem(QIcon("./resources/config/iconcs_002.png"),"Tabs",list));

    QStackedWidget* stack=new QStackedWidget(setDialog);
    setupUi(stack);
    connect(list,SIGNAL(currentRowChanged(int)),stack,SLOT(setCurrentIndex(int)));
    QVBoxLayout* mainLayout=new QVBoxLayout;
    QHBoxLayout* selectLayout=new QHBoxLayout;
    selectLayout->addWidget(list);
    selectLayout->addWidget(stack);
    mainLayout->addLayout(selectLayout);
    setDialog->setLayout(mainLayout);
    QDialogButtonBox* setDialogBtn=new QDialogButtonBox(QDialogButtonBox::Ok|QDialogButtonBox::Abort);
    connect(setDialogBtn,SIGNAL(accepted()),this,SLOT(writeSettings()));
    connect(setDialogBtn,SIGNAL(rejected()),setDialog,SLOT(close()));
    mainLayout->addWidget(setDialogBtn);

    //check the states of settings objects
    readSettings();
    setDialog->show();
}
void GlaucaSettings::readSettings(){
    QSettings s;
    //MainPage
    showDownloadRate->setChecked(s.value("Main/Downloads/showProgressInDock").toBool());
    showDownloadBar->setChecked(s.value("Main/Downloads/showQuickBar").toBool());
    createFolders->setChecked(s.value("Main/Downloads/createFolders").toBool());
    homePageGB->setChecked(!s.value("Main/useGlaucaHomePage").toBool());
    homePageUrlCombo->setEditText(s.value("Main/homePageUrl").toString());
    mouseSensibility->setValue(s.value("Main/Dock/mouseSensibility").toInt());
    showSlider->setChecked(s.value("Main/Dock/showSlider").toBool());
    int sortAct=s.value("Main/Dock/sortIconBehavior").toInt();
    if(sortAct==1)sortIconByTime->setChecked(true);
    else if(sortAct==2)sortIconByChanged->setChecked(true);
    else sortDisabled->setChecked(true);

    //Glauca
    quickSurfGB->setChecked(s.value("Glauca/SurfPanel/enabled").toBool());
    hideControlBar->setChecked(s.value("Glauca/SurfPanel/hideControlBar").toBool());
    notifierGB->setChecked(s.value("Glauca/WebNotifier/enabled").toBool());
    popUpWhenStarted->setChecked(s.value("Glauca/WebNotifier/notiWhenStarted").toBool());
    popUpWhenFinished->setChecked(s.value("Glauca/WebNotifier/notiWhenLoadingFinished").toBool());
    popUpForCurrent->setChecked(s.value("Glauca/WebNotifier/currentTabIncluded").toBool());

    //Tabs
    showCloseBtn->setChecked(s.value("Tabs/showCloseTabBtn").toBool());
    showNewTabBtn->setChecked(s.value("Tabs/showNewTabBtn").toBool());
    showAllTabBtn->setChecked(s.value("Tabs/showAllTabsButton").toBool());
    tabAutoResize->setChecked(s.value("Tabs/autoResize").toBool());
    darkerTabs->setChecked(s.value("Tabs/inactivedDarker").toBool());

    //Signals
    connect(useBlankPage,SIGNAL(clicked()),this,SLOT(handleHomepageBtnAction()));
    connect(useCurrentPage,SIGNAL(clicked()),this,SLOT(handleHomepageBtnAction()));
    connect(useLastSession,SIGNAL(clicked()),this,SLOT(handleHomepageBtnAction()));
}
void GlaucaSettings::handleHomepageBtnAction(){
    QPushButton* btn=(QPushButton*)sender();
    if(btn->objectName()=="useBlankPage")homePageUrlCombo->setEditText("about:blank");
    else if(btn->objectName()=="useCurrentPage")emit currentPageReuqest();
    else if(btn->objectName()=="useLastSession")homePageUrlCombo->setEditText("about:lastSession");
}
void GlaucaSettings::writeSettings(){
    QSettings s;
    s.clear();
    /*********************************
     *Init a lot of options
    **********************************/
    s.beginGroup("Main");
    s.setValue("useGlaucaHomePage",homePageGB->isChecked());
    s.setValue("homePageUrl",homePageUrlCombo->currentText());
    s.beginGroup("Downloads");
    s.setValue("showProgressInDock",showDownloadRate->isChecked());
    s.setValue("showQuickBar",showDownloadBar->isChecked());
    s.setValue("createFolders",createFolders->isChecked());
    s.endGroup();
    s.beginGroup("Dock");
    s.setValue("mouseSensibility",mouseSensibility->value());
    if(sortIconByTime->isChecked())s.setValue("sortIconBehavior",1);
    else if(sortIconByChanged->isChecked())s.setValue("sortIconBehavior",2);
    else s.setValue("sortIconBehavior",3);
    s.setValue("showSlider",showSlider->isChecked());
    s.endGroup();
    s.endGroup();
    s.beginGroup("Glauca");
    s.beginGroup("SurfPanel");
    s.setValue("enabled",quickSurfGB->isChecked());
    s.setValue("hideControlBar",hideControlBar->isChecked());
    s.endGroup();
    s.beginGroup("WebNotifier");
    s.setValue("enabled",notifierGB->isChecked());
    s.setValue("position","right-buttom");
    s.setValue("notiWhenStarted",popUpWhenStarted->isChecked());
    s.setValue("notiWhenLoadingFinished",popUpWhenFinished->isChecked());
    s.setValue("currentTabIncluded",popUpForCurrent->isChecked());
    s.endGroup();
    s.endGroup();
    /*********************************
     *Init tab-related items
    **********************************/
    s.beginGroup("Tabs");
    s.setValue("width",130);
    s.setValue("height",25);
    s.setValue("showCloseTabBtn",showCloseBtn->isChecked());
    s.setValue("double-click","close tab");
    s.setValue("movable",true);
    s.setValue("atLeastOneTab",true);
    s.setValue("showNewTabBtn",showNewTabBtn->isChecked());
    s.setValue("showAllTabsButton",showAllTabBtn->isChecked());
    s.setValue("inactivedDarker",darkerTabs->isChecked());
    s.setValue("autoResize",tabAutoResize->isChecked());
    s.endGroup();
    s.beginGroup("Storage");
    s.beginGroup("History");
    s.setValue("menuHistoryNumber",10);
    s.setValue("historyClickBehave","NewTab");
    s.setValue("tabRestoreMaxNumber",2);
    s.endGroup();
    s.endGroup();
}
