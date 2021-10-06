#include <iostream>
#include <window.h>
using namespace std;


int main( void ){
    Window window("Snake");
    if ( !window.InitWindow(600, 600)){
        cerr<<window.LastError<<endl;
        return -1;
    }
    window.mainLoop();
    return 0;
}
