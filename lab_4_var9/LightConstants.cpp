#include "LightConstants.h"

const GLfloat LightConstants::lightPosition[] = { 0.0, 0.0, -15.0, 0.0 };
const GLfloat LightConstants::lightAmbient[] = { 0.0, 0.0, 1.0, 1.0 };
const GLfloat LightConstants::lightDiffuse[] = { 0.0, 0.0, 1.0, 1.0 };

GLfloat LightConstants::spotlightPosition[] = { 0, 15, -10, 0.0 };
const GLfloat LightConstants::spotlightDirection[] = { -1.0, -1.0, -1.0 };
const GLfloat LightConstants::spotlightAmbient[] = { 1.0, 1.0, 1.0, 1.0 };
const GLfloat LightConstants::spotlightDiffuse[] = { 0.0, 1.0, 0.0, 1.0 };
const GLfloat LightConstants::spotlightCutoff = 120;
const GLfloat LightConstants::spotlightExponent = 1.0;

const GLfloat LightConstants::distantLightDirection[] = { 1.0, 0.0, -1.0, 1.0 };
const GLfloat LightConstants::distantLightDiffuse[] = { 1.0, 0.0, 0.0, 1.0 };
const GLfloat LightConstants::distantLightAmbient[] = { 1.0, 1.0, 1.0, 1.0 };

const GLfloat LightConstants::pointLightAmbient[] = { 0.2, 0.2, 0.2, 1.0 };
const GLfloat LightConstants::pointLightDiffuse[] = { 0.8, 0.8, 0.8, 1.0 };
const GLfloat LightConstants::pointLightSpecular[] = { 1.0, 1.0, 1.0, 1.0 };
const GLfloat LightConstants::pointLightPosition[] = { 2, 2, -8.0, 1.0 };
const GLfloat LightConstants::lightConstantAttenuation = 1.0;
const GLfloat LightConstants::lightLinearAttenuation = 0.05;
const GLfloat LightConstants::lightQuadraticAttenuation = 0.01;

void LightConstants::setNewSpotlightPosition(const GLfloat value)
{
	*(LightConstants::spotlightPosition + 0) = value;
}

GLfloat LightConstants::getSpotlightPosition()
{
	return *(LightConstants::spotlightPosition + 0);
}
