#ifndef GLAUCATABWIDGET_H
#define GLAUCATABWIDGET_H

#include <QWidget>
#include <QTabBar>
#include <QMenu>
#include "GlaucaTabs.h"
#include "GlaucaTabAddon.h"
#include <QGridLayout>
#include <QStackedWidget>
#include "MainWindow.h"
#include "GlaucaIconService.h"
#include "GlaucaWebView.h"
#include "GlaucaUrlAction.h"
#include <QNetworkAccessManager>
#include <cookieJar.h>
#include <GlaucaServices.h>
#include <QStatusBar>
/**This class is inherited QWidget
  it contains a GlaucaTabBar&a webView
  mainly display web contents**/
class GlaucaTabs;
class MainWindow;
class GlaucaIconService;
class GlaucaWebView;
class webControlAction;
class GlaucaServices;
class GlaucaTabWidget:public QWidget
{
    Q_OBJECT
public:
    GlaucaTabWidget(MainWindow* p);
    ~GlaucaTabWidget();
    void restoreTab(GlaucaWebTab* tab);
    void tabCloseRequest(int index);
	void addTabPage(GlaucaTabPage* page);
    //the GET funcs
    GlaucaTabs* getTabBar();
    QStackedWidget* getStack();
    GlaucaTabPage* getPage(int index);
    GlaucaTabPage* getCurrentPage();
    int getIndex(GlaucaTabPage* page);
	GlaucaIconService* getIconService();
    GlaucaServices* getServices();
    QStackedWidget* getProStack();
    QStackedWidget* getPageActions();
    QNetworkAccessManager* getNetworkManager();
    QStatusBar* getStatusBar();
    //the SET funcs
    void setStack(QStackedWidget*);
    void setTabs(GlaucaTabs* tabbar);
    void setIcon(int index,const QIcon& icon);
    void setText(int index,const QString& text);
    //void setConnect(GlaucaWebView* view);
    void setCornerWidget(QWidget* widget,bool flag);
    void loadPage();
    void loadPage(const QUrl& url);
    void setPageUrl(int index,QUrl* url);
    void setPageUrl(GlaucaWebTab* tab,const QUrl& url);
    MainWindow* getMainWin();
signals:
	void currentChanged(GlaucaTabPage* current);
public slots:
    //void removeView(GlaucaWebTab* tab);
    GlaucaWebTab* addBlankTab();
    void changeIcon();
    void setCurrentPage(int index);
    void moveTab(int from,int to);
    void initTabState();
    void changeState(int index);
    void adjustTitle();
    void finishLoading();
    void changeStatusMessageByPage(const QString& text);
    void changeStatusMessageByLinkeHover(const QString& text);
	void currentChangeSlot(int index);//this function aims to emit the signal;

private:
    GlaucaTabs* tabBar;
    QStackedWidget* viewStack,*progressStack;
    QList<GlaucaTabPage*> tabList;
    MainWindow* parent;
    QNetworkAccessManager* netManager;
    cookieJar* cookie;
    QStatusBar* statusBar;
    bool isLinkHovered;
    QString lastStatusMessage;
};

#endif // GLAUCATABWIDGET_H
