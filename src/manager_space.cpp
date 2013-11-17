#include "../include/manager_space.h"
#include <cstdlib>
#include <stdio.h>
<<<<<<< HEAD
#include <SDL2/SDL_image.h>

tex::tex() {
}

tex::tex(GLuint _id, int _w, int _h, int _col) {
=======

tex::tex(){
}

tex::tex(GLuint _id, int _w, int _h, int _col){
>>>>>>> e9fa410b886771995a5fa2629e3686a256048643
    id = _id;
    w = _w;
    h = _h;
    col = _col;
}
<<<<<<< HEAD

void tex::end() {
    glDeleteTextures(1, &id);
}

namespace manager_space {
///font stuff{
std::string test="test";
int font_size = 36;
const char *font_name="data/fonts/UbuntuMono-R.ttf";
///}
std::string SHADERS_PATH = "data/shaders/";
unsigned int W = 1366 , H = 768;
char* GAME_TITLE= {"Semaphores"};
int FPS = 40;
bool running = true, fullscreen = false;
GLuint FONT_SHADER =1;

void output(const char* c) {
    printf("%s\n", c);
}

GLuint surf2tex(SDL_Surface *surf) {
    int colors = surf->format->BytesPerPixel , texture_format = GL_RGB;
    if (colors == 4) {   // alpha
        if (surf->format->Rmask == 0x000000ff)
            texture_format = GL_RGBA;
        else
            texture_format = GL_BGRA;
    } else {             // no alpha
        if (surf->format->Rmask == 0x000000ff)
            texture_format = GL_RGB;
        else
            texture_format = GL_BGR;
    }

    GLuint texture;

    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);

    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glTexImage2D(GL_TEXTURE_2D, 0, colors, surf->w, surf->h, 0,
                 texture_format, GL_UNSIGNED_BYTE, surf->pixels);

    return texture;
}

void sdlDie() {
    output(SDL_GetError());
    SDL_Quit();
    exit(1);
}
=======
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
>>>>>>> e9fa410b886771995a5fa2629e3686a256048643
}
