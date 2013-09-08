#include "GlaucaServices.h"
#include <QtDebug>
GlaucaServices::GlaucaServices(MainWindow* p){
	parent=p;
	bookmarkService=new GlaucaBookmarkView();
	iconService=new GlaucaIconService(parent);
	historyService=new GlaucaHistoryService(parent);
	downloadService=new downloadView(parent);
	locationEdit=new locationBar(parent);
	panel=new GlaucaQuickPanel(parent);
	wikiEditor=new GlaucaWikiEditor(parent);
}
GlaucaServices::~GlaucaServices(){
}
locationBar* GlaucaServices::urlBar(){
	return locationEdit;
}

GlaucaWikiEditor* GlaucaServices::wiki(){
	return wikiEditor;
}
GlaucaQuickPanel* GlaucaServices::quickPanel(){
	return panel;
}

GlaucaBookmarkView* GlaucaServices::bookMark(){
	return bookmarkService;
}
GlaucaIconService* GlaucaServices::iconSet(){
	return iconService;
}
GlaucaHistoryService* GlaucaServices::history(){
	return historyService;
}
downloadView* GlaucaServices::download(){
	return downloadService;
}
