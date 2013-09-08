#include "cookieJar.h"
#include "MainWindow.h"
#include <QByteArray>
#include <QVariant>
#include <QtDebug>
#include <QSettings>
#include <QList>
#include <QDateTime>
//The very first two functions(>>&<<)are copied from Arora project and Special thanks to the author.
static const unsigned int JAR_VERSION = 23;

QT_BEGIN_NAMESPACE
QDataStream &operator<<(QDataStream &stream, const QList<QNetworkCookie> &list)
{
    stream << JAR_VERSION;
    stream << quint32(list.size());
    for (int i = 0; i < list.size(); ++i)
        stream << list.at(i).toRawForm();
    return stream;
}

QDataStream &operator>>(QDataStream &stream, QList<QNetworkCookie> &list)
{
    list.clear();

    quint32 version;
    stream >> version;

    if (version != JAR_VERSION)
        return stream;

    quint32 count;
    stream >> count;
    for (quint32 i = 0; i < count; ++i) {
        QByteArray value;
        stream >> value;
        QList<QNetworkCookie> newCookies = QNetworkCookie::parseCookies(value);
        if (newCookies.count() == 0 && value.length() != 0) {
            qWarning() << "CookieJar: Unable to parse saved cookie:" << value;
        }
        for (int j = 0; j < newCookies.count(); ++j)
            list.append(newCookies.at(j));
        if (stream.atEnd())
            break;
    }
    return stream;
}
QT_END_NAMESPACE
cookieJar::cookieJar(QObject *parent) :
    QNetworkCookieJar(parent)
{
    qRegisterMetaTypeStreamOperators<QList<QNetworkCookie> >("QList<QNetworkCookie>");//Init variant type
    loadCookies();
}
cookieJar::~cookieJar(){
    saveCookies();
}

bool cookieJar::setCookiesFromUrl(const QList<QNetworkCookie> &cookieList, const QUrl &url){
    return QNetworkCookieJar::setCookiesFromUrl(cookieList,url);
}
QList<QNetworkCookie> cookieJar::cookiesForUrl(const QUrl &url) const{
    return QNetworkCookieJar::cookiesForUrl(url);
}
QList<QNetworkCookie> cookieJar::pickCookies(const QList<QNetworkCookie>& list){
    QDateTime time=QDateTime::currentDateTime();
    QList<QNetworkCookie> tList;
    foreach(QNetworkCookie cookie,list){
        if(cookie.isSessionCookie()||cookie.expirationDate()<time)continue;
        tList<<cookie;
    }
    return tList;
}
bool cookieJar::loadCookies(){
    QSettings sets(MainWindow::getAppRoamingDir()+"profile/cookies.cks",QSettings::IniFormat);
    this->setAllCookies(pickCookies(qvariant_cast<QList<QNetworkCookie> >(sets.value("cookies"))));
    return true;
}
bool cookieJar::saveCookies(){
    QSettings sets(MainWindow::getAppRoamingDir()+"profile/cookies.cks",QSettings::IniFormat);
    sets.setValue("cookies",qVariantFromValue<QList<QNetworkCookie> >(pickCookies(allCookies())));
    return true;
}
