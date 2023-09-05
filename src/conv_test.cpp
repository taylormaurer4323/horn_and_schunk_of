#include <iostream>
#include <Eigen/Dense>
#include <opencv2/opencv.hpp>
#include <opencv2/core/eigen.hpp>
#include <filesystem>

//project specific
#include "project/gradient.h"
#include "project/convolution.h"
#include "project/preprocess_util.h"


namespace fs = std::filesystem;



int main(int argc, char *argv[])
{
   /*
    std::string path_to_file = argv[1];
    cv::Mat image_cv = cv::imread(path_to_file, cv::IMREAD_GRAYSCALE);

    cv::Mat gradx_img, grady_img, grad_img;
    cv::Mat Dx, Dy;
    cv::Sobel(image_cv, Dx, CV_64F, 1, 0, 3);
    cv::Sobel(image_cv, Dy, CV_64F, 0, 1, 3);
    
    */
   Eigen::Array<float, Dynamic, Dynamic> kernel {
        {-1 , 0, 1},
        {-2, 0, 2},
        {-1, 0, 1}
   };

    //Create reference to it...
    Eigen::Array<float, Eigen::Dynamic, Eigen::Dynamic> & flipped_kernel = kernel;
    //Readimage
    std::string path_to_file = "/mnt/e/projects/data/shoe/shoe/images/shoe_218.jpg";
    cv::Mat image_cv = cv::imread(path_to_file, cv::IMREAD_GRAYSCALE);
    Eigen::Array<float, Eigen::Dynamic, Eigen::Dynamic> img_eig;
    pp_util::cv2array(image_cv, img_eig);


   img_util::fliplr(flipped_kernel);
   std::cout<<"flipped kernel"<<std::endl;
   std::cout<<flipped_kernel<<std::endl;
   //can continue with convolution now that we flip!
   return 0;
}