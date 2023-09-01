#include <iostream>
#include <cmath>
#include <Eigen/Dense>
#include <opencv2/opencv.hpp>
#include <opencv2/core/eigen.hpp>
#include "project/convolution.h"


using namespace Eigen;

void img_util::convolution(const Array<float, Dynamic, Dynamic> & kernel, const Array<float, Dynamic, Dynamic> & img)
{
    std::cout<<"Convolution\n";
}

void img_util::fliplr(Array<float, Dynamic, Dynamic> & arr)
{
    int half_size = floor(arr.cols()/2);
    int zi_cols = arr.cols() - 1;
    for(int v = 0; v < arr.rows(); v++)
    {
        for(int u = 0; u<half_size; u++)
        {
            //Matlab style indexing (b/c stored as column major)
            float tmp_val = arr(v, u);
            arr(v,u) = arr(v, zi_cols - u);
            arr(v, zi_cols - u) = tmp_val;            
        }
    }

}