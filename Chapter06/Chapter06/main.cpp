#include <iostream>
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

void addTwoImages(Mat src1, Mat src2);
void addTwoImagesWithWeight(Mat src1, Mat src2);
void getDiffImage();

void main() {
	Mat src1 = imread("lenna.jpg", IMREAD_GRAYSCALE);
	Mat src2 = imread("aero.jpg", IMREAD_GRAYSCALE);

	if (src1.empty() || src2.empty()) {
		cerr << "Image is not loading!" << endl;
		return;
	}
	CV_Assert(src1.type() == CV_8UC1 || src2.type() == CV_8UC1);

	resize(src1, src1, Size(512, 512));
	resize(src2, src2, Size(512, 512));

	imshow("src1", src1);
	imshow("src2", src2);

	addTwoImages(src1, src2);
	addTwoImagesWithWeight(src1, src2);
	getDiffImage();

	waitKey();
	destroyAllWindows();
}

void addTwoImages(Mat src1, Mat src2) {
	Mat dst;
	add(src1, src2, dst);
	imshow("dst", dst);
}

void addTwoImagesWithWeight(Mat src1, Mat src2)
{
	Mat dst;
	addWeighted(src1, 0.3, src2, 0.3, 0, dst);
	imshow("dstWeight", dst);
}

void getDiffImage()
{
	Mat dst;
	Mat test1 = imread("test1.jpeg");
	Mat test2 = imread("test2.jpeg");

	imshow("test1", test1);
	imshow("test2", test2);

	absdiff(test2, test1, dst);
	imshow("diffImage", dst);
}
