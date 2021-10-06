#include "snake.h"

Snake::Snake()
{}

Snake::~Snake()
{
}

void Snake::reset(int x, int y)
{
    body.clear();
    body.push_back(Point(x, y));
    m_direction = Direction::up;
}

void Snake::move(Point fruitPosition)
{
    Point head = body.front();
    switch(m_direction)
    {
        case Direction::up   : head.up(); break;
        case Direction::down : head.down(); break;
        case Direction::left : head.left(); break;
        case Direction::right : head.right(); break;
    }
    if (fruitPosition != head)
        body.pop_back();
    body.insert(body.begin(), head);
}

const std::vector<Point> &Snake::getBody()
{
    return body;
}

void Snake::up()
{
    if (m_direction == Direction::down)
        return;
    m_direction = Direction::up;
}

void Snake::down()
{
    if (m_direction == Direction::up)
        return;
    m_direction = Direction::down;
}

void Snake::left()
{
    if (m_direction == Direction::right)
        return;
    m_direction = Direction::left;
}

void Snake::right()
{
    if (m_direction == Direction::left)
        return;
    m_direction = Direction::right;
}
