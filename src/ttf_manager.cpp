#include "../include/ttf_manager.h"
#include <cmath>
#include <string>
ttf_manager::ttf_manager() {
    //ctor
}

ttf_manager::~ttf_manager() {
    //dtor
}

void ttf_manager::init() {
    if(!TTF_WasInit() && TTF_Init()==-1) {
        output(TTF_GetError());
        sdlDie();
    }
}

void ttf_manager::end() {
    font.end();
}

void renderText(unsigned &id, float x , float y, float w, float h) {
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE,GL_REPLACE);
    glBindTexture(GL_TEXTURE_2D, id);

    glBegin(GL_QUADS);

    glTexCoord2f(0, 0);
    glVertex2f(x, y);
    glTexCoord2f(1, 0);
    glVertex2f(x+ w, y);
    glTexCoord2f(1, 1);
    glVertex2f(x+ w, y+ h);
    glTexCoord2f(0, 1);
    glVertex2f(x, y+ h);
    glVertex2f(x, y);
    glVertex2f(x+ w, y);
    glVertex2f(x+ w, y+ h);
    glVertex2f(x, y+ h);
    glEnd();
    glColor3f(10,20,30);
    glRectf(0,0,100,100);
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

void ttf_manager::make(const char *name, int size, int a, int b) {
    TTF_Font *ttf_font=TTF_OpenFont(name, size);
    if(!ttf_font) {
        output(TTF_GetError());
    }
    int tmp;
    metrics.assign(b-a+1, glyph_metric());
    for(int i=a; i<=b; i++) {
        TTF_GlyphMetrics(ttf_font,char(i), &tmp, &tmp, &tmp, &tmp, &metrics[i-a].w);
        if(i!=a)
        metrics[i-a].w+=metrics[i-a-1].w;
        metrics[i-a].c = i;
    }
    std::string s;
    for(int i=a; i<=b; i++) {
        s+=char(i);
    }
    SDL_Surface *msg = TTF_RenderText_Blended(ttf_font, s.c_str(), {255, 255, 255});
    font = tex(surf2tex(msg),msg->w, msg->h, GL_RGBA);
    SDL_FreeSurface(msg);
    TTF_CloseFont(ttf_font);

    GLfloat quad_tris[]= {
        0, 0,
        1, 0,
        0, 1,
        1, 1
    };

    GLfloat texdata[]= {
        0, 0,
        1, 0,
        0, 1,
        1, 1
    };

    GLuint vao, vbo, tbo;

    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, 4*2*sizeof(float), quad_tris, GL_STATIC_DRAW);

    glGenBuffers(1, &tbo);
    glBindBuffer(GL_ARRAY_BUFFER, tbo);
    glBufferData(GL_ARRAY_BUFFER, 4*2*sizeof(float), texdata, GL_STATIC_DRAW);

    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
    glBindBuffer( GL_ARRAY_BUFFER, vbo );
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, (void*)0);
    glBindBuffer( GL_ARRAY_BUFFER, tbo );
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, (void*)0);
    glBindVertexArray(0);
    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
    r = render_obj(vao, vbo, tbo);
}

void ttf_manager::write_let() {
    glBindVertexArray(r.vao);
    glDrawArrays( GL_TRIANGLE_STRIP, 0,4);
    glBindVertexArray(0);
}
