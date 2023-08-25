#include <iostream>
#include <Eigen/Dense>
#include <opencv2/opencv.hpp>
#include <opencv2/core/eigen.hpp>
#include "project/gradient.h"

#include <filesystem>
namespace fs = std::filesystem;



int main(int argc, char *argv[])
{
    /*
    * Horn and schunk apporach
    * 1) Find fx, fy, and ft
    * 2) Find update u and v vectors
    * 3) Identify cost, repeat...
    * 
    * Seems like there will be more to each step, but that's essentially it.
    * First step is to read in each file from the  data though and just display
    */
   /* Reading Files In:
   std::string path_to_files = argv[1];
   for(const std::filesystem::directory_entry & d : fs::directory_iterator(path_to_files))
   {
        std::string filename = d.path().filename().string();
        std::string token = filename.substr(filename.find('.')+1);
        if(strcmp(token.c_str(), "jpg") == 0)
        {
            std::cout<<"reading: "<<d.path().string()<<std::endl;
            cv::Mat image_cv = cv::imread(d.path().string(), cv::IMREAD_GRAYSCALE);
            cv::namedWindow("Display", cv::WINDOW_AUTOSIZE);
            cv::imshow("Display", image_cv);
            cv::waitKey(0);
        }
   }
    */

    std::string path_to_file = argv[1];
    cv::Mat image_cv = cv::imread(path_to_file, cv::IMREAD_GRAYSCALE);
    cv::namedWindow("Display", cv::WINDOW_AUTOSIZE);
    cv::imshow("Display", image_cv);
    cv::waitKey(0);
    Eigen::Array<float,Eigen::Dynamic, Eigen::Dynamic> image_arr;
    pp_util::cv2array(image_cv, image_arr);
    cv::Mat new_image_cv;
    pp_util::array2cv(image_arr,new_image_cv);
    cv::namedWindow("Display", cv::WINDOW_AUTOSIZE);
    cv::imshow("Display", new_image_cv*1.0/255.0);
    cv::waitKey(0);

    //Attmept to convert back
    //image_cv = 
    //Eigen::Array<float, Eigen::Dynamic, Eigen::Dynamic> testA = Eigen::Array<float, Eigen::Dynamic, Eigen::Dynamic>::Zero(3,3);
    //pp_util::array2cv(testA);
   //cv::Mat image_cv = cv::imread(path_to_file);
   //cv::namedWindow("Display", cv::WINDOW_AUTOSIZE);


    return 0;
}