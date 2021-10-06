#include "window.h"
#include <GLFW/glfw3.h>
#include <game.h>

using namespace std;

Window::Window(const char *title): m_title(title)
{    
}

bool Window::InitWindow(int w, int h)
{
    width = w;
    height = h;

    if( !glfwInit() )
    {
        LastError = "Failed to initialize GLFW";
        return false;
    }
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    window = glfwCreateWindow(w, h, m_title, nullptr, nullptr);
    if ( window == nullptr ){
        LastError = "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. ";
        glfwTerminate();
        return false;
    }
    glfwMakeContextCurrent(window);
    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
    glClearColor(0.0f, 0.0f, 0.1f, 0.0f);
    glOrtho(0, BOARDSIZE, 0, BOARDSIZE, -1, 1);
    return true;
}

void Window::drawQuad(Point p, Color color)
{
    glBegin(GL_QUADS);
    glColor3f(color.r, color.g, color.b);
    glVertex2i(p.x, p.y);
    glVertex2i(p.x, p.y + 1);
    glVertex2i(p.x + 1, p.y + 1);
    glVertex2i(p.x + 1, p.y);
    glEnd();
}

void Window::mainLoop(){
    Game game(BOARDSIZE, BOARDSIZE);
    game.setWindow(this);
    game.Init();
    double nowTime = 0.0, lastTime = 0.0;
    do {
        glClear(GL_COLOR_BUFFER_BIT);
        glfwPollEvents();

        if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS)
            game.KeyDown(KEY_RIGHT);
        else if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
            game.KeyDown(KEY_UP);
        else if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS)
            game.KeyDown(KEY_LEFT);
        else if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
            game.KeyDown(KEY_DOWN);

        game.Draw();
        nowTime = glfwGetTime();
        if (nowTime - lastTime > 0.2){
            game.Tick();
            lastTime = nowTime;
        }

        glfwSwapBuffers(window);
    }while( glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
                glfwWindowShouldClose(window) == 0 );
}
