#include <raylib.h>
#include "grid.h"



int main()
{   Color darkblue ={10,10,255,255};
   InitWindow(300, 600, "Tetris") ; //initialises window and take 3 values
   SetTargetFPS(60);   //if not define the computer will run it as fast as it can
    //Defining The game loop
    Grid grid = Grid();
    grid.Print();
    while(WindowShouldClose()==false) //windowshouls=dclose checks whether the esc or quit icon is pressed or not, if pressed it returns true
   {
     BeginDrawing(); //begin drawning canvas
     ClearBackground(darkblue);
     // implenmneting draw in grid
     grid.Draw();
     // now to make tetris more understandable we will make lines
     // for that we will use space of 1 pixel from each cell meaning 30(i.e cell size)-1 = 29 margin
     EndDrawing();   //ends drawing canvas
   }
   CloseWindow(); //closes the window
}