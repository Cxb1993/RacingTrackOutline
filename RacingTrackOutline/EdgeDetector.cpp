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

void EdgeDetector::setLowThreshold(int lowT){
    lowThreshold = lowT;
}

void EdgeDetector::setEdgeThreshold(int edgeT){
    edgeThreshold = edgeT;
}

void EdgeDetector::setWindowname(char *Window_Name){
    WindowName = Window_Name;
}

void EdgeDetector::cannyThreshold(cv::Mat src,int,void*,int width,int height){
    cv::cvtColor(src, src_gray, CV_BGR2GRAY);
    //cv::GaussianBlur(src_gray, detetected_edges, cv::Size(3,3),4000);
    diff.anisotropicDiffusion(src_gray, width, height);
    cv::Canny(src_gray, detetected_edges, lowThreshold, lowThreshold*ratio, kernelSize);
    detetected_edges.convertTo(detetected_edges, CV_8U);
    cv::HoughLinesP(detetected_edges, lines, 1, CV_PI/180,108,95,10);
    for( size_t i =0;i<lines.size();i++){
        double Angle = atan2(lines[i][2]-lines[i][0],lines[i][3]-lines[i][1])*180.0/CV_PI;
        if((Angle < 140 && Angle > 40) || (Angle>220 && Angle<320)){
            cv::line(src, cv::Point(lines[i][0], lines[i][1]), cv::Point(lines[i][2], lines[i][3]),cv::Scalar(0,0,255),3,8);
        }
    }
    dst = cv::Scalar::all(0);
    src.copyTo(dst, detetected_edges);
    cv::imshow(WindowName, dst);
}
