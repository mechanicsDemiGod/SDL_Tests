#include "../include/render_manager.h"
#include <fstream>

using namespace manager_space;

render_obj::render_obj(){
    hasT = false;
    hasV = false;
    hasN = false;
}
render_obj::render_obj(GLuint _vao,GLuint _vbo){
    render_obj();
    vao = _vao;
    vbo = _vbo;
    hasV = true;
}
render_obj::render_obj(GLuint _vao,GLuint _vbo,GLuint _tbo){
    render_obj();
    render_obj(_vao, _vbo);
    hasT = true;
    tbo = _tbo;
}
render_obj::render_obj(GLuint _vao,GLuint _vbo,GLuint _tbo,GLuint _nbo){
    render_obj();
    render_obj(_vao, _vbo, _tbo);
    hasN = true;
    nbo = _nbo;
}

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

GLuint render_manager::getProg(int index) {
    return prog[index];
}
