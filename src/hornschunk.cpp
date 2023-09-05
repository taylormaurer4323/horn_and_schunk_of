#include "project/hornschunk.h"
#include "project/gradient.h"
#include <iostream>

void hornschunk::run(const cv::Mat & img, cv::Mat & flow_field) {
    
    
    if(bInit_){
        //get fx by combining previous image gradient and current image gradient
        cv::Mat image_gradx, image_grady;
        //find current image gradient
        img_util::gradient_x(img, image_gradx);
        img_util::gradient_y(img, image_grady);
        cv::Mat f_x(img.rows, img.cols, CV_32F);
        f_x = 0.5 * (pimage_gradx_ + image_gradx);
        //repeat for fy
        cv::Mat f_y(img.rows, img.cols, CV_32F);
        f_y = 0.5 * (pimage_grady_ + image_grady);
        //image difference to get time derivative
        cv::Mat f_t(img.rows, img.cols, CV_32F);
        cv::subtract(pimage_, img, f_t);
        //find average flow - u first
        cv::Mat avgflow_u(img.rows, img.cols, CV_32F);
        img_util::get_avg_img(ufield_, avgflow_u);
        //v flow next
        cv::Mat avgflow_v(img.rows, img.cols, CV_32F);
        img_util::get_avg_img(vfield_, avgflow_v);
        //Perform update step (u)
        cv::Mat numerator(img.rows, img.cols, CV_32F);
        numerator = f_x.mul(avgflow_u) + f_y.mul(avgflow_v) + f_t;
        cv::Mat denominator(img.rows, img.cols, CV_32F);
        denominator = (1.0/lambda_) + f_x.mul(f_x) + f_y.mul(f_y);
        //tmp matrix to carry values for operations
        cv::Mat result(img.rows, img.cols, CV_32F);
        cv::divide(numerator, denominator, result);
        //u update
        ufield_ = avgflow_u - f_x.mul(result);
        vfield_ = avgflow_v - f_y.mul(result);
        //Apply blur
        cv::GaussianBlur(ufield_ + vfield_, flow_field, cv::Size(gsize_, gsize_), 0);
        //save
        pimage_ = img;
        pimage_gradx_ = image_gradx;
        pimage_grady_ = image_grady;

    } else {
        img_util::gradient_x(img, pimage_gradx_);
        img_util::gradient_y(img, pimage_grady_);
        flow_field = cv::Mat::zeros(img.rows, img.cols, CV_32F);
        pimage_ = img;
        bInit_ = true;
    }
}