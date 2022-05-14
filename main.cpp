#include <iostream>
#include "pose_transform.hpp"

int main(int, char**) {
    cv::Mat rot_vec = (cv::Mat_<float>(1, 3) << 1, 1, 1);
    cv::Mat result;
    sparkpose::rotVec2Matrix(rot_vec, result);
    printf("Result is:\n");
    std::cout << result << std::endl;
    printf("The col of result is %d.\n", result.cols);
    printf("The row of result is %d.\n", result.rows);
    printf("The channel of result is %d.\n", result.channels());
    
}
