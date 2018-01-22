#ifndef TEXTURE_H
#define TEXTURE_H

#include "Common.h"
#include "Vec.h"
#include "bitmap_image.h"

struct Texture {

};


GLfloat* coordinatesToTexture(GLfloat* triangulationCoord)
{
	GLfloat* textCoord = new GLfloat[N_COORD * 2 * N_TRIANG * 2 * N_TRIANG];
	int size_1 = 3 * N_TRIANG * 2 * N_TRIANG;
	int size_2 = N_COORD * N_COORD * N_TRIANG * 2 * N_TRIANG;
	int offset = 3, offset_tex = 2;

	for (int i = 0; i < size_2; i+=3) {
		(triangulationCoord[i] += 0.8) /= 1.6;
		(triangulationCoord[i + 2] += 0.8) /= 1.6;
	}

	for (int i = 0; i < size_1; i++) {
		textCoord[offset_tex * i] = triangulationCoord[offset * i];
		textCoord[offset_tex * i + 1] = triangulationCoord[offset * i + 2];
	}

	return textCoord;
}


void loadTexture(int number, GLuint* textures, const string& file)
{	
	bitmap_image image(file);

	if (image.thereIsData()) {
		unsigned char* image_arr = &image.data_[0];

		glGenTextures(1, &textures[number]);
		glActiveTexture(GL_TEXTURE + number);
		glBindTexture(GL_TEXTURE_2D, textures[number]);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, (int)image.width_, (int)image.height_, 0, GL_RGB, GL_UNSIGNED_BYTE, image_arr);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else cout << "Texture failed to load at path: " << endl;

}

#endif 
