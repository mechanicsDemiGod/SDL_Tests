#version 330 core

uniform sampler2D text;
in vec2 UV;

void main(){
    vec4 mat_dif = texture2D( text, UV ).rgba;
<<<<<<< HEAD
    gl_FragColor.rgba = vec4(mat_dif)+vec4(1,1,1,.1);
=======
    gl_FragColor.rgba = vec4(mat_dif);
    gl_FragColor.rgba = vec4(1,1,1,1);
>>>>>>> e9fa410b886771995a5fa2629e3686a256048643
}
