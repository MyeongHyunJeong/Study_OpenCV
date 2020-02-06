//#include <iostream>
//#include "opencv2/opencv.hpp"
//
//using namespace std;
//using namespace cv;
//
//void brightness1(Mat src) {
//	Mat dst = src + 100;
//	imshow("dst", dst);
//}
//
//void brightness2(Mat src) {
//	Mat dst(src.rows, src.cols, src.type());
//	for (int j = 0; j < src.rows; j++) {
//		for (int i = 0; i < src.cols; i++) {
//			dst.at<uchar>(j, i) = src.at<uchar>(j, i) + 100;
//		}
//	}
//	imshow("dst2", dst);
//}
//
//void brightness3(Mat src) {
//	Mat dst(src.rows, src.cols, src.type());
//	int v = 0;
//	for (int j = 0; j < src.rows; j++) {
//		for (int i = 0; i < src.cols; i++) {
//			v = src.at<uchar>(j, i) + 100;
//			dst.at<uchar>(j, i) = v > 255 ? 255 : v < 0 ? 0 : v;
//		}
//	}
//	imshow("dst3", dst);
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
//	brightness1(src);
//	brightness2(src);	//직접 구현(255 넘어가면 다시 0)
//	brightness3(src);	//직접 구현(0보다 작으면 0, 255보다 크면 255)
//
//	waitKey();
//	destroyAllWindows();
//}