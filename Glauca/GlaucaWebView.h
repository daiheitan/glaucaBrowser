#ifndef GLAUCAWEBVIEW_H
#define GLAUCAWEBVIEW_H

#include <QWebView>
#include <QBuffer>
#include <QProgressBar>
#include "GlaucaTabWidget.h"
#include <QNetworkRequest>
#include <GlaucaTabPage.h>
#include <QTextEdit>

class GlaucaTabWidget;
class GlaucaWebView:public QWebView
{
	Q_OBJECT
public:
	GlaucaWebView(QWidget* p);
	~GlaucaWebView();
signals:
	void searchRequest(const QString query);
	void createWindowRequest(QWebPage::WebWindowType type);
public slots:
	
	void viewPageSource();
	void addSelectedToWiki();
	void addPageToWiki();
protected:
	QWebView* createWindow(QWebPage::WebWindowType type);
	void mouseDoubleClickEvent(QMouseEvent *event);
	void contextMenuEvent(QContextMenuEvent *event);
};

#endif // GLAUCAWEBVIEW_H