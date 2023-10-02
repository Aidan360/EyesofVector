#include "spac.hpp"
#include <array>
// Screen Ratio 30:17 
extern int screenMaxX;
extern int screenMaxY; 
namespace vectorR{


    void createOffset(int thickness);
    class keyBoard { 
        public: 
        void start();
        void render();
        void kill();
        void detect();
        int letterCount = 6;
        bool numbersOnly = true;
        std::vector<std::string> input;
        int rows[5] = {letterCount, 10, 10, 9, 9}; 
        std::string rowContent [4][10] = {
        {"0","1","2","3","4","5","6","7","8","9"},
        {"Q","W","E","R","T","Y","U","I","O","P"},
        {"A","S","D","F","G","H","J","K","L"},
        {"Z","X","C","V","B","N","M","DEL","ENT"},
        }; 
        private: 
        int borderOffset = 12; // creating the Green Offset Border
        int screenX = screenMaxX - borderOffset;
        int screenY = screenMaxY - borderOffset;
        int spaces; 
        int squareHeight;
        int squareLength;
        int killNum = 0;

        // row 5 has enter and space

    };
    class autonmousInput { // show field for touch screen usage, and stat inputs on the left
        public: 
        void start();
        void render(); 
        void detect();
        void kill();
        int inSpeed; // whenever inputting round down
        int inSize; // whenever inputting round up 
        std::vector<float> noGoZone; // removes triballs from autonmous selection, 
        int partnerStart; // 1-4 correlated to the set starting positions 
        int selfStart; // our starting position
        bool color; // red is false blue is true 
        private:
        int borderOffset = 12; // creating the Green Offset Border
    };
    class preview { 
        public:
        void start();
        void kill();
        std::string autonomousName;
        private: 
        int borderOffset = 12; // creating the Green Offset Border
    };

    class startScreen {
        public: 
        void start();
        void render(); 
        void detect();
        void kill();
        std::string autonomousName; 
        private:
        int borderOffset = 12; // creating the Green Offset Border
        int screenX = screenMaxX - borderOffset;
        int screenY = screenMaxY - borderOffset;
        int leftColProp = 3; // proportions of screen
        int rightColProp = 7; // proportions of screen
        int rowProp = 5; // proportions of screen
    };


}