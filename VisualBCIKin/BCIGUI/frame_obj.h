#ifndef FRAME_OBJ_H
#define FRAME_OBJ_H

#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <opencv/cxcore.h>
#include <opencv/highgui.h>
#include <opencv2/opencv.hpp>
#include "zoom_lvl.h"
#include "BumbleCam.h"
#include "../PointCloudCapture.h"

/* The frame object class contains data structure to store one frame grabbed from the camera and to zoom into 
  that image. there is no inherent limit as as to how many zoom levels you can go down into, but it can be 
  restricted to a certain amount.
  
///********************************************************************************************************/// 
class frame_obj{
public:

    static const int disp_height = 600;
    static const int disp_width = 800;
    static const int rows = 4 ;
    static const int columns = 4 ;
    IplImage* orig_img ;  // original image, right camera
	IplImage* orig_img2 ; // left image for stereo depth functions (use when using a stereo camera)
    IplImage* disp_img  ;
    IplImage* mask; // mast indicating the flood filled area
    CvConnectedComp fillComp;
    //IplImage* sel_obj;

    int cur_lvl;
    vector<zoom_lvl*> z_lvls;

	std::vector<Stimulus> stimulus_boxes;   

    frame_obj(cv::Mat& imageMat);
    ~frame_obj();

    void get_new_frame(cv::Mat& imageMat);


	IplImage* select_obj(Stimulus s);
    IplImage* expand_selection();

    
   
    int zoom_in(CvRect r);
	int zoom_out();
	int go_home();
    void getMask(cv::Mat& _mask){
		cv::Mat temp = mask;
		temp.copyTo(_mask);		
	}; // returns mask 
    CvConnectedComp getFillComp(){return fillComp;} // returns connected component
    IplImage* getBaseImg(){return orig_img;};
    IplImage* get_sel_obj(); // returns selected object without resizing
    IplImage* show_sel_obj(); // return selected object resized to fit the main display
   

private:

    //pointer to camera object
    PointCloudCapture* stereo_cam ;

    CvScalar color;
    static const int flags = (255<<8) + 8 + CV_FLOODFILL_MASK_ONLY + CV_FLOODFILL_FIXED_RANGE;

	CvRect obj_area;

	/* flood fills the image with seed point.this is used as a mask */ 
    IplImage* floodfill(CvPoint seed);

	/* using the flood filled image as a mask will isolate the 
	corresponding image area from the original image */
    CvRect isolate(IplImage* mask);

	/* maps a CVrect into a Cvrect in the original image */
	CvRect get_original_loc(CvRect parent, CvRect zoom);
    CvPoint get_original_loc(CvRect parent, CvPoint p);

	/*given a CvRect inside the original image, 
	will increase size to correct the aspect ratio to the display ratio */
    CvRect fix_aspect(CvRect box);

    /* given a CvRect will zoom into that section of the original image 
	and returns an image with correct display width and height */
	IplImage* zoom_to(CvRect sel_area);

   /* object selection and expand functions  */
    void mark_obj_area(Stimulus s);
	void increase_obj_area();
    
	void update_stimulus_boxes();

};

#endif