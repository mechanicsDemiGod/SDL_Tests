#version 330 core

layout(location = 0) in vec2 vert;
layout(location = 1) in vec2 uv;

varying vec2 pos;

out vec2 UV;

void main(){
    //gl_Position.xy = vert + pos;
    gl_Position.xy = vert;
    UV = vec2(1- uv.x, uv.y);
}