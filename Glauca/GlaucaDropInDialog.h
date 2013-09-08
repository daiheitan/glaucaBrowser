#ifndef GLAUCADROPINDIALOG_H
#define GLAUCADROPINDIALOG_H

#include <QWidget>
#include <QtGui>
class GlaucaDropInDialog:public QWidget
{
    Q_OBJECT
public:
    GlaucaDropInDialog(QWidget* p);
protected:
    void dragEnterEvent(QDragEnterEvent *event);
    void dropEvent(QDropEvent *event);
private:
    void installTheme(const QString& path);
};

#endif // GLAUCADROPINDIALOG_H
