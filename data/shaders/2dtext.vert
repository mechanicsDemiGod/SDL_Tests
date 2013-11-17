#version 330 core
<<<<<<< HEAD

layout(location = 0) in vec2 vert;
layout(location = 1) in vec2 uv;

uniform mat4 mvp;

out vec2 UV;

void main(){
    gl_Position = mvp * vec4(vert,1,1);
    UV = vec2(uv.x,uv.y);
}
=======
in vec3 rawposition;

void main(){
    gl_Position.xyz = rawposition;
    gl_Position.w = 1.0;
}
>>>>>>> e9fa410b886771995a5fa2629e3686a256048643
