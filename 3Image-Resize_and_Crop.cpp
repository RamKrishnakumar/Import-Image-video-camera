#include<opencv2/imgcodecs.hpp>
#include<opencv2/imgproc.hpp>
#include<opencv2/highgui.hpp>
#include<iostream>
using namespace std;
using namespace cv;

/// <summary>
/// Resize and Croping Images
/// </summary>
void main() {
	string path = "Resources/test.png";
	Mat img = imread(path);
	Mat imgResize,imgCrop;
	
	//to know the current size of the image of above mentioned path
	//cout << img.size() << endl;//768 x 559
	
	//////////////Image Resize ////////////////////
	//resize(img, imgResize, Size(640,530));//can to resize but aspect ration get changed
	resize(img, imgResize, Size(), 0.5,0.5);// to do resize by scaling when we don't know the specific pixel ratio

	//To crop an Image/////////////////////////////////
	// to crop we are going to use rectangle data type
	
	Rect roi(170, 20, 400,300 );//Rect roi(X,Y,width,height)

	imgCrop = img(roi);
	
	imshow("image", img);
	//imshow("image resize", imgResize);//to show the resized image
	imshow("crop", imgCrop);
	waitKey(0);
} 