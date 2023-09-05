#include "project/gradient.h"
#include <cmath>
#include <opencv2/opencv.hpp>



void img_util::gradient_x(const cv::Mat & input, cv::Mat & output)
{
    cv::GaussianBlur(input, output, cv::Size(5,5), 0);
    cv::Sobel(output, output, CV_32F, 1, 0, 5);
    
}

void img_util::gradient_y(const cv::Mat & input, cv::Mat & output)
{
    cv::GaussianBlur(input, output, cv::Size(5,5), 0);
    cv::Sobel(input, output, CV_32F, 0, 1, 5);
    
}

void img_util::gradient(const cv::Mat & input, cv::Mat & output)
{
    cv::Laplacian(input, output, CV_32F);
}
void img_util::get_avg_img(const cv::Mat & img, cv::Mat & avg_img)
{
    cv::Mat top_img(avg_img.rows, avg_img.cols, CV_32F);
    cv::Mat right_img(avg_img.rows, avg_img.cols, CV_32F);
    cv::Mat bottom_img(avg_img.rows, avg_img.cols, CV_32F);
    cv::Mat left_img(avg_img.rows, avg_img.cols, CV_32F);
    img_util::shift_img(0, -1, img, top_img);
    img_util::shift_img(1, 0, img, right_img);
    img_util::shift_img(0, 1, img, bottom_img);
    img_util::shift_img(-1, 0, img, left_img);
    avg_img = 0.25 * (top_img + right_img + bottom_img + left_img);
    



}
void img_util::shift_img(int s_c, int s_r,
    const cv::Mat & img, cv::Mat & shifted_img)
{    
    int og_c = std::max(0, s_c); 
    int og_r = std::max(0, s_r);
    int new_c = abs(std::min(0, s_c));
    int new_r = abs(std::min(0, s_r));
    //std::cout<<"Indexing from ("<<og_c<<", "<<og_r<<") w/width ("<<img.cols - new_c - og_c<<", "<<img.rows-new_r - og_r<<")\n";
    cv::Rect r(og_c, og_r, img.cols-new_c - og_c, img.rows-new_r - og_r);
    
    //std::cout<<"Indexing from ("<<new_c<<", "<<new_r<<") w/width ("<<img.cols - new_c - og_c<<", "<<img.rows-new_r - og_r<<")\n";    
    cv::Rect r_ind(new_c, new_r, img.cols - new_c - og_c, img.rows - new_r - og_r);
    shifted_img = cv::Mat::zeros(shifted_img.rows, shifted_img.cols, CV_32F);
    img(r).copyTo(shifted_img(r_ind));
    
}
/* Below is an old implementation
* Input:
*   s_r: shift in rows [pixels]
*   s_c: shift in columns [pixels]
*/
/*
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

*/