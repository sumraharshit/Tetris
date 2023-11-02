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
   void HandleInput();

   void MoveLeft();

   void MoveRight();

   void MoveDown();

   private:
   bool isBlockOutside();
   void BlockRotation();
   void Locking();
   bool CheckCollision();
   std::vector<Block> blocks;
   Block currentBlock;
   Block nextBlock;

};
