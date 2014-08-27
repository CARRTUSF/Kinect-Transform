#ifndef BUMBLECAM_H
#define BUMBLECAM_H


#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <opencv/cxcore.h>
#include <opencv/highgui.h>
#include <opencv2/opencv.hpp>

class BumbleCam 
{
public:
    BumbleCam(std::string type);
    IplImage* GrabHiRight();
    IplImage* GrabHiLeft();
    IplImage* GrabLowRight();
    IplImage* GrabLowLeft();
    IplImage* GrabImage();


private:
    //IplImage* Grabimage();
    CvCapture* capture ;
    CvCapture* capture2 ; 
    IplImage* img ;
    IplImage* img2 ;
    bool isStereo;

};

#endif