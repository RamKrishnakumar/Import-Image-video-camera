# OpenCV-learning-basics
Learning OpenCV Basics

Setup the EnvironMent 
# Virtual-Paint
Creating Virtual Painter using OpenCV

Installation of OPENCV Windows
Step1. Go to https://github.com/opencv/opencv and download the Lastest Release
       Extract it Anyweher you want to extract 
       In My case C:\Users\vk560\Documents\
Step2. Add bin folder to the Environment Variables path
       In My case : C:\Users\vk560\Documents\opencv\build\x64\vc15\bin
       Restart Computer
Step3. Clone Repositry using Visual Studio 2019 .
Step4. Set the platform target to x64
       Add Directories by going to Project-Properties-Configuration Properties-
             VC++ Directories
                1. Add Build Directories: D:\opencv\build\include
                2. Add Library Directories: D:\opencv\build\x64\vc15\lib
             Linker Input 
                3. Add Linker input: opencv_world450d.lib
                   d for debug without d for release 
                   
Now  All set Play

At the same time we can run only 1 out of 8 below .cpp file 
So first of all you have to Exclude all file except the one that you want to use if file are not exclude already
/////To Exclude from project//////////
1. Right click on the perticular .cpp file then,
2. Click on Exclude from Project 


To use files one by one below files:-
1import-image-vid-camera.cpp
2basicfunction.cpp
3Image-resize-crop.cpp
4Drawing-shapes-text.cpp
5Warp-Perspective.cpp
6Color-Detection.cpp
7Shapes-Detection.cpp
8Face-Detection.cpp

1. Pull the project in VS 2019
2. then click Right mouse button on a perticular file you want to run
3. Click Include in Project .
