#ifndef GLAUCAWEBTAB_H
#define GLAUCAWEBTAB_H

#include "GlaucaTabPage.h"
#include "GlaucaWebView.h"

class GlaucaWebView;
class GlaucaWebTab:public GlaucaTabPage{
Q_OBJECT
public:
	GlaucaWebTab(GlaucaTabWidget* parent=0);
	QIcon getIcon();
	QProgressBar* getProBar();
	//QWidget* actWid;
	GlaucaWebView* view();
	QUrl url()const;
signals:
	void urlChanged(QUrl&);
	void buffLoaded();
	void loadStarted();
	void loadFinished(bool flag);
public slots:
	void loadIcon();
	void createIcon();
	void downloadRequest(const QNetworkRequest request);
	void unsupportedContent(QNetworkReply* reply);
private:
	GlaucaWebView* _view;
	QBuffer iconBuffer;
	GlaucaTabWidget* parent;
	QProgressBar* progressbar;
	QIcon icon;
};
#endif