#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QFileDialog>
#include <QWidget>


#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
using namespace std;
using namespace cv;


#include <bits/stdc++.h>

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector< Mat > v_mat;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    string ruta_img_1="/home/christian/Documentos/T_Grafica/lena.bmp";
    string ruta_img_1_temp="/home/christian/Documentos/T_Grafica/lena.bmp";

    string ruta_img_1_A="/home/christian/Documentos/T_Grafica/lena.bmp";
    string ruta_img_1_B="/home/christian/Documentos/T_Grafica/lena.bmp";
    Mat M_img_A;
    Mat M_img_B;

    bool bi=false;
    bool ecu=false;
    vvi histograma_RGB;
    Mat M_img_1=imread(ruta_img_1);
    Mat M_img_1_temp;
    Mat M_img_1_temp_c;
    Mat M_img_1_temp_b;
    Mat M_img_1_temp_bi;
    Mat M_img;

    string ruta_img_M="/home/christian/Documentos/T_Grafica/img_m.bmp";
    string ruta_img_AA="/home/christian/Documentos/T_Grafica/img_aa.bmp";
    string ruta_img_F="/home/christian/Documentos/T_Grafica/img_f.bmp";

    Mat M_img_M=imread(ruta_img_M);
    Mat M_img_AA=imread(ruta_img_AA);
    Mat M_img_F=imread(ruta_img_F);
    Mat U;
    Mat D;
    Mat R;

public slots:
    void actualizar(Mat Mimg);
    void DisplayImage();
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QImage imdisplay;
    QTimer* Timer;

private slots:

    void on_horizontalSlider_c_sliderMoved(int position);

    void on_horizontalSlider_b_sliderMoved(int position);

    void on_pushButton_clicked();

    void on_btn_2_clicked(bool checked);



    void on_pushButton_abrir_clicked();

    void on_pushButton_Save_clicked();

    void on_pushButton_Binarizar_clicked();


    void on_horizontalSlider_e_sliderMoved(int position);

    void on_open_img_A_clicked();

    void on_open_img_B_clicked();

    void on_pushButton_suma_clicked();

    void on_pushButton_resta_clicked();

    void on_pushButton_divicion_clicked();


    void on_horizontalSlider_a_sliderMoved(int position);

    void on_pushButton_M_clicked();

    void on_pushButton_AA_clicked();

    void on_pushButton_F_clicked();

    void on_pushButton_D_clicked();

    void on_pushButton_U_clicked();

    void on_pushButton_R_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
