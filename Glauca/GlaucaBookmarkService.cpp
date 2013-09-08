#include "GlaucaBookmarkService.h"
#include <QStringList>
#include <QFile>
#include <QTextStream>
#include <QtDebug>
#include <QToolBar>
#include <QLabel>
#include <QVBoxLayout>
#include <QDialog>
#include <QHBoxLayout>
#include <QPushButton>
#include <QCursor>
#include <QPoint>
#include <QToolBar>

GlaucaBookmarkView::GlaucaBookmarkView():controllerInstance(0){
    controllerInstance=new GlaucaBookmarkController(this);
	addBMBtn=0;
}
GlaucaBookmarkController* GlaucaBookmarkView::controller(){
	return controllerInstance;
}
QPushButton* GlaucaBookmarkView::addBookmarkBtn(QWidget *parent){
	if(addBMBtn==0){
		addBMBtn = MainWindow::custButton("./resources/001_17.png","Save bookMark",parent);
		addBMBtn->setStyleSheet("QPushButton{border:0px;}");
		addBMBtn->connect(addBMBtn,SIGNAL(clicked()),controllerInstance,SLOT(addBookmarkBtnPressed()));
	}
    return addBMBtn;
}
QToolButton* GlaucaBookmarkView::bookmarkBtn(QWidget *parent){
    QToolButton* bookMarkButton=new QToolButton(parent);
    QMenu* bookmarkMenu=createMenu(controllerInstance->getModel()->getInMenuNodes());
    bookMarkButton->setIcon(QIcon("./resources/bookMarkBtn.png"));
    bookMarkButton->setText("BookMark");
    bookMarkButton->setMenu(bookmarkMenu);
    bookMarkButton->setPopupMode(QToolButton::InstantPopup);
    return bookMarkButton;
}
GlaucaBookmarkModel* GlaucaBookmarkView::getModel(){
    return controllerInstance->getModel();
}

QToolBar* GlaucaBookmarkView::bookmarkBar( QWidget *parent){
    QDomElement node=controllerInstance->getModel()->getInQuickBarNodes().firstChildElement();
    QToolBar* convBar=new QToolBar(parent);
    for(;!node.isNull();node = node.nextSiblingElement()){
        if(node.tagName() == "bookMark"){
            MenuAction* act = new MenuAction(node.attribute("title"),node.attribute("url"));
            convBar->addAction(act);
        }
    }
    return convBar;
}
QMenu* GlaucaBookmarkView::createMenu(QDomElement node, QWidget *parent){
    specialMenu* menu=new specialMenu(parent);
    menu->setTitle(node.attribute("title"));
    node=node.firstChildElement();
    for(;!node.isNull();node=node.nextSiblingElement()){
        if(node.tagName()=="bookMark"){
            MenuAction* act=new MenuAction(node.attribute("title"),node.attribute("url"));
            menu->addAction(act);
        }
        else if(node.tagName()=="seprator")menu->addSeparator();
        else menu->addMenu(createMenu(node));
    }
    return menu;
}
void GlaucaBookmarkView::saveSelectWindow(GlaucaTabPage* tab){
	if(tab->isExtensionView())return;
	GlaucaWebTab* view=(GlaucaWebTab*)tab;
    QString t=view->title();
    QString u=view->url().toString();
    controllerInstance->setCurrentTab(tab);
    QDialog* addWin=new QDialog(MainWindow::instance());
    addWin->setWindowFlags(Qt::Dialog|Qt::FramelessWindowHint);
    addWin->setModal(true);
    addWin->setAttribute(Qt::WA_DeleteOnClose, true);
    QVBoxLayout* layout=new QVBoxLayout(addWin);
    QDomElement node;
    bool saved=controllerInstance->getModel()->isPageSaved(u,node);
    if(saved)layout->addWidget(new QLabel("Edit BookMark",addWin));
    else layout->addWidget(new QLabel("AddTo BookMark",addWin));
    QHBoxLayout* tempLayout=new QHBoxLayout;
    tempLayout->addWidget(new QLabel("Name: ",addWin));
    QLineEdit* tempEdit=new QLineEdit(addWin);
    tempEdit->setText(t);
    tempEdit->setObjectName("SaveBookmarkDialogNameLine");
    tempEdit->selectAll();
    QLineEdit* tempEdit2=new QLineEdit(addWin);
    tempEdit2->setObjectName("SaveBookmarkDialogUrlLine");
    tempEdit->setText(u);
    QHBoxLayout* tempLayout2=new QHBoxLayout;
    tempLayout2->addWidget(new QLabel("Url: ",addWin));
    tempLayout2->addWidget(tempEdit2);
    tempLayout->addWidget(tempEdit);
    layout->addLayout(tempLayout);
    layout->addLayout(tempLayout2);
    layout->addWidget(new QLabel("Path:",addWin));
    layout->addWidget(getPathMenu(addWin,node));
    tempLayout=new QHBoxLayout(addWin);
    tempLayout->addStretch(0);
    QPushButton* addFolder=new QPushButton("Add Folder",addWin);
    tempLayout->addWidget(addFolder);
   addFolder-> connect(addFolder,SIGNAL(clicked()),controllerInstance,SLOT(addNewFolderBtnPressed()));
    QPushButton* delFolder=new QPushButton("Delete Folder",addWin);
    tempLayout->addWidget(delFolder);
   delFolder->connect(delFolder,SIGNAL(clicked()),controllerInstance,SLOT(delFolderBtnPressed()));
    QPushButton* submit=new QPushButton("Submit",addWin);
    tempLayout->addWidget(submit);
    submit->connect(submit,SIGNAL(clicked()),controllerInstance,SLOT(saveBookmarkBtnPressed()));
    QPushButton* cancel=new QPushButton("Cancel",addWin);
    tempLayout->addWidget(cancel);
   cancel-> connect(cancel,SIGNAL(clicked()),controllerInstance,SLOT(cancelBtnPressed()));
    layout->addLayout(tempLayout);
    QPoint point=QCursor::pos();
    if(point.x()<325)point.rx()+=325;
    point.setX(point.x()-320);
    addWin->move(point);
    addWin->show();
}
QTreeWidget* GlaucaBookmarkView::getPathMenu(QWidget *parent, const QDomElement &n){
    QTreeWidget* tree=new QTreeWidget(parent);
    tree->setObjectName("SaveBookmarkDialogTreeWidget");
    tree->setColumnCount(1);
    QDomElement node=controllerInstance->getModel()->getNodes().firstChildElement();
    QMap<QTreeWidgetItem*,QDomElement> map=controllerInstance->getMap();
    for(;!node.isNull();node=node.nextSiblingElement()){
        QTreeWidgetItem* item=new QTreeWidgetItem;
        item->setText(0,node.attribute("title"));
        tree->addTopLevelItem(item);
        map.insert(item,node);
        if(controllerInstance->getModel()->hasChild(node,n)){
            tree->setCurrentItem(item);
           controllerInstance->getModel()->appendPathMenu(item,node.firstChildElement());
        }
        else controllerInstance->getModel()->appendPathMenu(item,node.firstChildElement(),n);
    }
    tree->connect(tree,SIGNAL(itemChanged(QTreeWidgetItem*,int)),controllerInstance,SLOT(varifyFolderName(QTreeWidgetItem*)));
    return tree;
}

//GlaucaBookmarkController
QMap<QTreeWidgetItem*,QDomElement>& GlaucaBookmarkController::getMap(){
    return map;
}
QIcon GlaucaBookmarkController::getBookmarkIconForUrl(const QUrl& url){
	if(url.isEmpty()||!getModel()->isPageSaved(url.toString()))
	{
		qDebug()<<4<<endl;
        return QIcon("./resources/001_17.png");
	}
    else return QIcon("./resources/001_15.png");
}
GlaucaTabPage* GlaucaBookmarkController::getCurrentTab(){
    return current;
}
void GlaucaBookmarkController::refreshBookmarkIcon(){
	bookmarkViewInstance->addBookmarkBtn()->setIcon(getBookmarkIconForUrl(current->url()) );
}
void GlaucaBookmarkController::setCurrentTab(GlaucaTabPage *tab){
    current=tab;
	connect(current,SIGNAL(urlChanged(QUrl&)),this,SLOT(refreshBookmarkIcon()));
	refreshBookmarkIcon();
}

GlaucaBookmarkModel* GlaucaBookmarkController::getModel(){
    return bookmarkModelInstance;
}
GlaucaBookmarkController::GlaucaBookmarkController(GlaucaBookmarkView* view):bookmarkViewInstance(view){
	bookmarkModelInstance=new GlaucaBookmarkModel();
	bookmarkModelInstance->setController(this);
}

void GlaucaBookmarkController::setModel(GlaucaBookmarkModel* model){
    bookmarkModelInstance=model;
}
void GlaucaBookmarkController::setView(GlaucaBookmarkView* view){
    bookmarkViewInstance=view;
}
void GlaucaBookmarkController::addBookmarkBtnPressed(){
    bookmarkViewInstance->saveSelectWindow(current);
}
void GlaucaBookmarkController::saveBookmarkBtnPressed(){
    QPushButton* btn=(QPushButton*)sender();
    QDialog* dialog=qobject_cast<QDialog*>(btn->parent());
    QLineEdit* tempEdit=dialog->findChild<QLineEdit*>("SaveBookmarkDialogNameLine");
    QString title=tempEdit->text();
    tempEdit=dialog->findChild<QLineEdit*>("SaveBookmarkDialogUrlLine");
    QString url=tempEdit->text();
    QTreeWidget* tree=dialog->findChild<QTreeWidget*>("SaveBookmarkDialogTreeWidget");
    QTreeWidgetItem* item=tree->currentItem();
    QDomElement node=map[item];
    bookmarkModelInstance->saveBookmarkItem(title,url,node);
    map.clear();
    //delete(quickconn);
    //quickconn=this->qucikconn(this->getInQuickBarNodes());
    QPushButton* t=(QPushButton*)sender();
    t->window()->close();
}

void GlaucaBookmarkController::addNewFolderBtnPressed(){
    QPushButton* btn=(QPushButton*)sender();
    QDialog* dialog=qobject_cast<QDialog*>(btn->parent());
    QTreeWidget* tree=dialog->findChild<QTreeWidget*>("SaveBookmarkDialogTreeWidget");
    QTreeWidgetItem* item=tree->currentItem();
    QTreeWidgetItem* temp=new QTreeWidgetItem;
    temp->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsEditable|Qt::ItemIsEnabled|Qt::ItemIsSelectable);
    temp->setText(0,"New Folder");
    item->addChild(temp);
    tree->setCurrentItem(temp,0,QItemSelectionModel::Select);
    QDomElement node=map[item];
    QDomElement t=bookmarkModelInstance->getBookmarkDoc().createElement("folder");
    t.setAttribute("title",temp->text(0));
    node.appendChild(t);
    map.insert(temp,t);
}

void GlaucaBookmarkController::varifyFolderName(QTreeWidgetItem * item){
    QDomElement t=map[item];
    t.setAttribute("title",item->text(0));
}

void GlaucaBookmarkController::delFolderBtnPressed(){
    QPushButton* btn=(QPushButton*)sender();
    QDialog* dialog=qobject_cast<QDialog*>(btn->parent());
    QTreeWidget* tree=dialog->findChild<QTreeWidget*>("SaveBookmarkDialogTreeWidget");
    QTreeWidgetItem* item=tree->currentItem();
    QDomElement node=map[item];
    node.parentNode().removeChild(node);
    map.remove(item);
    item->parent()->removeChild(item);
    delete(item);
}

void GlaucaBookmarkController::cancelBtnPressed(){
    map.clear();
    QPushButton* t=(QPushButton*)sender();
    t->window()->close();
}

//Model
GlaucaBookmarkModel::GlaucaBookmarkModel(){
    path=MainWindow::getAppRoamingDir()+"profile/bookmark.xml";//init the path of the BookMark xml
    if(!GlaucaXMLService::exist(path))createBookmarkFile();
    else bookMark=GlaucaXMLService::read(path);
}
QDomDocument GlaucaBookmarkModel::getBookmarkDoc(){
    return bookMark;
}

void GlaucaBookmarkModel::setController(GlaucaBookmarkController* controller){
    controllerInstance=controller;
}
QDomElement GlaucaBookmarkModel::getNodes(){
    return bookMark.documentElement();
}

QDomElement GlaucaBookmarkModel::getInMenuNodes(){
    return bookMark.documentElement().elementsByTagName("inToolBar").at(0).toElement();
}

QDomElement GlaucaBookmarkModel::getInQuickBarNodes(){
    return bookMark.documentElement().elementsByTagName("inQuickBar").at(0).toElement();
}

bool GlaucaBookmarkModel::isPageSaved(const QString& addr,QDomElement& n){
   QDomElement node = this->getInQuickBarNodes().firstChildElement();
   bool result=false;
   for(;!node.isNull();node = node.nextSiblingElement()){
        if(node.tagName() == "bookMark"){
            QString savedadd = node.attribute("url");
            if (addr == savedadd) {result = true;break;}
        }
    }
   if(result){n=node;return true;}
   node =  this->getInMenuNodes().firstChildElement();
   for(;!node.isNull();node=node.nextSiblingElement()){
       if(node.tagName() == "bookMark"){
           QString savedadd = node.attribute("url");
           if (addr == savedadd) {result = true;break;}
         }
       else if(node.tagName() == "seprator");
       else result = isPageSaved(addr);
    }
   if(result){n=node;return true;}
   else return false;
}

bool GlaucaBookmarkModel::isPageSaved(const QString &addr){
	qDebug()<<addr<<endl;
    QDomElement node = this->getInQuickBarNodes().firstChildElement();
    bool result=false;
    for(;!node.isNull();node = node.nextSiblingElement()){
         if(node.tagName() == "bookMark"){
             QString savedadd = node.attribute("url");
             if (addr == savedadd) {result = true;break;}
         }
     }
    if(result)return true;
    node =  this->getInMenuNodes().firstChildElement();
    for(;!node.isNull();node=node.nextSiblingElement()){
        if(node.tagName() == "bookMark"){
            QString savedadd = node.attribute("url");
            if (addr == savedadd) {result = true;break;}
          }
        else if(node.tagName() == "seprator");
        else result = isPageSaved(addr);
     }
    if(result)return true;
    else return false;
}

void GlaucaBookmarkModel::createBookmarkFile(){
    QDomElement root=bookMark.createElement("root");
    QDomElement elm=bookMark.createElement("inToolBar");
    QDomElement child=bookMark.createElement("inQuickBar");
    elm.setAttribute("title","BookMark Menu");
    child.setAttribute("title","Quick Launch Bar");
    bookMark.appendChild(root);
    root.appendChild(elm);
    root.appendChild(child);

    QDomNode node=bookMark.createProcessingInstruction("xml", "version=\"1.0\" encoding=\"UTF-8\"");
    bookMark.insertBefore(node,root);
    GlaucaXMLService::write(path,bookMark);
}
void GlaucaBookmarkModel::appendPathMenu(QTreeWidgetItem* item,QDomElement node,QDomElement n){
    for(;!node.isNull();node=node.nextSiblingElement()){
        if(node.tagName()=="bookMark"||node.tagName()=="seprator");
        else {
            QTreeWidgetItem* tempItem=new QTreeWidgetItem;
            tempItem->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsEditable|Qt::ItemIsEnabled|Qt::ItemIsSelectable);
            tempItem->setText(0,node.attribute("title"));
            item->addChild(tempItem);
            controllerInstance->getMap().insert(tempItem,node);
            if(hasChild(node,n)){
                tempItem->treeWidget()->setCurrentItem(tempItem);
                appendPathMenu(tempItem,node.firstChildElement());
            }
            else appendPathMenu(tempItem,node.firstChildElement(),n);
        }
    }
}
bool GlaucaBookmarkModel::hasChild(const QDomElement &a, const QDomElement &b){
    QDomElement temp=a.firstChildElement();
    for(;!temp.isNull();temp=temp.nextSiblingElement())if(temp==b)return true;
    return false;
}
void GlaucaBookmarkModel::appendPathMenu(QTreeWidgetItem *item, QDomElement node){
    for(;!node.isNull();node=node.nextSiblingElement()){
        if(node.tagName()=="bookMark"||node.tagName()=="seprator");
        else {
            QTreeWidgetItem* tempItem=new QTreeWidgetItem;
            tempItem->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsEditable|Qt::ItemIsEnabled|Qt::ItemIsSelectable);
            tempItem->setText(0,node.attribute("title"));
            item->addChild(tempItem);
            controllerInstance->getMap().insert(tempItem,node);
        }
    }
}
void GlaucaBookmarkModel::saveBookmarkItem(const QString &title, const QString &url, QDomElement &parent){
    QDomElement temp=bookMark.createElement("bookMark");
    temp.setAttribute("title",title);
    temp.setAttribute("url",url);
    parent.appendChild(temp);
    GlaucaXMLService::write(path,bookMark);
    MainWindow::instance()->getService()->iconSet()->saveIcon((GlaucaWebTab*)controllerInstance->getCurrentTab());
}

