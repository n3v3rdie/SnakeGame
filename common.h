#ifndef COMMON_H
#define COMMON_H

class Point{
public:
    Point(): x(0), y(0){};
    Point(int x, int y): x(x), y(y){};
    int x;
    int y;
    void right(){
        x += 1;
    };
    void left(){
        x -= 1;
    };
    void up(){
        y += 1;
    };
    void down(){
        y -= 1;
    };
    friend bool operator!= (const Point p1, const Point p2){
        return ((p1.x != p2.x) || (p1.y != p2.y));
    }
    friend bool operator== (const Point p1, const Point p2){
        return ((p1.x == p2.x) && (p1.y == p2.y));
    }
};

class Color{
public:
    Color(float r, float g, float b):
        r(r), g(g), b(b)
    {};
    float r;
    float g;
    float b;
};

#endif // COMMON_H
