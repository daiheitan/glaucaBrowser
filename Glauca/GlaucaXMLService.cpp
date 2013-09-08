#include "GlaucaXMLService.h"
#include <QFile>
#include <QTextStream>
#include <QtDebug>

bool GlaucaXMLService::write(const QString &path, QDomDocument& bookMark){
    QFile f(path);
    if(f.exists())f.remove();
    f.open(QIODevice::WriteOnly|QIODevice::Text);
    QTextStream in(&f);
    bookMark.save(in,4);
    f.close();

    return true;
}
QDomDocument GlaucaXMLService::read(const QString &path){
    QFile f(path);
    f.open(QFile::ReadOnly|QFile::Text);
    QDomDocument dom;
    dom.setContent(&f);
    return dom;
}
bool GlaucaXMLService::exist(const QString &path){
    QFile f(path);
    return f.exists();
}
