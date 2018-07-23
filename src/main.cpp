#include <SFML/Graphics.hpp>
#include "World.h"
#include "Player.h"
#include "com.h"
#include "Wall.h"
#include "Cam.h"

using namespace sf;
RenderWindow window;


const String title = "Game";
VideoMode VidMod;
VideoMode monitor = VidMod.getDesktopMode();
World world;
Player player;
Cam cam;
void render();
void update();
void run(){
    window.setFramerateLimit(60);
    while (running && window.isOpen()){
        Event event;
        window.setKeyRepeatEnabled(false);
        while (window.pollEvent(event)){
            switch (event.type){
                case sf::Event::Closed:
                    window.close();
                    break;

                case sf::Event::KeyPressed:
                    if(event.key.code == Keyboard::Right)
                        player.setRight(true);
                    if(event.key.code == Keyboard::Left)
                        player.setLeft(true);
                    if(event.key.code == Keyboard::Up)
                        player.setUp(true);
                    if(event.key.code == Keyboard::Down)
                        player.setDown(true);
                    break;

                case sf::Event::KeyReleased:
                    if(event.key.code == Keyboard::Right)
                        player.setRight(false);
                    if(event.key.code == Keyboard::Left)
                        player.setLeft(false);
                    if(event.key.code == Keyboard::Up)
                        player.setUp(false);
                    if(event.key.code == Keyboard::Down)
                        player.setDown(false);
                    break;
            }
        }
        update();
        render();
    }
    window.close();
}

void update(){
    for(Wall wall: world.walls){
        player.collide_wall(wall);
    }
    player.update();
}

void render(){
    window.clear(Color(0,255,0));
    world.render(window);
    player.render(window);
    cam.update(player,window);
    window.display();
}

int main()
{
    running = true;
    ContextSettings settings;
    window.create(VideoMode(width,height),title,Style::Close);
    window.setPosition(Vector2i((monitor.width-width)/2,(monitor.height-height)/2));
    run();
    return 0;
}
