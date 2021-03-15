#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream> //input output stream

using namespace std;//to remove std:: 
using namespace cv;//to remove cv::

	////Importing images////

	//we don't want any output so we use void main() below
//void main() {
//	//string here only recognize using std lib to define string we need below representaiton
//		//std::string;
//		//cv::imread;
//	//OR we can use two header file above 1. using namespace std;(to remove std::string)
//	//2. using namespace cv;(to remove cv::imread) so I'm gonna use these header file )
//	string path = "Resources/test.png";
//	Mat img = imread(path);   //Mat is the matrix datatype to handle all the images,introduced by the openCv
//	imshow("Image", img); //this will show the image but close automatically
//	waitKey(0);//this function will not let the image close automatically 
//}

	/// <summary>
	/// Video Capturing
	/// </summary>
	/// usually video is basically series of frame so we have to capture all sequence of frames one by one and 
	/// represent it as video
//void main() {
//	string path = "Resources/test_video.mp4";
//	//video capture object to capture images from given path
//	VideoCapture cap(path);
//	Mat img;
//	while (true) {
//		cap.read(img);
//		imshow("Video", img);
//		waitKey(20);
//	}
//}
 
///////////////  Webcam //////////////////

int main() {
	//we have to add id no. of our camera 0 if we have one camera
	VideoCapture cap(0);
	Mat img;
	while (true) {
		cap.read(img);
		imshow("webcam", img);
		waitKey(1);
	}

}