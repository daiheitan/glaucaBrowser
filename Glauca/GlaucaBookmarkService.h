#ifndef GLAUCABOOKMARKSERVICE_H
#define GLAUCABOOKMARKSERVICE_H
#include "MainWindow.h"

//This class provide common service about BookMarks
#include <QDomElement>
#include "GlaucaXMLService.h"
#include <QMenu>
#include <QAction>
#include <QTreeWidget>
#include <QObject>
#include <QMap>
#include "GlaucaUrlAction.h"
#include "GlaucaWebView.h"
#include <QPushButton>

class MainWindow;
class QToolBar;
class GlaucaWebView;
/////////////MVC reDesign/////////////
class GlaucaBookmarkModel;
class GlaucaBookmarkView;
class GlaucaBookmarkController:public QObject{
    Q_OBJECT
public:
    GlaucaBookmarkController(GlaucaBookmarkView* view);//Must link controller to a view
    GlaucaBookmarkModel* getModel();
    QMap<QTreeWidgetItem*,QDomElement>& getMap();
    GlaucaTabPage* getCurrentTab();
	QIcon getBookmarkIconForUrl(const QUrl& url);
public slots:
	void setCurrentTab(GlaucaTabPage* tab);
    void setModel(GlaucaBookmarkModel* model);
    void setView(GlaucaBookmarkView* view);
    void addBookmarkBtnPressed();
    void saveBookmarkBtnPressed();
    void addNewFolderBtnPressed();
    void varifyFolderName(QTreeWidgetItem * item);
    void delFolderBtnPressed();
    void cancelBtnPressed();
	void refreshBookmarkIcon();
private:
    GlaucaBookmarkView* bookmarkViewInstance;
    GlaucaBookmarkModel* bookmarkModelInstance;
    QMap<QTreeWidgetItem*,QDomElement> map;
    GlaucaTabPage* current;
};

class GlaucaBookmarkView{
public:
    GlaucaBookmarkView();
    GlaucaBookmarkModel* getModel();
	GlaucaBookmarkController* controller();
    void setController(GlaucaBookmarkController* controller);
    QMenu* createMenu(QDomElement node,QWidget* parent=0);//this will create a menu depend on the DOM given
    QToolBar* bookmarkBar(QWidget* parent=0);
    QToolButton* bookmarkBtn(QWidget* parent=0);
    QPushButton* addBookmarkBtn(QWidget* parent=0);
    void saveSelectWindow(GlaucaTabPage* tab);
    QTreeWidget* getPathMenu(QWidget* parent,const QDomElement& n);
private:
    GlaucaBookmarkController* controllerInstance;
	QPushButton* addBMBtn;
};
class GlaucaBookmarkModel{
public:
    GlaucaBookmarkModel();
    QDomDocument getBookmarkDoc();
    void setController(GlaucaBookmarkController* controller);
    QDomElement getNodes();
    QDomElement getInMenuNodes();
    QDomElement getInQuickBarNodes();
    bool isPageSaved(const QString& addr,QDomElement& n);
    bool isPageSaved(const QString &addr);
    bool hasChild(const QDomElement& a,const QDomElement& b);
    void appendPathMenu(QTreeWidgetItem* item,QDomElement node,QDomElement n);
    void appendPathMenu(QTreeWidgetItem *item, QDomElement node);
    void saveBookmarkItem(const QString& title,const QString& url,QDomElement& parent);
private:
    void createBookmarkFile();
    GlaucaBookmarkController* controllerInstance;
    QDomDocument bookMark;
    QString path;
};

#endif // GLAUCABOOKMARKSERVICE_H
