#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED
#include <SFML/Graphics.hpp>
#include "Wall.h"
#include "com.h"
using namespace sf;

class Player{
    public:

    RectangleShape rect;
    int x = 64;
    int y = 64;
    bool left,right,up,down;
    int xspeed = 0;
    int yspeed = 0;
    int speed = 8;
    void setLeft(bool b){left = b;}
    void setRight(bool b){right = b;}
    void setDown(bool b){down = b;}
    void setUp(bool b){up = b;}

    void collide_wall(Wall wall) {
		if(x+w >= wall.x && y < wall.y+w && y+w > wall.y&&x < wall.x+w){
            right = false;
        }

		if(x <= wall.x+w && y < wall.y+w && y+w > wall.y&& x+w > wall.x+w/2){
			left = false;
        }

		if(y+w >= wall.y && x < wall.x+w && x+w > wall.x&&y < wall.y+w){
			down = false;
        }

		if(y <= wall.y+w && x < wall.x+w && x+w > wall.x&& y+w > wall.y+w/2){
            up = false;
        }

	}

    void update(){
        if(left){xspeed = -speed;yspeed = 0;}
        else if(right){xspeed = speed;yspeed = 0;}
        else if(up){yspeed = -speed;xspeed = 0;}
        else if(down){yspeed = speed;xspeed = 0;}else{
            xspeed = 0;
            yspeed = 0;
        }

        x += xspeed;
        y += yspeed;
    }

    void walk(int dx,int dy){
        x += dx*16;
        y += dy*16;
    }

    void render(RenderWindow &win){
        rect.setFillColor(Color(245, 246, 250));
        rect.setPosition(Vector2f(x,y));
        rect.setSize(Vector2f(w,w));
        win.draw(rect);
    }

};

#endif // PLAYER_H_INCLUDED
