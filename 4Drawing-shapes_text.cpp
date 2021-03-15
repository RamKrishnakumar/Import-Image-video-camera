#include<opencv2/imgcodecs.hpp>
#include<opencv2/imgproc.hpp>
#include<opencv2/highgui.hpp>
#include<iostream>
using namespace std;
using namespace cv;

//////////////to draw shapse and to write text on images////////////////
void main() {

	////////////////////   Blank Image generate //////////////////////

	Mat img(512, 512, CV_8UC3, Scalar(255, 255, 255));// Mat img(size,size, type, Scaler(R,G,B)), to declare color we use Scaler() having RGB value
	              ///(CV_8UC3) :- 8 represent 8bits which is Unsigned represented by U nd  C3: channel 3(Red,Green,Blue)
	
	/////////////////// Generate Circle shape image ///////////////////
				/*circle(InputOutputArray img, Point center, int radius,
				const Scalar& color, int thickness = 1 or FILLED to fill shape,
					int lineType = LINE_8, int shift = 0);*/	
	circle(img, Point(256, 256), 155, Scalar(255, 0, 0),FILLED); // (256,256) is half of above (512,512) that defines center point
	
	////////////////// To Draw a rectangle ///////////////////////////
    /*rectangle(InputOutputArray img, Point pt1, Point pt2,
                          const Scalar& color, int thickness = 1,
                          int lineType = LINE_8, int shift = 0);*/
	//rectangle(img,Point(130,226),Point(382,286), Scalar(255,255,255),3);

	        ////////////////////  OR //////////////////////////////////////

	/*rectangle(InputOutputArray img, Rect rec(X,Y,Width,height),const Scalar& color, int thickness = 1,int lineType = LINE_8, int shift = 0);*/
                                             //X,Y represent point of starting of rectangle
	rectangle(img, Rect(130, 226, 252, 60), Scalar(0, 0, 0), FILLED);

	///////////////////// To Draw a line ////////////////////////////
	/*line(InputOutputArray img, Point pt1, Point pt2, const Scalar& color,
                     int thickness = 1 or FILLED, int lineType = LINE_8, int shift = 0);*/
	line(img, Point(130, 296), Point(382, 296), 2);

	///////////////////Draw Text on Image ////////////////////////
	/*putText( InputOutputArray img, const String& text, Point org,
                         int fontFace, double fontScale, Scalar color,
                         int thickness = 1, int lineType = LINE_8,
                         bool bottomLeftOrigin = false );*/
	putText(img, "    JackFarrum  AutoBot ", Point(137, 262), FONT_ITALIC, 0.5, Scalar(0, 69, 255), 2);

	imshow("Image", img);//to show our genrated image 
	waitKey(0);
}