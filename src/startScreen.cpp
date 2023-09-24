#include "screen.hpp" 

void vectorR::startScreen::render() {
    createOffset(borderOffset);
    pros::screen::set_pen(COLOR_WHITE);
    pros::screen::draw_rect(borderOffset + screenX/) // left button
}