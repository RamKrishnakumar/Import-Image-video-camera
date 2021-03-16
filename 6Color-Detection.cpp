#include<opencv2/imgcodecs.hpp>
#include<opencv2/imgproc.hpp>
#include<opencv2/highgui.hpp>
#include<iostream>
using namespace std;
using namespace cv;

//////////////// Color Detection //////////////////////////

void main() {
	Mat  imgHSV, outputmask;

	/////////// default values to detect orance color ///////////
	       /*int hmin = 0, smin = 110, vmin = 153;
	       int hmax = 19, smax = 240, vmax = 255;*/

	//default  values for trackbar at starting--------
	int hmin = 0, smin = 0, vmin = 0;
	int hmax = 179, smax = 255, vmax = 255;

	string path = "Resources/shapes.png";
	Mat img = imread(path);

	//To detect color we are going to convert our source image into HSV space(basically hue saturation and value easy) ////////////////////////////////

	cvtColor(img, imgHSV, COLOR_BGR2HSV);

	//to find out these hsv min & max value we can use OpenCV function track bar to input value 
	//at runnig time to find the hsv min and max values track bar can created using while loop.implementation of track bar ##trackbar
//--------------------------##trackbar-----------------------------------------------------------------------------------------------------------------
	namedWindow("Trackbars", (640, 200));
	createTrackbar("Hue Min", "Trackbars", &hmin, 179);//for hue min 179 is maximum value for trackbar
	createTrackbar("Hue Max", "Trackbars", &hmax, 179);//for hue max 179 is maximum value for trackbar
	createTrackbar("Sat Min", "Trackbars", &smin, 255);//for sat min 255 is mximum value for trackbar
	createTrackbar("Sat Max", "Trackbars", &smax, 255);//for sat max 255 is mximum value for trackbar
	createTrackbar("Val Min", "Trackbars", &vmin, 255);//for val min 255 is mximum value for trackbar
	createTrackbar("Val Max", "Trackbars", &vmax, 255);//for val max 255 is mximum value for trackbar
//------------------------------------------------------------------------------------------------------------------------------------------------------

	
	//Now we are going to use inRange function to collect our color from HSV image/////////////////////////////////
	//we have to difine range of color that we want to detect
	while (true) {
		Scalar lowerlimit(hmin, smin, vmin);//lowerlimit(hue minimum, saturation minimum, value minimum )
		Scalar upperlimit(hmax, smax, vmax);//upperlimti(hue maximum, saturation maximum, value maximum 

		inRange(imgHSV, lowerlimit, upperlimit, outputmask);



		imshow("Source Image", img);//to show normal imported image from resources
		imshow("HSV Image", imgHSV);//to show converted img from normal to hsv
		imshow("Image output mask", outputmask);
		waitKey(1);
	}
}