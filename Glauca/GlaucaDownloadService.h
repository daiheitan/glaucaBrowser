#ifndef GLAUCADOWNLOADSERVICE_H
#define GLAUCADOWNLOADSERVICE_H

#include <QWidget>
#include "MainWindow.h"
#include <QTime>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <GlaucaXMLService.h>
#include <QGroupBox>

class MainWindow;
class downloadBarController;
class downloadController;
class downloadModel;
//DownloadBar is a view class always with contains a lot of downloadBarItems.
//Once a download action starts,a downloadBarItem is created and will be added
//to the model class's item list.
//downloadBar mainly control all items and update their information
//downloadModel control download process and provide download speed ,etc.
//model also contains some item lists
//downloadBarItem provide a GUI of a downBar item and accept information changes
//from downloadBar
class downloadBarItem:public QWidget{
    Q_OBJECT
public:
    downloadBarItem(QNetworkReply* reply,const QString& pathString);
    bool isHide();
    void setPercent(double percent);
    double getPercent();
    double getSpeed();
    void setSpeed(double speed);
    bool isFinished();
    bool isPaused();
    //QUrl& getUrl();
    QTime& getTimer();
    QFile* getOutputFile();
    QNetworkReply* getReply();
    qint64& getByteSize();
protected:
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseDoubleClickEvent(QMouseEvent *event);
    void contextMenuEvent(QContextMenuEvent *event);
signals:
    void pause();
    void conti();
    void openFolder();
    void reDownload();
    void cancel();
    void openFile();
    void copyLink();
    void delFile();
    void finished();
    void readyRead();
    void downloadProgress(qint64 received,qint64 total);
private slots:
    void menuTriggered(QAction* action);
    void copyLinkLocation();
private:
    bool ifPaused;
    double per,sp;
    QString url,fileName,size,path;
    QProgressBar* pBar;
    QGroupBox* itemGroup;
    QNetworkReply* reply;
    QFile* outputFile;
    QTime timer;
    qint64 byteSize;
};
class downloadBar:public QWidget{
public:
    downloadBar(QWidget* parent=0);
    void addNewDownloadBarItem(downloadBarItem* item);
    void delDownloadBarItem(downloadBarItem* item);
    void setText(const QString& text);
    void setPercent(int percent);
protected:
   // void contextMenuEvent(QContextMenuEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
private:
    QProgressBar* pBar;
    QVBoxLayout* boxLayout;
    QGroupBox* box;
    int fileNum;
    downloadBarController* controller;
};

class downloadView:public QObject{
    Q_OBJECT
public:
    downloadView(QObject* parent=0);
    QDialog* showDownloadPathWindow(const QUrl& url);
    downloadBar* getDownloadBar();
    void downloadRequest(const QNetworkRequest& request);
private:
    downloadController* controller;
    downloadBar* bar;
};

class downloadController:public QObject{
    Q_OBJECT
public:
    downloadController(downloadView* view);
    void setModel(downloadModel* model);
    downloadModel* getModel();
    void showDownloadPathWindow(const QUrl& url);
public slots:
    void pathWinConfirmAction();
    void pathBtnPressed();
private:
    downloadView* view;
    downloadModel* model;
};

class downloadModel:public QObject{
    Q_OBJECT
public:
    //get info
    downloadModel(downloadBarController* con,downloadController* dCon);
    static QString getDownloadSpeedString(double v);
    double getDownloadPercent(qint64 received,qint64 total);
    //update downloadBar
    void deleteDownloadBarItem(downloadBarItem* item);
    void downloadRequest(const QUrl& url);
public slots:
    void downloadProcess(const QString& path,const QUrl& url);
    void downloadFinished();
    void readyReadContent();
    void downloadProgressAction(qint64 got,qint64 total);
private:
    downloadBarController* barController;
    downloadController* totalController;
};

class downloadBarController:public QObject{
    Q_OBJECT
public:
    downloadBarController(downloadBar* dBar);
    void setModel(downloadModel* dModel);
    void addNewDownloadBarItem(QNetworkReply* reply,const QString& path);
public slots:
    void pauseBtnPressed();
    void continueBtnPressed();
    void abortBtnPressed();
    void openFilePathBtnPressed();
    void openFileBtnPressed();
    void deleteFileBtnPressed();
    void deleteDownloadItemBtnPressed(downloadBarItem* item);
    void deleteAllItemBtnPressed();
    void restartBtnPressed();
    void updateBarSpeed();
    void updateBarPercent();
private:
    //downloadBarItem* getItemFromMenu(QMenu*& menu);
    //item list
    QList<downloadBarItem*> itemList;
    downloadBar* bar;
    downloadModel* model;
};

/*donwloadFileControl handle stuffs related to files*/
class downloadFileType{
public:
    //if a file type is firstly downloaded,this will return true;
    //accept a url and will analyze the url and get a fileType;
    static bool isFirstDonwload(const QUrl& url);
    static bool changePath(const QString& fileType,const QString& newPath);
    //changeAllPath will change the default path of all file types.
    //ifInit determines if some default folders are created under the new path
    static bool changeAllPath(const QString& newPath);
    static QString getFilePath(const QString& fileType);
};

/*
class GlaucaDownloadService:public QWidget{
    Q_OBJECT
public:
    GlaucaDownloadService(MainWindow* p);
    ~GlaucaDownloadService();
    void downloadRequest(const QUrl& url);
    void showDownloadPathWindow(const QUrl& url);
public slots:
    //these two funcs are different.
    //showDonwloadWindow will show a list of the downloading and completed files
    //showDwonloadPathWindow will be displayed the first time a file type's donwloaded
    //and return the file path selected
    void showGlaucaDownloadWindow();
    void downloadFinished();
    void readDownloadContent();
    downloadBar* getDownloadBar();
    void pauseDownload();
    void continueDownload();
signals:
    void pathWinReady(const QString& fileName,const QUrl& url);
private slots:
    void pathWindowCloseAction();
    void downloadProcess(const QString& fileName,const QUrl& url);
    void pathBtnPressed();
private:
    downloadFileControl* fileControl;
    QFile output;
    MainWindow* parent;
    //QList downloadWidgetList;
    downloadBar* bar;
};
*/

#endif // GLAUCADOWNLOADSERVICE_H
