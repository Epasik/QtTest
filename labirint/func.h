#ifndef FUNC_H
#define FUNC_H
#include <iostream>
#include <cstdlib>
#include <utility>
#include <ctime>
#include <fstream>
//#include <conio.h>
#include <stack>
#include <windows.h>

using namespace std;

const int height = 15;
const int width = 15;
const char CELL = '.';
const char WALL = '#';
const char VISITED = ' ';
const int distance_ = 2;


struct cell{
    int x;
    int y;
};
//структура хранящая клетку и количество чего то...
struct cellString{
    cell cells[4];
    int size;
};

struct player {
    cell start_pos = {1,1};
    cell end_pos = {height-2, width-2};
    cell current_player_pos;

};



void DrawField();
void movementPlayer(int val);
void Congratulations();
void Update();
cellString getNeighbours(char maze[][width], cell c);
int unvisitedCount(char maze[][width]);
int removeWall(cell first, cell second,char maze[][width]);
void generate_step();
void init_maze();
void init_start_player_pos();
void check_win();

#endif // FUNC_H
