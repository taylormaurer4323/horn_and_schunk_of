#include "project/preprocess_util.h"
#include <Eigen/Dense>
#include <opencv2/opencv.hpp>
#include <opencv2/core/eigen.hpp>

using namespace Eigen;

void pp_util::cv2array(const cv::Mat & img_cv, Array<float, Dynamic, Dynamic> & img_eig)
{
    //First convert to matrix
    Matrix<float, Dynamic, Dynamic> img_mat;
    cv::cv2eigen(img_cv, img_mat);
    img_eig = img_mat.array();
}

void pp_util::array2cv(const Array<float, Dynamic, Dynamic> & img_eig, cv::Mat & img_cv)
{
    Matrix<float, Dynamic, Dynamic> img_mat = img_eig.matrix();
    cv::eigen2cv(img_mat, img_cv);
}
