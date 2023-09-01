#include <iostream>
#include <Eigen/Dense>
#include <opencv2/opencv.hpp>
#include <opencv2/core/eigen.hpp>

#ifndef CONVOLUTION_H_
#define CONVOLUTION_H_

using namespace Eigen;

namespace img_util 
{
  void convolution(const Array<float, Dynamic, Dynamic> & kernel, const Array<float, Dynamic, Dynamic> & img);
  void fliplr(Array<float, Dynamic, Dynamic> & arr);

}



#endif //CONVOLUTION_H_