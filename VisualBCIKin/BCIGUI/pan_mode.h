

#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <opencv/cxcore.h>
#include <opencv/highgui.h>
#include <opencv2/opencv.hpp>
#include <assert.h>
#include "Disp_Win.h"
#include "BumbleCam.h"

using namespace std;
class pan_mode {

public:
	Disp_Win* main_disp;
	BumbleCam* stereo_cam ;

	IplImage* disp_img;

	pan_mode(Disp_Win* disp, BumbleCam* cam);
	~pan_mode();

	void pan(CvPoint m); 
	void standby();


private:

	static const int delay = 10;

	CvRect up_button;
	CvRect left_button;
	CvRect right_button;
	CvRect down_button;

	bool contained(CvRect& area, CvPoint p);

	void show_live_feed(int d);
	void draw_buttons();

};