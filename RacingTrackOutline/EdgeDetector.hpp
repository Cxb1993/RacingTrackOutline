//
//  EdgeDetector.hpp
//  RacingTrackOutline
//
//  Created by Marvin Aquino on 10/3/16.
//  Copyright © 2016 Marvin Aquino. All rights reserved.
//

#ifndef EdgeDetector_hpp
#define EdgeDetector_hpp

#include <stdio.h>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

#endif /* EdgeDetector_hpp */

class EdgeDetector{
private:
    int edgeThreshold, lowThreshold, ratio = 3, kernelSize;
    int const maxLowThreshold = 100;
    char* WindowName;
    cv::vector<cv::Vec4i> lines;
    cv::Mat src_gray,dst,detetected_edges;
    
public:
    void setKernelSize(int kernelS);
    void setLowThreshold (int lowT);
    void setEdgeThreshold(int edgeT);
    void setWindowname(char* Window_Name);
    void cannyThreshold(cv::Mat src, int,void*);
    
};
