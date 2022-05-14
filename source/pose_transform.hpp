#ifndef POSE_TRANSFORM_HPP_
#define POSE_TRANSFORM_HPP_

#include "opencv2/opencv.hpp"
#include "eigen3/Eigen/Core"
#include "eigen3/Eigen/Dense"

namespace sparkpose{

    bool rotVec2Matrix(const cv::InputArray& rotVec, cv::OutputArray& rotMat);

    bool rotVec2Matrix(const Eigen::Vector3f& rotVec, Eigen::Matrix3f& rotMat, Eigen::AngleAxisf& aa, Eigen::Quaternionf& q);
}

#endif