//
//  diffMethods.hpp
//  RacingTrackOutline
//
//  Created by Marvin Aquino on 13/10/16.
//  Copyright © 2016 Marvin Aquino. All rights reserved.
//

#ifndef diffMethods_hpp
#define diffMethods_hpp

#include <stdio.h>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/core.hpp>

class diffMethods{
private:
    int ddepth = -1;
    const int iter=16;
    const double k=23,lambda =1.0/7.0;
    double  dx=1,dy=1,dd= sqrt(2);
    double idxSqr = 1.0/(dx*dx),idySqr = 1.0/(dy*dy),iddSqr = 1/(dd*dd);
    cv::Mat nablaN,nablaS,nablaW,nablaE,nablaNE,nablaSE,nablaSW,nablaNW;
    cv::Mat cN,cS,cW,cE,cNE,cSE,cSW,cNW;
    float ahN[3][3] = { {0, 1, 0}, {0, -1, 0}, {0, 0, 0} };
    float ahS[3][3] = { {0, 0, 0}, {0, -1, 0}, {0, 1, 0} };
    float ahE[3][3] = { {0, 0, 0}, {0, -1, 1}, {0, 0, 0} };
    float ahW[3][3] = { {0, 0, 0}, {1, -1, 0}, {0, 0, 0} };
    float ahNE[3][3] = { {0, 0, 1}, {0, -1, 0}, {0, 0, 0} };
    float ahSE[3][3] = { {0, 0, 0}, {0, -1, 0}, {0, 0, 1} };
    float ahSW[3][3] = { {0, 0, 0}, {0, -1, 0}, {1, 0, 0} };
    float ahNW[3][3] = { {1, 0, 0}, {0, -1, 0}, {0, 0, 0} };
    
    cv::Mat hN = cv::Mat(3, 3, CV_32FC1, &ahN);
    cv::Mat hS = cv::Mat(3, 3, CV_32FC1, &ahS);
    cv::Mat hE = cv::Mat(3, 3, CV_32FC1, &ahE);
    cv::Mat hW = cv::Mat(3, 3, CV_32FC1, &ahW);
    cv::Mat hNE = cv::Mat(3, 3, CV_32FC1, &ahNE);
    cv::Mat hSE = cv::Mat(3, 3, CV_32FC1, &ahSE);
    cv::Mat hSW = cv::Mat(3, 3, CV_32FC1, &ahSW);
    cv::Mat hNW = cv::Mat(3, 3, CV_32FC1, &ahNW);
public:
    void anisotropicDiffusion(cv::Mat out, int width,int height);
};

#endif /* diffMethods_hpp */
