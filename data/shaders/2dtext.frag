#version 330 core
<<<<<<< HEAD

uniform sampler2D text;
in vec2 UV;

void main(){
    vec4 mat_dif = texture2D( text, UV ).rgba;
    gl_FragColor.rgba = vec4(mat_dif);
=======
out vec3 color;

void main(){
    color = vec3(1.0, 0.0, 0.0);
>>>>>>> e9fa410b886771995a5fa2629e3686a256048643
}
