#ifndef CAMERA_H
#define CAMERA_H

#include "Common.h"
#include "Vec.h"

GLfloat theta = 8.0;

struct Camera {

	vec4 position;
	vec4 at;
	vec4 up;

	Camera() {}

	void initialize()
	{
		position = vec4(0.0, 0.8, 6.0, 1.0);
		at = vec4(1.0, 0.76, 3.0, 1.0);
		up = vec4(0.0, 1.0, 0.0, 1.0);
	}

	vec3 position_3()
	{
		return vec3(position.x, position.y, position.z);
	}

	/* Displacement on the Z axis + */
	void displacementPosZ()
	{
		/*
		vec4 aux = at;
		at.x += 0.5;
		at.z += 0.5;
		position = aux;
		*/
		position.z += 0.02;
		at.z += 0.02;
	}

	/* Displacement on the Z axis - */
	void displacementNegZ()
	{
		position.z -= 0.02;
		at.z -= 0.02;
	}

	/* Displacement on the X axis + */
	void displacementPosX()
	{
		position.x += 0.02;
		at.x += 0.02;
		/*
		at.x = sin(theta * M_PI / 180);
		at.z = cos(theta * M_PI / 180);
		theta += 8.0;
		if (theta >= 360) theta = 0.0;
		*/
	}

	/* Displacement on the X axis - */
	void displacementNegX()
	{
		position.x -= 0.02;
		at.x -= 0.02;
		/*
		at.x = sin(theta * M_PI / 180);
		at.z = cos(theta * M_PI / 180);
		theta -= 8.0;
		if (theta <= -360) theta = 0.0;
		*/
	}

	/* Displacement on the X axis + */
	void displacementPosY()
	{
		at.y += 0.04;
	}

	/* Displacement on the X axis - */
	void displacementNegY()
	{
		at.y -= 0.04;
	}

	mat4 GetViewMatrix__()
	{
		return LookAt(position, position + at, up);
	}

	mat4 GetViewMatrix()
	{
		return LookAt(position, at, up);
	}
};

#endif 
