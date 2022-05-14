find_package(OpenCV 4 REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_library(
    sparkpose SHARED
    pose_transform.hpp
    pose_transform.cpp
)

target_link_libraries(sparkpose ${OpenCV_LIBS})