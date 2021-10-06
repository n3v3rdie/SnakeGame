#include <iostream>
#include <ctime>
#include "game.h"
#include "snake.h"
#include "window.h"

Game::Game(int w, int h):
    width(w), height(h)
{
}

void Game::Init()
{
    snake.reset(9, 2);
    createFruit();
}

void Game::Tick()
{
    changeSnakeDirection();
    snake.move(fruit);
    checkCollision();
    drawFruit();
    drawSnake();
}

void Game::Draw()
{
    drawFruit();
    drawSnake();
}

void Game::KeyDown(KeyEvent key)
{
    lastKey = key;
}

void Game::setWindow(Window *w)
{
    window = w;
}

void Game::drawFruit()
{
    window->drawQuad(fruit, Color(0.7, 0, 0));
}

void Game::drawSnake()
{
    for (Point p: snake.getBody()){
        window->drawQuad(p, Color(0, 0.7, 0));
    }
}

void Game::createFruit()
{
    do {
        fruit.x = getRandom(width);
        fruit.y = getRandom(height);
    }while(!checkFruitPosition());
}

int Game::getRandom(int maxValue)
{
    std::srand(std::time(0));
    return std::rand() % maxValue;
}

void Game::checkCollision()
{
    auto snakeBody = snake.getBody();
    Point snakeHead = snakeBody.front();
    if (snakeHead == fruit)
        createFruit();
    if ((snakeHead.x > width-1) || (snakeHead.x < 0) ||
       (snakeHead.y > height-1) || (snakeHead.y < 0) ) {
       Init();
    }
    if (snake.getBody().size() < 4)
        return;

    for (size_t i=4; i<snakeBody.size()-1; i++){
        if (snakeHead == snakeBody[i])
            Init();
    }
}

void Game::changeSnakeDirection()
{
    switch (lastKey) {
        case KEY_UP   : snake.up(); break;
        case KEY_DOWN : snake.down(); break;
        case KEY_LEFT : snake.left(); break;
        case KEY_RIGHT: snake.right(); break;
        case NO_KEY   : return;
    }
    lastKey = NO_KEY;
}

bool Game::checkFruitPosition()
{
    for (Point p: snake.getBody()){
        if (p == fruit) return false;
    }
    return true;
}
