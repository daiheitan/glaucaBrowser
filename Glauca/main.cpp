#include <QtGui/QApplication>
#include "qtwin.h"
#include "MainWindow.h"
/*#include <QtPlugin>
Q_IMPORT_PLUGIN(qico)
Q_IMPORT_PLUGIN(qgif)
Q_IMPORT_PLUGIN(qjpeg)
Q_IMPORT_PLUGIN(qcncodecs)
Q_IMPORT_PLUGIN(qjpcodecs)
Q_IMPORT_PLUGIN(qkrcodecs)*/
int main(int argc, char *argv[])
{
    //QTextCodec::setCodecForTr(QTextCodec::codecForName("GBK"));
   // QTextCodec::setCodecForCStrings(QTextCodec::codecForName("GBK"));
    QApplication app(argc,argv);
    QCoreApplication::setApplicationName("Glauca");
        QCoreApplication::setOrganizationName("GlaucaProject");
    MainWindow* w=MainWindow::instance();
    w->buildWindow();
    if (QtWin::isCompositionEnabled()) {
        QtWin::extendFrameIntoClientArea(w);
        w->setContentsMargins(0, 0, 0, 0);
    }
    w->setAttribute(Qt::WA_DeleteOnClose,true);
    w->show();
    return app.exec();
}
