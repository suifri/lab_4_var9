#pragma once
#include <GL/glut.h>
#include "vector3.h"
#define _USE_MATH_DEFINES // enable the definition of M_PI
#include <math.h>
#define PI 3.14159265359
#include "stb_image.h"
#include <iostream>

class TorusDrawerService
{
private:
	Vector3 getPoint(float out_angle, float int_angle, float out_radius, float int_radius);
	Vector3 getPointNormal(float out_angle, float int_angle, float out_radius, float int_radius);
	void glTorusTexCoord(float out_angle, float int_angle, int tx);
public:
	void drawTorus(GLfloat out_radius, GLfloat int_radius, GLint textureId);
	static void loadTexture(const char* filename, GLuint& textureID);
};

