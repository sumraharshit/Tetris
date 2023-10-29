#pragma once
#include<vector>
#include<raylib.h>

class Grid
{
public:
    Grid();
     int grid[20][10];
    // initialising the grid
    void Initialise(); // making it public as it is required by other parts of the program as well
    void Print(); 
    void Draw();
   
private:
   int numRows;
   int numColms;
   int cellSize;
   // after we have printed the grid and gave it the value 0 we have to guve colors to different blocks of tetris
   std::vector<Color> colours;
};
