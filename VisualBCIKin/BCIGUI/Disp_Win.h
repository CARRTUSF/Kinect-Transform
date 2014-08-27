#ifndef DISP_WIN_H
#define DISP_WIN_H


#pragma once
#include <iostream>
//#include <vector>
//#include <algorithm>
#include <string>
#include "Menu.h"
#include "frame_obj.h"
#include "Stimulus.h"
#include <opencv/cxcore.h>
#include <opencv/highgui.h>
#include <opencv2/opencv.hpp>

using namespace std;

class Disp_Win{

public:

    vector<Stimulus> frame_stimuli;
    vector<Stimulus> menu_stimuli;
    /*flag to indicate we're busy displaying stimuli. we do not want to change menu's in the middle of a stimulus sequence
     Menu changing function(with mouse/ pointing device will wait for this flag to be false before changing menu )*/
    bool busy_displaying;

    Disp_Win(int disp_h,
             int disp_w, 
             int menu_w,
             IplImage *img
             );

    ~Disp_Win();  //destructor
    void update_display(IplImage* img, CvRect area);
    // resizes if not correct size and then display.does not modify passed parameter
    void update_view(IplImage* img);
     // updates the current display image and stimuli
    void update_frame(frame_obj* cur_frame);
    void update_menu(string m);
    /* a menu bar on the left side of the screen. will only be used when nesscerry.
    (also used for displaying the customized actions for identified objects) */
    void update_left_menu(string m){};

    /* getContainingStimulus(CvPoint x) function will return a stimulus that contains the given mouse pointer co-ordinates
    allows the BCI GUI to be tested with a mouse //*/
    Stimulus getContainingStimulus(CvPoint x);

    // active stimuli is frame stimuli + menu stimuli
    vector<Stimulus> get_active_stimuli();


	/**
	 * \brief Displays group of stimuli on screen for duration ms
	 * \param <stimuli> - group of stimuli as a vector<Stimulus>
	 * \param <duration> - stimulus on time (i.e time it is highlighted)
	 */
    void show_stimuli(vector<Stimulus> stimuli, int duration = 500);

    void show_stimulus(Stimulus s, int delay);
    void reDrawDisplay();

	/* The following functions return parameters about the display size */
    int get_disp_height() { return disp_height; }
	int get_disp_width() { return disp_width; }
	int get_menu_width() { return menu_width ;}
    CvSize getCanvasSize() { return cvSize((disp_width + menu_width),disp_height); }
    IplImage* getDispImage(){ return disp_canvas;}
    void setup_stimuli_presentation(vector<Stimulus> stimuli);
  

private:

	int disp_height;
    int disp_width;
    int menu_width;
    
    IplImage* disp_canvas ;
    IplImage* temp_disp_canvas ;
    IplImage* sel_obj    ; 
    IplImage* temp_img ;

    Menu_group* menu_select ;
    Menu_group* menu_home ;
    Menu_group* menu_pan ;
    Menu_group* menu_zoom;


    CvRect view_area;
    CvRect menu_area;


    void update_display_resize(IplImage* img,  CvRect  view_area);
    void initialize_menus();

    // visual stimulus presentstion modes
    void highlightBorders(vector<Stimulus> stimuli); // drwars a box around the stimulus
    void invertColors(vector<Stimulus> stimuli); // inverts the color of the stimulus regeion
    void invertColorsCenter(vector<Stimulus> stimuli); // inverts the color of the stimulus regeion
    void invertColorsCenter2(vector<Stimulus> stimuli); // inverts the color of the stimulus regeion

};

#endif