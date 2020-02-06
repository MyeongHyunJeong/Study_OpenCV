#include <iostream>
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

int main() {
	VideoCapture sample("Sample02.mp4");
	if (!sample.isOpened()) {
		cerr << "Video is not loading!" << endl;
		return -1;
	}

	double fps = sample.get(CAP_PROP_FPS);
	int delay = cvRound(1000 / fps);

	cout << "Frame height : " << cvRound(sample.get(CAP_PROP_FRAME_HEIGHT)) << endl;
	cout << "Frame width : " << cvRound(sample.get(CAP_PROP_FRAME_WIDTH)) << endl;
	cout << "Frame fps : " << fps << endl;
	cout << "Delay : " << delay << endl;


	Mat frame;

	while (true) {
		sample >> frame;
		if (frame.empty()) {
			cerr << "frame is not exist!" << endl;
			break;
		}

		imshow("frame", frame);
		if (waitKey(delay) == 27) {
			break;
		}
	}

	destroyAllWindows();

	return 0;
}