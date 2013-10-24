#include "../include/manager_space.h"
#include <cstdlib>
#include <stdio.h>

tex::tex(){
}

tex::tex(GLuint _id, int _w, int _h, int _col){
    id = _id;
    w = _w;
    h = _h;
    col = _col;
}
void tex::end(){
    glDeleteTextures(1, &id);
}

namespace manager_space{
    unsigned int W = 800 , H = 600;
    char* GAME_TITLE= {"Semaphores"};
    int FPS = 40, font_size = 16;
    bool running = true, fullscreen = false;
    extern const char *font_name="data/fonts/OpenSans-R.ttf";

    void output(const char* c){
        printf("%s\n", c);
    }

    void sdlDie(){
        output(SDL_GetError());
        SDL_Quit();
        exit(1);
    }
}
