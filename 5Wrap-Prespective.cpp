#include<opencv2/imgcodecs.hpp>
#include<opencv2/imgproc.hpp>
#include<opencv2/highgui.hpp>
#include<iostream>
using namespace std;
using namespace cv;

////////////////// Wraping Perspective ///////////////////
// In this we mark some images and shos their top view ///
//Any Image view, whatever the angle is wrap used to shows top view //

void main() {
	Mat king_matrix,queen_matrix,jack_matrix,nine_matrix, imgKing, imgQueen, imgJack,imgNine;
	string path = "Resources/cards.jpg";
	Mat img = imread(path);

////////////////// Warp Perspective of KING CARD //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

			//now We need some point to wrap image so here I use paint to find out coordinates of the imported image
            //src points
			Point2f kingsrc[4] = { {529,142},{771,190},{405,395},{674,457} };
			///////////  Aspect Ratio of cards (2.5:3.5)  ////////
			float w = 250, h = 350;
			//destination points
			Point2f kingdst[4] = { {0.0f,0.0f},{w,0.0f},{0.0f,h},{w,h} };

			//////////// We have to user transformation Matrix ////////
			king_matrix = getPerspectiveTransform(kingsrc, kingdst);///this matrix take some values and gives some correspending value after transformation
	
			//Warp Perspective
			warpPerspective(img, imgKing, king_matrix, Point(w, h));
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

////////////////Warp Perspective of Queen Card ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

			//Need some points using paint , source points
			Point2f queensrc[4] = { {66,325},{336,280},{94,631},{400,571} };

			//Destination Points Array
			Point2f queendst[4] = { {0.0f,0.0f},{w,0.0f},{0.0f,h},{w,h} };

			//Transformation matrix
			queen_matrix = getPerspectiveTransform(queensrc, queendst);

			//Warp Perspective
			warpPerspective(img, imgQueen, queen_matrix, Point(w, h));

////////////////Warp Perspective of Jack  Card ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

			//Need some points using paint , source points
			Point2f jacksrc[4] = { {778,108},{1017,85},{844,356},{1115,330} };

			//Destination Points Array
			Point2f jackdst[4] = { {0.0f,0.0f},{w,0.0f},{0.0f,h},{w,h} };

			//Transformation matrix
			jack_matrix = getPerspectiveTransform(jacksrc, jackdst);

			//Warp Perspective
			warpPerspective(img, imgJack, jack_matrix, Point(w, h));
////////////////Warp Perspective of Nine Card ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

			//Need some points using paint , source points
			Point2f ninesrc[4] = { {743,385},{1021,436},{649,708},{966,781} };
			//Destination points
			Point2f ninedst[4] = { {0.0f,0.0f},{w,0.0f }, {0.0f,h}, {w,h} };

			//Matrix Transformation
			nine_matrix = getPerspectiveTransform(ninesrc, ninedst);

			//Warp Perspective
			warpPerspective(img, imgNine, nine_matrix, Point(w, h));

////////////////// To create circles on point that we have have selected to do the warping /////////////////////////////////////////////////////////////////////////////////////////

			for (int i = 0; i < 4; i++) {
				circle(img, kingsrc[i], 6, Scalar(0, 0, 255), FILLED); // to mark corner points of king card with circle
				circle(img, queensrc[i], 6, Scalar(0, 0, 255), FILLED);// to mark corner points of queen card with circle
				circle(img, jacksrc[i], 6, Scalar(0, 0, 255), FILLED);// to mark corner points of jack card with circle
				circle(img, ninesrc[i], 6, Scalar(0, 0, 255), FILLED);// to mark corner points of nine card with circle
			}
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

	imshow("Image",img);
	//imshow("King image Warp", imgKing);
	//imshow("Queen Image Warp", imgQueen);
   // imshow("Jack Warp", imgJack);
    //imshow("Nine Warp", imgNine);
	waitKey(0);

}