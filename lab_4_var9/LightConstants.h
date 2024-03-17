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
	static const GLfloat spotlightDirection[3];
	static const GLfloat spotlightAmbient[membersSize];
	static const GLfloat spotlightDiffuse[membersSize];
	static const GLfloat spotlightCutoff;
	static const GLfloat spotlightExponent;

	static const GLfloat distantLightDirection[membersSize];
	static const GLfloat distantLightAmbient[membersSize];
	static const GLfloat distantLightDiffuse[membersSize];

	static const GLfloat pointLightPosition[membersSize];
	static const GLfloat pointLightAmbient[membersSize];
	static const GLfloat pointLightDiffuse[membersSize];
	static const GLfloat pointLightSpecular[membersSize];
	static const GLfloat lightConstantAttenuation;
	static const GLfloat lightLinearAttenuation;
	static const GLfloat lightQuadraticAttenuation;

	static void setNewSpotlightPosition(const GLfloat value);
	static GLfloat getSpotlightPosition();
};

