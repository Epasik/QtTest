#include <iostream>
#include<cstdlib>
#include <utility>
#include<ctime>
#include<fstream>
#include <conio.h>
#include<stack>
#include <windows.h>
#include<func.h>

using namespace std;

//Функция возвращающая список соседей, который включает их координаты и количество

int main()
{

    init_maze();
    generate_step();
    init_start_player_pos();
    DrawField();
    check_win();


    return 0;
}
