#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
    std::cout << "OpenCV version: " << CV_VERSION << std::endl;
    // 造一张 200x200 的蓝色图，再模糊一下，验证核心库能链能跑
    cv::Mat img(200, 200, CV_8UC3, cv::Scalar(255, 100, 0));
    cv::Mat blurred;
    cv::GaussianBlur(img, blurred, cv::Size(9, 9), 3.0);
    std::cout << "blur ok, size = " << blurred.size() << std::endl;
    std::cout << "Press Enter to exit..." << std::endl;

    cv::imshow("Blurred Image", blurred);
    cv::waitKey(0);

    return 0;
}
