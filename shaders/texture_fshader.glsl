#version 150 core

in vec2 TexCoord;
in vec4 heigts_coor;

uniform sampler2D texture1;
uniform sampler2D texture2;
uniform sampler2D texture3;
uniform sampler2D texture4;
uniform sampler2D texture5;
uniform sampler2D texture6;
uniform sampler2D texture7;

out vec4 fColor;

void main() { 

	if (heigts_coor.y >= 0.30) fColor = texture(texture7, TexCoord);
	else if (heigts_coor.y >= 0.29) {
		fColor = mix(texture(texture7, TexCoord), texture(texture6, TexCoord), 0.2);
	}
	else if (heigts_coor.y >= 0.27) {
		fColor = mix(texture(texture5, TexCoord), texture(texture6, TexCoord), 0.9);
		//fColor = texture(texture4, TexCoord);
	}
	else if (heigts_coor.y >= 0.15) {
		fColor = mix(texture(texture4, TexCoord), texture(texture3, TexCoord), 0.4);
		//fColor = texture(texture3, TexCoord);
	}
	else if (heigts_coor.y >= 0.02) {
		fColor = mix(texture(texture3, TexCoord), texture(texture2, TexCoord), 0.4);
		//fColor = texture(texture2, TexCoord);
	}
	else if (heigts_coor.y >= -0.2) {
		fColor = mix(texture(texture3, TexCoord), texture(texture2, TexCoord), 0.7);
		//fColor = texture(texture2, TexCoord);
	}
	else fColor = texture(texture1, TexCoord); // * vec4(0.09, 0.12, 0.655, 1.0);
	// fColor = mix(texture(texture1, TexCoord), texture(texture2, TexCoord), 0.2);
	
}