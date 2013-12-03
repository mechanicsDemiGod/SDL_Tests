#include "../include/ttf_manager.h"
#include <cmath>
#include <string>

glyph_metric::glyph_metric(){
}

ttf_manager::ttf_manager() {
    //ctor
}

ttf_manager::~ttf_manager() {
    //dtor
}

void ttf_manager::setMat(){
    proj = glm::ortho(0.f, (float)W, (float)H, 0.f);
    view = glm::mat4(1);
    model = glm::mat4(1);
    mvp = proj * view * model;
}

void ttf_manager::calcMat(){
    mvp = proj * view * model;
}

void ttf_manager::init() {
    if(!TTF_WasInit() && TTF_Init()==-1) {
        output(TTF_GetError());
        sdlDie();
    }
    setMat();
}

void ttf_manager::end() {
    font.end();
}

void ttf_manager::make(const char *name, int size, int a, int b) {
    TTF_Font *ttf_font=TTF_OpenFont(name, size);
    if(!ttf_font) {
        output(TTF_GetError());
    }
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
    glBindVertexArray(r.vao);
    glDrawArrays( GL_TRIANGLE_STRIP, 0,4);
    glBindVertexArray(0);
}

void ttf_manager::drawImg(int w, int h) {
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
        ptr[0]=0;
        ptr[2]=1;
        ptr[4]=0;
        ptr[6]=1;
        glUnmapBufferARB(GL_ARRAY_BUFFER);
    }
    ///
    glBindVertexArray(r.vao);
    glDrawArrays( GL_TRIANGLE_STRIP, 0,4);
    glBindVertexArray(0);
}
