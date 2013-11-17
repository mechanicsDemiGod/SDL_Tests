#include "../include/ttf_manager.h"
#include <cmath>
#include <string>
<<<<<<< HEAD

glyph_metric::glyph_metric(){
}

=======
>>>>>>> e9fa410b886771995a5fa2629e3686a256048643
ttf_manager::ttf_manager() {
    //ctor
}

ttf_manager::~ttf_manager() {
    //dtor
}

<<<<<<< HEAD
void ttf_manager::setMat(){
    proj = glm::ortho(0.f, (float)W, (float)H, 0.f);
    view = glm::mat4(1);
    model = glm::mat4(1);
    mvp = proj * view * model;
}

void ttf_manager::calcMat(){
    mvp = proj * view * model;
}

=======
>>>>>>> e9fa410b886771995a5fa2629e3686a256048643
void ttf_manager::init() {
    if(!TTF_WasInit() && TTF_Init()==-1) {
        output(TTF_GetError());
        sdlDie();
    }
<<<<<<< HEAD
    setMat();
=======
>>>>>>> e9fa410b886771995a5fa2629e3686a256048643
}

void ttf_manager::end() {
    font.end();
}

<<<<<<< HEAD
=======
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

>>>>>>> e9fa410b886771995a5fa2629e3686a256048643
void ttf_manager::make(const char *name, int size, int a, int b) {
    TTF_Font *ttf_font=TTF_OpenFont(name, size);
    if(!ttf_font) {
        output(TTF_GetError());
    }
<<<<<<< HEAD
    std::string s;
    for(int i=a; i<=b; i++) {
        s+=char(i);
    }
    SDL_Surface *msg = TTF_RenderText_Blended(ttf_font, s.c_str(), {255, 255, 255});
    font = tex(surf2tex(msg),msg->w, msg->h, GL_BGR);

    //TTF_SetFontStyle()

    int tmp;
    metrics.assign(b-a+1, glyph_metric());
    //compute for integer
    float tot =0;
    for(int i=a; i<=b; i++) {
        int w= 0;
        TTF_GlyphMetrics(ttf_font,char(i), &tmp, &tmp, &tmp, &tmp, &w);
        if(i-a==0)
            metrics[i-a].w=w;
        else
            metrics[i-a].w=w+metrics[i-a-1].w;
        metrics[i-a].c=i;
        tot+=w;
    }
    //TTF_FONt
    //divide tex location
    for(int i=a; i<=b; i++) {
            metrics[i-a].wt = (float)metrics[i-a].w/tot;
    }
=======
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
>>>>>>> e9fa410b886771995a5fa2629e3686a256048643

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
<<<<<<< HEAD
    SDL_FreeSurface(msg);
    TTF_CloseFont(ttf_font);
}

void ttf_manager::write_let(int w, int h, float xt1, float xt2) {
    ///
    glBindBufferARB(GL_ARRAY_BUFFER, r.vbo);
    float *ptr = (float*) glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY);
    if(ptr){
        ptr[2]=w;
        ptr[5]=h;
        ptr[6]=w;
        ptr[7]=h;
        glUnmapBufferARB(GL_ARRAY_BUFFER);
    }
    ///
    ///
    glBindBufferARB(GL_ARRAY_BUFFER, r.tbo);
    ptr = (float*) glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY);
    if(ptr){
        ptr[0]=xt1;
        ptr[2]=xt2;
        ptr[4]=xt1;
        ptr[6]=xt2;
        glUnmapBufferARB(GL_ARRAY_BUFFER);
    }
    ///
=======
}

void ttf_manager::write_let() {
>>>>>>> e9fa410b886771995a5fa2629e3686a256048643
    glBindVertexArray(r.vao);
    glDrawArrays( GL_TRIANGLE_STRIP, 0,4);
    glBindVertexArray(0);
}
