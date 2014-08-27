#ifndef STIMULUS_H
#define STIMULUS_H


#pragma once
#include <vector>
#include <opencv/cxcore.h>
#include <opencv/highgui.h>
#include <opencv2/opencv.hpp>

class Stimulus {
public:
    static int StimulusIdCounter;
    int StimulusID; //unique ID for each stimuli
    //defines what action each stimulus coresponds to
    enum action_t {
        UNDEFINED,  // undefined 
        IMAGE_GRID, // for stimuli on the grid
        ZOOM_MODE,  // zoom button   
        HOME,       // home button, goes HOME
        BACK,       // back one step
        PAUSE, SLEEP, SELECT_MODE, SELECT, PAN_MODE, MOVE_MODE ,
          CUSTOM_CMD1, CUSTOM_CMD2, CUSTOM_CMD3,
          PAN_LEFT, PAN_RIGHT, PAN_UP, PAN_DOWN, CONFIRM, CANCEL, EXPAND_SELECTION, ERR, DUMMY };
    action_t action;

    //double resultScore;
    std::vector<int> groupIDs;
    double getAvgScore(int  n = -1);
    bool addResult(double result);

    //constructors
	Stimulus();
    Stimulus(action_t ac);
	Stimulus(CvRect r, CvPoint offset = cvPoint(0,0), enum action_t ac = UNDEFINED );

    bool contains(CvPoint a); // check if point a is inside the stimulus screen regieon
    CvPoint getCenter(); //gets the center location of the stimulus

    CvRect rel_scr_region; // location in Image. Useful for zoomed in imges
	CvRect abs_scr_region; // screen area in display window
    double clasificationScore;
    std::vector<double> resultScores;
    bool noDisplay;
	
private:
    
    

	

};

#endif