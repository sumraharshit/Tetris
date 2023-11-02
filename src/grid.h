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
    bool isCellOutsideGrid(int row, int column);
    bool CellEmpty(int row, int column);

    int ClearFullRows(); // a implementation of all the Rowfull(), RowClear(), MoveRow();

private:
   int numRows;
   int numColms;
   int cellSize;
   std::vector<Color> colours; // after we have printed the grid and gave it the value 0 we have to guve colors to different blocks of tetris
   bool Rowfull(int row); //checks whether the row is full or not
   void RowClear(int row); // clears the row when the row is full
   void MoveRow(int row, int numRows); // Moving the rows down when cleared
};
