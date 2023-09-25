
#include "main.h"
#include "controller.hpp"
#include <limits>
#include <vector>
namespace vectorR {
/* 
12 Field Triballs Points , 4 Climbing Points, 2 Center Barrier points, 
4 side barrier points, 8 Net points, 12 loading zone points, 
4 starting points, 6 center line points, 
First half of colored things are red, second half of colored things are blue. 
*/
extern float CompetitionFieldObjectArray[4][52];
/*
12 Field triballs points, 4 climbing points, 2 center barrier points, 
4 side barrier points, 8 net points, 
12 loading zone points, 2 starting points. 
*/
extern float SkillsFieldObjectArray[3][44]; 

class triball {
    public: 
    float x;
    float y; 
    float id;
    float status;
    bool rendered;
    std::string Color = "green";
    void render();
    void destroy();
    private: 
    float Diameter = 6.18;
};

class barriers {
    float x1; // dot 1 and dot 2 to make lines
    float x2;
    float y1;
    float y2;
    bool rendered;
    std::string Color = "black";
    void render();
    void destroy();
    private: 
    float thickness = 2.38;
};

class field{
    float x1; // long tape X
    float x2;
    float x3; // short tape red X
    float x4;
    float x5; // short tape blue X 
    float x6;
    float y1;
    float y2;
    float y3;
    float y4;
    float y5;
    float y6;
    std::string backgroundColor = "Gray";
    std::string tapeColor = "White";
    void render();
    void destroy();
    private: 
    int fieldSize = 140;
};

class goal{
    float x1;
    float x2;
    float x3;
    float x4;
    float y1;
    float y2;
    float y3;
    float y4;
    std::string color;
    void render();
    void destroy();
};
class matchLoad {
    float x1;
    float x2;
    float x3;
    float y1;
    float y2;
    float y3;
    std::string color;
    void render();
    void destroy();
};
class climbingPole {
    float x1;
    float x2;
    float y1;
    float y2;
    std::string color;
    void render();
    void destroy();
};


class spac {
 public:
    float timeTotal;
    float timeRemaining;
    std::vector<float> triballDistances;
    std::vector<float> goalDistances;
    std::vector<float> poleDistances;
    void Screen();
    void renderAll();
    void Save();
    void Run();
    void pathFind();
    void input();
    

};

}