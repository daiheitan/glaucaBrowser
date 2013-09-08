#ifndef GLAUCATABPAGE_H
#define GLAUCATABPAGE_H

#include <QWidget>
#include <QUrl>

/*! This class is a base class for all tab Page widgets
  provides some funcs to check what this widget is
  */
class GlaucaTabPage:public QWidget
{
public:
	GlaucaTabPage(QWidget* parent,bool ifWebView);
	void setTitle(const QString& t);
	QString title();
	QUrl url()const;
	void setUrl(const QUrl& url);
	bool isWebView();
	bool isExtensionView();
signals:

public slots:
private:
	QString _title;
	bool _ifWebView;
	QUrl _url;
};

#endif // GLAUCATABPAGE_H
