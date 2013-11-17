#ifndef MANAGER_SPACE_H
#define MANAGER_SPACE_H

#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <GL/gl.h>
<<<<<<< HEAD
#include <iostream>
=======
>>>>>>> e9fa410b886771995a5fa2629e3686a256048643

class tex{
    public :
    int col;
    int w, h;
    GLuint id;
    tex();
    tex(GLuint id, int w, int h, int col);
    void end();
};

namespace manager_space{
<<<<<<< HEAD
    extern std::string test, SHADERS_PATH;
    extern unsigned int W, H ;
    extern char* GAME_TITLE;
    extern int FPS, font_size, inv_font_size;
    extern bool running, fullscreen;
    extern const char *font_name;
    extern GLuint FONT_SHADER;

    void output(const char* c);

    GLuint surf2tex(SDL_Surface *surf);

=======
    extern unsigned int W, H ;
    extern char* GAME_TITLE;
    extern int FPS, font_size;
    extern bool running, fullscreen;
    extern const char *font_name;

    void output(const char* c);

>>>>>>> e9fa410b886771995a5fa2629e3686a256048643
    void sdlDie();
}

#endif // MANAGER_SPACE_H
