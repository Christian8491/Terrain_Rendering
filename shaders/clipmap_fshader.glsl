#version 150 core

uniform vec3 backgroundColor;

out vec4 fColor;

void main() { 
	
	fColor =  vec4(backgroundColor, 1.0); 
}