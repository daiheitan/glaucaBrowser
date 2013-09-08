#include "GlaucaUrlAction.h"
#include <QtDebug>
#include <QMenu>

specialMenu::specialMenu(QWidget* p):QMenu(p){
    this->setAttribute(Qt::WA_DeleteOnClose,true);
}
void specialMenu::contextMenuEvent(QContextMenuEvent *event){
    MenuAction* act=qobject_cast<MenuAction*>(this->actionAt(event->pos()));
    if(act==0)return;
    act->openMenu();
}

/****************************************************************************
  *class: MenuAction
  *funcs: MenuAction
          --This will create an object of MenuAction.With a Title title,a Url
            u,also need a pointer to the MainWindow
          handle
          --when mouseClick signal is emitted,this will emit the singal clicked
            with the specified Url url;
  *Usage: This class is used as a Private Class of GlaucaBookmarkService,in order
          to store the url of a certain action in the menu
  ---------------------------------------------------------------------------
  *class: QToolAction
  *Usage: Just as above
  ****************************************************************************/

MenuAction::MenuAction(const QString &title, const QString &u,const QIcon& icon):QAction(0),menu(0){
    this->setText(title);
    this->setIcon(icon);
    url=u;
    menu.addAction("Open");
    menu.addAction("Open In NewTab");
    menu.addAction("Delete");
    connect(&menu,SIGNAL(triggered(QAction*)),this,SLOT(handleMenuRequest(QAction*)));
    connect(this,SIGNAL(triggered()),this,SLOT(handle()));
    connect(this,SIGNAL(clicked(QString)),MainWindow::instance(),SLOT(openLinkRequest(QString)));
}
void MenuAction::handle(){
    emit clicked(url);
}
void MenuAction::openMenu(){
    menu.exec(QCursor::pos());
}
void MenuAction::handleMenuRequest(QAction* act){
    if(act->text()=="Open")this->handle();
    else if(act->text()=="Open In NewTab")emit openInNewTabRequest();
    else if(act->text()=="Delete")emit deleteRequest();
}

MenuRestoreAction::MenuRestoreAction(GlaucaWebTab *v):QAction(0),view(v){
    this->setText(view->title());
    connect(this,SIGNAL(triggered()),this,SLOT(handle()));
}
void MenuRestoreAction::handle(){
    MainWindow::instance()->getTabWidget()->restoreTab(view);
}
