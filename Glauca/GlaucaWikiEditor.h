#ifndef GLAUCAWIKIEDITOR_H
#define GLAUCAWIKIEDITOR_H

#include <QTreeWidget>
#include <QWebView>
#include <QSqlDatabase>
#include "MainWindow.h"

class GlaucaWikiEditor
{
public:
	GlaucaWikiEditor(QWidget* parent=0);
public slots:
	bool addDoc(const QString& title,const QWebElement& element);
	void showWikiWin();
private:
	bool initDB();
	QTreeWidget* tWid;
	QWebView* view;
	QSqlDatabase db;
	QWidget* p;
	GlaucaTabPage* wid;
};

#endif // GLAUCAWIKIEDITOR_H
