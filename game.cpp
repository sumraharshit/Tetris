#include "game.h"
#include <random>

Game::Game()
{
    grid = Grid();
    // now to randomly store a random block 
    blocks = GetAllBlocks();
    //defined the curretn and next bloack ad in the classic tetris game the current aand next blocks are shown
    currentBlock = GetRandomBlock();
    nextBlock = GetRandomBlock();
}

// we will create a random fuction to get the random block from the blocks vector

Block Game::GetRandomBlock()
{    if(blocks.empty())
{
       blocks = GetAllBlocks();
}
    int randomindex=rand() % blocks.size(); //will generate a random index number from the blocks vector and store in the randomindex
    Block block = blocks[randomindex];
    blocks.erase(blocks.begin()+randomindex);
    return block;
}

std::vector<Block> Game::GetAllBlocks()
{
    return {IBlock(), JBlock(), LBlock(), OBlock(), SBlock(), TBlock(), ZBlock()};
}

void Game::Draw()
{
    grid.Draw();
    currentBlock.Draw();
}

void Game::HandleInput()
{
    int keypressed = GetKeyPressed(); //GetKeyPressed() like many others, is a default function in raylib
     switch (keypressed)
     {
        case KEY_LEFT:
        MoveLeft();
        break;
        case KEY_RIGHT:
        MoveRight();
        break;
        case KEY_DOWN:
        MoveDown();
        break;
        case KEY_UP:
        BlockRotation();
        break;
        // now the main problem arises that the block goes out of the grid we have to resolve that
     }
    
}

void Game::MoveLeft()
{
    currentBlock.Move(0,-1);
    if(isBlockOutside()|| CheckCollision()==false)
    {
        currentBlock.Move(0,1); // what we have done here is that if the position of the block goes outside of the grid then it reverses
                                // its  position like here if move(0.-1) goes outside then isBlockOutside() function becomes true
                                // and position in reversed
    }
}

void Game::MoveRight()
{
    currentBlock.Move(0,1);
    if(isBlockOutside()|| CheckCollision()==false)
    {
        currentBlock.Move(0,-1);
    }
}

void Game::MoveDown()
{
    currentBlock.Move(1,0);
    if(isBlockOutside()|| CheckCollision()==false)
    {
        currentBlock.Move(-1,0);
        Locking(); //to lock the block at the bottom of the screen
    }
}

bool Game::isBlockOutside()  // to check if the block gets outside of the grid or not
{  std::vector<Position> tiles = currentBlock.GetCellPosition();
   for(Position item: tiles)
   {
    if(grid.isCellOutsideGrid(item.row, item.column))
    {
        return true;
    }
   }
    return false;
}

void Game::BlockRotation()  //to rotate the block
{
    currentBlock.Rotate();
}

void Game::Locking() // implemented to lock the blocks when it touches the bottom
{
    std::vector<Position> tiles = currentBlock.GetCellPosition();
    for(Position item: tiles)
    {
        grid.grid[item.row][item.column]= currentBlock.id;      
    }
 currentBlock = nextBlock;
 nextBlock = GetRandomBlock();
 grid.ClearFullRows();
}

bool Game::CheckCollision()   // to check whether the block collides with the another block. 
{  
    std::vector<Position> tiles = currentBlock.GetCellPosition();
    for(Position item : tiles)
    {
        if(grid.CellEmpty(item.row, item.column)==false)
        {
            return false;
        }
    }
    return true;
}
