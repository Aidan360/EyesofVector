#include "screen.hpp" 

void vectorR::startScreen::render() {
    createOffset(borderOffset);
    pros::screen::set_pen(COLOR_WHITE);
    pros::screen::draw_rect(borderOffset + screenX/5, borderOffset + screenY/7, borderOffset + 2*(screenX/5), borderOffset + 2*(screenY/7)); // left button
    pros::screen::set_pen(COLOR_CORAL);
    pros::screen::print(E_TEXT_SMALL,borderOffset + 1.5*screenX/5 , borderOffset + 1.5*screenY/7, "SPAC"); // left button text    
    
} 