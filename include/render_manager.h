#ifndef MANAGER_RENDER_H
#define MANAGER_RENDER_H
#include "manager_space.h"
#include <vector>
#include <string>

using namespace std;

class render_obj {
public:
    render_obj();
    render_obj(GLuint _vao, GLuint _vbo);
    render_obj(GLuint _vao, GLuint _vbo, GLuint _tbo);
    render_obj(GLuint _vao, GLuint _vbo, GLuint _tbo, GLuint _nbo);
    void end();

    bool hasV, hasT, hasN;
    GLuint vao, vbo, tbo, nbo;
};

class render_manager {
public:
    render_manager();
    virtual ~render_manager();
    void loadShader(const char *vertexpath, const char *fragmentpath);
    void end();
    void useProg(int index);
    GLuint getProg(int index);
    void putTex(GLuint t_id, int where, const char *var_name);

    int in_use;
    vector<GLuint> prog;
};

#endif // MANAGER_RENDER_H
