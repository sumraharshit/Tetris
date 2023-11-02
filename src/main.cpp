#include <raylib.h>
#include "game.h"
double LastTimeUpdation =0;

bool MovingBlockDown(double interval)
{
  double CurentTime = GetTime();
  if(CurentTime - LastTimeUpdation>=interval)
  { LastTimeUpdation = CurentTime;
    return true;
  }
  return false;
}

int main()
{   Color darkblue ={10,10,255,255};
   InitWindow(300, 600, "Tetris") ; //initialises window and take 3 values
   SetTargetFPS(60);   //if not define the computer will run it as fast as it can
    //Defining The game loop
    Game game=Game();
    while(WindowShouldClose()==false) //windowshouls=dclose checks whether the esc or quit icon is pressed or not, if pressed it returns true
   {   game.HandleInput();
     // THE FUNCTION IS DEFINED TO DROP THE BLOCK AS IN CLAASSIC TETRIS
    //NOW THE ISSUE IS THAT THE BLOCK DROPS EVERY QUICKLY THATS BEACAUSE WE HAVE SET THE FPS TO 60, MEANING THAT THE BLOCK DROPS 60
    //GRIDS EVERY SECOND, NOW TO FIX THAT WE CAN IMPLEMENT EVENT TRIGGER THAT WILL MAKE SURE THAT THE BLOCK DROPS AFTER A CERTAIN TIME
    // TIME INTERVAL.
    // have commented the previously implemented Movedown function.
    if(MovingBlockDown(0.5))
    {
      game.MoveDown();
    }
     BeginDrawing(); //begin drawning canvas
     ClearBackground(darkblue);
     // implenmneting draw in game which will draw with help of of grid and block
       game.Draw();
     // now to make tetris more understandable we will make lines
     // for that we will use space of 1 pixel from each cell meaning 30(i.e cell size)-1 = 29 margin
     EndDrawing();   //ends drawing canvas
   }
   CloseWindow(); //closes the window
}
