//
//  diffMethods.cpp
//  RacingTrackOutline
//
//  Created by Marvin Aquino on 13/10/16.
//  Copyright © 2016 Marvin Aquino. All rights reserved.
//

#include "diffMethods.hpp"

void diffMethods::anisotropicDiffusion(cv::Mat output, int width,int height){
    for(int i = 0; i < iter; i++){
        cv::filter2D(output, nablaN, ddepth, hN);
        cv::filter2D(output, nablaS, ddepth, hS);
        cv::filter2D(output, nablaW, ddepth, hW);
        cv::filter2D(output, nablaE, ddepth, hE);
        cv::filter2D(output, nablaNE, ddepth, hNE);
        cv::filter2D(output, nablaSE, ddepth, hSE);
        cv::filter2D(output, nablaSW, ddepth, hSW);
        cv::filter2D(output, nablaNW, ddepth, hNW);
        //exponential flux
        cN = nablaN / k;
        cN = cN.mul(cN);
        cN = 1.0 / (1.0 + cN);
        //exp(-cN, cN);
        
        cS = nablaS / k;
        cS = cS.mul(cS);
        cS = 1.0 / (1.0 + cS);
        //exp(-cS, cS);
        
        cW = nablaW / k;
        cW = cW.mul(cW);
        cW = 1.0 / (1.0 + cW);
        //exp(-cW, cW);
        
        cE = nablaE / k;
        cE = cE.mul(cE);
        cE = 1.0 / (1.0 + cE);
        //exp(-cE, cE);
        
        cNE = nablaNE / k;
        cNE = cNE.mul(cNE);
        cNE = 1.0 / (1.0 + cNE);
        //exp(-cNE, cNE);
        
        cSE = nablaSE / k;
        cSE = cSE.mul(cSE);
        cSE = 1.0 / (1.0 + cSE);
        //exp(-cSE, cSE);
        
        cSW = nablaSW / k;
        cSW = cSW.mul(cSW);
        cSW = 1.0 / (1.0 + cSW);
        //exp(-cSW, cSW);
        
        cNW = nablaNW / k;
        cNW = cNW.mul(cNW);
        cNW = 1.0 / (1.0 + cNW);
        //exp(-cNW, cNW);
        
        output = output + lambda * (idySqr * cN.mul(nablaN) + idySqr * cS.mul(nablaS) +
                                    idxSqr * cW.mul(nablaW) + idxSqr * cE.mul(nablaE) +
                                    iddSqr * cNE.mul(nablaNE) + iddSqr * cSE.mul(nablaSE) +
                                    iddSqr * cNW.mul(nablaNW) + iddSqr * cSW.mul(nablaSW));
        
    }
}
