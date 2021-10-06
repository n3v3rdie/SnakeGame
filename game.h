#ifndef GAME_H
#define GAME_H

#include "common.h"
#include "snake.h"

class Window;

enum KeyEvent {KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT, NO_KEY};

class Game
{
public:
    Game(int w, int h);

    void Init();
    void Tick();
    void Draw();
    void setWindow(Window *w);
    void KeyDown(KeyEvent key);
private:
    const int width;
    const int height;
    Point fruit;
    Snake snake;
    Window *window;
    KeyEvent lastKey;
    void drawFruit();
    void drawSnake();
    void createFruit();
    void checkCollision();
    void changeSnakeDirection();
    bool checkFruitPosition();
    int getRandom(int maxValue);
};

#endif // GAME_H
