#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "Common.h"
#include "Clipmap.h"

int numVertices_1 = 6;
int numVertices_2 = 24;
int numVer = 3;

GLfloat background[] = {

	100.0, 80.0, 100.0,
	100.0, -5.0, 100.0,
	-100.0, -5.0, 100.0,

	100.0, 80.0, 100.0,
	-100.0, -5.0, 100.0,
	-100.0, 80.0, 100.0

};

GLfloat background_2[] = {

	-3.1, 0.0, 3.1,
	-3.1, 0.0, 1.55,
	3.1, 0.0, 3.1,

	3.1, 0.0, 3.1,
	1.55, 0.0, 1.55,
	-3.1, 0.0, 1.55,

	3.1, 0.0, 3.1,
	1.55, 0.0, 1.55,
	3.1, 0.0, -3.1,

	3.1, 0.0, -3.1,
	1.55, 0.0, 1.55,
	1.55, 0.0, -1.55,

	3.1, 0.0, -3.1,
	1.55, 0.0, -1.55,
	-3.1, 0.0, -3.1,

	-3.1, 0.0, -3.1,
	1.55, 0.0, -1.55,
	-1.55, 0.0, -1.55,

	-3.1, 0.0, -3.1,
	-3.1, 0.0, 1.55,
	-1.55, 0.0, -1.55,

	-1.55, 0.0, 1.55,
	-3.1, 0.0, 1.55,
	-1.55, 0.0, -1.55,

	/*
	3.1, -0.1, 3.1,
	3.1, -0.1, -3.1,
	-3.1, -0.1, -3.1,
	-3.1, -0.1, -3.1,
	-3.1, -0.1, 3.1,
	3.1, -0.1, 3.1
	*/
};

GLfloat background_3[] = {

	-4.65, 0.0, 4.65,
	-4.65, 0.0, 3.1,
	4.65, 0.0, 4.65,

	4.65, 0.0, 4.65,
	3.1, 0.0, 3.1,
	-4.65, 0.0, 3.1,

	4.65, 0.0, 4.65,
	3.1, 0.0, 3.1,
	4.65, 0.0, -4.65,

	4.65, 0.0, -4.65,
	3.1, 0.0, 3.1,
	3.1, 0.0, -3.1,

	4.65, 0.0, -4.65,
	3.1, 0.0, -3.1,
	-4.65, 0.0, -4.65,

	-4.65, 0.0, -4.65,
	3.1, 0.0, -3.1,
	-3.1, 0.0, -3.1,

	-4.65, 0.0, -4.65,
	-4.65, 0.0, 3.1,
	-3.1, 0.0, -3.1,

	-3.1, 0.0, 3.1,
	-4.65, 0.0, 3.1,
	-3.1, 0.0, -3.1,

	/*
	4.65, -0.05, 4.65,
	4.65, -0.05, -4.65,
	-4.65, -0.05, -4.65,
	-4.65, -0.05, -4.65,
	-4.65, -0.05, 4.65,
	4.65, -0.05, 4.65
	*/
};

GLfloat background_4[] = {

	-6.2, 0.0, 6.2,
	-6.2, 0.0, 4.65,
	6.2, 0.0, 6.2,

	6.2, 0.0, 6.2,
	4.65, 0.0, 4.65,
	-6.2, 0.0, 4.65,

	6.2, 0.0, 6.2,
	4.65, 0.0, 4.65,
	6.2, 0.0, -6.2,

	6.2, 0.0, -6.2,
	4.65, 0.0, 4.65,
	4.65, 0.0, -4.65,

	6.2, 0.0, -6.2,
	4.65, 0.0, -4.65,
	-6.2, 0.0, -6.2,

	-6.2, 0.0, -6.2,
	4.65, 0.0, -4.65,
	-4.65, 0.0, -4.65,

	-6.2, 0.0, -6.2,
	-6.2, 0.0, 4.65,
	-4.65, 0.0, -4.65,

	-4.65, 0.0, 4.65,
	-6.2, 0.0, 4.65,
	-4.65, 0.0, -4.65,

	/*
	6.2, -0.3, 6.2,
	6.2, -0.3, -6.2,
	-6.2, -0.3, -6.2,
	-6.2, -0.3, -6.2,
	-6.2, -0.3, 6.2,
	6.2, -0.3, 6.2
	*/
};

GLfloat background_5[] = {

	-7.75, 0.0, 7.75,
	-7.75, 0.0, 6.2,
	7.75, 0.0, 7.75,

	7.75, 0.0, 7.75,
	6.2, 0.0, 6.2,
	-7.75, 0.0, 6.2,

	7.75, 0.0, 7.75,
	6.2, 0.0, 6.2,
	7.75, 0.0, -7.75,

	7.75, 0.0, -7.75,
	6.2, 0.0, 6.2,
	6.2, 0.0, -6.2,

	7.75, 0.0, -7.75,
	6.2, 0.0, -6.2,
	-7.75, 0.0, -7.75,

	-7.75, 0.0, -7.75,
	6.2, 0.0, -6.2,
	-6.2, 0.0, -6.2,

	-7.75, 0.0, -7.75,
	-7.75, 0.0, 6.2,
	-6.2, 0.0, -6.2,

	-6.2, 0.0, 6.2,
	-7.75, 0.0, 6.2,
	-6.2, 0.0, -6.2,

	/*
	7.75, -0.4, 7.75,
	7.75, -0.4, -7.75,
	-7.75, -0.4, -7.75,
	-7.75, -0.4, -7.75,
	-7.75, -0.4, 7.75,
	7.75, -0.4, 7.75
	*/
};

GLfloat background_6[] = {

	-9.3, 0.0, 9.3,
	-9.3, 0.0, 7.75,
	9.3, 0.0, 9.3,

	9.3, 0.0, 9.3,
	7.75, 0.0, 7.75,
	-9.3, 0.0, 7.75,

	9.3, 0.0, 9.3,
	7.75, 0.0, 7.75,
	9.3, 0.0, -9.3,

	9.3, 0.0, -9.3,
	7.75, 0.0, 7.75,
	7.75, 0.0, -7.75,

	9.3, 0.0, -9.3,
	7.75, 0.0, -7.75,
	-9.3, 0.0, -9.3,

	-9.3, 0.0, -9.3,
	7.75, 0.0, -7.75,
	-7.75, 0.0, -7.75,

	-9.3, 0.0, -9.3,
	-9.3, 0.0, 7.75,
	-7.75, 0.0, -7.75,

	-7.75, 0.0, 7.75,
	-9.3, 0.0, 7.75,
	-7.75, 0.0, -7.75
};

#endif