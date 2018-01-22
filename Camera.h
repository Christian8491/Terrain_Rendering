#ifndef CAMERA_H
#define CAMERA_H

#include "Common.h"
#include "Vec.h"

GLfloat theta = 8.0;

struct Camera {

	vec4 position;
	vec4 front;
	vec4 up;

	Camera() {}
	
	void initialize()
	{
		position = vec4(0.0, 0.6, 0.0, 1.0);
		front = vec4(0.0, 0.1, 10.5, 1.0);
		up = vec4(0.0, 1.0, 0.0, 1.0);
	}

	vec3 position_3()
	{
		vec3 aux = (position.x, position.y, position.z);
		return aux;
	}

	/* Displacement on the Z axis + */
	void displacementPosZ()
	{
		/*
		vec4 aux = front;
		front.x += 0.5;
		front.z += 0.5;
		position = aux;
		*/
		position.z += 0.02;
		front.z += 0.02;
	}

	/* Displacement on the Z axis - */
	void displacementNegZ()
	{
		position.z -= 0.02;
		front.z -= 0.02;
	}

	/* Displacement on the X axis + */
	void displacementPosX()
	{	
		position.x += 0.02;
		front.x += 0.02;
		/*
		front.x = sin(theta * M_PI / 180);
		front.z = cos(theta * M_PI / 180);
		theta += 8.0;
		if (theta >= 360) theta = 0.0;
		*/
	}

	/* Displacement on the X axis - */
	void displacementNegX()
	{
		position.x -= 0.02;
		front.x -= 0.02;
		/*
		front.x = sin(theta * M_PI / 180);
		front.z = cos(theta * M_PI / 180);
		theta -= 8.0;
		if (theta <= -360) theta = 0.0;
		*/
	}

	/* Displacement on the X axis + */
	void displacementPosY()
	{
		front.y += 0.04;
	}

	/* Displacement on the X axis - */
	void displacementNegY()
	{
		front.y -= 0.04;
	}

	mat4 GetViewMatrix__()
	{
		return LookAt(position, position + front, up);
	}

	mat4 GetViewMatrix()
	{
		return LookAt(position, front , up);
	}
};

#endif 
  