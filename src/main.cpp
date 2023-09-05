#include <iostream>
#include <Eigen/Dense>
#include <opencv2/opencv.hpp>
#include "project/gradient.h"
#include "project/hornschunk.h"
#include <memory>
#include <filesystem>
namespace fs = std::filesystem;



int main(int argc, char *argv[])
{


    std::unique_ptr<hornschunk> hs;
    //hs.run();
    
    std::string path_to_files = argv[1];
    bool bInit = false;
    cv::Mat flow_field;
    float lambda = 100;
    for(const std::filesystem::directory_entry & d : fs::directory_iterator(path_to_files))
    {
        std::string filename = d.path().filename().string();
        std::string token = filename.substr(filename.find('.')+1);
        if(strcmp(token.c_str(), "jpg") == 0)
        {
            std::cout<<"reading: "<<d.path().string()<<std::endl;
            cv::Mat image;
            cv::Mat display = cv::imread(d.path().string(), cv::IMREAD_GRAYSCALE);
            display.convertTo(image, CV_32F);
            
            if(hs)
            {
                hs->run(image, flow_field);
                cv::namedWindow("flow", cv::WINDOW_AUTOSIZE);
                cv::imshow("flow", flow_field);
                cv::namedWindow("image", cv::WINDOW_AUTOSIZE);
                cv::imshow("image", display);
                cv::waitKey(0);
            } else {
                hs = std::make_unique<hornschunk>(image.rows, image.cols);
                hs->run(image, flow_field);
            }
        }
    }
    return 0;
}