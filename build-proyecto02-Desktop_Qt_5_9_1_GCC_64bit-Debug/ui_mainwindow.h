/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QPushButton *btn_1;
    QLabel *lbl_img;
    QPushButton *btn_2;
    QLabel *label_2;
    QSlider *horizontalSlider_b;
    QLabel *label;
    QSlider *horizontalSlider_c;
    QLabel *lbl_h;
    QPushButton *pushButton_abrir;
    QPushButton *pushButton_Save;
    QPushButton *pushButton_Binarizar;
    QLabel *label_3;
    QSlider *horizontalSlider_e;
    QFrame *frame_2;
    QFrame *frame_5;
    QWidget *tab_2;
    QPushButton *open_img_A;
    QPushButton *open_img_B;
    QLabel *lbl_img_A;
    QLabel *lbl_img_B;
    QLabel *lbl_img_resultado;
    QFrame *frame;
    QLabel *label_5;
    QPushButton *pushButton_suma;
    QPushButton *pushButton_resta;
    QPushButton *pushButton_divicion;
    QPushButton *pushButton_por_a;
    QSlider *horizontalSlider_a;
    QFrame *frame_3;
    QFrame *frame_4;
    QWidget *tab_3;
    QLabel *lbl_img_m;
    QLabel *lbl_img_AA;
    QPushButton *pushButton_M;
    QPushButton *pushButton_AA;
    QLabel *lbl_img_D;
    QPushButton *pushButton_D;
    QPushButton *pushButton_U;
    QLabel *lbl_img_U;
    QLabel *lbl_img_F;
    QPushButton *pushButton_F;
    QLabel *lbl_img_R;
    QPushButton *pushButton_R;
    QTextBrowser *textBrowser;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1153, 821);
        MainWindow->setMinimumSize(QSize(1153, 821));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 1121, 781));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        btn_1 = new QPushButton(tab);
        btn_1->setObjectName(QStringLiteral("btn_1"));
        btn_1->setGeometry(QRect(20, 640, 89, 25));
        lbl_img = new QLabel(tab);
        lbl_img->setObjectName(QStringLiteral("lbl_img"));
        lbl_img->setGeometry(QRect(70, 130, 451, 341));
        btn_2 = new QPushButton(tab);
        btn_2->setObjectName(QStringLiteral("btn_2"));
        btn_2->setGeometry(QRect(420, 520, 89, 25));
        label_2 = new QLabel(tab);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(600, 90, 67, 17));
        horizontalSlider_b = new QSlider(tab);
        horizontalSlider_b->setObjectName(QStringLiteral("horizontalSlider_b"));
        horizontalSlider_b->setGeometry(QRect(590, 120, 160, 16));
        horizontalSlider_b->setMinimum(-255);
        horizontalSlider_b->setMaximum(255);
        horizontalSlider_b->setOrientation(Qt::Horizontal);
        label = new QLabel(tab);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(600, 40, 151, 17));
        horizontalSlider_c = new QSlider(tab);
        horizontalSlider_c->setObjectName(QStringLiteral("horizontalSlider_c"));
        horizontalSlider_c->setGeometry(QRect(590, 70, 160, 16));
        horizontalSlider_c->setMinimum(1);
        horizontalSlider_c->setMaximum(100);
        horizontalSlider_c->setValue(50);
        horizontalSlider_c->setOrientation(Qt::Horizontal);
        lbl_h = new QLabel(tab);
        lbl_h->setObjectName(QStringLiteral("lbl_h"));
        lbl_h->setGeometry(QRect(570, 270, 311, 261));
        lbl_h->setScaledContents(true);
        pushButton_abrir = new QPushButton(tab);
        pushButton_abrir->setObjectName(QStringLiteral("pushButton_abrir"));
        pushButton_abrir->setGeometry(QRect(60, 50, 89, 25));
        pushButton_Save = new QPushButton(tab);
        pushButton_Save->setObjectName(QStringLiteral("pushButton_Save"));
        pushButton_Save->setGeometry(QRect(70, 530, 89, 25));
        pushButton_Binarizar = new QPushButton(tab);
        pushButton_Binarizar->setObjectName(QStringLiteral("pushButton_Binarizar"));
        pushButton_Binarizar->setGeometry(QRect(590, 210, 89, 25));
        label_3 = new QLabel(tab);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(610, 150, 67, 17));
        horizontalSlider_e = new QSlider(tab);
        horizontalSlider_e->setObjectName(QStringLiteral("horizontalSlider_e"));
        horizontalSlider_e->setGeometry(QRect(590, 180, 160, 16));
        horizontalSlider_e->setMaximum(80);
        horizontalSlider_e->setSingleStep(2);
        horizontalSlider_e->setOrientation(Qt::Horizontal);
        frame_2 = new QFrame(tab);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setGeometry(QRect(40, 100, 491, 411));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        frame_5 = new QFrame(tab);
        frame_5->setObjectName(QStringLiteral("frame_5"));
        frame_5->setGeometry(QRect(560, 260, 361, 291));
        frame_5->setFrameShape(QFrame::StyledPanel);
        frame_5->setFrameShadow(QFrame::Raised);
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        open_img_A = new QPushButton(tab_2);
        open_img_A->setObjectName(QStringLiteral("open_img_A"));
        open_img_A->setGeometry(QRect(60, 40, 89, 25));
        open_img_B = new QPushButton(tab_2);
        open_img_B->setObjectName(QStringLiteral("open_img_B"));
        open_img_B->setGeometry(QRect(60, 300, 89, 25));
        lbl_img_A = new QLabel(tab_2);
        lbl_img_A->setObjectName(QStringLiteral("lbl_img_A"));
        lbl_img_A->setGeometry(QRect(20, 70, 261, 221));
        lbl_img_A->setStyleSheet(QStringLiteral(""));
        lbl_img_A->setScaledContents(true);
        lbl_img_B = new QLabel(tab_2);
        lbl_img_B->setObjectName(QStringLiteral("lbl_img_B"));
        lbl_img_B->setGeometry(QRect(30, 340, 251, 221));
        lbl_img_B->setScaledContents(true);
        lbl_img_resultado = new QLabel(tab_2);
        lbl_img_resultado->setObjectName(QStringLiteral("lbl_img_resultado"));
        lbl_img_resultado->setGeometry(QRect(610, 80, 481, 391));
        lbl_img_resultado->setScaledContents(true);
        frame = new QFrame(tab_2);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(330, 60, 120, 21));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        label_5 = new QLabel(frame);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 0, 101, 20));
        pushButton_suma = new QPushButton(tab_2);
        pushButton_suma->setObjectName(QStringLiteral("pushButton_suma"));
        pushButton_suma->setGeometry(QRect(340, 110, 89, 25));
        pushButton_resta = new QPushButton(tab_2);
        pushButton_resta->setObjectName(QStringLiteral("pushButton_resta"));
        pushButton_resta->setGeometry(QRect(340, 150, 89, 25));
        pushButton_divicion = new QPushButton(tab_2);
        pushButton_divicion->setObjectName(QStringLiteral("pushButton_divicion"));
        pushButton_divicion->setGeometry(QRect(340, 190, 89, 25));
        pushButton_por_a = new QPushButton(tab_2);
        pushButton_por_a->setObjectName(QStringLiteral("pushButton_por_a"));
        pushButton_por_a->setGeometry(QRect(340, 230, 89, 25));
        horizontalSlider_a = new QSlider(tab_2);
        horizontalSlider_a->setObjectName(QStringLiteral("horizontalSlider_a"));
        horizontalSlider_a->setGeometry(QRect(310, 260, 231, 16));
        horizontalSlider_a->setMaximum(100);
        horizontalSlider_a->setPageStep(1);
        horizontalSlider_a->setOrientation(Qt::Horizontal);
        frame_3 = new QFrame(tab_2);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        frame_3->setGeometry(QRect(10, 70, 301, 221));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        frame_4 = new QFrame(tab_2);
        frame_4->setObjectName(QStringLiteral("frame_4"));
        frame_4->setGeometry(QRect(10, 330, 311, 251));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        lbl_img_m = new QLabel(tab_3);
        lbl_img_m->setObjectName(QStringLiteral("lbl_img_m"));
        lbl_img_m->setGeometry(QRect(20, 80, 231, 231));
        lbl_img_m->setScaledContents(true);
        lbl_img_AA = new QLabel(tab_3);
        lbl_img_AA->setObjectName(QStringLiteral("lbl_img_AA"));
        lbl_img_AA->setGeometry(QRect(20, 380, 231, 211));
        lbl_img_AA->setScaledContents(true);
        pushButton_M = new QPushButton(tab_3);
        pushButton_M->setObjectName(QStringLiteral("pushButton_M"));
        pushButton_M->setGeometry(QRect(50, 20, 89, 25));
        pushButton_AA = new QPushButton(tab_3);
        pushButton_AA->setObjectName(QStringLiteral("pushButton_AA"));
        pushButton_AA->setGeometry(QRect(50, 320, 89, 25));
        lbl_img_D = new QLabel(tab_3);
        lbl_img_D->setObjectName(QStringLiteral("lbl_img_D"));
        lbl_img_D->setGeometry(QRect(260, 50, 221, 231));
        lbl_img_D->setScaledContents(true);
        pushButton_D = new QPushButton(tab_3);
        pushButton_D->setObjectName(QStringLiteral("pushButton_D"));
        pushButton_D->setGeometry(QRect(318, 10, 121, 25));
        pushButton_U = new QPushButton(tab_3);
        pushButton_U->setObjectName(QStringLiteral("pushButton_U"));
        pushButton_U->setGeometry(QRect(340, 310, 89, 25));
        lbl_img_U = new QLabel(tab_3);
        lbl_img_U->setObjectName(QStringLiteral("lbl_img_U"));
        lbl_img_U->setGeometry(QRect(280, 380, 211, 211));
        lbl_img_U->setScaledContents(true);
        lbl_img_F = new QLabel(tab_3);
        lbl_img_F->setObjectName(QStringLiteral("lbl_img_F"));
        lbl_img_F->setGeometry(QRect(590, 50, 211, 231));
        lbl_img_F->setScaledContents(true);
        pushButton_F = new QPushButton(tab_3);
        pushButton_F->setObjectName(QStringLiteral("pushButton_F"));
        pushButton_F->setGeometry(QRect(660, 10, 89, 25));
        lbl_img_R = new QLabel(tab_3);
        lbl_img_R->setObjectName(QStringLiteral("lbl_img_R"));
        lbl_img_R->setGeometry(QRect(580, 370, 221, 231));
        lbl_img_R->setScaledContents(true);
        pushButton_R = new QPushButton(tab_3);
        pushButton_R->setObjectName(QStringLiteral("pushButton_R"));
        pushButton_R->setGeometry(QRect(650, 330, 89, 25));
        textBrowser = new QTextBrowser(tab_3);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(330, 340, 121, 31));
        tabWidget->addTab(tab_3, QString());
        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        btn_1->setText(QApplication::translate("MainWindow", "Equalizar", Q_NULLPTR));
        lbl_img->setText(QString());
        btn_2->setText(QApplication::translate("MainWindow", "Equalizar2", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Brillo:", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Contraste:", Q_NULLPTR));
        lbl_h->setText(QString());
        pushButton_abrir->setText(QApplication::translate("MainWindow", "Abrir", Q_NULLPTR));
        pushButton_Save->setText(QApplication::translate("MainWindow", "Guardar", Q_NULLPTR));
        pushButton_Binarizar->setText(QApplication::translate("MainWindow", "Binarizar", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "Ecualizar", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Tab 1", Q_NULLPTR));
        open_img_A->setText(QApplication::translate("MainWindow", "Imagen A", Q_NULLPTR));
        open_img_B->setText(QApplication::translate("MainWindow", "Imagen B", Q_NULLPTR));
        lbl_img_A->setText(QString());
        lbl_img_B->setText(QString());
        lbl_img_resultado->setText(QString());
        label_5->setText(QApplication::translate("MainWindow", "OPERACIONES", Q_NULLPTR));
        pushButton_suma->setText(QApplication::translate("MainWindow", " A+B", Q_NULLPTR));
        pushButton_resta->setText(QApplication::translate("MainWindow", " A-B", Q_NULLPTR));
        pushButton_divicion->setText(QApplication::translate("MainWindow", "(A+B)/2", Q_NULLPTR));
        pushButton_por_a->setText(QApplication::translate("MainWindow", "a*A+(1-a)*B", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Tab 2", Q_NULLPTR));
        lbl_img_m->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        lbl_img_AA->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        pushButton_M->setText(QApplication::translate("MainWindow", "Abrir M", Q_NULLPTR));
        pushButton_AA->setText(QApplication::translate("MainWindow", "Abrir AA", Q_NULLPTR));
        lbl_img_D->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        pushButton_D->setText(QApplication::translate("MainWindow", "Calcula D = M-A", Q_NULLPTR));
        pushButton_U->setText(QApplication::translate("MainWindow", "Calcular U", Q_NULLPTR));
        lbl_img_U->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        lbl_img_F->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        pushButton_F->setText(QApplication::translate("MainWindow", "Abrir F", Q_NULLPTR));
        lbl_img_R->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        pushButton_R->setText(QApplication::translate("MainWindow", "R", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "Tarea 3", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
