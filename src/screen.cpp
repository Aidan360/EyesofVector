#include "screen.hpp"
#include "pros/colors.h"
#include "pros/motors.hpp"
#include "pros/screen.h"

     int screenMaxX = 480;
     int screenMaxY = 272; 

void vectorR::createOffset(int thickness) { 
   // pros::screen::set_pen(COLOR_VECTOR_GREEN);
    for (int i = 0; i < thickness; ++i) {
            pros::screen::draw_rect(0 + i,0 + i,screenMaxX - i,screenMaxY - i);
    }
}


