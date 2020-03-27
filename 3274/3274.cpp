#include <iostream>
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;
Mat g_sobelGradient_X, g_sobelGradient_Y;
Mat g_sobelAbsGradient_X, g_sobelAbsGradient_Y;
int g_sobelKernelSize = 1;
int main(int argc, const char * argv[]) {


	VideoCapture cap(0);



	while (1)
	{
		Mat InMat;
		Mat OutMat;
		cv::threshold(InMat, OutMat, 0, 255, THRESH_OTSU);
		cap >> InMat;
			Sobel(InMat, g_sobelGradient_X, CV_16S, 1, 0, (2 * g_sobelKernelSize + 1), 1, 1, BORDER_DEFAULT);
			convertScaleAbs(g_sobelGradient_X, g_sobelAbsGradient_X);


			Sobel(InMat, g_sobelGradient_Y, CV_16S, 0, 1, (2 * g_sobelKernelSize + 1), 1, 1, BORDER_DEFAULT);
			convertScaleAbs(g_sobelGradient_Y, g_sobelAbsGradient_Y);
			addWeighted(g_sobelAbsGradient_X, 0.5, g_sobelAbsGradient_Y, 0.5, 0, OutMat);
			imshow("Sobel边缘检测", OutMat);
		imshow("InMat", InMat);
		convertScaleAbs(OutMat, OutMat);

		waitKey(30);

	}
}