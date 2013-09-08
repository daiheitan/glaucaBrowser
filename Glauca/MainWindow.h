#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QtGui/QMainWindow>
#include <QAction>
#include <QLineEdit>
#include "GlaucaTabWidget.h"
#include <QWidget>
#include <Qt>
#include <QTimer>
#include "locationBar.h"
#include "GlaucaServices.h"
#include "GlaucaWebView.h"
#include "GlaucaDocks.h"
#include "GlaucaSettings.h"
#include <QStackedWidget>

class GlaucaTabWidget;
class locationBar;
class GlaucaServices;
class GlaucaBookmakService;
class GlaucaIconService;
class GlaucaWebView;
class GlaucaHistoryService;
class GlaucaWidget;
class MainWindow : public QWidget
{
    Q_OBJECT

public:
    void buildWindow();
    ~MainWindow();
    GlaucaServices* getService();
    QNetworkAccessManager* getNetworkManager();
    static QPushButton *custButton(QString str,QString str1=NULL,QWidget* parent=0);
    static MainWindow* instance();
    QPushButton* max;
    GlaucaTabWidget* getTabWidget();
	QUrl getCurrentUrl();
    static QString getAppRoamingDir();
    void setStateBtnCurrentIndex(int index);
public slots:

     void showToolBar();
     void hideToolBar();
     void changeText(int index);
     //void maxclicked();
     void openLinkRequest(const QString& url);
     void addSavedNewPage();
     //void initTabState();
     //void changeState(int index);
     void applyTheme();
     void changeBtnStates();
protected:
     void timerEvent(QTimerEvent *event);
     //void mouseMoveEvent(QMouseEvent *e);
     //void mousePressEvent(QMouseEvent *e);
private slots:
     void setHomePageText();
     void openPluginWin();
     void handleTextEdit();
private:
     static MainWindow* _mainWin;
     MainWindow();
     void initStateBtn();

     QString jQuery;
     QPoint last,pos0;
     QToolBar *quickcon;
     QPushButton* bookMark,*back,*forward;
     QToolButton *stop,*reload,*go;
     QStackedWidget* stateBtnStack;

     // node1;
     int progress;
     GlaucaTabWidget* tabWidget;
     QWebSettings* setting;
     GlaucaServices* service;
     GlaucaDocks* leftDock;
     GlaucaSettings* sets;
     QWidget* toolBarWidget;
};

#endif // MAINWINDOW_H
