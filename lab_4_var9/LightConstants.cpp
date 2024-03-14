#include "LightConstants.h"

const GLfloat LightConstants::lightPosition[] = { 0.0, 0.0, -15.0, 0.0 };
const GLfloat LightConstants::lightAmbient[] = { 0.0, 0.0, 1.0, 1.0 };
const GLfloat LightConstants::lightDiffuse[] = { 0.0, 0.0, 1.0, 1.0 };

GLfloat LightConstants::spotlightPosition[] = { 0.0, 0.0, 10.0, 1.0 };
const GLfloat LightConstants::spotlightDirection[] = { 0.0, 0.0, -1.0, 1.0 };
const GLfloat LightConstants::spotlightAmbient[] = { 1.0, 1.0, 1.0, 1.0 };
const GLfloat LightConstants::spotlightDiffuse[] = { 0.0, 1.0, 0.0, 1.0 };
const GLfloat LightConstants::spotlightCutoff = 2.0;
const GLfloat LightConstants::spotlightExponent = 10.0;

const GLfloat LightConstants::distantLightDirection[] = { 1.0, 0.0, -1.0, 1.0 };
const GLfloat LightConstants::distantLightDiffuse[] = { 1.0, 0.0, 0.0, 1.0 };
const GLfloat LightConstants::distantLightAmbient[] = { 1.0, 1.0, 1.0, 1.0 };

void LightConstants::setNewSpotlightPosition(const GLfloat value)
{
	*(LightConstants::spotlightPosition + 1) = value;
}

GLfloat LightConstants::getSpotlightPosition()
{
	return *(LightConstants::spotlightPosition + 1);
}
