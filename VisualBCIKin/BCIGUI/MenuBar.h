

#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <opencv/cxcore.h>
#include <opencv/highgui.h>
#include <opencv2/opencv.hpp>
#include <iostream>
#include <iomanip>
#include <fstream>
#include "SockStream.h"
#include <vector>
#include <algorithm>
#include <assert.h>
#include <time.h>
#include "Disp_Win.h"
#include "BumbleCam.h"
#include "pan_mode.h"
#include "Stimulus.h"
#include "Stimulus_presentation.h"

using namespace std;

class MenuBar {

public: 
    //MenuBar();
    void add_menu(Menu_group  m){}; // adds a menu to the programs list of menus
    void set_menu(Menu_group  m){};


};