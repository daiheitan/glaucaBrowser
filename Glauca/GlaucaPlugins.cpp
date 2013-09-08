#include "GlaucaPlugins.h"
#include <QWidget>
#include <QListWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QDebug>
#include <GlaucaDropInDialog.h>

pluginWinListWidget::pluginWinListWidget(const QPixmap &icon, const QString &name, const QString &author, const QString &des,QWidget* parent):
    QWidget(parent),
    n(name),
    a(author),
    d(des),
    ico(icon){

    QHBoxLayout* layout=new QHBoxLayout(this);
    this->setLayout(layout);
    QLabel* label=new QLabel(this);
    label->setPixmap(icon);
    layout->addWidget(label);
    QVBoxLayout* desLayout=new QVBoxLayout(this);
    QLabel* nameLabel=new QLabel(name,this);
    desLayout->addWidget(nameLabel);
    QLabel* authorLabel=new QLabel("Author: "+author,this);
    desLayout->addWidget(authorLabel);
    QLabel* desLabel=new QLabel(des,this);
    desLabel->setWordWrap(true);
    desLayout->addWidget(desLabel);
    layout->addLayout(desLayout);
}

void GlaucaPlugins::showPluginWindow(MainWindow *p){
    QWidget* win=new GlaucaDropInDialog(p);
    win->setAttribute(Qt::WA_DeleteOnClose,true);
    win->setFixedSize(340,350);
    QListWidget* sList=new QListWidget(win);
    sList->setObjectName("extViewList");
    sList->setFlow(QListView::LeftToRight);
    sList->setIconSize(QSize(32,32));
    sList->setFixedHeight(60);
    sList->setViewMode(QListView::IconMode);
    sList->setMovement(QListView::Static);
    QSettings set;
    QString path=p->getAppRoamingDir()+"/profile/themes/"+set.value("Default/currentTheme").toString()+"/chrome/dialogs/";
    sList->addItem(new QListWidgetItem(QIcon(path+"extension.png"),"Extensions",sList));
    sList->addItem(new QListWidgetItem(QIcon(path+"theme.png"),"Themes",sList));
    //QStackedWidget* stack=new QStackedWidget(win);
    QListWidget* themeList=new QListWidget(win);
    QString xmlPath=p->getAppRoamingDir()+"/profile/theme.xml";
    getExtensionList(themeList,xmlPath);
    //stack->addWidget(themeList);
    themeList->setFixedHeight(200);
    //sList->connect(sList,SIGNAL(currentRowChanged(int)),stack,SLOT(setCurrentIndex(int)));
    QVBoxLayout* mainLayout=new QVBoxLayout(win);
    win->setLayout(mainLayout);
    mainLayout->addWidget(sList);
    mainLayout->addWidget(themeList);
    mainLayout->setSpacing(5);
    mainLayout->addStretch(0);
    win->show();
}
void GlaucaPlugins::getExtensionList(QListWidget *list, const QString &Tpath){
    QDomDocument plugin=GlaucaXMLService::read(Tpath);
    QDomNodeList pluginListDom=plugin.documentElement().elementsByTagName("theme");
    for(int i=0;i<pluginListDom.count();i++){
        QDomNode node=pluginListDom.at(i);
        QDomElement pElement=node.toElement();
        QString pName=pElement.attribute("name");
        QString pAuthor=pElement.attribute("author");
        QString path=MainWindow::instance()->getAppRoamingDir()+"/profile/themes/"+pName+"@"+pAuthor+"/";
        //pluginWinListWidget * ListItem=new pluginWinListWidget(QPixmap(path+"icon.png"),pName,pAuthor,pElement.attribute("des"),list);
        //QListWidgetItem* item=new QListWidgetItem(list);
        //list->setItemWidget(item,ListItem);
        list->setIconSize(QSize(40,40));
        list->setWordWrap(true);
        list->addItem(new QListWidgetItem(QIcon(path+"icon.png"),pName+"\n"+pAuthor+"\n"+pElement.attribute("des"),list));
    }
}
