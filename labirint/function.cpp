//#include <conio.h>
//#include <process.h>
#include <iostream>
#include<func.h>
#include<stack>

using namespace std;

bool win = false;
stack <cell> steck;
player igrok;

char maze[height][width];


void Congratulations() {
    //Очищаем консоль
    system("сls");
    //Цвет фона и текста
    //system("color 2F");
    cout<< "You Win!!!!" << endl << "Press any key to exit";
    //getch();
    exit(0);
}

void DrawField(){
    system("cls");
    //На текущую позицию помещаем игрока
    maze[igrok.current_player_pos.x][igrok.current_player_pos.y] = '@';
    for(int i = 0; i< height; i++) {
        for(int j = 0; j < width; j++) {
                cout << maze[i][j];
            }
        cout << endl;
    }

}

void movementPlayer(int val){
    switch(val){
    case 'w':
        if(maze[igrok.current_player_pos.x - 1][igrok.current_player_pos.y] != '#')
        {
            //Оставляем за собой решетки
            maze[igrok.current_player_pos.x][igrok.current_player_pos.y] = VISITED;
            igrok.current_player_pos.x--;
            if (igrok.current_player_pos.x == igrok.end_pos.x && igrok.current_player_pos.y == igrok.end_pos.y)
            {
                win = true;

            }
        }
        break;
    case 's':
        if(maze[igrok.current_player_pos.x + 1][igrok.current_player_pos.y] != WALL)
        {
            //Оставляем за собой решетки
            maze[igrok.current_player_pos.x][igrok.current_player_pos.y] = VISITED;
            igrok.current_player_pos.x++;
            if (igrok.current_player_pos.x == igrok.end_pos.x && igrok.current_player_pos.y == igrok.end_pos.y)
            {
                win = true;

            }
        }
        break;
    case 'a':
        if(maze[igrok.current_player_pos.x][igrok.current_player_pos.y - 1] != '#')
        {
            //Оставляем за собой решетки
            maze[igrok.current_player_pos.x][igrok.current_player_pos.y] = VISITED;
            igrok.current_player_pos.y--;
            if (igrok.current_player_pos.x == igrok.end_pos.x && igrok.current_player_pos.y == igrok.end_pos.y)
            {
                win = true;

            }
        }
        break;
    case 'd':
        if(maze[igrok.current_player_pos.x][igrok.current_player_pos.y + 1] != WALL)
        {
            //Оставляем за собой решетки
            maze[igrok.current_player_pos.x][igrok.current_player_pos.y] = VISITED;
            igrok.current_player_pos.y++;
            if (igrok.current_player_pos.x == igrok.end_pos.x && igrok.current_player_pos.y == igrok.end_pos.y)
            {
                win = true;

            }
        }
        break;
    }
}

void Update() {
    //Если нажата клавиша на клавиатуре
    if (_kbhit()) {
        int val = getch();
        movementPlayer(val);
        if (win == true){
            Congratulations();
        }
        //Отрисовка
        DrawField();
    }
}

void init_start_player_pos(){
    igrok.current_player_pos.x = igrok.start_pos.x;
    igrok.current_player_pos.y = igrok.start_pos.y;
}

int unvisitedCount(char maze[][width]){ //used
    int count = 0, i, j;
    for (i = 0; i < height; i++)
        for (j = 0; j < width; j++)
            if(maze[i][j] != WALL && maze[i][j] != VISITED) count++;
    return count;
}

cellString getNeighbours(char maze[][width], cell c){
    int i;
    //cell c - ячейка которую мы передали для поиска у нее соседей
    //Берем ее координаты
    int x = c.x;
    int y = c.y;
    //Ищем соседей и записываем их координаты
    //Сосед сверху
    cell up = {x, y - distance_};
    //Сосед справа
    cell rt = {x + distance_, y};
    //Сосед снизу
    cell dw = {x, y + distance_};
    //Сосед слева
    cell lt = {x - distance_, y};
    //Помещеаем всех соседей в один массив
    cell d[4]  = {dw, rt, up, lt};
    int size = 0;
    //Массив соседей
    cellString cells;
    //cells.cells = malloc(4 * sizeof(cell));

    for(i = 0; i < 4; i++){ //для каждого направдения
        if(d[i].x > 0 && d[i].x < width && d[i].y > 0 && d[i].y < height){ //если не выходит за границы лабиринта
            //
            char mazeCellCurrent = maze[d[i].y][d[i].x];
            //Выбрали соседа
            cell cellCurrent = d[i];
            //Если эта ячейка не является стеной и не является посещенной
            if(mazeCellCurrent != WALL && mazeCellCurrent != VISITED)
            {
                //Записываем ее в массив
                cells.cells[size] = cellCurrent;
                size++;
            }
        }
    }
    //Меняем размер массива
    cells.size = size;
    //Возвращаем массив с соседями
    return cells;
}

void generate_step(){
    //Рандомное число
    int randNum;
    //Точка старта
    cell startCell = {1,1};
    //Текущая точка
    cell currentCell = startCell;
    //Помещаем текущую клетку в стек
    steck.push(currentCell);
    maze[startCell.x][startCell.y] = VISITED;
    //Координаты следующей ячейки
    cout<<time(0)<< "\n";
    cell cellNext;
    //Получаем соседей
    int counter = 0;
    //Пока есть непосещенные клетки
    while(unvisitedCount(maze) > 0){
        cellString cellStringNeighbours = getNeighbours(maze, currentCell);
    //Проверяем есть ли у текущей клетки непосещенные соседи
        if(cellStringNeighbours.size != 0){ //если есть(размер больше 0)
            //Берем случайного соседа от 0 до количества соседей
            //Значит в переменной cellStringNeighbours хранятся данные соседей, а size это количество этих соседей(ячеек)
            counter++;
            srand(time(0) + counter); // автоматическая рандомизация
            randNum = rand() % cellStringNeighbours.size;

            //выбираем случайного соседа и переходим к нему
            cellNext = cellStringNeighbours.cells[randNum];
            //заносим текущую точку в стек
            steck.push(cellNext);
            //убираем стенку между текущей и соседней точками(Передаем текущую точку и следующую и карту)
            removeWall(currentCell, cellNext, maze);
            //Уменьшаем количество непосещенных клеток
            //unvisitedNum--;
            //делаем соседнюю точку текущей и отмечаем ее посещенной
            currentCell = cellNext;
            maze[currentCell.y][currentCell.x] = VISITED;
            //???maze = setMode(d.startPoint, d.maze, GENVISITED);
            //free(cellStringNeighbours.cells);
        }
        else if(steck.empty() == false)
        { //если нет соседей, возвращаемся на предыдущую ячейку в стеке посещенных ячеек
                steck.pop();
                currentCell = steck.top();
        }
    }
}


int removeWall(cell first, cell second, char maze[][width]){
    //Если не выходит за границы
    if(first.x < width && first.x > 0 && first.y < height && first.y > 0 && second.x < width && second.x > 0 && second.y < height && second.y > 0 ) {
        int xDiff = second.x - first.x;
        int yDiff = second.y - first.y;
        int addX, addY;
        cell target;
        if(xDiff != 0){
            addX = xDiff / abs(xDiff);
        }
        else{
            addX = 0;
        }
        //addX = (xDiff != 0) ? (xDiff / abs(xDiff)) : 0;
        addY = (yDiff != 0) ? (yDiff / abs(yDiff)) : 0;

        target.x = first.x + addX; //координаты стенки
        target.y = first.y + addY;

        maze[target.y][target.x] = VISITED;
        return 0;
    }
    else return -1;


}




void init_maze(){
    for(int i = 0; i < height; i++){
            for(int j = 0; j < width; j++){
                if((i % 2 != 0  && j % 2 != 0) && //если ячейка нечетная по x и y,
                   (i < height-1 && j < width-1))   //и при этом находится в пределах стен лабиринта
                       maze[i][j] = CELL;       //то это КЛЕТКА
                else maze[i][j] = WALL;           //в остальных случаях это СТЕНА.
            }
        }
}
void check_win(){
    while(!win)
    {
        Update();
    }
}
