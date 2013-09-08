#ifndef GLAUCATABADDON_H
#define GLAUCATABADDON_H

#include <QWidget>
#include <QMenu>
#include <QToolButton>
#include <QHBoxLayout>
#include "GlaucaTabs.h"
#include <QSpacerItem>
#include "GlaucaTabWidget.h"

/*This class will setUp a QWidget called GlaucaTabAddon;
  It will fill in the blank part of TabBar in a QTabWidget
  It mainly provide a newTab Button and the control buttons
  and accept contextMenuEvents
  AS each TabAddon must have a TabBar,this provide a variable
  to restore the pointer
  When the tabLayout is changed,the tabAddonLayout should be
  updated
  */
class GlaucaTabs;
class GlaucaTabWidget;
class GlaucaTabAddon:public QWidget
{
    Q_OBJECT
public:
    GlaucaTabAddon(GlaucaTabs*);
    ~GlaucaTabAddon();
    QHBoxLayout* Layout();
    void refreshLayout();
    QToolButton* getAddButton();
    void dentifyParent(GlaucaTabWidget*);
public slots:
    void contextMenuEvent(QContextMenuEvent * event,QMenu* menu);
private:
    QToolButton* newTabButton;
    QHBoxLayout* layout;
    GlaucaTabs* tabBar;
    GlaucaTabWidget* parent;
};

#endif // GLAUCATABADDON_H
