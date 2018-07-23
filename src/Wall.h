#ifndef WALL_H_INCLUDED
#define WALL_H_INCLUDED
#include <SFML/Graphics.hpp>
#include "com.h"

using namespace sf;

class Wall {

    public:

    RectangleShape rect;
    int x,y;

	Wall(int x,int y){
        rect.setFillColor(Color(44,58,71,255));
        this->x = x*w;
        this->y = y*w;
    }

    void render(RenderWindow &win){
        rect.setPosition(Vector2f(x,y));
        rect.setSize(Vector2f(w,w));
        win.draw(rect);
    }

};

#endif // WALL_H_INCLUDED
