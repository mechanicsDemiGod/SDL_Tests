#include "..\include\manager.h"

#include <cstdlib>
<<<<<<< HEAD
#include <sstream>
=======

>>>>>>> e9fa410b886771995a5fa2629e3686a256048643

using namespace manager_space;


manager::manager() {
}

manager::~manager() {
    SDL_DestroyWindow(window);
}

void manager::init() {
    window = SDL_CreateWindow(
                 GAME_TITLE,
                 SDL_WINDOWPOS_CENTERED,
                 SDL_WINDOWPOS_CENTERED,
<<<<<<< HEAD
                 W,
                 H,
=======
                 640,
                 480,
>>>>>>> e9fa410b886771995a5fa2629e3686a256048643
                 SDL_WINDOW_OPENGL |SDL_WINDOW_RESIZABLE
             );
    ttf_manag.init();
}

void manager::initOpengl() {
    context = SDL_GL_CreateContext(window);
    if(context == NULL) {
        sdlDie();
    }
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

    SDL_GL_SetSwapInterval(1);

    glewExperimental = true,glewInit();
    glEnable(GL_TEXTURE);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

}

void manager::end() {
    ttf_manag.end();
    gl.end();
    SDL_GL_DeleteContext(context);
    if(window != NULL)
        SDL_DestroyWindow(window);
}

<<<<<<< HEAD
void manager::write(std::string s, float x, float y){
    if(gl.in_use != FONT_SHADER) {
        gl.useProg(FONT_SHADER);
        gl.putTex(ttf_manag.font.id, FONT_SHADER, "text");
    }

    float prec=0;
    for(int i=0; i<s.size(); i++) {
        int loc = int(s[i])-32;
        int x1, x2;
        float xt1, xt2;
        //position
=======
void manager::write(std::string s, int x, int y) {
    if(gl.in_use != 0) {
        gl.useProg(0);
        gl.putTex(ttf_manag.font.id, 0, "text");
    }

    int prec;
    for(int i=0; i<s.size(); i++) {
        GLuint posId  = glGetUniformLocation(gl.getProg(gl.in_use), "pos");
        int loc = int(s[i]) - 32;
        int x1, x2;
>>>>>>> e9fa410b886771995a5fa2629e3686a256048643
        if(loc == 0)
            x1 = 0;
        else
            x1 = ttf_manag.metrics[loc-1].w;
        x2 = ttf_manag.metrics[loc].w;
<<<<<<< HEAD
        //texture
        if(loc == 0)
            xt1 = 0;
        else
            xt1 = ttf_manag.metrics[loc-1].wt;
        xt2 = ttf_manag.metrics[loc].wt;

        ttf_manag.view = glm::translate(glm::mat4(1), glm::vec3(x + prec, y, 0));
        ttf_manag.calcMat();
        glUniformMatrix4fv(gl.getUniform("mvp"), 1, GL_FALSE, &ttf_manag.mvp[0][0]);
        prec+=x2-x1;

        ttf_manag.write_let(x2-x1, ttf_manag.font.h, xt1, xt2);
    }
}

void manager::write(int s, float x, float y){
    std::stringstream stream;
    string ss;
    stream<<s;
    stream>>ss;
    write(ss, x, y);
}

=======
        glUniform2f(posId, x + prec, y);

        prec+=x2-x1;

        ttf_manag.write_let();
    }
}

>>>>>>> e9fa410b886771995a5fa2629e3686a256048643
//SDL
//{

void manager::windowShow() {
}

void manager::windowHide() {
}

void manager::windowMove(int x, int y) {
}

void manager::windowResize(int x, int y) {
}

void manager::windowMinimize() {
}

void manager::windowMaximize() {
}

void manager::windowRestore() {
}

void manager::windowMouseEnter() {
}

void manager::windowMouseLeave() {
}

void manager::windowFocusGain() {
}

void manager::windowFocusLost() {
}

void manager::windowClose() {
    running = false;
}

void manager::keyboardDown(SDL_Keysym key) {
<<<<<<< HEAD
    manager_space::test+=key.sym;
=======
>>>>>>> e9fa410b886771995a5fa2629e3686a256048643
    switch(key.sym) {
    case SDLK_ESCAPE: {
        running = false;
        break;
    }
    case SDLK_f: {
        fullscreen = !fullscreen;
        SDL_SetWindowFullscreen(window,fullscreen?SDL_WINDOW_FULLSCREEN:SDL_WINDOW_FULLSCREEN_DESKTOP);
    }
    }
}

void manager::keyboardUp(SDL_Keysym key) {
    switch(key.sym) {
    case SDLK_ESCAPE: {
        running = false;
        break;
    }
    }
}

void manager::mouseMove(int x, int y) {
    mx = x;
    my = y;
}

void manager::mouseButtonDown(SDL_MouseButtonEvent e) {
    switch(e.button) {
    case SDL_BUTTON_LEFT: {
        break;
    }

    case SDL_BUTTON_MIDDLE: {
        break;
    }

    case SDL_BUTTON_RIGHT: {
        break;
    }

    case SDL_BUTTON_X1: {
        break;
    }

    case SDL_BUTTON_X2: {
        break;
    }
    }
}

void manager::mouseButtonUp(SDL_MouseButtonEvent e) {
    switch(e.button) {
    case SDL_BUTTON_LEFT: {
        break;
    }

    case SDL_BUTTON_MIDDLE: {
        break;
    }

    case SDL_BUTTON_RIGHT: {
        break;
    }

    case SDL_BUTTON_X1: {
        break;
    }

    case SDL_BUTTON_X2: {
        break;
    }
    }
}

// x negative left - positive right
// y negative up - positive down
void manager::mouseWheel(int x, int y) {
}

//}
