#include "../include/render_manager.h"
#include <fstream>
<<<<<<< HEAD
#include <SDL2/SDL_image.h>

using namespace manager_space;

render_obj::render_obj() {
=======

using namespace manager_space;

render_obj::render_obj(){
>>>>>>> e9fa410b886771995a5fa2629e3686a256048643
    hasT = false;
    hasV = false;
    hasN = false;
}
<<<<<<< HEAD
render_obj::render_obj(GLuint _vao,GLuint _vbo) {
    hasT = false;
    hasV = false;
    hasN = false;
=======
render_obj::render_obj(GLuint _vao,GLuint _vbo){
    render_obj();
>>>>>>> e9fa410b886771995a5fa2629e3686a256048643
    vao = _vao;
    vbo = _vbo;
    hasV = true;
}
<<<<<<< HEAD
render_obj::render_obj(GLuint _vao,GLuint _vbo,GLuint _tbo) {
    hasT = false;
    hasV = false;
    hasN = false;
    vao = _vao;
    vbo = _vbo;
    hasV = true;
    hasT = true;
    tbo = _tbo;
}
render_obj::render_obj(GLuint _vao,GLuint _vbo,GLuint _tbo,GLuint _nbo) {
    hasT = false;
    hasV = false;
    hasN = false;
    vao = _vao;
    vbo = _vbo;
    hasV = true;
    hasT = true;
    tbo = _tbo;
=======
render_obj::render_obj(GLuint _vao,GLuint _vbo,GLuint _tbo){
    render_obj();
    render_obj(_vao, _vbo);
    hasT = true;
    tbo = _tbo;
}
render_obj::render_obj(GLuint _vao,GLuint _vbo,GLuint _tbo,GLuint _nbo){
    render_obj();
    render_obj(_vao, _vbo, _tbo);
>>>>>>> e9fa410b886771995a5fa2629e3686a256048643
    hasN = true;
    nbo = _nbo;
}

<<<<<<< HEAD
GLuint render_manager::getUniform(const char *s) {
    GLuint prog = getProg(in_use);
    return glGetUniformLocation(prog ,s);
}

void render_obj::end() {
    glDeleteVertexArrays(1, &vao);
    if(hasV)
        glDeleteBuffers(1, &vbo);
    if(hasT)
        glDeleteBuffers(1, &tbo);
    if(hasN)
        glDeleteBuffers(1, &nbo);
}

void render_manager::putTex(GLuint t_id, int where, const char *var_name) {
=======
void render_obj::end(){
    glDeleteVertexArrays(1, &vao);
    if(hasV)
    glDeleteBuffers(1, &vbo);
    if(hasT)
    glDeleteBuffers(1, &tbo);
    if(hasN)
    glDeleteBuffers(1, &nbo);
}

void render_manager::putTex(GLuint t_id, int where, const char *var_name){
>>>>>>> e9fa410b886771995a5fa2629e3686a256048643
    glActiveTexture(GL_TEXTURE0 + where);
    glBindTexture(GL_TEXTURE_2D, t_id);
    GLuint textureId  = glGetUniformLocation(getProg(in_use), var_name);
    glUniform1i(textureId, 0);
}

render_manager::render_manager() {
    in_use = -1;
}

render_manager::~render_manager() {
    //dtor
}

void render_manager::end() {
    for(int i=0; i<prog.size(); i++) {
        glDeleteProgram(prog[i]);
    }
    prog.clear();
<<<<<<< HEAD
    for(int i=0;i<texture.size();i++){
        texture[i].end();
    }
    texture.clear();
    IMG_Quit();
}

void render_manager::loadPNG(const char *name){
    SDL_Surface *img = IMG_Load(name);
    GLuint img_id = surf2tex(img);
    texture.push_back(tex(img_id,img->w,img->h,img->format->BytesPerPixel));
}

void render_manager::deletePNG(int ind){
    texture[ind].end();
    texture.erase(texture.begin() + ind);
=======
>>>>>>> e9fa410b886771995a5fa2629e3686a256048643
}

void render_manager::loadShader(const char *vertexpath, const char *fragmentpath) {
    GLuint vertexid = glCreateShader(GL_VERTEX_SHADER);
    GLuint fragmentid = glCreateShader(GL_FRAGMENT_SHADER);

    string vertexcode, fragmentcode, line;

    ifstream stream;
    stream.open(vertexpath);
    for(; getline(stream, line); vertexcode += "\n" + line);
    stream.close();

    stream.open(fragmentpath);
    for(; getline(stream, line); fragmentcode += "\n" + line);
    stream.close();

    GLint ret = GL_FALSE;
    int loglen = 0;
    GLchar *log;

    const char *vertexcodeptr = vertexcode.c_str();
    glShaderSource(vertexid, 1, &vertexcodeptr, NULL);
    glCompileShader(vertexid);

    glGetShaderiv(vertexid, GL_COMPILE_STATUS, &ret);
    glGetShaderiv(vertexid, GL_INFO_LOG_LENGTH, &loglen);

    if(loglen) {
        output("error : vert prog");
        log = new GLchar[loglen];
        glGetShaderInfoLog(vertexid, loglen, NULL, log);
        output(log);
        delete[] log;
    }

    const char *fragmentcodeptr = fragmentcode.c_str();
    glShaderSource(fragmentid, 1, &fragmentcodeptr, NULL);
    glCompileShader(fragmentid);

    loglen = 0;

    glGetShaderiv(fragmentid, GL_COMPILE_STATUS, &ret);
    glGetShaderiv(fragmentid, GL_INFO_LOG_LENGTH, &loglen);

    if(loglen) {
        output("error : frag prog");
        log = new GLchar[loglen];
        glGetShaderInfoLog(fragmentid, loglen, NULL, log);
        output(log);
        delete[] log;
    }

    GLuint programid = glCreateProgram();
    glAttachShader(programid, vertexid);
    glAttachShader(programid, fragmentid);
    glLinkProgram(programid);

    loglen = 0;

    glGetProgramiv(programid, GL_LINK_STATUS, &ret);
    glGetProgramiv(programid, GL_INFO_LOG_LENGTH, &loglen);

    if(loglen) {
        output("error : whole shader prog");
        log = new GLchar[loglen];
        glGetProgramInfoLog(programid, loglen, 0, log);
        output(log);
        delete[] log;
    }

    glDeleteShader(vertexid);
    glDeleteShader(fragmentid);

    prog.push_back(programid);
}

void render_manager::useProg(int index) {
    glUseProgram(prog[index]);
    in_use = index;
}

<<<<<<< HEAD
void render_manager::init(){
    string path = SHADERS_PATH;
    this->loadShader((path + "simple.vert").c_str(), (path + "simple.frag").c_str());
    this->loadShader((path + "2dtext.vert").c_str(), (path + "2dtext.frag").c_str());
    output("init image loader");
    if(!IMG_Init(IMG_INIT_PNG)){
        output(IMG_GetError());
    }
}

=======
>>>>>>> e9fa410b886771995a5fa2629e3686a256048643
GLuint render_manager::getProg(int index) {
    return prog[index];
}
