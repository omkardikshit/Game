#ifndef CAM_H_INCLUDED
#define CAM_H_INCLUDED

class Cam{

    public:
        void update(Player player,RenderWindow &window){
            View cam;
            float x = (player.x-width/2);
            float y = (player.y-width/2);
            if(x < 0)x=0;
            if(y < 0)y=0;
            if(x >= 416) x = 416;
            if(y >= height-w)y = height-w;
            cam.setSize(Vector2f(width,height));
            cam.reset(FloatRect(x, y, width, height));
            window.setView(cam);
        }

};

#endif // CAM_H_INCLUDED
