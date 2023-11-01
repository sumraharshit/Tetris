#include "block.h"

Block::Block()
{
    cellSize=30;
    rotationState=0;
    rowOffset=0;
    columnOffset=0;
    colours = GetCellColors();
}

void Block::Draw()
{
    std::vector<Position> tiles = GetCellPosition();
    for(Position item:tiles)
    {
        DrawRectangle(item.column*cellSize+1, item.row*cellSize+1, cellSize-1, cellSize-1, colours[id]);
    }
}
// to move the block using rowOffset and columnOffset
void Block::Move(int row, int column)
{
    rowOffset += row;
    columnOffset += column;
}

// to calculate the position of the block after we have applied offset we can calculate it by using a different method
std::vector<Position> Block::GetCellPosition()
{
   // fisrt we need to have the default position of the block
   std::vector<Position> tiles = cells[rotationState];
   // now to store the new postion in a vector
   std::vector<Position> movedTiles;
   for(Position item: tiles)
   {
    Position newPosition = Position(item.row+rowOffset,item.column+columnOffset);
    movedTiles.push_back(newPosition);
   }
   return movedTiles;
}

void Block::Rotate()  // to roate the block will be called by the BlockRotation function in game file
{
    rotationState++;
    if(rotationState==(int)cells.size())
    rotationState=0;
}
