#include "screen.hpp"
void vectorR::keyBoard::start() {
    killNum = 0;
}
void vectorR::keyBoard::render() { 
    createOffset(borderOffset);
    squareHeight = screenY/5;
    squareLength = screenX/10; 
    spaces = (screenX - letterCount*squareLength)/2; 
    for (int i = 0; i < letterCount; ++i) { // gets the first row, spaces is the blank space, s
         pros::screen::set_pen(COLOR_DEEP_SKY_BLUE);
        pros::screen::draw_rect(borderOffset + spaces + squareLength * i, borderOffset, borderOffset + spaces + squareLength*(i+1), borderOffset + squareHeight);
        if(size(input) >= i) {
            pros::screen::print(pros::E_TEXT_SMALL,(borderOffset + spaces + (squareLength*i) + squareLength/2), (squareHeight/2), "d%", input[i]);
        }
    }
     pros::screen::set_pen(COLOR_WHITE);
    for (int i = 1; i < std::size(rows); ++i) { // gets keyboard rows i is for all y calc, j is for all x calc. should print individual letters. 
        for (int j = 0; j < std::size(rowContent[i]); ++j) {
            pros::screen::draw_rect(borderOffset + squareLength * j, borderOffset + squareHeight*i, borderOffset + squareLength*(j+1), borderOffset + squareHeight*(i+1));
            pros::screen::print(pros::E_TEXT_SMALL,borderOffset + squareLength*(j) + squareLength/2, squareHeight * i + (squareHeight/2), "d%", rowContent[i-1][j]); 
        }
    }
}
void vectorR::keyBoard::detect() { 
    pros::screen_touch_status_s_t status;
    status = pros::c::screen_touch_status();
    if ((status.touch_status = pros::E_TOUCH_PRESSED)){ 
        float touchX = status.x; 
        float touchY = status.y; 
        int row = int(status.y/squareHeight);
        int column = int(status.x/squareLength);
        if (row == 0) {
        }
        else if ((row = 5) && (column = 8)) {
            kill();
        }
        else if ((row = 5) && (column = 7)) {
            input.clear();
        }
        else {
            input.push_back(rowContent[row-1][column-1]);
        }
    }
}
void vectorR::keyBoard::kill() {
    killNum = 1;
}