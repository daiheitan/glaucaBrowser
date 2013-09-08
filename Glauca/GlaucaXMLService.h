#ifndef GLAUCAXMLSERVICE_H
#define GLAUCAXMLSERVICE_H

#include <QDomElement>
#include <QXmlStreamWriter>

class GlaucaXMLService
{
public:
    static bool write(const QString& path,QDomDocument& doc);
    static QDomDocument read(const QString& path);
    static bool exist(const QString& path);
};

#endif // GLAUCAXMLSERVICE_H
