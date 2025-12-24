#include <iostream>
#include <deque>
#include <windows.h>
#include <ctime>
#include <conio.h>

using namespace std;

struct Point
{
    int x, y;
};
deque<Point> snake;
Point food;
int width = 20, height = 20;
int score = 0;
char direction = 'W';
bool gameOver = false;

void generateFood()
{
    while (1)
    {
        food.x = (rand() % (width - 2)) + 1;
        food.y = (rand() % (width - 2)) + 1;

        bool onSnake = false;

        for (auto segment : snake)
        {
            if (segment.x == food.x && segment.y == food.y)
            {
                onSnake = true;
                break;
            }
        }
        if (!onSnake)
            break;
    }
}

void draw()
{
    system("cls");
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            if (x == 0 || x == width - 1 || y == 0 || y == height - 1)
                cout << "# ";
            else if (x == food.x && y == food.y)
                cout << "@ ";
            else
            {
                bool isSnake = false;
                Point head = snake.front();
                if (x == head.x && y == head.y)
                {
                    cout << "H";
                    isSnake = true;
                    break;
                }
                else
                {
                    for (auto segment : snake)
                    {
                        if (x == segment.x && y == segment.y)
                        {
                            cout << "O";
                            isSnake = true;
                            break;
                        }
                    }
                }
                if (!isSnake)
                    cout << "  ";
            }
        }
        cout << endl;
    }
}

void input()
{
    if (_kbhit())
    {
        char key = _getch();
        if (key == 'w' || key == 'W' || key == 'a' || key == 'A' || key == 's' || key == 'D' || key == 'd' || key == 'D')
            direction = key;
        else if (key == 'X' || key == 'x')
            gameOver = true;
    }
}

void logic()
{
    Point head = snake.front();
    if (direction == 'W' || direction == 'w')
        head.y--;
    if (direction == 'A' || direction == 'a')
        head.x--;
    if (direction == 'S' || direction == 's')
        head.y++;
    if (direction == 'D' || direction == 'd')
        head.x++;

    if (head.x == 0 || head.x == width - 1 || head.y == 0 || head.y == height - 1)
        gameOver = true;

    for (int i = 1; i < snake.size(); i++)
    {
        if (snake[i].x == head.x && snake[i].y == head.y)
            gameOver = true;
    }

    snake.push_front(head);

    if (head.x == food.x && head.y == food.y)
    {
        score += 10;
        generateFood();
    }
    else
    {
        snake.pop_back();
    }
}

int main()
{
    cout << "\t\t\tSNAKE GAME\n\n";
    cout << "Guide:\n1. The walls are indicated by #. Do not touch them else you die.\n2. The food is indicated by @. Picking the food gives 10 points.\n3. The snake is represented by O with its head via H.\n4. Use W, A, S, D for UP, LEFT, DOWN, RIGHT respectively.\n5. Enter X to end the game.\n\n\nPress ENTER to continue" << endl;
    getchar();
    system("cls");

    srand(time(NULL));
    snake = {{10, 10}, {10, 11}, {10, 12}};

    generateFood();

    while (!gameOver)
    {
        draw();
        input();
        logic();
        Sleep(100);
    }

    system("cls");
    cout << "============================" << endl;
    cout << "       GAME OVER!           " << endl;
    cout << "       Final Score: " << score << endl;
    cout << "============================" << endl;
}