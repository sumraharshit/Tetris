#include "grid.h"
#include <iostream>
using namespace std;

Grid::Grid()
{
    numRows=20;
    numColms = 10;
    cellSize=30;
    Initialise();
    // now we need to initialise the grid so making another public method to initialise the grid
    colours = GetCellColors();
}
// implementation of initialisation of the grid
void Grid::Initialise()
{ 
  for(int row=0;row<numRows;row++)
  {
    for(int column=0; column<numColms; column++)
    {
      grid[row][column]=0; 
    }
  } }
 // now we have to print the grid aur to display the grid on the screen

 void Grid::Print()
 {
    for(int rows=0;rows<numRows;rows++)
    {
        for(int columns=0; columns<numColms;columns++)
        {cout<<grid[rows][columns]<<" ";}
        cout<<endl;
    }

   
 }
// after we have printed the grid and gave it the value 0 we have to guve colors to different blocks of tetris
std::vector<Color> Grid::GetCellColors()
{
   Color darkgrey={26, 31, 40, 255};
   Color green={47, 230, 23, 255};
   Color red={232, 18, 18, 255};
   Color orange={226, 116, 17, 255};
   Color yellow={237, 234, 4, 255};
   Color purple={166, 0, 247, 255};
   Color cyan={21, 204, 209, 255};
   Color blue={13, 64, 216, 255};

   return {darkgrey, green, red, orange, yellow, purple,cyan, blue};
}

void Grid::Draw()
{
  for(int row=0; row<numRows; row++)
  {
    for(int column=0; column<numColms; column++)
    {
      int cellValue = grid[row][column];
      // to draw the recangles on the grid
      // DrawRectangle(x cordinate, y cordinate, width, height, colour)
      // since we will be row and column to define cordinates we can mutiply cellSize with ro and columns to create an cell 
      DrawRectangle(column*cellSize+1, row*cellSize+1, cellSize-1, cellSize-1, colours[cellValue] );
      // now lets call the draw function we have created in the main
    }
  }
}