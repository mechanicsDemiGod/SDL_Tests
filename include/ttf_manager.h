#ifndef TTF_MANAGER_H
#define TTF_MANAGER_H
#include "manager_space.h"
#include "render_manager.h"
#include <SDL2/SDL_ttf.h>
#include <vector>

using namespace manager_space;

class glyph_metric {
    public:
    int w;
    char c;

    glyph_metric() {}
    glyph_metric(int _w, char _c) {
        w=_w;
        c=_c;
    }
};

class ttf_manager {
public:
    ttf_manager();
    virtual ~ttf_manager();
    void end();
    void init();
    void make(const char *name, int size, int a, int b);
    void write_let();

    int height;
    std::vector<glyph_metric> metrics;
    tex font;
    render_obj r;
};

#endif // TTF_MANAGER_H
