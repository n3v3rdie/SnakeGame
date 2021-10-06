#ifndef WINDOW_H
#define WINDOW_H

#include <string>
class Point;
class Color;
class GLFWwindow;

class Window
{
public:
    Window(const char *title);

    std::string LastError;
    void mainLoop();
    bool InitWindow(int w, int h);
    void drawQuad(Point p, Color color);
private:
    int width;
    int height;
    const char *m_title;
    const int BOARDSIZE = 20;
    GLFWwindow *window;
};

#endif // WINDOW_H
