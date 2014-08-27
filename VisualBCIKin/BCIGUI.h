#pragma once

#include <opencv/cxcore.h>
#include <opencv/highgui.h>
#include <opencv2/opencv.hpp>
#include <pcl/point_types.h>
#include <pcl/point_cloud.h>
#include "PointCloudCapture.h"
#include "BCITypes.h"


#include "./BCIGUI/zoom_lvl.h"
#include "./BCIGUI/Disp_Win.h"
#include "./BCIGUI/frame_obj.h"
#include "./BCIGUI/pan_mode.h"
#include "./BCIGUI/BumbleCam.h"
#include "./BCIGUI/Stimulus.h"
#include "./BCIGUI/Stimulus_presentation.h"
#include "./BCIGUI/ObjMatch.h"

class BCIGUI
{
public:
	BCIGUI(void);
	~BCIGUI(void);

	frame_obj* curr_frame;                //selection grid
	Disp_Win* main_disp;                  // display Window
	PointCloudCapture* stereo_cam;        //camera object
	Stimulus_presentation* stimu_present;

private:
	// for mouse override 
	bool mouseInterupt; // = false;
	CvPoint mousePointerPos; 

};

