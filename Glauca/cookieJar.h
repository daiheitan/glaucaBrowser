#ifndef COOKIEJAR_H
#define COOKIEJAR_H

#include <QNetworkCookieJar>

class cookieJar : public QNetworkCookieJar
{
    Q_OBJECT
public:
    cookieJar(QObject *parent = 0);
    ~cookieJar();
    QList<QNetworkCookie> cookiesForUrl(const QUrl &url) const;
    bool setCookiesFromUrl(const QList<QNetworkCookie> &cookieList, const QUrl &url);
private:
    QList<QNetworkCookie> pickCookies(const QList<QNetworkCookie>& list);
    bool loadCookies();
    bool saveCookies();
};

#endif // COOKIEJAR_H
