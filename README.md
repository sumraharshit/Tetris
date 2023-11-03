# Tetris
Tetris is a puzzle video game in which falling tetrominoes are manipulated, with help of user input to form complete rows. The main aim of doing this project was to practise and improve OOPs implementation.The readme of the classic game of Tetris created with C++ using the OOPs concept and RayLib library consists of information about how to run the code on your system, bug fixes, updates, etc.

# How to run the code
You need to <b>install raylib library</b> on your system. RayLib is an open source library favourably used for creating video game.<br>It can downloaded by using the link
[Download](https://raysan5.itch.io/raylib/download/eyJpZCI6ODUzMzEsImV4cGlyZXMiOjE2OTg4NjkxODR9.DfmgzFy50G0K2uwVRK1o9Gmz0v4%3d)<br><br>
The files have been included for smooth execution, so you just need to download zip from repository and Raylib Library, open the folder in IDE and run the main.cpp file.<br>
If you are interested in knowing the whole process, you can go thorugh the link [here](https://github.com/raysan5/raylib/wiki#development-platforms)<br>

# Work Flow
In a specified grid, a random block among 7 different blocks moves down after a time interval using event trigger. The block can be manipulated by following user inputs.<br>
<b>User Inputs</b><br>
<b>Up Arrow</b>: To rotate the block. Each block has 4 different rotation states.<br>
<b>Down Arrow</b>: To move the block down.<br>
<b>Right Arrow</b>: To move the block right.<br>
<b>Left Arrow</b>: To move the block left.<br><br>
As the block touches the bottom of the screen(grid) or collides with other blocks it gets locked in that position. The code prevents the block to move out of grid or to overlap the other blocks.
The program checks from bottom to top, whether any row has been completely filled or not. If it is, then the filled row is cleared and the partially filed rows are moved down.<br><br>
The comments have been added in the code files for better understanding.
