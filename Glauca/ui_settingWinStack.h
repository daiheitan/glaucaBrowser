/********************************************************************************
** Form generated from reading UI file 'settingWinStack.ui'
**
** Created: Tue Feb 8 18:28:06 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGWINSTACK_H
#define UI_SETTINGWINSTACK_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QStackedWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_settingStack
{
public:
    QWidget *mainPage;
    QGroupBox *groupBox_2;
    QCheckBox *showDownloadRate;
    QCheckBox *showDownloadBar;
    QCheckBox *createFolders;
    QPushButton *fileTypeControl;
    QPushButton *headersControl;
    QGroupBox *homePageGB;
    QComboBox *homePageUrlCombo;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *useBlankPage;
    QPushButton *useCurrentPage;
    QPushButton *useLastSession;
    QGroupBox *groupBox_3;
    QLabel *label;
    QSpinBox *mouseSensibility;
    QCheckBox *showSlider;
    QRadioButton *sortIconByTime;
    QRadioButton *sortIconByChanged;
    QRadioButton *sortDisabled;
    QPushButton *dockThemeSelector;
    QWidget *page;
    QGroupBox *quickSurfGB;
    QLabel *label_2;
    QComboBox *qucikSurfCallOutCombo;
    QCheckBox *hideControlBar;
    QGroupBox *notifierGB;
    QLabel *label_3;
    QComboBox *notifierPosition;
    QLabel *label_4;
    QDoubleSpinBox *notifierStayTimeSpin;
    QCheckBox *popUpWhenStarted;
    QCheckBox *popUpWhenFinished;
    QCheckBox *popUpForCurrent;
    QWidget *page_2;
    QGroupBox *groupBox_6;
    QGroupBox *groupBox_7;
    QLabel *label_5;
    QComboBox *leftDoubleAct;
    QComboBox *leftShiftAct;
    QLabel *label_6;
    QLabel *label_7;
    QComboBox *leftCtrlAct;
    QLabel *label_8;
    QComboBox *leftAltAct;
    QGroupBox *groupBox_8;
    QLabel *label_9;
    QComboBox *rightDoubleAct;
    QComboBox *rightShiftAct;
    QLabel *label_10;
    QLabel *label_11;
    QComboBox *rightCtrlAct;
    QLabel *label_12;
    QComboBox *rightAltAct;
    QLabel *label_13;
    QComboBox *comboBox_12;
    QGroupBox *groupBox_9;
    QCheckBox *showCloseBtn;
    QCheckBox *showNewTabBtn;
    QCheckBox *showAllTabBtn;
    QCheckBox *checkBox_12;
    QCheckBox *tabAutoResize;
    QCheckBox *darkerTabs;
    QCheckBox *linkInNewTab;
    QCheckBox *preventAutoTabCreating;
    QCheckBox *CloseWinWhenLastTabClosed;

    void setupUi(QStackedWidget *settingStack)
    {
        if (settingStack->objectName().isEmpty())
            settingStack->setObjectName(QString::fromUtf8("settingStack"));
        settingStack->resize(400, 383);
        mainPage = new QWidget();
        mainPage->setObjectName(QString::fromUtf8("mainPage"));
        groupBox_2 = new QGroupBox(mainPage);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 120, 381, 91));
        showDownloadRate = new QCheckBox(groupBox_2);
        showDownloadRate->setObjectName(QString::fromUtf8("showDownloadRate"));
        showDownloadRate->setGeometry(QRect(10, 20, 221, 17));
        showDownloadBar = new QCheckBox(groupBox_2);
        showDownloadBar->setObjectName(QString::fromUtf8("showDownloadBar"));
        showDownloadBar->setGeometry(QRect(10, 40, 211, 17));
        createFolders = new QCheckBox(groupBox_2);
        createFolders->setObjectName(QString::fromUtf8("createFolders"));
        createFolders->setGeometry(QRect(10, 60, 211, 17));
        fileTypeControl = new QPushButton(groupBox_2);
        fileTypeControl->setObjectName(QString::fromUtf8("fileTypeControl"));
        fileTypeControl->setGeometry(QRect(240, 20, 121, 20));
        headersControl = new QPushButton(groupBox_2);
        headersControl->setObjectName(QString::fromUtf8("headersControl"));
        headersControl->setGeometry(QRect(240, 50, 121, 20));
        homePageGB = new QGroupBox(mainPage);
        homePageGB->setObjectName(QString::fromUtf8("homePageGB"));
        homePageGB->setGeometry(QRect(10, 20, 383, 91));
        homePageGB->setCheckable(true);
        homePageGB->setChecked(false);
        homePageUrlCombo = new QComboBox(homePageGB);
        homePageUrlCombo->setObjectName(QString::fromUtf8("homePageUrlCombo"));
        homePageUrlCombo->setGeometry(QRect(10, 20, 371, 22));
        homePageUrlCombo->setEditable(true);
        horizontalLayoutWidget = new QWidget(homePageGB);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 50, 371, 31));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        useBlankPage = new QPushButton(horizontalLayoutWidget);
        useBlankPage->setObjectName(QString::fromUtf8("useBlankPage"));

        horizontalLayout->addWidget(useBlankPage);

        useCurrentPage = new QPushButton(horizontalLayoutWidget);
        useCurrentPage->setObjectName(QString::fromUtf8("useCurrentPage"));

        horizontalLayout->addWidget(useCurrentPage);

        useLastSession = new QPushButton(horizontalLayoutWidget);
        useLastSession->setObjectName(QString::fromUtf8("useLastSession"));

        horizontalLayout->addWidget(useLastSession);

        groupBox_3 = new QGroupBox(mainPage);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 220, 381, 121));
        label = new QLabel(groupBox_3);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 20, 181, 16));
        mouseSensibility = new QSpinBox(groupBox_3);
        mouseSensibility->setObjectName(QString::fromUtf8("mouseSensibility"));
        mouseSensibility->setGeometry(QRect(191, 18, 42, 22));
        mouseSensibility->setMinimum(1);
        mouseSensibility->setMaximum(100);
        showSlider = new QCheckBox(groupBox_3);
        showSlider->setObjectName(QString::fromUtf8("showSlider"));
        showSlider->setGeometry(QRect(10, 40, 141, 17));
        showSlider->setChecked(true);
        sortIconByTime = new QRadioButton(groupBox_3);
        sortIconByTime->setObjectName(QString::fromUtf8("sortIconByTime"));
        sortIconByTime->setGeometry(QRect(10, 60, 181, 17));
        sortIconByChanged = new QRadioButton(groupBox_3);
        sortIconByChanged->setObjectName(QString::fromUtf8("sortIconByChanged"));
        sortIconByChanged->setGeometry(QRect(10, 80, 181, 17));
        sortDisabled = new QRadioButton(groupBox_3);
        sortDisabled->setObjectName(QString::fromUtf8("sortDisabled"));
        sortDisabled->setGeometry(QRect(10, 100, 171, 17));
        dockThemeSelector = new QPushButton(groupBox_3);
        dockThemeSelector->setObjectName(QString::fromUtf8("dockThemeSelector"));
        dockThemeSelector->setGeometry(QRect(250, 20, 111, 23));
        settingStack->addWidget(mainPage);
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        quickSurfGB = new QGroupBox(page);
        quickSurfGB->setObjectName(QString::fromUtf8("quickSurfGB"));
        quickSurfGB->setGeometry(QRect(10, 10, 381, 81));
        quickSurfGB->setCheckable(true);
        label_2 = new QLabel(quickSurfGB);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 20, 151, 21));
        qucikSurfCallOutCombo = new QComboBox(quickSurfGB);
        qucikSurfCallOutCombo->setObjectName(QString::fromUtf8("qucikSurfCallOutCombo"));
        qucikSurfCallOutCombo->setGeometry(QRect(160, 20, 111, 22));
        hideControlBar = new QCheckBox(quickSurfGB);
        hideControlBar->setObjectName(QString::fromUtf8("hideControlBar"));
        hideControlBar->setGeometry(QRect(10, 50, 221, 17));
        notifierGB = new QGroupBox(page);
        notifierGB->setObjectName(QString::fromUtf8("notifierGB"));
        notifierGB->setGeometry(QRect(10, 100, 381, 101));
        notifierGB->setCheckable(true);
        label_3 = new QLabel(notifierGB);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 20, 91, 16));
        notifierPosition = new QComboBox(notifierGB);
        notifierPosition->setObjectName(QString::fromUtf8("notifierPosition"));
        notifierPosition->setGeometry(QRect(100, 20, 81, 22));
        label_4 = new QLabel(notifierGB);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(190, 20, 141, 16));
        notifierStayTimeSpin = new QDoubleSpinBox(notifierGB);
        notifierStayTimeSpin->setObjectName(QString::fromUtf8("notifierStayTimeSpin"));
        notifierStayTimeSpin->setGeometry(QRect(330, 20, 41, 22));
        popUpWhenStarted = new QCheckBox(notifierGB);
        popUpWhenStarted->setObjectName(QString::fromUtf8("popUpWhenStarted"));
        popUpWhenStarted->setGeometry(QRect(10, 50, 241, 17));
        popUpWhenFinished = new QCheckBox(notifierGB);
        popUpWhenFinished->setObjectName(QString::fromUtf8("popUpWhenFinished"));
        popUpWhenFinished->setGeometry(QRect(190, 50, 171, 17));
        popUpForCurrent = new QCheckBox(notifierGB);
        popUpForCurrent->setObjectName(QString::fromUtf8("popUpForCurrent"));
        popUpForCurrent->setGeometry(QRect(10, 70, 161, 17));
        settingStack->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        groupBox_6 = new QGroupBox(page_2);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        groupBox_6->setGeometry(QRect(10, 10, 381, 181));
        groupBox_7 = new QGroupBox(groupBox_6);
        groupBox_7->setObjectName(QString::fromUtf8("groupBox_7"));
        groupBox_7->setGeometry(QRect(10, 20, 171, 121));
        label_5 = new QLabel(groupBox_7);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 20, 46, 13));
        leftDoubleAct = new QComboBox(groupBox_7);
        leftDoubleAct->setObjectName(QString::fromUtf8("leftDoubleAct"));
        leftDoubleAct->setGeometry(QRect(60, 16, 101, 22));
        leftShiftAct = new QComboBox(groupBox_7);
        leftShiftAct->setObjectName(QString::fromUtf8("leftShiftAct"));
        leftShiftAct->setGeometry(QRect(60, 40, 101, 22));
        label_6 = new QLabel(groupBox_7);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 45, 46, 13));
        label_7 = new QLabel(groupBox_7);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(11, 68, 46, 13));
        leftCtrlAct = new QComboBox(groupBox_7);
        leftCtrlAct->setObjectName(QString::fromUtf8("leftCtrlAct"));
        leftCtrlAct->setGeometry(QRect(60, 64, 101, 22));
        label_8 = new QLabel(groupBox_7);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(12, 90, 46, 13));
        leftAltAct = new QComboBox(groupBox_7);
        leftAltAct->setObjectName(QString::fromUtf8("leftAltAct"));
        leftAltAct->setGeometry(QRect(60, 88, 101, 22));
        groupBox_8 = new QGroupBox(groupBox_6);
        groupBox_8->setObjectName(QString::fromUtf8("groupBox_8"));
        groupBox_8->setGeometry(QRect(200, 20, 171, 121));
        label_9 = new QLabel(groupBox_8);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(10, 20, 46, 13));
        rightDoubleAct = new QComboBox(groupBox_8);
        rightDoubleAct->setObjectName(QString::fromUtf8("rightDoubleAct"));
        rightDoubleAct->setGeometry(QRect(60, 16, 101, 22));
        rightShiftAct = new QComboBox(groupBox_8);
        rightShiftAct->setObjectName(QString::fromUtf8("rightShiftAct"));
        rightShiftAct->setGeometry(QRect(60, 40, 101, 22));
        label_10 = new QLabel(groupBox_8);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(10, 45, 46, 13));
        label_11 = new QLabel(groupBox_8);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(11, 68, 46, 13));
        rightCtrlAct = new QComboBox(groupBox_8);
        rightCtrlAct->setObjectName(QString::fromUtf8("rightCtrlAct"));
        rightCtrlAct->setGeometry(QRect(60, 64, 101, 22));
        label_12 = new QLabel(groupBox_8);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(12, 90, 46, 13));
        rightAltAct = new QComboBox(groupBox_8);
        rightAltAct->setObjectName(QString::fromUtf8("rightAltAct"));
        rightAltAct->setGeometry(QRect(60, 88, 101, 22));
        label_13 = new QLabel(groupBox_6);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(10, 151, 71, 16));
        comboBox_12 = new QComboBox(groupBox_6);
        comboBox_12->setObjectName(QString::fromUtf8("comboBox_12"));
        comboBox_12->setGeometry(QRect(70, 148, 101, 22));
        groupBox_9 = new QGroupBox(page_2);
        groupBox_9->setObjectName(QString::fromUtf8("groupBox_9"));
        groupBox_9->setGeometry(QRect(10, 200, 381, 81));
        showCloseBtn = new QCheckBox(groupBox_9);
        showCloseBtn->setObjectName(QString::fromUtf8("showCloseBtn"));
        showCloseBtn->setGeometry(QRect(10, 20, 141, 17));
        showNewTabBtn = new QCheckBox(groupBox_9);
        showNewTabBtn->setObjectName(QString::fromUtf8("showNewTabBtn"));
        showNewTabBtn->setGeometry(QRect(10, 40, 131, 17));
        showAllTabBtn = new QCheckBox(groupBox_9);
        showAllTabBtn->setObjectName(QString::fromUtf8("showAllTabBtn"));
        showAllTabBtn->setGeometry(QRect(10, 60, 141, 17));
        checkBox_12 = new QCheckBox(groupBox_9);
        checkBox_12->setObjectName(QString::fromUtf8("checkBox_12"));
        checkBox_12->setEnabled(false);
        checkBox_12->setGeometry(QRect(160, 20, 201, 17));
        tabAutoResize = new QCheckBox(groupBox_9);
        tabAutoResize->setObjectName(QString::fromUtf8("tabAutoResize"));
        tabAutoResize->setGeometry(QRect(160, 40, 191, 17));
        darkerTabs = new QCheckBox(groupBox_9);
        darkerTabs->setObjectName(QString::fromUtf8("darkerTabs"));
        darkerTabs->setGeometry(QRect(160, 60, 161, 17));
        linkInNewTab = new QCheckBox(page_2);
        linkInNewTab->setObjectName(QString::fromUtf8("linkInNewTab"));
        linkInNewTab->setGeometry(QRect(10, 290, 171, 17));
        preventAutoTabCreating = new QCheckBox(page_2);
        preventAutoTabCreating->setObjectName(QString::fromUtf8("preventAutoTabCreating"));
        preventAutoTabCreating->setGeometry(QRect(10, 310, 281, 17));
        CloseWinWhenLastTabClosed = new QCheckBox(page_2);
        CloseWinWhenLastTabClosed->setObjectName(QString::fromUtf8("CloseWinWhenLastTabClosed"));
        CloseWinWhenLastTabClosed->setGeometry(QRect(190, 290, 201, 17));
        settingStack->addWidget(page_2);

        retranslateUi(settingStack);

        settingStack->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(settingStack);
    } // setupUi

    void retranslateUi(QStackedWidget *settingStack)
    {
        settingStack->setWindowTitle(QApplication::translate("settingStack", "StackedWidget", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("settingStack", "Downloads", 0, QApplication::UnicodeUTF8));
        showDownloadRate->setText(QApplication::translate("settingStack", "Keep showing download rate in the dock", 0, QApplication::UnicodeUTF8));
        showDownloadBar->setText(QApplication::translate("settingStack", "Show the download quick Bar", 0, QApplication::UnicodeUTF8));
        createFolders->setText(QApplication::translate("settingStack", "Create different folders for Types", 0, QApplication::UnicodeUTF8));
        fileTypeControl->setText(QApplication::translate("settingStack", "File Types Control", 0, QApplication::UnicodeUTF8));
        headersControl->setText(QApplication::translate("settingStack", "Web Headers Control", 0, QApplication::UnicodeUTF8));
        homePageGB->setTitle(QApplication::translate("settingStack", "Use customed Start page instead of GlaucaStartPage", 0, QApplication::UnicodeUTF8));
        useBlankPage->setText(QApplication::translate("settingStack", "Blank Page", 0, QApplication::UnicodeUTF8));
        useCurrentPage->setText(QApplication::translate("settingStack", "Current Page", 0, QApplication::UnicodeUTF8));
        useLastSession->setText(QApplication::translate("settingStack", "Last Session", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("settingStack", "Dock Related", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("settingStack", "Set Mouse Moving Sensibility(1-100):", 0, QApplication::UnicodeUTF8));
        showSlider->setText(QApplication::translate("settingStack", "Show Quick View Slider", 0, QApplication::UnicodeUTF8));
        sortIconByTime->setText(QApplication::translate("settingStack", "Sort Icons by added time", 0, QApplication::UnicodeUTF8));
        sortIconByChanged->setText(QApplication::translate("settingStack", "Sort Icons by recently changed", 0, QApplication::UnicodeUTF8));
        sortDisabled->setText(QApplication::translate("settingStack", "Never Sort Icons", 0, QApplication::UnicodeUTF8));
        dockThemeSelector->setText(QApplication::translate("settingStack", "Theme Selector", 0, QApplication::UnicodeUTF8));
        quickSurfGB->setTitle(QApplication::translate("settingStack", "Enable Quick surf Mode", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("settingStack", "Action to Call Out Surf Panel:", 0, QApplication::UnicodeUTF8));
        qucikSurfCallOutCombo->clear();
        qucikSurfCallOutCombo->insertItems(0, QStringList()
         << QApplication::translate("settingStack", "Left Double Click", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("settingStack", "LeftClick+ Alt", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("settingStack", "LeftClick+Shift", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("settingStack", "LeftClick+Ctrl", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("settingStack", "RightDoubleClick", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("settingStack", "RightClick+Alt", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("settingStack", "RightClick+Shift", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("settingStack", "RightClick+Ctrl", 0, QApplication::UnicodeUTF8)
        );
        hideControlBar->setText(QApplication::translate("settingStack", "Hide Control Buttons,location Bar,etc.", 0, QApplication::UnicodeUTF8));
        notifierGB->setTitle(QApplication::translate("settingStack", "Enable Temp Notifier", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("settingStack", "PopUp Notifier At", 0, QApplication::UnicodeUTF8));
        notifierPosition->clear();
        notifierPosition->insertItems(0, QStringList()
         << QApplication::translate("settingStack", "Left-Top", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("settingStack", "Left-Buttom", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("settingStack", "Right-Top", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("settingStack", "Right-Buttom", 0, QApplication::UnicodeUTF8)
        );
        label_4->setText(QApplication::translate("settingStack", "And Stay for Seconds(1-5s)", 0, QApplication::UnicodeUTF8));
        popUpWhenStarted->setText(QApplication::translate("settingStack", "PopUp when Loading Started", 0, QApplication::UnicodeUTF8));
        popUpWhenFinished->setText(QApplication::translate("settingStack", "PopUp When Loading Finished", 0, QApplication::UnicodeUTF8));
        popUpForCurrent->setText(QApplication::translate("settingStack", "Also For Current Tab", 0, QApplication::UnicodeUTF8));
        groupBox_6->setTitle(QApplication::translate("settingStack", "Tab Mouse Clicking behavior", 0, QApplication::UnicodeUTF8));
        groupBox_7->setTitle(QApplication::translate("settingStack", "Left Click", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("settingStack", "Double", 0, QApplication::UnicodeUTF8));
        leftDoubleAct->clear();
        leftDoubleAct->insertItems(0, QStringList()
         << QApplication::translate("settingStack", "Close", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("settingStack", "Lock", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("settingStack", "Add BookMark", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("settingStack", "Private", 0, QApplication::UnicodeUTF8)
        );
        leftShiftAct->clear();
        leftShiftAct->insertItems(0, QStringList()
         << QApplication::translate("settingStack", "Close", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("settingStack", "Lock", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("settingStack", "Add BookMark", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("settingStack", "Private", 0, QApplication::UnicodeUTF8)
        );
        label_6->setText(QApplication::translate("settingStack", "Shift+", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("settingStack", "Ctrl+", 0, QApplication::UnicodeUTF8));
        leftCtrlAct->clear();
        leftCtrlAct->insertItems(0, QStringList()
         << QApplication::translate("settingStack", "Close", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("settingStack", "Lock", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("settingStack", "Add BookMark", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("settingStack", "Private", 0, QApplication::UnicodeUTF8)
        );
        label_8->setText(QApplication::translate("settingStack", "Alt+", 0, QApplication::UnicodeUTF8));
        leftAltAct->clear();
        leftAltAct->insertItems(0, QStringList()
         << QApplication::translate("settingStack", "Close", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("settingStack", "Lock", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("settingStack", "Add BookMark", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("settingStack", "Private", 0, QApplication::UnicodeUTF8)
        );
        groupBox_8->setTitle(QApplication::translate("settingStack", "Right Click", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("settingStack", "Double", 0, QApplication::UnicodeUTF8));
        rightDoubleAct->clear();
        rightDoubleAct->insertItems(0, QStringList()
         << QApplication::translate("settingStack", "Close", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("settingStack", "Lock", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("settingStack", "Add BookMark", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("settingStack", "Private", 0, QApplication::UnicodeUTF8)
        );
        rightShiftAct->clear();
        rightShiftAct->insertItems(0, QStringList()
         << QApplication::translate("settingStack", "Close", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("settingStack", "Lock", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("settingStack", "Add BookMark", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("settingStack", "Private", 0, QApplication::UnicodeUTF8)
        );
        label_10->setText(QApplication::translate("settingStack", "Shift+", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("settingStack", "Ctrl+", 0, QApplication::UnicodeUTF8));
        rightCtrlAct->clear();
        rightCtrlAct->insertItems(0, QStringList()
         << QApplication::translate("settingStack", "Close", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("settingStack", "Lock", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("settingStack", "Add BookMark", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("settingStack", "Private", 0, QApplication::UnicodeUTF8)
        );
        label_12->setText(QApplication::translate("settingStack", "Alt+", 0, QApplication::UnicodeUTF8));
        rightAltAct->clear();
        rightAltAct->insertItems(0, QStringList()
         << QApplication::translate("settingStack", "Close", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("settingStack", "Lock", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("settingStack", "Add BookMark", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("settingStack", "Private", 0, QApplication::UnicodeUTF8)
        );
        label_13->setText(QApplication::translate("settingStack", "Wheel Click", 0, QApplication::UnicodeUTF8));
        comboBox_12->clear();
        comboBox_12->insertItems(0, QStringList()
         << QApplication::translate("settingStack", "Close", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("settingStack", "Lock", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("settingStack", "Add BookMark", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("settingStack", "Private", 0, QApplication::UnicodeUTF8)
        );
        groupBox_9->setTitle(QApplication::translate("settingStack", "Look 'n Feel", 0, QApplication::UnicodeUTF8));
        showCloseBtn->setText(QApplication::translate("settingStack", "Show Close Tab Button", 0, QApplication::UnicodeUTF8));
        showNewTabBtn->setText(QApplication::translate("settingStack", "Show New Tab Button", 0, QApplication::UnicodeUTF8));
        showAllTabBtn->setText(QApplication::translate("settingStack", "Show All Tab Button", 0, QApplication::UnicodeUTF8));
        checkBox_12->setText(QApplication::translate("settingStack", "Tab TransParency(Not Usable Now)", 0, QApplication::UnicodeUTF8));
        tabAutoResize->setText(QApplication::translate("settingStack", "Auto Resize Tab Length", 0, QApplication::UnicodeUTF8));
        darkerTabs->setText(QApplication::translate("settingStack", "Darker UnActivated Tabs", 0, QApplication::UnicodeUTF8));
        linkInNewTab->setText(QApplication::translate("settingStack", "Always Open Link In New Tabs", 0, QApplication::UnicodeUTF8));
        preventAutoTabCreating->setText(QApplication::translate("settingStack", "Prevent WebSites from Automatically Creating Tabs", 0, QApplication::UnicodeUTF8));
        CloseWinWhenLastTabClosed->setText(QApplication::translate("settingStack", "Close Window When Last Tab Closed", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class settingStack: public Ui_settingStack {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGWINSTACK_H
