#ifndef GLAUCADETAILLISTWIDGET_H
#define GLAUCADETAILLISTWIDGET_H
/*This widget provide the look'n feel of an item in the downloadManager*/

#include <QWidget>
#include <QProgressBar>
#include <QToolButton>
#include <QPixmap>
#include <QLabel>
#include <QHBoxLayout>

class GlaucaDetailListWidget:public QWidget{
    Q_OBJECT
public:
    GlaucaDetailListWidget(const QPixmap& icon,QWidget* parent=0);
    QProgressBar* progressBar();
    void setTitle(const QString& title);
    void setDetailIntro(const QString &detail);
    QToolButton* continueBtn();
    QToolButton* stopBtn();
    QToolButton* cancelBtn();
public slots:
    void setProgress(int prog);
private:
    QToolButton* continueButton,*stopButton,*cancelButton;
    QLabel *titleLabel,*detailLabel;
    QHBoxLayout* progressLayout;
    QProgressBar* progress;
};

#endif // GLAUCADETAILLISTWIDGET_H
