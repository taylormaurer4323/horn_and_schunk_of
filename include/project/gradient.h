#include <iostream>
#include <opencv2/opencv.hpp>

#ifndef GRADIENT_H_
#define GRADIENT_H_


namespace img_util 
{

  void gradient_x(const cv::Mat & input, cv::Mat & output);
  void gradient_y(const cv::Mat & input, cv::Mat & output);
  void gradient(const cv::Mat & input, cv::Mat & output);
  void get_avg_img(const cv::Mat & img, cv::Mat & avg_img);
  void shift_img(int s_r, int s_c, const cv::Mat & img, cv::Mat & shifted_img_diff);
}



#endif //GRADIENT_H_