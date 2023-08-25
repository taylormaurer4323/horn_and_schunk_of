#include "project/gradient.h"
#include "project/preprocess_util.h"
#include <Eigen/Dense>
#include <opencv2/opencv.hpp>
#include <opencv2/core/eigen.hpp>

using namespace Eigen;
/*
* Input:
*   s_r: shift in rows [pixels]
*   s_c: shift in columns [pixels]
*/
void img_util::shift_gradient_calc(int s_r, int s_c, 
    const Array<float, Dynamic, Dynamic> & img, 
    Array<float, Dynamic, Dynamic> & grad_img)
{
    //create the shifted image
    Array<float, Dynamic, Dynamic> img_shift = 
        img.block(s_r, s_c, img.rows() - s_r, img.cols() - s_c);
    //reduce the original image
    Array<float, Dynamic, Dynamic> img_redux = 
        img.block(0, 0, img.rows() - s_r, img.cols() - s_c);
    //Now subtract the two matrices
    grad_img = img_redux - img_shift;
}

void img_util::gradient_x(const cv::Mat & input, cv::Mat & output)
{
    //convert input to eigen array
    Array<float, Dynamic, Dynamic> img_eig;
    pp_util::cv2array(input, img_eig);
    Array<float, Dynamic, Dynamic> grad_img_eig = 
        Array<float, Dynamic, Dynamic>::Zero(img_eig.rows(), img_eig.cols());
    //Perform cacl
    img_util::shift_gradient_calc(1, 0, img_eig, grad_img_eig);
    //Convert back to opencv
    pp_util::array2cv(grad_img_eig, output);
    
}

void img_util::gradient_y(const cv::Mat & input, cv::Mat & output)
{
    //convert input to eigen array
    Array<float, Dynamic, Dynamic> img_eig;
    pp_util::cv2array(input, img_eig);
    Array<float, Dynamic, Dynamic> grad_img_eig = 
        Array<float, Dynamic, Dynamic>::Zero(img_eig.rows(), img_eig.cols());
    //Perform cacl
    img_util::shift_gradient_calc(0, 1, img_eig, grad_img_eig);
    //Convert back to opencv
    pp_util::array2cv(grad_img_eig, output);
}

void img_util::gradient(const cv::Mat & input, cv::Mat & output)
{
    //convert input to eigen array
    Array<float, Dynamic, Dynamic> img_eig;
    pp_util::cv2array(input, img_eig);
    Array<float, Dynamic, Dynamic> grad_img_eig = 
        Array<float, Dynamic, Dynamic>::Zero(img_eig.rows(), img_eig.cols());
    //Perform cacl
    img_util::shift_gradient_calc(1, 1, img_eig, grad_img_eig);
    //Convert back to opencv
    pp_util::array2cv(grad_img_eig, output);
}

