#ifndef URLAUTOFILLER_H
#define URLAUTOFILLER_H

#include <QString>
#include <QWidget>
class urlAutoFiller:public QWidget
{
    Q_OBJECT
public:
    urlAutoFiller();
    QString getUrl(QString str);
public slots:
    void getResponse();
private:
    QString url;

};

#endif // URLAUTOFILLER_H
