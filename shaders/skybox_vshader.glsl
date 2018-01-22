#version 150 core

in vec3 vPosition;

out vec3 TexCoord;

uniform mat4 projection;
uniform mat4 view;

void main()
{
    TexCoord = vPosition;
    vec4 pos = projection * view * vec4(vPosition, 1.0);
    gl_Position = pos.xyww;
}