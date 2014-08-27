#ifndef MENU_H
#define MENU_H


#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Stimulus.h"

using namespace std;


// Menu's will be loaded as a image with five menu items each.
class Menu_group {

public:
    Menu_group(IplImage* img, Stimulus::action_t actions[], int numActions);
    Menu_group(){};
    IplImage* menu_img ;
    vector<Stimulus> stimuli4Items;
    ~Menu_group()
    {
        cout << "Menu_group destructor called" << endl;
        //cvReleaseImage(&menu_img);
    }

private:


};

////when given a file name will create the menu
//Menu_grou::Menu_grou(string filename, int actions)
//{
//    menu_img = 0;
//    menu_img = cvLoadImage(filename.c_str());
//    Stimulus temp_stimulus;
//    CvPoint offset;
//    CvRect tempR = cvRect(0, 0 , 150, 85 );
//    //assert( menu_img != 0 );
//    int size = 2 ;//actions.size();
//    for(int i = 0; i < size ; i++)
//    {
//        //create a stimulus for every action
//       // offset = cvPoint(800, i*85 );
//        //temp_stimulus = Stimulus(tempR, offset, actions[i]);        
//        //stimuli4Items.push_back(temp_stimulus);
//
//    }
//    return;
//
//}


#endif