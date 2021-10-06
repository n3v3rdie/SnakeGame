#ifndef SNAKE_H
#define SNAKE_H
#include <vector>
#include "common.h"

enum Direction{ up, right, down, left};

class Snake
{
public:
    Snake();
    ~Snake();
    void reset(int x, int y);
    void move(Point fruitPosition);
    const std::vector<Point> &getBody();
    void up();
    void down();
    void left();
    void right();

private:
    std::vector<Point> body;
    Direction m_direction = Direction::up;
};

#endif // SNAKE_H
