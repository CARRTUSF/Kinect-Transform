#ifndef STIMULUS_PRESENT_H
#define STIMULUS_PRESENT_H

#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <math.h>
#include <opencv/cxcore.h>
#include <opencv/highgui.h>
#include <opencv2/opencv.hpp>
#include <iomanip>
#include <fstream>
#include "SockStream.h"
#include <assert.h>
#include <time.h>
#include "Disp_Win.h"
#include "BumbleCam.h"
#include "pan_mode.h"
#include "Stimulus.h"
#include "ConsoleLogger.h"
#include "StimulusContainer.h"
#include <windows.h> <WINDOWS.H>
#include <strsafe.h> <STRSAFE.H>

typedef map<int, double> StimuScores;    

class Stimulus_presentation {

public :

    Stimulus_presentation(Disp_Win *d);
	vector<Stimulus> cur_stimuli;   
    Disp_Win *display;

	void clear_stimuli();
	void add_stimulus(Stimulus s);
    void add_stimuli(vector<Stimulus> stimuVec);
	void add_stimuli(CvRect r, CvPoint offset);
	
    
    Stimulus present_stimuli_onscreen(int numTimes, int numSequences = 3);
    void present_stimuli_onscreen_once(Sequence StimuGroups);


    StimulusContainer container;    
    static vector<StimuScores> ScoreSheet;
    static bool send_data;
    static bool result_rcvd;
    static bool bci_data_valid;
    
    Stimulus setected_stimulus;
    
    static std::string string2send; // be careful with memory
    static vector<double> classificationScores;
    static map<int,double> ResultScores; // used to store received results for all stimuli

private:

    static const int STIMULUS_ON_TIME = 200; // the time a a single stimulus remains highlighted onthe screen
    static const int INTER_STIMULUS_DURATION = 50 ; // the time between presentin two stimulus. ie the time between the end of first highlight and the begining of the second 
    static int expectedNumResults; // # of stimuli sent to BCI. wait till this many results are read from the BCI
    static int numResultSets; // num of result sets to read

    bool grid_mode;

    //int expectedNumResults; // wait till this many results are read.
    int originalNumStimuli;
    int num_stimuli_groups;   


    void send2BCI(string s);

    // http://stackoverflow.com/questions/4681581/how-do-i-call-worker-thread-in-a-same-class-c-mfc/4681614#4681614

    static DWORD WINAPI BCIreaderWrap(LPVOID pSelf);
    static DWORD BCIreader();
    static DWORD WINAPI BCIwriter(LPVOID pSelf);
    HANDLE startBCIreadThread();
    HANDLE startBCIwriteThread();
};

#endif