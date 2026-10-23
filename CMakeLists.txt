cmake_minimum_required(VERSION 3.16)
project(cpp-vision-toolbox LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenCV REQUIRED COMPONENTS core imgproc)

add_executable(vision main.cpp)
target_link_libraries(vision PRIVATE ${OpenCV_LIBS})
target_include_directories(vision PRIVATE ${OpenCV_INCLUDE_DIRS})

# MSVC 默认按系统代码页(GBK)读源文件，UTF-8 中文注释会被误读导致诡异报错；
# /utf-8 强制源码与执行字符集均为 UTF-8
if(MSVC)
  target_compile_options(vision PRIVATE /utf-8)
endif()
