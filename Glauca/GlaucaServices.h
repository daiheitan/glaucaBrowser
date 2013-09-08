#ifndef GLAUCASERVICES_H
#define GLAUCASERVICES_H
/*!
   \class GlaucaServices
   this class will provide access to all the services of Glauca
   !*/
#include "GlaucaBookmarkService.h"
#include "GlaucaIconService.h"
#include "MainWindow.h"
#include "GlaucaHistoryService.h"
#include "GlaucaDownloadService.h"
#include "locationBar.h"
#include "GlaucaQuickPanel.h"
#include "GlaucaWikiEditor.h"

class GlaucaWikiEditor;
class GlaucaQuickPanel;
class MainWindow;
class GlaucaBookmarkView;
class GlaucaIconService;
class GlaucaHistoryService;
class downloadView;
class locationBar;
class GlaucaServices
{
public:
	GlaucaServices(MainWindow* p);
	~GlaucaServices();
	GlaucaBookmarkView* bookMark();
	GlaucaIconService* iconSet();
	GlaucaHistoryService* history();
	downloadView* download();
	locationBar* urlBar();
	GlaucaQuickPanel* quickPanel();
	GlaucaWikiEditor* wiki();
private:
	GlaucaBookmarkView* bookmarkService;
	GlaucaIconService* iconService;
	GlaucaHistoryService* historyService;
	downloadView* downloadService;
	MainWindow* parent;
	locationBar* locationEdit;
	GlaucaQuickPanel* panel;
	GlaucaWikiEditor* wikiEditor;
};

#endif // GLAUCASERVICES_H
