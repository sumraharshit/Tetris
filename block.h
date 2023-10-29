#pragma once
#include <vector>
#include <map>
#include "position.h"
#include "colour.h"

class Block
{  public:
   Block();
   void Draw();
   void Move(int row, int column);
   std::vector<Position> GetCellPosition();
   int id;                                     // to identify each block uniquely
   std::map<int, std::vector<Position>> cells; // a map where different roatation state will be stored
   private:
   int cellSize;
   int rotationState;
   // in order to move the blocks we can shift the origin of the blocks for that we have to calculate the new origin
   int rowOffset;
   int columnOffset;
   std::vector<Color> colours;
};