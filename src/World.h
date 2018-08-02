#ifndef WORLD_H_INCLUDED
#define WORLD_H_INCLUDED
#include <vector>
#include "Wall.h"
#include <fstream>
#include <SFML/Graphics.hpp>
using namespace sf;
class World{
    public:


    std::vector<Wall> walls;
    Image img;
    World(){
        img.loadFromFile("map.png");
        Color col = img.getPixel(0,0);
        for (int i = 0; i < img.getSize().x; i++){
            for (int j = 0; j < img.getSize().y; j++){
                if(img.getPixel(i,j).r == 0 && img.getPixel(i,j).g == 0 && img.getPixel(i,j).b == 0){
                    walls.push_back(Wall(i,j));
                }
            }
        }
}

    void render(RenderWindow &win){
        for (Wall w : walls){
            w.render(win);
        }
    }

};

#endif // WORLD_H_INCLUDED
