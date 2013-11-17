#ifndef MANAGER_H
#define MANAGER_H
#include "manager_space.h"
#include "render_manager.h"
#include "ttf_manager.h"
#include <string>

class manager {
public:
    //FUNCTIONS
    manager();
    void init();
    void initOpengl();
    void end();
    ~manager();
    void windowShow();
    void windowHide();
    void windowMove(int x, int y);
    void windowResize(int x, int y);
    void windowMinimize();
    void windowMaximize();
    void windowRestore();
    void windowMouseEnter();
    void windowMouseLeave();
    void windowFocusGain();
    void windowFocusLost();
    void windowClose();
    void keyboardDown(SDL_Keysym key);
    void keyboardUp(SDL_Keysym key);
    void mouseMove(int x, int y);
    void mouseButtonDown(SDL_MouseButtonEvent e);
    void mouseButtonUp(SDL_MouseButtonEvent e);
    void mouseWheel(int x, int y);
    bool runs() {
        return running;
    }
<<<<<<< HEAD
    void write(int s, float x, float y);
    void write(std::string s, float x, float y);
=======
    void write(std::string s, int x, int y);
>>>>>>> e9fa410b886771995a5fa2629e3686a256048643
    //VARIABLES
    render_manager gl;
    ttf_manager ttf_manag;
    SDL_Window *window;
    SDL_GLContext context;
    int mx, my;
};

#endif // MANAGER_H
