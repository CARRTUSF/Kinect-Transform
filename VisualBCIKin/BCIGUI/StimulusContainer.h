#pragma once
#ifndef STIMULUS_CONTAINER_H
#define STIMULUS_CONTAINER_H
 /*
 Wiritten by Indika Pathirage
 USF CARRT WMRA-BCI project September 2012
 
 This class will contain functionality:
  1) act as a container for stimuli.
  2) organize stimuli into groups for presentation
  3) keep track of results for each stimuli.
  4) Calculates the checker board pattern etc..
*/


#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <time.h>
#include "Stimulus.h"
#include "Disp_Win.h"

using namespace std;



struct stimulusGroup{
    vector<Stimulus> stimuli;
    int groupID;
    double result;
};

typedef vector<stimulusGroup> Sequence;

class StimulusContainer{
public:
    StimulusContainer();
    void setDisplay(Disp_Win *disp);
    //~StimulusContainer();
    void addStimuli(Stimulus s);
    void addStimuli(vector<Stimulus> stimuVec);
    void addStimuli(CvRect r, CvPoint offset);
    void clear_stimuli();
    void clear_scores();
    Sequence newStimulusGrouping();
    //Sequence stimulusGroups;
    vector<Sequence> sequences;
    /* input: map<groupID, result> */
    bool storeResults(const Sequence &seq, map<int, double> groupResults);
    Stimulus getSelectedStimulus();
    Stimulus getSelectedStimulus2(int n,int highestN);
    /* saves an image of the stimuli on disk */
    void debugDrawStimuli(Stimulus selected, vector<Stimulus> sVec);
    vector<Stimulus> getActiveStimuli();
    vector<int> getRandomSequence(int n);
    

private:

    
    int rows;
    int columns;    
    map<int, Stimulus> StimuliMap; // holds stimuli that are currrntly valid.
    vector<Stimulus> curStimuli;
    int originalNumStimuli;
    int num_stimuli_groups;
    Stimulus selectedStimu;
    Disp_Win *display;
    void calculate_grid_size();
    void pad_grid();
    
    int isAcceptbleSeq(Sequence &groups);
    Sequence createGroups();
    
};

#endif