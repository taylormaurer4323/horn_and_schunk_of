#include <iostream>
#include <Eigen/Dense>
#include <opencv2/opencv.hpp>
#include <opencv2/core/eigen.hpp>

#ifndef GRADIENT_H_
#define GRADIENT_H_

using namespace Eigen;

namespace img_util 
{
  void gradient_x(const cv::Mat & input, cv::Mat & output);
  void gradient_y(const cv::Mat & input, cv::Mat & output);
  void gradient(const cv::Mat & input, cv::Mat & output);
  void shift_gradient_calc(int s_r, int s_c, 
    const Array<float, Dynamic, Dynamic> & img,
    Array<float, Dynamic, Dynamic> & grad_img);

  void sobel_gradient_calc(
    const Array<float, Dynamic, Dynamic> & img,
    Array<float, Dynamic, Dynamic> & grad_img);

}



#endif //GRADIENT_H_