#ifndef GLAUCAQUICKPANEL_H
#define GLAUCAQUICKPANEL_H

#include <QWidget>
#include <QToolBar>

class GlaucaQuickPanel : public QWidget
{
    Q_OBJECT
public:
    explicit GlaucaQuickPanel(QWidget *parent = 0);
signals:
    void back();
    void forward();
    void stop();
    void refresh();
    void go(const QString& url);
    void home();
public slots:
    void upBarAction();
    void downBarAction();
    void leftBarAction();
    void rightBarAction();
protected:
private slots:
    void handleFocus(QWidget* old,QWidget* now);
private:
    QToolBar* historyBar;
    QToolBar* closedBar;
    QToolBar* bookmarkBar;
    QToolBar* toolsBar;
};

#endif // GLAUCAQUICKPANEL_H
