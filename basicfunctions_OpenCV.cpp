#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

using namespace std;
using namespace cv;

/////////////// Image functions ///////////////
int main() {
	string path = "Resources/test.png";
	Mat img = imread(path);
	Mat imgGray,imgBlur,imgCanny,imgDia,imgErode;

	
	                                         ////////  Converting Image into greyscale ////////////////
	cvtColor(img, imgGray, COLOR_BGR2GRAY); //cvtColor(ourimage, destination img, conversion)
	
											///////// Converting Image into Blur Image //////////////
	GaussianBlur(img, imgBlur, Size(7, 7), 5, 0); //GaussionBlur(ourimage, destination img, size of kernel,sigma X, sigmaY 
	
												  /////////Edges Detector for Image ///////////////////////////////////
	Canny(imgBlur, imgCanny, 125/*threshold1 value*/, 225/*threshold1 value*/);
	
	//////////// Image Dialation  +++++++ Increasing thickness ++++++++++++////////////////////////////
	//when we detect Edges of image most edges are not fully joined or very thin to detect proper 
	//so that edges increase their thickness 
	Mat kernel = getStructuringElement(MORPH_RECT, Size(5, 5));//this creates kernel which we can use for dialation in python numpy does that structuring
	dilate(imgCanny, imgDia, kernel);

	/////////////Image Erode *******Decreasing the thickness********///////////////////////////////
	//when we detect edges of image and edges are so thick then
	// to decrease edges thicknes we do erosion
	erode(imgDia, imgErode, kernel);

	//functions to show the image in popup windows

	imshow("image", img);
	imshow("image gray", imgGray);//to show greyscale image 
	imshow("image blur", imgBlur);//to show blured image
	imshow("detected", imgCanny); //to show edges of the images
	imshow("image dialation", imgDia);//to show dialated edges of the image
	imshow("image Erode", imgErode);
	waitKey(0);
}
