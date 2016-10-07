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

void EdgeDetector::cannyThreshold(cv::Mat src,int,void*){
    cv::cvtColor(src, src_gray, CV_BGR2GRAY);
    //cv::medianBlur(src_gray,src_gray,5);
    cv::GaussianBlur(src_gray, detetected_edges, cv::Size(3,3),4000);
    cv::Canny(detetected_edges, detetected_edges, lowThreshold, lowThreshold*ratio, kernelSize);
    detetected_edges.convertTo(detetected_edges, CV_8U);
    cv::HoughLinesP(detetected_edges, lines, 1, CV_PI/180,115,100,5);
    for( size_t i =0;i<lines.size();i++){
        /*float rho = lines[i][0];
        float theta = lines[i][1];
        double a = cos(theta),b = sin(theta);
        double x0 = a*rho, y0 = b*rho;
        cv::Point pt1(cvRound(x0+1000*(-b)),cvRound(y0+1000*(a)));
        cv::Point pt2(cvRound(x0-1000*(-b)),cvRound(y0-1000*(a)));
        cv::line(detetected_edges, pt1, pt2, cv::Scalar(0,0,255));*/
        cv::line(src, cv::Point(lines[i][0], lines[i][1]), cv::Point(lines[i][2], lines[i][3]),cv::Scalar(0,0,255),3,8);
    }
    dst = cv::Scalar::all(0);
    src.copyTo(dst, detetected_edges);
    cv::imshow(WindowName, dst);
}
