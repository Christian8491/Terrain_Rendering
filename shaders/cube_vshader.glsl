#version 150 core

in vec3 vPosition;
in vec3 vNormal;

out vec3 Position;
out vec3 Normal;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
    Normal = mat3(transpose(inverse(model))) * vNormal;
    Position = vec3(model * vec4(vPosition, 1.0));
    gl_Position = projection * view * model * vec4(vPosition, 1.0);
}