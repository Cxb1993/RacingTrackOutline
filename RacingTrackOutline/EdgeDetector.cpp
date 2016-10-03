//
//  EdgeDetector.cpp
//  RacingTrackOutline
//
//  Created by Marvin Aquino on 10/3/16.
//  Copyright © 2016 Marvin Aquino. All rights reserved.
//

#include "EdgeDetector.hpp"

void EdgeDetector::setKernelSize(int kernelS){
    kernelSize = kernelS;
}

void EdgeDetector::setThreshold(int edgeT, int lowT){
    edgeThreshold = edgeT;
    lowThreshold = lowT;
}

void EdgeDetector::setWindowname(char *Window_Name){
    WindowName = Window_Name;
}

void EdgeDetector::cannyThreshold(cv::Mat src,int,void*){
    cv::cvtColor(src, src_gray, CV_BGR2GRAY);
    cv::blur(src_gray,detetected_edges,cv::Size(3,3));
    cv::Canny(detetected_edges, detetected_edges, lowThreshold, lowThreshold*ratio, kernelSize);
    dst = cv::Scalar::all(0);
    cv::imshow(WindowName, dst);
}
