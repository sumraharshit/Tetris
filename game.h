#pragma once
#include "grid.h"
#include "blocks.cpp"

class Game
{ public:
   Game();
   Grid grid;
   // to hold the blocks that are randomly generated we have to define a vector
   Block GetRandomBlock();
   std::vector<Block> GetAllBlocks();
   void Draw();
   private:
   std::vector<Block> blocks;
   Block currentBlock;
   Block nextBlock;

};