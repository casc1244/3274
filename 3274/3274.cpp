#include <iostream>
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;
int main(int argc, const char * argv[]) {


	VideoCapture cap(0);


	while (1)
	{
		Mat InMat;
		Mat OutMat;
		cap >> InMat;
		Sobel(InMat, OutMat, 3,1,1,1,1);
		imshow("InMat", InMat);
		imshow("OutMat", OutMat);

		waitKey(30);

	}
}