#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

using namespace std;
using namespace cv;
/// <summary>
/// Shapes Detection
/// </summary>

///////Function to Get Contours of preprocessed image----------------
void getContours(Mat imgDil, Mat img) {

	//contours will be a Vector & inside the vector it's like list & inside that list there is another list diff points
	/*{ {Point(20,30),Point(50,60)},
		{},
		{}};
		this above kind of structure we create below to get contours
		*/
	//Contours decleration
	vector<vector<Point>> contours;

	//basically hierarchy is  a vector consisting four integer values inside
	//Hierarchy decleration
	vector<Vec4i> hierarchy;

	//vector<Rect> boundRect(contours.size());//it is declaration of vector variable
	string objectType;

	//findContours(input img,contours, hierarcry, type or method,chain approximation )
	findContours(imgDil, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
	//drawContours(img,contours,-1,Scalar(255,0,255),2);

	//here we represented all contours without any filters every image get detected 
	//Let's take a condition like if some shapes are too less in area then no. contour will draw


	for (int i = 0; i < contours.size(); i++) {
		int area = contourArea(contours[i]);// this function here will help us to find the area of the shapes
		cout << area << endl;//to print the areas 

		vector<vector<Point>> conPoly(contours.size());//declaration of conPoly which contains only some specific points of curves only out of contours.size
		vector<Rect> boundRect(contours.size());
		

		if (area > 1000) {
			//Now here we try to find out bounding box around the shape to that 
			
			float peri = arcLength(contours[i], true);//true here tell that countour around the shape is closed
			//Now we will try to find the corners Or No. of curves that perticular polygon has.
			//if polygon has 4 curves or 4 corner points then its a rectangle or if it has 3 curves then its triangle if alot curver then its circle

			approxPolyDP(contours[i], conPoly[i], 0.02 * peri, true);//approxPolyDP(contours of i th element, output poly, random no. multiplied by peri OR we can use any random no., true for complete polygon)  

            drawContours(img, conPoly, i, Scalar(255, 0, 255), 2);//here this will draw contours using some specific corners

			//Now to determine the shape name , if we check the lenght of any of conPoly thatmay give us approximation of whereter its a rectangle or square
			cout << conPoly[i].size() << endl;

			//-----------------------------------------------------------------------------------------------------------------------------------------------------------
			//just to show the box around maximum covering area
            			boundRect[i] = boundingRect(conPoly[i]); //it is a function to get bound rectangle(shapes covering max area) around shapes
						//
						////boundRect[i].tl():- only for topleft points    && boundRect[i].br():- for bottom left points
						rectangle(img, boundRect[i].tl(), boundRect[i].br(), Scalar(0, 255, 0), 2);// It will draw rectanle of max area covered by any detected shape
			//-----------------------------------------------------------------------------------------------------------------------------------------------------------

			//To give the name of shape using above informations
			int objCorner = (int)conPoly[i].size();

			if (objCorner == 3) { objectType = "Triangle"; }
			else if (objCorner == 4) { 
				//objectType = "Rectangle";  //this here will show square and rectangle as rectangle
			    //to differ between square and rectange we use ratio like when we divide width by heigh or vice verse it should give us value 1 for square
				//but in real there is always some variation in square so instead of giving exact 1, we difine a range 

				float aspRatio = (float)boundRect[i].width / (float)boundRect[i].height;
				if(aspRatio>0.95 && aspRatio < 1.05){ objectType = "Square"; }
				else { objectType = "Rectangle"; }
			}
			else if (objCorner > 4) { objectType = "Circle"; } 

			//To write the shape name 
			putText(img, objectType, { boundRect[i].x,boundRect[i].y - 5 }, FONT_ITALIC, 0.75, Scalar(0, 255, 0),1);

		}
	}
}


int main() {

	Mat imgGray, imgCanny, imgDia, imgErode, imgBlur;

	string path = "Resources/shapes.png";
	Mat img = imread(path);
	////////////////**************** Pre-processing of Image********** //////////////////////////
	
	// First we have to do preprocessing of image before we find shapes
	//If we find the edges of our image then we can find of which shape this image is
	//We use canny edge detector to detect image
	GaussianBlur(img, imgBlur, Size(3, 3), 3, 0);
	Canny(imgBlur, imgCanny, 25, 75);
	Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
	dilate(imgCanny, imgDia, kernel);
	//------------------------------------------------------------------------------------------

	//Now We try to find the contures of edges to detect shape-----------
	getContours(imgDia,img);

	imshow("Image", img);
	//imshow("Image Gray", imgGray);
	//imshow("Blur Image", imgBlur);
	//imshow("Canny Image", imgCanny);
	//imshow("Dialated Image", imgDia);
	waitKey(0);
	return 0;
}