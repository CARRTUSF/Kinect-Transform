#ifndef ZOOM_H
#define ZOOM_H


#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <assert.h>
#include "line_pair.h"
#include <opencv/cxcore.h>
#include <opencv/highgui.h>
#include <opencv2/opencv.hpp>
#include "Stimulus.h"


class zoom_lvl{

public:

	IplImage* img;
	IplImage* edges;
	IplImage* disp_img;
    CvRect original_grid; //stores origin to original image


	std::vector<int> v_grd_lns;
	std::vector<int> h_grd_lns;
	std::vector<int> v_dots;
	std::vector<int> h_dots;

	//these will store a CvRect for each box in the grid that we draw
	std::vector<Stimulus> stimulus_boxes;


	zoom_lvl(IplImage* img, CvRect original);
    ~zoom_lvl();
    //draws grid with given number of rows and columns
	void draw_grid(int rows, int columns);

    //given a row and a column will return a CvRect for that grid box
    CvRect get_Rect(int row, int column);

    //given a point will return a CvRect for the grid that contains that point
    CvRect get_Rect(CvPoint seed);

    CvPoint get_Center_dot(CvPoint seed);
    CvPoint get_Center_dot(CvRect r);

    CvPoint get_row_col(CvPoint a);
	
private:

    //helper functions
    void draw_grid_lines();
	//void zoom_lvl::create_stimuli_boxes();
    void edge_detect();
	int select_grid_lines(int rows, int columns);
	void create_stimulus_boxes();
	vector<int> get_highest_n(vector<line_pair> &sum_pairs,int grd_ln);


};

#endif