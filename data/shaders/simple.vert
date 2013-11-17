#version 330 core

layout(location = 0) in vec2 vert;
layout(location = 1) in vec2 uv;

<<<<<<< HEAD
uniform vec2 pos;
uniform float inv_size, font_size;
uniform mat4 m, v, p, mvp;
=======
varying vec2 pos;
>>>>>>> e9fa410b886771995a5fa2629e3686a256048643

out vec2 UV;

void main(){
<<<<<<< HEAD
    gl_Position = mvp * vec4(vert,1,1);
    //gl_Position = vec4(vert,1,1);
    //gl_Position.xy = vert+pos;
    UV = vec2(uv.x,uv.y);
=======
    //gl_Position.xy = vert + pos;
    gl_Position.xy = vert;
    UV = vec2(1- uv.x, uv.y);
>>>>>>> e9fa410b886771995a5fa2629e3686a256048643
}