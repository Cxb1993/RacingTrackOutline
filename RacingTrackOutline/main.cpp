//
//  main.cpp
//  RacingTrackOutline
//
//  Created by Marvin Aquino on 9/15/16.
//  Copyright © 2016 Marvin Aquino. All rights reserved.
//

#ifdef __WIN32
    #include <Windows.h>
#elif __APPLE__
    #include <opencv.hpp>
    #include <highgui.hpp>
#endif
#include <iostream>
#include <opencv.hpp>
#include <highgui.hpp>
#include <EdgeDetector.hpp>

cv::Mat Video;
char* WindowName = "Video";
EdgeDetector edgeDetector;
int lowThreshold = 8,edgeThreshold= 1,curFrame;
int main(int argc, const char * argv[]) {
    cv::VideoCapture cap("/Users/marvingonaq/Documents/RacingTrackOutline/RacingTrackOutline/Full\ Lap\ Nurburgring\ Nissan\ -\ GTR.mp4");
    if(!cap.isOpened()){
        std::cout << "Error while opening file" << std::endl;
        return -1;
    }
    cap.set(CV_CAP_PROP_POS_MSEC, 2000);
    cap.set(CV_CAP_PROP_FPS,25);
    double fps = cap.get(CV_CAP_PROP_FPS);
    std::cout << "Frames per Second: " << fps << std::endl;
    cv::namedWindow(WindowName,CV_WINDOW_NORMAL);
    curFrame = cap.get(CV_CAP_PROP_POS_FRAMES);
    while(1){
        cv::Mat frame;
        bool bSuccess = cap.read(frame);
        
        if(!bSuccess){
            std::cout << "Cannot get frame from Video" << std::endl;
            break;
        }
        cv::resize(frame, frame, cv::Size(1280,720));
        edgeDetector.setWindowname(WindowName);
        edgeDetector.setKernelSize(3);
        cv::createTrackbar("Min Threshold", WindowName, &lowThreshold ,10);
        edgeDetector.setEdgeThreshold(edgeThreshold);
        edgeDetector.setLowThreshold(lowThreshold);
        edgeDetector.cannyThreshold(frame,0,0);
        //imshow(WindowName,frame);//Show current frame in "Video" window
        if(cv::waitKey(1)==27){
            std::cout << "'q' key has been pressed, closing video." << std::endl;
            cv:cvDestroyWindow(WindowName);
            break;
         }
        curFrame++;
    }
    //std::cout << "Using OpenCV" << CV_VERSION << "/n" <<std::endl;
    //std::cout << cv::getBuildInformation();
    return 0;
}
