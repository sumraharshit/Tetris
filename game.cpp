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