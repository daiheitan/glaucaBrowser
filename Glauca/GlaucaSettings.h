#ifndef GLAUCASETTINGS_H
#define GLAUCASETTINGS_H

#include <QSettings>
#include <QWidget>
#include "ui_settingWinStack.h"
class GlaucaSettings:public QWidget,public Ui_settingStack
{
    Q_OBJECT
public:
    GlaucaSettings(QWidget* parent=0);
    ~GlaucaSettings();
    void readSettings();
signals:
    void currentPageReuqest();
public slots:
    void glaucaSettingsWindow();
    void writeSettings();
private slots:
    void handleHomepageBtnAction();
private:
    void initSettings();
};

#endif // GLAUCASETTINGS_H
