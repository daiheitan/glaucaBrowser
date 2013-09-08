#ifndef LOCATIONBAR_H
#define LOCATIONBAR_H

#include <QWidget>
#include <QComboBox>
#include "GlaucaTabWidget.h"
#include "urlAutoFiller.h"
#include <QHBoxLayout>

class GlaucaTabWidget;
class locationBar : public QWidget
{
Q_OBJECT
public:
    explicit locationBar(QWidget *parent = 0);
    void setRelatedTabWidget(GlaucaTabWidget* p);
    QString text();
    void setText(const QString& text);
    void setCornerWidget(QWidget* wid,bool flag);
    QComboBox* getLocationEdit();
    void adjustLocation(const QString& url);
    void restore();
signals:
    void returnPressed();//If the return Key has pressed on the textEdit

public slots:
    void changeLocation();
private:
    QString lastMessage;
    QComboBox* locationTextBar;
    QHBoxLayout *leftLayout,*rightLayout;
    GlaucaTabWidget* tabWidget;
    urlAutoFiller fill;
};

#endif // LOCATIONBAR_H
