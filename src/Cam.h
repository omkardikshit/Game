#ifndef CAM_H_INCLUDED
#define CAM_H_INCLUDED
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
using namespace std;
class Cam{
    public:
        void update(Player player,World world,RenderWindow &window){
            View cam;
            cam.setSize(Vector2f(width,height));
            float x = player.x-width/2+16;
            float y = player.y-height/2+16;
            if(x < 0) x = 0;
            if(y < 0) y = 0;
            if(y > world.img.getSize().y*w-height) y = world.img.getSize().y*w-height;
            if(x > (world.img.getSize().x*w-width)) x = (world.img.getSize().x*w-width);
            cam.reset(FloatRect(x,y,width,height));
            window.setView(cam);
        }

};

#endif // CAM_H_INCLUDED
