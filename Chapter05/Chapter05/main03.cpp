#include <iostream>
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

Mat contrast1(Mat src);
Mat contrast2(Mat src);
Mat calcGrayHist(Mat src);
Mat getGrayHistImage(const Mat& hist);
void histogram_stretching(Mat src);
void histogram_equalization(Mat src);

void main() {
	Mat src = imread("lenna.jpg", IMREAD_GRAYSCALE);
	if (src.empty()) {
		cerr << "Image is not loading!" << endl;
		return;
	}
	CV_Assert(src.type() == CV_8UC1);

	imshow("src", src);
	imshow("dst1", contrast1(src));
	imshow("dst2", contrast2(src));

	imshow("hist_src", getGrayHistImage(calcGrayHist(src)));

	histogram_stretching(src); 
	histogram_equalization(src); 

	waitKey();
	destroyAllWindows();
}

Mat contrast1(Mat src) {
	float s = 2.f;
	Mat dst = s * src;
	return dst;
}

Mat contrast2(Mat src) {
	float alpha = 1.f;
	Mat dst = src + (src - 128) * alpha;
	return dst;
}

Mat calcGrayHist(Mat src) {
	Mat hist;
	int channels[] = { 0 };
	int dims = 1;
	const int histSize[] = { 256 };
	float graylevel[] = { 0, 256 };
	const float* ranges[] = { graylevel };
	
	calcHist(&src, 1, channels, noArray(), hist, dims, histSize, ranges);

	return hist;
}

Mat getGrayHistImage(const Mat& hist) {
	CV_Assert(hist.type() == CV_32FC1);
	CV_Assert(hist.size() == Size(1, 256));

	double histMax;
	minMaxLoc(hist, 0, &histMax);

	Mat imgHist(100, 256, CV_8UC1, Scalar(255));
	for (int i = 0; i < 256; i++) {
		line(imgHist, Point(i, 100),
			Point(i, 100 - cvRound(hist.at<float>(i, 0) * 100 / histMax)), Scalar(0));
	}

	return imgHist;
}

void histogram_stretching(Mat src) {
	double gmin, gmax;
	minMaxLoc(src, &gmin, &gmax);

	Mat dst = (src - gmin) * 255 / (gmax - gmin);
	imshow("dst3", dst);
	imshow("dst3Hist", getGrayHistImage(calcGrayHist(dst)));
}

void histogram_equalization(Mat src) {
	Mat dst;
	equalizeHist(src, dst);
	imshow("equaldst", dst);
	imshow("equaldstHist", getGrayHistImage(calcGrayHist(dst))); 
}