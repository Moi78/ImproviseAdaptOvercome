cmake_minimum_required(VERSION 3.24)

add_executable(Improvise_Adapt_Overcome main.cpp Graphics.cpp Graphics.h Image.cpp Image.h Robot.cpp Robot.h RobotMS.cpp RobotMS.h)

find_package(SDL2 REQUIRED)
target_link_libraries(Improvise_Adapt_Overcome SDL2::SDL2)

find_package(SDL2_image REQUIRED)
target_link_libraries(Improvise_Adapt_Overcome SDL2_image::SDL2_image)
