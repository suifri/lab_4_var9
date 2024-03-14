#pragma once
#include <GL/glut.h>

static class FogService
{
private:
	static GLboolean isFogLinear;

public:
	static void drawFog(const GLfloat r, const GLfloat g, const GLfloat b);
	static void setFogType(const GLboolean isFogLinear = true);
	static GLboolean getFogType();
};

