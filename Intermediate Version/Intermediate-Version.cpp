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

enum Direction
{
    UP,
    DOWN,
    LEFT,
    RIGHT
};

class Snake
{
private:
    deque<Point> body;
    Direction dir;

public:
    Snake()
    {
        body = {{10, 10}, {10, 11}, {10, 12}};
        dir = Direction::UP;
    }
    const deque<Point> &getBody() const { return body; }
    Point getHead() const { return body.front(); }
    Direction getDirection() const { return dir; }
    void setDirection(Direction newDir)
    {
        dir = newDir;
    }

    Point getNextHead() const
    {
        Point next = body.front();
        switch (dir)
        {
        case Direction::UP:
            next.y--;
            break;
        case Direction::DOWN:
            next.y++;
            break;
        case Direction::LEFT:
            next.x--;
            break;
        case Direction::RIGHT:
            next.x++;
            break;
        }
        return next;
    }

    void move(bool ateFood)
    {
        body.push_front(getNextHead());
        if (!ateFood)
            body.pop_back();
    }

    bool selfCollision()
    {
        Point head = body.front();
        for (int i = 1; i < body.size(); i++)
        {
            if (head.x == body[i].x && head.y == body[i].y)
                return true;
        }
        return false;
    }
};

class Food
{
public:
    Point pos;

    void generate(int width, int height, Snake &snake)
    {
        while (1)
        {
            pos.x = rand() % (width - 2) + 1;
            pos.y = rand() % (height - 2) + 1;

            bool onSnake = false;

            for (auto segment : snake.getBody())
            {
                if (segment.x == pos.x && segment.y == pos.y)
                {
                    onSnake = true;
                    break;
                }
            }
            if (!onSnake)
                break;
        }
    }
};

void draw(int width, int height, Snake &snake, Food &food, int score)
{
    COORD c = {0, 0};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
    cout << "RETRO SNAKE | Score: " << score << endl;
    char headChar;
    switch (snake.getDirection())
    {
    case Direction::UP:
        headChar = '^';
        break;
    case Direction::DOWN:
        headChar = 'V';
        break;
    case Direction::RIGHT:
        headChar = '>';
        break;
    case Direction::LEFT:
        headChar = '<';
        break;
    }
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            if (x == 0 || x == width - 1 || y == 0 || y == height - 1)
                cout << "#";
            else if (x == food.pos.x && y == food.pos.y)
                cout << "@";
            else
            {
                bool isSnake = false;

                Point head = snake.getHead();
                if (x == head.x && y == head.y)
                {
                    cout << headChar;
                    isSnake = true;
                }
                else
                {
                    for (auto segment : snake.getBody())
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
                    cout << " ";
            }
        }
        cout << endl;
    }
    cout << "Controls: W A S D | X to quit\n";
}
int main()
{
    srand(time(0));
    int width = 20;
    int height = 20;
    int score = 0;
    bool gameOver = false;

    Snake snake;
    Food food;
    food.generate(width, height, snake);

    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO ci;
    GetConsoleCursorInfo(out, &ci);
    ci.bVisible = false;
    SetConsoleCursorInfo(out, &ci);

    while (!gameOver)
    {
        if (_kbhit())
        {
            char key = _getch();
            switch (key)
            {
            case 'w':
                if (snake.getDirection() != Direction::DOWN)
                    snake.setDirection(Direction::UP);
                break;
            case 's':
                if (snake.getDirection() != Direction::UP)
                    snake.setDirection(Direction::DOWN);
                break;
            case 'a':
                if (snake.getDirection() != Direction::RIGHT)
                    snake.setDirection(Direction::LEFT);
                break;
            case 'd':
                if (snake.getDirection() != Direction::LEFT)
                    snake.setDirection(Direction::RIGHT);
                break;
            case 'x':
                gameOver = true;
                break;
            }
        }
        Point nextHead = snake.getNextHead();
        bool eating = false;
        if (nextHead.x == food.pos.x && nextHead.y == food.pos.y)
            eating = true;

        if (eating)
        {
            Beep(1000, 150); //Eating food sound
            score += 10;
            food.generate(width, height, snake);
        }

        snake.move(eating);

        Point head = snake.getHead();
        if (head.x <= 0 || head.y <= 0 || head.x >= width - 1 || head.y >= height - 1 || snake.selfCollision())
        {
            gameOver = true;
        }

        draw(width, height, snake, food, score);
        int delay = max(30, 100 - score);
        Sleep(delay);
    }
    //Game Over Sound
    Beep(330, 200);
    Beep(294, 200);
    Beep(262, 200);
    Beep(220, 600);
    system("cls");
    cout << "============================" << endl;
    cout << "       GAME OVER!           " << endl;
    cout << "       Final Score: " << score << endl;
    cout << "============================" << endl;
}
