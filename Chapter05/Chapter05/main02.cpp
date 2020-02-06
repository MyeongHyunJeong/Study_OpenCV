//#include <iostream>
//#include "opencv2/opencv.hpp"
//
//using namespace std;
//using namespace cv;
//
//void on_brightness(int pos, void* userdata) {
//	Mat src = *(Mat*)userdata;
//	Mat dst = src + pos;
//
//	imshow("dst", dst);
//}
//
//void main() {
//	Mat src = imread("lenna.jpg", IMREAD_GRAYSCALE);
//	if (src.empty()) {
//		cerr << "Image is not loading!" << endl;
//		return;
//	}    
//	CV_Assert(src.type() == CV_8UC1);
//
//	imshow("src", src);
//
//	namedWindow("dst");
//	createTrackbar("Brightness", "dst", 0, 100, on_brightness, (void*)&src);
//
//
//	waitKey();
//	destroyAllWindows();
//}