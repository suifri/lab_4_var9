#pragma once
#include <GL/glut.h>


static class LightConstants
{
private:
	static const GLint membersSize = 4;
public:
	static const GLfloat lightPosition[membersSize];
	static const GLfloat lightAmbient[membersSize];
	static const GLfloat lightDiffuse[membersSize];

	static GLfloat spotlightPosition[membersSize];
	static const GLfloat spotlightDirection[membersSize];
	static const GLfloat spotlightAmbient[membersSize];
	static const GLfloat spotlightDiffuse[membersSize];
	static const GLfloat spotlightCutoff;
	static const GLfloat spotlightExponent;

	static const GLfloat distantLightDirection[membersSize];
	static const GLfloat distantLightAmbient[membersSize];
	static const GLfloat distantLightDiffuse[membersSize];

	static void setNewSpotlightPosition(const GLfloat value);
	static GLfloat getSpotlightPosition();
};

