#include "pose_transform.hpp"

namespace sparkpose {

    bool rotVec2Matrix(const cv::InputArray& rotVec, cv::OutputArray& rotMat) {
        cv::Mat rotation_vec = rotVec.getMat();
        if (rotation_vec.channels() > 1) {
            printf("MATRIX OPERATION ONLY SUITABLE FOR CHANNEL 1.\n");
            return false;
        }
        if (
            (rotation_vec.cols == 1 && rotation_vec.rows == 3) || 
            (rotation_vec.cols == 3 && rotation_vec.rows == 1)
        ) {
            cv::Mat result;
            try{
                cv::Rodrigues(rotation_vec, result);
                rotMat.assign(result);
                return true;
            } catch (cv::Exception& e) {
                printf("AN OPENCV EXCEPTION OCCURED: \n");
                printf("%s\n", e.what());
                return false;
            }
        } else {
            printf("INPUT ARRAY IS INVALID, NEEDS TO BE AN 3x1 or 1x3 matrix,\n");
            return false;
        }
        return false;
    };

    bool rotVec2Matrix(const Eigen::Vector3f& rotVec, Eigen::Matrix3f& rotMat, Eigen::AngleAxisf& aa, Eigen::Quaternionf& q) {
        /* The norm of the rotation vector is the rotation angle, the unit vector is the rotation axis */
        aa.angle() = rotVec.norm();
        aa.axis() = rotVec.normalized();
        rotMat = aa.matrix();
        q = aa;

    };

    
}