#ifndef HORNSCHUNK_H_
#define HORNSCHUNK_H_
#include <opencv2/opencv.hpp>

class hornschunk
{
public:
    //allow definition of default constructors other than this one...
    hornschunk(int img_width, int img_height) : img_width_(img_width), img_height_(img_height){
        
        //Initialize space for matrices that are carried
        //through
        pimage_ = cv::Mat::zeros(img_width, img_height, CV_32F);
        pimage_gradx_ = cv::Mat::zeros(img_width, img_height, CV_32F);
        pimage_grady_ = cv::Mat::zeros(img_width, img_height, CV_32F);
        //initialize ufield and vfield
        ufield_ = cv::Mat::zeros(img_width, img_height, CV_32F);
        vfield_ = cv::Mat::zeros(img_width, img_height, CV_32F);
    }

    //This function will perform all necessary things
    void run(const cv::Mat & img, cv::Mat & flow_field);
    void setLambda(float value){ lambda_ = value; }
    float getLambda(){ return lambda_; }
    bool getInit(){ return bInit_; }

private:
    cv::Mat ufield_;
    cv::Mat vfield_;
    cv::Mat pimage_;
    cv::Mat pimage_gradx_;
    cv::Mat pimage_grady_;
    int img_height_;
    int img_width_;

    int gsize_ = 5;
    float lambda_ = 1;
    bool bInit_ = false;
};


#endif //HORNSCHUNK_H_