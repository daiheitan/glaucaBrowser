#ifndef GLAUCADOCKS_H
#define GLAUCADOCKS_H

/********************************************
 *class GlaucaDocks
 *purpose To provice a common access to featured docks
 *inherit QDockWidget
 ********************************************/
#include <QDockWidget>
#include <QVBoxLayout>
#include <QMenu>
#include <QToolButton>
#include <QPropertyAnimation>

class GlaucaDockButton:public QToolButton{
public:
    GlaucaDockButton(QWidget* parent);
    void showBalloon(int mSec,const QString& text);//Show a balloon for mSec*1000 seconds
    void showNotifier();//Show a notifier(circle),the content should be a number or sth.like that
    void clearNotifier();
    void normal();
protected:
    void paintEvent(QPaintEvent *event);
    void enterEvent(QEvent *event);
    void leaveEvent(QEvent *event);
private:
    bool showNoti,showBal;
    QString balloonTxt;
    QPropertyAnimation *enlarge,*shrink;
};

class GlaucaDocks:public QDockWidget
{
    Q_OBJECT
public:
    GlaucaDocks(const QString & title,QWidget* p=0, Qt::WindowFlags flags = 0);
    ~GlaucaDocks();
    //There are several ways to add widgets to a dock
    QToolButton* addMenuBtn(const QString& title,const QIcon& icon,QMenu* menu);//This will return a button with a certain menu
    QToolButton* addActBtn(const QString& title,const QIcon& icon);//This will return a certain button
    void removeWidget();
    void setAutoHide(bool flag);
    bool autoHide();
    void showDock();
    int showBalloon(const QString& content);
protected slots:
    void changeMenuOpenState();
protected:
    void leaveEvent(QEvent *event);
    void paintEvent(QPaintEvent *event);
private:
    QWidget *parent;
    QVBoxLayout* mainLayout;
    //Bool Values to restore the states of the widget;
    bool menuOpened;
};

#endif // GLAUCADOCKS_H
