#ifndef TTF_MANAGER_H
#define TTF_MANAGER_H
#include "manager_space.h"
#include "render_manager.h"
#include <SDL2/SDL_ttf.h>
#include <vector>
<<<<<<< HEAD
#include <glm/gtc/matrix_transform.hpp>
#include <glm/glm.hpp>
=======
>>>>>>> e9fa410b886771995a5fa2629e3686a256048643

using namespace manager_space;

class glyph_metric {
    public:
<<<<<<< HEAD
    float wt;
    int w;
    char c;

    glyph_metric();
=======
    int w;
    char c;

    glyph_metric() {}
    glyph_metric(int _w, char _c) {
        w=_w;
        c=_c;
    }
>>>>>>> e9fa410b886771995a5fa2629e3686a256048643
};

class ttf_manager {
public:
    ttf_manager();
    virtual ~ttf_manager();
    void end();
    void init();
    void make(const char *name, int size, int a, int b);
<<<<<<< HEAD
    void write_let(int w, int h,float xt1, float yt1);
    void setMat();
    void calcMat();
    glm::mat4 proj, model, view, mvp;
=======
    void write_let();

>>>>>>> e9fa410b886771995a5fa2629e3686a256048643
    int height;
    std::vector<glyph_metric> metrics;
    tex font;
    render_obj r;
};

#endif // TTF_MANAGER_H
