#version 150 core

in vec3 vPosition;
in vec2 vTexCoord;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

out vec2 TexCoord;
out vec4 heigts_coor;

void main() { 
    
    gl_Position =  projection * view * model * vec4(vPosition, 1.0); 
    TexCoord = vTexCoord;

    heigts_coor = vec4(vPosition, 1.0); 
}