#include "grid.h"
#include "colour.h"
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

bool Grid::isCellOutsideGrid(int row, int column)
{
  if(row >=0 && row<numRows && column>=0 && column<numColms)
  return false;
  return true;

}

bool Grid::CellEmpty(int row, int column)
{  if(grid[row][column]==0)
  {return true;}

  return false;
}

int Grid::ClearFullRows()
{  int completed =0;
   for(int row = numRows-1; row>=0; row--)
   {
    if(Rowfull(row))
    {
       RowClear(row);
       completed++;
    }

    else if(completed>0)
    {
      MoveRow(row, completed);
    }
   }

   return completed;
}

bool Grid::Rowfull(int row)
{  for(int column = 0; column< numColms; column ++)
 {
   if(grid[row][column]==0)
    {
      return false;
    }
 }

 return true; 
}

void Grid::RowClear(int row)
{  
  for(int column = 0; column< numColms; column++)
  {
    grid[row][column]=0;
  }
}

void Grid::MoveRow(int row, int numRows)
{
  for(int column=0; column < numColms; column++)
  {
    grid[row+numRows][column]=grid[row][column];
    grid[row][column]=0;
  }
}
