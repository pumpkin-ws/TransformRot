cmake_minimum_required(VERSION 3.0.0)
project(TransformRot VERSION 0.1.0)

include(CTest)
enable_testing()

add_compile_options("-std=c++14")

find_package(OpenCV 4 REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

include_directories(${PROJECT_SOURCE_DIR}/source/)

add_subdirectory(${PROJECT_SOURCE_DIR}/source)

add_executable(TransformRot main.cpp)
target_link_libraries(TransformRot ${OpenCV_LIBS} sparkpose)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
