#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include <opencv2/opencv.hpp>
#include "opencv2/imgproc/imgproc.hpp"
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <QMainWindow>

#include <QFileDialog>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/types_c.h>
#include <bits/stdc++.h>





using namespace std;
using namespace cv;

#define see(X) cout<<#X<<" "<<X<<endl;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<float> vf;
typedef vector<vf> vvf;

/****************************************************************************************************/

vvi get_histo(Mat &image){
    vvi hist_RGB(3);
    hist_RGB[0].resize(256);
    hist_RGB[1].resize(256);
    hist_RGB[2].resize(256);
    int val_color;
    for( int y = 0; y < image.rows; y++ ){
        for( int x = 0; x < image.cols; x++ ){
            for (int c = 0; c < 3; ++c) {
               val_color = image.at<Vec3b>(y,x)[c];
               ++hist_RGB[c][val_color];
            }
        }
    }
    return hist_RGB;
}


//ecualizacion
Mat equalize(Mat &image, vvi hist_RGB, int value){
    //maximos por canal del histograma RGB
    vi max_values_RGB(3);
    for (int c = 0; c < 3; ++c) {
        for (int i = 0; i < 256; ++i) {
            max_values_RGB[c] = max(max_values_RGB[c], hist_RGB[c][i]);
        }
    }
    see("mejores")
    see(max_values_RGB[0]);
    see(max_values_RGB[1]);
    see(max_values_RGB[2]);

    //value porcentajes
    vi val_RGB(3);
    for (int c = 0; c < 3; ++c) {
        val_RGB[c] = (max_values_RGB[c]*value)/100;
    }
    //calcular poscion min m, max M
    vi m_rgb(3), flag_m_rgb(3,1);
    vi M_rgb(3), flag_M_rgb(3,1);
    for (int c = 0; c < 3; ++c) {
        for (int i = 0; i < 255; ++i) {
            if( hist_RGB[c][i] > val_RGB[c] && flag_m_rgb[c] ){//mayor que el %
                m_rgb[c]=i;
                flag_m_rgb[c]=0;
            }
            if( hist_RGB[c][255-i] > val_RGB[c] && flag_M_rgb[c] ){//mayor que el %
                M_rgb[c]=255-i;
                flag_M_rgb[c]=0;
            }
        }
    }
    for (int i = 0; i < 3; ++i) {
        see(m_rgb[i]);
        see(M_rgb[i]);
    }
    //contruir imagen FORMULA
    Mat new_image = Mat::zeros( image.size(), image.type() );
    for( int y = 0; y < image.rows; y++ ){
        for( int x = 0; x < image.cols; x++ ){
            for( int c = 0; c < 3; c++ ){
                new_image.at<Vec3b>(y,x)[c] = saturate_cast<uchar>( (image.at<Vec3b>(y,x)[c]-m_rgb[c])*(255/(M_rgb[c]-m_rgb[c]) ) );
            }
        }
    }
    return new_image;
}



/*************************************************/
Mat brillo(Mat image, int value){
    Mat new_image = Mat::zeros( image.size(), image.type() );
    for( int y = 0; y < image.rows; y++ ){
        for( int x = 0; x < image.cols; x++ ){
            for( int c = 0; c < 3; c++ ){
                new_image.at<Vec3b>(y,x)[c] = saturate_cast<uchar>( image.at<Vec3b>(y,x)[c] + value );
            }
        }
    }
    return new_image;

}

Mat contraste(Mat image, int value){
    float val = (value*2.0)/100.0;
    //float beta = 50-value;

    Mat new_image = Mat::zeros( image.size(), image.type() );
    for( int y = 0; y < image.rows; y++ ){
        for( int x = 0; x < image.cols; x++ ){
            for( int c = 0; c < 3; c++ ){
                new_image.at<Vec3b>(y,x)[c] = saturate_cast<uchar>( (image.at<Vec3b>(y,x)[c] * val) );
                //new_image.at<Vec3b>(y,x)[c] = saturate_cast<uchar>( (image.at<Vec3b>(y,x)[c] * val)+beta );
            }
        }
    }
    return new_image;

}
Mat Binarizar(Mat &image, int value){
    Mat new_image = Mat::zeros( image.size(), image.type() );
    for( int y = 0; y < image.rows; y++ ){
        for( int x = 0; x < image.cols; x++ ){
            int temp=0;
            for( int c = 0; c < 3; c++ ){
                temp+=image.at<Vec3b>(y,x)[c];
            }
            for( int c = 0; c < 3; c++ ){
                new_image.at<Vec3b>(y,x)[c] = saturate_cast<uchar>( temp/3 );
            }
        }
    }
    return new_image;
}


Mat Binarizar_u(Mat &image, int value){
    Mat new_image = Mat::zeros( image.size(), image.type() );
    for( int y = 0; y < image.rows; y++ ){
        for( int x = 0; x < image.cols; x++ ){
            int temp=0;
            for( int c = 0; c < 3; c++ ){
                temp+=image.at<Vec3b>(y,x)[c];
            }
            for( int c = 0; c < 3; c++ ){
                int u = temp/3;
                if(u>value) new_image.at<Vec3b>(y,x)[c] = saturate_cast<uchar>( 255 );
                else new_image.at<Vec3b>(y,x)[c] = saturate_cast<uchar>( 0 );
                //new_image.at<Vec3b>(y,x)[c] = saturate_cast<uchar>( temp/3 );
            }
        }
    }
    return new_image;
}

Mat negacion(Mat &image_A){
    Mat new_image = Mat::zeros( image_A.size(), image_A.type() );
    for( int y = 0; y < image_A.rows; y++ ){
        for( int x = 0; x < image_A.cols; x++ ){
            for( int c = 0; c < 3; c++ ){
                new_image.at<Vec3b>(y,x)[c] = saturate_cast<uchar>(255 - image_A.at<Vec3b>(y,x)[c]);
            }
        }
    }
   return new_image;
}

Mat ope_and(Mat &image_A, Mat &image_B){
    Mat new_image = Mat::zeros( image_A.size(), image_A.type() );
    for( int y = 0; y < image_A.rows; y++ ){
        for( int x = 0; x < image_A.cols; x++ ){
            for( int c = 0; c < 3; c++ ){
                new_image.at<Vec3b>(y,x)[c] = saturate_cast<uchar>( image_A.at<Vec3b>(y,x)[c]*image_B.at<Vec3b>(y,x)[c]/255 );
            }
        }
    }
   return new_image;
}
Mat ope_or(Mat &image_A, Mat &image_B){
    Mat new_image = Mat::zeros( image_A.size(), image_A.type() );
    for( int y = 0; y < image_A.rows; y++ ){
        for( int x = 0; x < image_A.cols; x++ ){
            for( int c = 0; c < 3; c++ ){
                new_image.at<Vec3b>(y,x)[c] = saturate_cast<uchar>( (image_A.at<Vec3b>(y,x)[c]+image_B.at<Vec3b>(y,x)[c])%255 );
            }
        }
    }
   return new_image;
}

Mat suma_AB(Mat &image_A, Mat &image_B){
    Mat new_image = Mat::zeros( image_A.size(), image_A.type() );
    for( int y = 0; y < image_A.rows; y++ ){
        for( int x = 0; x < image_A.cols; x++ ){
            for( int c = 0; c < 3; c++ ){
                new_image.at<Vec3b>(y,x)[c] = saturate_cast<uchar>( image_A.at<Vec3b>(y,x)[c] + image_B.at<Vec3b>(y,x)[c]);
            }
        }
    }
   return new_image;
}
Mat resta_AB(Mat &image_A, Mat &image_B){
    Mat new_image = Mat::zeros( image_A.size(), image_A.type() );
    for( int y = 0; y < image_A.rows; y++ ){
        for( int x = 0; x < image_A.cols; x++ ){
            for( int c = 0; c < 3; c++ ){
                new_image.at<Vec3b>(y,x)[c] = saturate_cast<uchar>( image_A.at<Vec3b>(y,x)[c] - image_B.at<Vec3b>(y,x)[c]);
            }
        }
    }
   return new_image;
}
Mat divicion(Mat &image_A, Mat &image_B){
    Mat new_image = Mat::zeros( image_A.size(), image_A.type() );
    for( int y = 0; y < image_A.rows; y++ ){
        for( int x = 0; x < image_A.cols; x++ ){
            for( int c = 0; c < 3; c++ ){
                new_image.at<Vec3b>(y,x)[c] = saturate_cast<uchar>( (image_A.at<Vec3b>(y,x)[c] + image_B.at<Vec3b>(y,x)[c])/2 );
            }
        }
    }
   return new_image;
}

Mat suma_a(Mat &image_A, Mat &image_B, float a){
    Mat new_image = Mat::zeros( image_A.size(), image_A.type() );
    for( int y = 0; y < image_A.rows; y++ ){
        for( int x = 0; x < image_A.cols; x++ ){
            for( int c = 0; c < 3; c++ ){
                new_image.at<Vec3b>(y,x)[c] = saturate_cast<uchar>( a*(image_A.at<Vec3b>(y,x)[c]) + (1.0-a)*(image_B.at<Vec3b>(y,x)[c]) );
            }
        }
    }
   return new_image;
}




Mat get_histograma(Mat src){
    //Mat src;
    /// Load image
    //src = imread( ruta_imagen );
    //if( !src.data ){ return -1; }
    /// Separate the image in 3 places ( B, G and R )
    vector<Mat> bgr_planes;
    split( src, bgr_planes );
    /// Establish the number of bins
    int histSize = 256;
    /// Set the ranges ( for B,G,R) )
    float range[] = { 0, 256 } ;
    const float* histRange = { range };
    bool uniform = true; bool accumulate = false;
    Mat b_hist, g_hist, r_hist;
    /// Compute the histograms:
    calcHist( &bgr_planes[0], 1, 0, Mat(), b_hist, 1, &histSize, &histRange, uniform, accumulate );
    calcHist( &bgr_planes[1], 1, 0, Mat(), g_hist, 1, &histSize, &histRange, uniform, accumulate );
    calcHist( &bgr_planes[2], 1, 0, Mat(), r_hist, 1, &histSize, &histRange, uniform, accumulate );
    // Draw the histograms for B, G and R
    int hist_w = 512;//512;
    int hist_h = 400;
    int bin_w = cvRound( (double) hist_w/histSize );
    Mat histImage( hist_h, hist_w, CV_8UC3, Scalar( 0,0,0) );
    /// Normalize the result to [ 0, histImage.rows ]
    normalize(b_hist, b_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat() );
    normalize(g_hist, g_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat() );
    normalize(r_hist, r_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat() );
    /// Draw for each channel
    for( int i = 1; i < histSize; i++ ){
            line( histImage, Point( bin_w*(i-1), hist_h - cvRound(b_hist.at<float>(i-1)) ) ,
                                             Point( bin_w*(i), hist_h - cvRound(b_hist.at<float>(i)) ),
                                             Scalar( 255, 0, 0), 2, 8, 0  );
            line( histImage, Point( bin_w*(i-1), hist_h - cvRound(g_hist.at<float>(i-1)) ) ,
                                             Point( bin_w*(i), hist_h - cvRound(g_hist.at<float>(i)) ),
                                             Scalar( 0, 255, 0), 2, 8, 0  );
            line( histImage, Point( bin_w*(i-1), hist_h - cvRound(r_hist.at<float>(i-1)) ) ,
                                             Point( bin_w*(i), hist_h - cvRound(r_hist.at<float>(i)) ),
                                             Scalar( 0, 0, 255), 2, 8, 0  );
    }
    return histImage;
    // Display
    //namedWindow("calcHist Demo", CV_WINDOW_AUTOSIZE );
    //imshow("calcHist Demo", histImage );
    //waitKey(0);
}


/*
v_mat histo_RGB(Mat src){

    v_mat h[3];

    vector<Mat> bgr_planes;
    split( src, bgr_planes );
    /// Establish the number of bins
    int histSize = 256;
    // Set the ranges ( for B,G,R) )
    float range[] = { 0, 256 } ;
    const float* histRange = { range };
    bool uniform = true; bool accumulate = false;
    Mat b_hist, g_hist, r_hist;
    // Compute the histograms:
    calcHist( &bgr_planes[0], 1, 0, Mat(), b_hist, 1, &histSize, &histRange, uniform, accumulate );
    calcHist( &bgr_planes[1], 1, 0, Mat(), g_hist, 1, &histSize, &histRange, uniform, accumulate );
    calcHist( &bgr_planes[2], 1, 0, Mat(), r_hist, 1, &histSize, &histRange, uniform, accumulate );
    // Draw the histograms for B, G and R
    int hist_w = 512;//512;
    int hist_h = 400;
    int bin_w = cvRound( (double) hist_w/histSize );
    Mat histImage( hist_h, hist_w, CV_8UC3, Scalar( 0,0,0) );
    Mat histImage_G( hist_h, hist_w, CV_8UC3, Scalar( 0,0,0) );
    Mat histImage_B( hist_h, hist_w, CV_8UC3, Scalar( 0,0,0) );
    /// Normalize the result to [ 0, histImage.rows ]
    normalize(b_hist, b_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat() );
    normalize(g_hist, g_hist, 0, histImage_G.rows, NORM_MINMAX, -1, Mat() );
    normalize(r_hist, r_hist, 0, histImage_B.rows, NORM_MINMAX, -1, Mat() );
    /// Draw for each channel
    for( int i = 1; i < histSize; i++ ){
            line( histImage, Point( bin_w*(i-1), hist_h - cvRound(b_hist.at<float>(i-1)) ) ,
                                             Point( bin_w*(i), hist_h - cvRound(b_hist.at<float>(i)) ),
                                             Scalar( 255, 0, 0), 2, 8, 0  );
            line( histImage_G, Point( bin_w*(i-1), hist_h - cvRound(g_hist.at<float>(i-1)) ) ,
                                             Point( bin_w*(i), hist_h - cvRound(g_hist.at<float>(i)) ),
                                             Scalar( 0, 255, 0), 2, 8, 0  );
            line( histImage_B, Point( bin_w*(i-1), hist_h - cvRound(r_hist.at<float>(i-1)) ) ,
                                             Point( bin_w*(i), hist_h - cvRound(r_hist.at<float>(i)) ),
                                             Scalar( 0, 0, 255), 2, 8, 0  );
    }
    h[0] = histImage;
    h[1] = histImage_G;
    h[2] = histImage_B;
    return h;

}
*/

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Mat img = imread("/home/christian/Documentos/T_Grafica/lena.bmp");
    //Mat img2;
    //cvResize(img, img2, Size(100,100));
    cvtColor(img,img,CV_BGR2RGB);
    QImage imdisplay((uchar*)img.data, img.cols, img.rows, img.step, QImage::Format_RGB888);
    ui->lbl_img->setPixmap(QPixmap::fromImage(imdisplay));

    //EQUALIZAR

}

MainWindow::~MainWindow()
{
    delete ui;
}

/***********************************************************/

void MainWindow::DisplayImage(){
    Mat img = imread("/home/christian/Documentos/T_Grafica/lena.bmp");
    Mat img2;
 /*   //cvResize(img, img2, Size(100,100));
    cvtColor(img,img,CV_BGR2RGB);
    QImage imdisplay((uchar*)img.data, img.cols, img.rows, img.step, QImage::Format_RGB888);
    ui->display_image->setPixmap(QPixmap::fromImage(imdisplay));
*/
    Mat Mimg = imread("/home/christian/Documentos/T_Grafica/lena.bmp");

    QImage image((uchar*)img.data, img.cols, img.rows, img.step, QImage::Format_RGB888);
    ui->lbl_img->setPixmap(QPixmap::fromImage(image));
}



void MainWindow::on_horizontalSlider_c_sliderMoved(int position)
{
    if(bi==true){
        //Mat Mimg = imread("/home/christian/Documentos/T_Grafica/lena.bmp");
        if(M_img_1_temp_c.rows< 1) M_img_1_temp_c = M_img_1_temp_bi;
        else{
            M_img_1_temp_c = M_img_1_temp_bi;
        }
        //M_img_1_temp = M_img_1;
        //Mat img = contraste(Mimg ,position);
        //Mat img = contraste(M_img_1_temp ,position);
        M_img_1_temp = contraste(M_img_1_temp_c ,position);
        actualizar(M_img_1_temp);
        /*

        cvtColor(M_img_1_temp,M_img_1_temp,CV_BGR2RGB);
        QImage image((uchar*)M_img_1_temp.data, M_img_1_temp.cols, M_img_1_temp.rows, M_img_1_temp.step, QImage::Format_RGB888);
        ui->lbl_img->setPixmap(QPixmap::fromImage(image));*/
    }
    else{
        //Mat Mimg = imread("/home/christian/Documentos/T_Grafica/lena.bmp");
        if(M_img_1_temp_c.rows< 1) M_img_1_temp_c = M_img_1;
        else{
            M_img_1_temp_c = M_img_1;
        }
        //M_img_1_temp = M_img_1;
        //Mat img = contraste(Mimg ,position);
        //Mat img = contraste(M_img_1_temp ,position);
        M_img_1_temp = contraste(M_img_1_temp_c ,position);
        //QImage image = MatToQImage(Mimg2);
        actualizar(M_img_1_temp);
        /*
        cvtColor(M_img_1_temp,M_img_1_temp,CV_BGR2RGB);
        QImage image((uchar*)M_img_1_temp.data, M_img_1_temp.cols, M_img_1_temp.rows, M_img_1_temp.step, QImage::Format_RGB888);
        ui->lbl_img->setPixmap(QPixmap::fromImage(image));
        */
    }
}
/***************************************************************/

void MainWindow::actualizar(Mat Mimg){

    Mat img_act = Mimg;
    cvtColor(img_act,img_act,CV_BGR2RGB);
    QImage image((uchar*)img_act.data, img_act.cols, img_act.rows, img_act.step, QImage::Format_RGB888);
    ui->lbl_img->setPixmap(QPixmap::fromImage(image));


    Mat img = get_histograma(Mimg);

    cvtColor(img,img,CV_BGR2RGB);
    QImage hist((uchar*)img.data, img.cols, img.rows, img.step, QImage::Format_RGB888);
    ui->lbl_h->setPixmap(QPixmap::fromImage(hist));
}

void MainWindow::on_horizontalSlider_b_sliderMoved(int position)
{


    if(bi==true){
        if(M_img_1_temp_c.rows<1) M_img_1_temp_b = M_img_1_temp_bi;
        else{
            M_img_1_temp_b = M_img_1_temp_bi;
        }

        M_img_1_temp = brillo(M_img_1_temp_b ,position);
        actualizar(M_img_1_temp);

    }
    else{
        if(M_img_1_temp_c.rows<1) M_img_1_temp_b = M_img_1;
        else{
            M_img_1_temp_b = M_img_1;
        }
        //Mat Mimg = imread("/home/christian/Documentos/T_Grafica/lena.bmp");
        //Mat img = brillo(Mimg ,position);
        M_img_1_temp = brillo(M_img_1_temp_b ,position);
        actualizar(M_img_1_temp);
        /*
        //QImage image = MatToQImage(Mimg2);
        cvtColor(M_img_1_temp,M_img_1_temp,CV_BGR2RGB);
        QImage image((uchar*)M_img_1_temp.data, M_img_1_temp.cols, M_img_1_temp.rows, M_img_1_temp.step, QImage::Format_RGB888);
        ui->lbl_img->setPixmap(QPixmap::fromImage(image));
        */
    }
}

void MainWindow::on_pushButton_clicked()
{/*
    //Mat Mimg = imread("/home/christian/Documentos/T_Grafica/lena.bmp");
    Mat img = brillo(Mimg ,position);
    //QImage image = MatToQImage(Mimg2);
    cvtColor(img,img,CV_BGR2RGB);
    QImage image((uchar*)img.data, img.cols, img.rows, img.step, QImage::Format_RGB888);
    ui->lbl_img->setPixmap(QPixmap::fromImage(image));
*/
    Mat image = imread("/home/christian/Documentos/T_Grafica/lena.bmp");

        // Check for failure


        //Convert the image from BGR to YCrCb color space
        Mat hist_equalized_image;
        cvtColor(image, hist_equalized_image, COLOR_BGR2YCrCb);

        //Split the image into 3 channels; Y, Cr and Cb channels respectively and store it in a std::vector
        vector<Mat> vec_channels;
        split(hist_equalized_image, vec_channels);

        //Equalize the histogram of only the Y channel
        equalizeHist(vec_channels[0], vec_channels[0]);

        //Merge 3 channels in the vector to form the color image in YCrCB color space.
        merge(vec_channels, hist_equalized_image);

        //Convert the histogram equalized image from YCrCb to BGR color space again
//        cvtColor(hist_equalized_image, hist_equalized_image, COLOR_YCrCb2BGR);
        cvtColor(hist_equalized_image, hist_equalized_image, COLOR_YCrCb2RGB);

        //mat img;
        //cvtColor(img,img,CV_BGR2RGB);
        QImage image2((uchar*)hist_equalized_image.data, hist_equalized_image.cols, hist_equalized_image.rows, hist_equalized_image.step, QImage::Format_RGB888);
        ui->lbl_img->setPixmap(QPixmap::fromImage(image2));
        cout<<"hola"<<endl;

/*
        //Define the names of windows
        String windowNameOfOriginalImage = "Original Image";
        String windowNameOfHistogramEqualized = "Histogram Equalized Color Image";

        // Create windows with the above names
        namedWindow(windowNameOfOriginalImage, WINDOW_NORMAL);
        namedWindow(windowNameOfHistogramEqualized, WINDOW_NORMAL);

        // Show images inside the created windows.
        imshow(windowNameOfOriginalImage, image);
        imshow(windowNameOfHistogramEqualized, hist_equalized_image);

        waitKey(0); // Wait for any keystroke in any one of the windows

        destroyAllWindows(); //Destroy all opened windows

        return 0;*/
}

void MainWindow::on_btn_2_clicked(bool checked)
{
    Mat image = imread("/home/christian/Documentos/T_Grafica/lena.bmp");

        // Check for failure


        //Convert the image from BGR to YCrCb color space
        Mat hist_equalized_image;
        cvtColor(image, hist_equalized_image, COLOR_BGR2YCrCb);

        //Split the image into 3 channels; Y, Cr and Cb channels respectively and store it in a std::vector
        vector<Mat> vec_channels;
        split(hist_equalized_image, vec_channels);

        //Equalize the histogram of only the Y channel
        equalizeHist(vec_channels[0], vec_channels[0]);

        //Merge 3 channels in the vector to form the color image in YCrCB color space.
        merge(vec_channels, hist_equalized_image);


        cvtColor(hist_equalized_image, hist_equalized_image, COLOR_YCrCb2RGB);

        //mat img;
        //cvtColor(img,img,CV_BGR2RGB);
        QImage image2((uchar*)hist_equalized_image.data, hist_equalized_image.cols, hist_equalized_image.rows, hist_equalized_image.step, QImage::Format_RGB888);
        ui->lbl_img->setPixmap(QPixmap::fromImage(image2));
        cout<<"hola"<<endl;
        ////********************************************************************************/////////

        Mat src, dst;

          /// Load image
          src = imread("/home/christian/Documentos/T_Grafica/lena.bmp");


          /// Separate the image in 3 places ( B, G and R )
          vector<Mat> bgr_planes;
          split( src, bgr_planes );

          /// Establish the number of bins
          int histSize = 256;

          /// Set the ranges ( for B,G,R) )
          float range[] = { 0, 256 } ;
          const float* histRange = { range };

          bool uniform = true; bool accumulate = false;

          Mat b_hist, g_hist, r_hist;

          /// Compute the histograms:
          calcHist( &bgr_planes[0], 1, 0, Mat(), b_hist, 1, &histSize, &histRange, uniform, accumulate );
          calcHist( &bgr_planes[1], 1, 0, Mat(), g_hist, 1, &histSize, &histRange, uniform, accumulate );
          calcHist( &bgr_planes[2], 1, 0, Mat(), r_hist, 1, &histSize, &histRange, uniform, accumulate );

          // Draw the histograms for B, G and R
          int hist_w = 512; int hist_h = 400;
          int bin_w = cvRound( (double) hist_w/histSize );

          Mat histImage( hist_h, hist_w, CV_8UC3, Scalar( 0,0,0) );

          /// Normalize the result to [ 0, histImage.rows ]
          normalize(b_hist, b_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat() );
          normalize(g_hist, g_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat() );
          normalize(r_hist, r_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat() );

          /// Draw for each channel
          for( int i = 1; i < histSize; i++ )
          {
              line( histImage, Point( bin_w*(i-1), hist_h - cvRound(b_hist.at<float>(i-1)) ) ,
                               Point( bin_w*(i), hist_h - cvRound(b_hist.at<float>(i)) ),
                               Scalar( 255, 0, 0), 2, 8, 0  );
              line( histImage, Point( bin_w*(i-1), hist_h - cvRound(g_hist.at<float>(i-1)) ) ,
                               Point( bin_w*(i), hist_h - cvRound(g_hist.at<float>(i)) ),
                               Scalar( 0, 255, 0), 2, 8, 0  );
              line( histImage, Point( bin_w*(i-1), hist_h - cvRound(r_hist.at<float>(i-1)) ) ,
                               Point( bin_w*(i), hist_h - cvRound(r_hist.at<float>(i)) ),
                               Scalar( 0, 0, 255), 2, 8, 0  );
          }

          //ui->lbl_h->setPixmap(QPixmap::fromImage(histImage));

          cvtColor(histImage,histImage,CV_BGR2RGB);
          QImage image3((uchar*)histImage.data, histImage.cols, histImage.rows, histImage.step, QImage::Format_RGB888);
          ui->lbl_h->setPixmap(QPixmap::fromImage(image3));


          //ui->lbl_img->setPixmap(QPixmap::fromImage(image2));
          // Display
         // namedWindow("calcHist Demo", CV_WINDOW_AUTOSIZE );
          //imshow("calcHist Demo", histImage );



}

void MainWindow::on_pushButton_abrir_clicked()
{
    //QString rutaImagen = Q
    QString rutaImagen = QFileDialog::getOpenFileName(this, tr("Abrir imagen"), QString(),
    tr("Images ( *.png *.bmp *.jpg)"));
    ruta_img_1 = rutaImagen.toUtf8().constData();
    M_img_1_temp = imread(ruta_img_1);
    M_img_1 = M_img_1_temp;

    actualizar(M_img_1_temp);
}

void MainWindow::on_pushButton_Save_clicked()
{
    Mat gray_image;
    cvtColor( M_img_1_temp, gray_image, CV_BGR2GRAY );

    imwrite( "/home/christian/Documentos/T_Grafica/Gray_Image.bmp", gray_image );
}

void MainWindow::on_pushButton_Binarizar_clicked()
{
    bi=true;
    //M_img_temp = Binarizar(M_img ,1);
    M_img_1_temp_bi = Binarizar(M_img_1_temp ,1);

    actualizar(M_img_1_temp_bi);
    /*cvtColor(M_img_1_temp_bi,M_img_1_temp_bi,CV_BGR2RGB);
    QImage image((uchar*)M_img_1_temp_bi.data, M_img_1_temp_bi.cols, M_img_1_temp_bi.rows, M_img_1_temp_bi.step, QImage::Format_RGB888);
    ui->lbl_img->setPixmap(QPixmap::fromImage(image));*/
}







void MainWindow::on_horizontalSlider_e_sliderMoved(int position)
{
    if(ecu == false){
        M_img_1_temp = M_img_1;
        ecu  = true;
        histograma_RGB = get_histo(M_img_1_temp);
    }
    Mat img_e = equalize(M_img_1_temp ,histograma_RGB,position);
    //M_img = equalize(M_img_1_temp ,histograma_RGB,position);
    actualizar(img_e);
}

void MainWindow::on_open_img_A_clicked()
{
    QString rutaImagen = QFileDialog::getOpenFileName(this, tr("Abrir imagen A"), QString(),
    tr("Images ( *.png *.bmp *.jpg)"));
    ruta_img_1_A = rutaImagen.toUtf8().constData();
    //M_img_1_temp = imread(ruta_img_1);
    //M_img_1 = M_img_1_temp;
    M_img_A = imread(ruta_img_1_A);
    //actualizar(M_img_A);
    cvtColor(M_img_A,M_img_A,CV_BGR2RGB);
    QImage image((uchar*)M_img_A.data, M_img_A.cols, M_img_A.rows, M_img_A.step, QImage::Format_RGB888);
    ui->lbl_img_A->setPixmap(QPixmap::fromImage(image));
}

void MainWindow::on_open_img_B_clicked()
{
    QString rutaImagen = QFileDialog::getOpenFileName(this, tr("Abrir imagen A"), QString(),
    tr("Images ( *.png *.bmp *.jpg)"));
    ruta_img_1_B = rutaImagen.toUtf8().constData();
    //M_img_1_temp = imread(ruta_img_1);
    //M_img_1 = M_img_1_temp;
    M_img_B = imread(ruta_img_1_B);
    //actualizar(M_img_A);
    cvtColor(M_img_B,M_img_B,CV_BGR2RGB);
    QImage image((uchar*)M_img_B.data, M_img_B.cols, M_img_B.rows, M_img_B.step, QImage::Format_RGB888);
    ui->lbl_img_B->setPixmap(QPixmap::fromImage(image));
}




void MainWindow::on_pushButton_suma_clicked()
{
    Mat Res = suma_AB(M_img_A,M_img_B);
    QImage image((uchar*)Res.data, Res.cols, Res.rows, Res.step, QImage::Format_RGB888);
    ui->lbl_img_resultado->setPixmap(QPixmap::fromImage(image));

}

void MainWindow::on_pushButton_resta_clicked()
{
    Mat Res = resta_AB(M_img_A,M_img_B);
    QImage image((uchar*)Res.data, Res.cols, Res.rows, Res.step, QImage::Format_RGB888);
    ui->lbl_img_resultado->setPixmap(QPixmap::fromImage(image));
}

void MainWindow::on_pushButton_divicion_clicked()
{
    Mat Res = divicion(M_img_A,M_img_B);
    QImage image((uchar*)Res.data, Res.cols, Res.rows, Res.step, QImage::Format_RGB888);
    ui->lbl_img_resultado->setPixmap(QPixmap::fromImage(image));
}


void MainWindow::on_horizontalSlider_a_sliderMoved(int position)
{
    float a = position/100.0;

    Mat Res = suma_a(M_img_A,M_img_B,a);
    QImage image((uchar*)Res.data, Res.cols, Res.rows, Res.step, QImage::Format_RGB888);
    ui->lbl_img_resultado->setPixmap(QPixmap::fromImage(image));
}

void MainWindow::on_pushButton_M_clicked()
{
    QString rutaImagen = QFileDialog::getOpenFileName(this, tr("Abrir imagen"), QString(),
    tr("Images ( *.png *.bmp *.jpg)"));
    ruta_img_M = rutaImagen.toUtf8().constData();
    //M_img_1_temp = imread(ruta_img_1);
    //M_img_1 = M_img_1_temp;
    M_img_M = imread(ruta_img_M);
    //actualizar(M_img_A);
    cvtColor(M_img_M,M_img_M,CV_BGR2RGB);
    QImage image((uchar*)M_img_M.data, M_img_M.cols, M_img_M.rows, M_img_M.step, QImage::Format_RGB888);
    ui->lbl_img_m->setPixmap(QPixmap::fromImage(image));
}

void MainWindow::on_pushButton_AA_clicked()
{
    QString rutaImagen = QFileDialog::getOpenFileName(this, tr("Abrir imagen"), QString(),
    tr("Images ( *.png *.bmp *.jpg)"));
    ruta_img_AA = rutaImagen.toUtf8().constData();
    //M_img_1_temp = imread(ruta_img_1);
    //M_img_1 = M_img_1_temp;
    M_img_AA = imread(ruta_img_AA);
    //actualizar(M_img_A);
    cvtColor(M_img_AA,M_img_AA,CV_BGR2RGB);
    QImage image((uchar*)M_img_AA.data, M_img_AA.cols, M_img_AA.rows, M_img_AA.step, QImage::Format_RGB888);
    ui->lbl_img_AA->setPixmap(QPixmap::fromImage(image));
}

void MainWindow::on_pushButton_F_clicked()
{
    QString rutaImagen = QFileDialog::getOpenFileName(this, tr("Abrir imagen"), QString(),
    tr("Images ( *.png *.bmp *.jpg)"));
    ruta_img_F = rutaImagen.toUtf8().constData();
    //M_img_1_temp = imread(ruta_img_1);
    //M_img_1 = M_img_1_temp;
    M_img_F = imread(ruta_img_F);
    //actualizar(M_img_A);
    cvtColor(M_img_F,M_img_F,CV_BGR2RGB);
    QImage image((uchar*)M_img_F.data, M_img_F.cols, M_img_F.rows, M_img_F.step, QImage::Format_RGB888);
    ui->lbl_img_F->setPixmap(QPixmap::fromImage(image));
}

void MainWindow::on_pushButton_D_clicked()
{
    D = resta_AB(M_img_M,M_img_AA);
    QImage image((uchar*)D.data, D.cols, D.rows, D.step, QImage::Format_RGB888);
    ui->lbl_img_D->setPixmap(QPixmap::fromImage(image));
}

void MainWindow::on_pushButton_U_clicked()
{
    U = Binarizar_u(D,50);
    //M_img_1_temp_bi = Binarizar(M_img_1_temp ,1);

    //actualizar(M_img_1_temp_bi);
    //cvtColor(M_img_1_temp_bi,M_img_1_temp_bi,CV_BGR2RGB);
    QImage image((uchar*)U.data, U.cols, U.rows, U.step, QImage::Format_RGB888);
    ui->lbl_img_U->setPixmap(QPixmap::fromImage(image));
}

void MainWindow::on_pushButton_R_clicked()
{
    Mat tem1 = negacion(U);
    Mat tem2 = ope_and(M_img_F,tem1);
    Mat tem3 = ope_and(M_img_AA ,U);
    R = ope_or(tem2 ,tem3);
    QImage image((uchar*)R.data, R.cols, R.rows, R.step, QImage::Format_RGB888);
    ui->lbl_img_R->setPixmap(QPixmap::fromImage(image));
}
