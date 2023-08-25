#include <iostream>
#include <Eigen/Dense>
#include <opencv2/opencv.hpp>
#include <opencv2/core/eigen.hpp>

#ifndef PREPROCESS_UTIL_H_
#define PREPROCESS_UTIL_H_

using namespace Eigen;

namespace pp_util 
{
    //convert from cv::Mat (grayscale) to Eigen::Array which is the best
    //to work with for images. 
    void cv2array(const cv::Mat & img_cv, Array<float, Dynamic, Dynamic> & img_eig);
    void array2cv(const Array<float, Dynamic, Dynamic> & img_eig, cv::Mat & img_cv);
}



#endif //PREPROCESS_UTIL_H_