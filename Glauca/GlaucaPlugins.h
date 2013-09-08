#ifndef GLAUCAPLUGINS_H
#define GLAUCAPLUGINS_H

/*This class Controls the plugin interface
  handle with the plugin Dialog
  handle with skins*/

#include <QObject>
#include "MainWindow.h"
#include <QListWidget>

class pluginWinListWidget:public QWidget{
public:
    pluginWinListWidget(const QPixmap& icon,const QString& name,const QString& author,const QString& des,QWidget* parent);
    QString n,a,d;
    QPixmap ico;
};

class GlaucaPlugins
{
public:
    static void showPluginWindow(MainWindow* p);
private:
    static void getExtensionList(QListWidget* list,const QString& path);
};

#endif // GLAUCAPLUGINS_H
