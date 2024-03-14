#pragma once
#include <GL/glut.h>

static class RotationService
{
private:
	static GLboolean rotationEnabled;
	static GLfloat rotationAngle;
public:

	static void setRotationEnabled(const GLboolean roatationEnabled = true);
	static GLboolean getRotationEnabled();

	static void setRotationAngle(const GLfloat rotationAngle);
	static GLfloat getRotationAngle();
};

