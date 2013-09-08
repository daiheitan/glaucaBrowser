#ifndef GLAUCAICONSERVICE_H
#define GLAUCAICONSERVICE_H

//This class mainly handle with most *.ico issues
#include <QIcon>
#include <QHttp>
#include <QUrl>
#include <QFile>
#include "GlaucaTabWidget.h"
#include <QBuffer>
#include "GlaucaWebView.h"
#include "MainWindow.h"
#include <QSqlDatabase>
#include "GlaucaWebTab.h"

class MainWindow;
class GlaucaWebView;
class GlaucaIconService:public QObject
{
    Q_OBJECT
public:
    GlaucaIconService(MainWindow* p);
    ~GlaucaIconService();
    void saveIcon(GlaucaWebTab* tab);
    void tempIconRequest(QBuffer& buff,GlaucaWebTab* tab);
private slots:
    void loadFinished(int id,bool error);
    //void tempRequestFinished();
signals:
    void fileSucceed();
private:
        QString bookMarkIconPath;
        //QString bookMarkIconContentFile;
        QList<QString> bookMarkUrls;
        QFile* file;
        QHttp* http;
        MainWindow* parent;
        //QSqlDatabase db;
};

#endif // GLAUCAICONSERVICE_H
