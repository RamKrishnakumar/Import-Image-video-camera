#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/objdetect.hpp>//header file that will allow us to work with harr cascading
#include <iostream>

using namespace std;
using namespace cv;

/// <summary>
/// FACE DETECTION from IMAGE
/// to detect the face we are going to use voila jones method of harr cascades
/// We have some already trained model in xml file for it named frontalface_default.xml
/// we are going to use frontalface_default.xml file to load our cascade and to detect faces
/// </summary>

void main(){
	string path = "Resources/test.png";
	Mat img = imread(path);

	CascadeClassifier faceCascade;
	faceCascade.load("Resources/haarcascade_frontalface_default.xml");
	
	//to identify whether the file is loaded successfully porperly if it's not loaded properly then it will popup an error-------
	if (faceCascade.empty()) {cout << "XML file not loaded" << endl;}
	//---------------------------------------------------------------------------------------------------------------------------

	//Now after checking we are ready to detect faces
	//To detect the faces and to store them we need to store bounding boxes(max surface area coverd) to store bounding boxes we need vectors

	vector<Rect> faces;
	faceCascade.detectMultiScale(img, faces, 1.1, 10);//If the face got detected here we won't be able to know that becuase we aren't displaying anything here

	for (int i = 0; i < faces.size(); i++) {
		rectangle(img, faces[i].tl(), faces[i].br(), Scalar(255, 0, 255));
	}

	imshow("Image",img);
	waitKey(0);
}