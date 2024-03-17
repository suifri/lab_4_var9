#include "Settings.h"

void Settings::lightInitialSettings()
{
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHTING);
	glEnable(GL_FOG);

	//spotlight settings
	glLightfv(GL_LIGHT1, GL_POSITION, LightConstants::spotlightPosition);
	glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, LightConstants::spotlightDirection);
	glLightfv(GL_LIGHT1, GL_AMBIENT, LightConstants::spotlightAmbient);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, LightConstants::spotlightDiffuse);
	glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, LightConstants::spotlightCutoff);
	glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, LightConstants::spotlightExponent);

	////distant settings
	glLightfv(GL_LIGHT2, GL_POSITION, LightConstants::distantLightDirection);
	glLightfv(GL_LIGHT2, GL_AMBIENT, LightConstants::distantLightAmbient);
	glLightfv(GL_LIGHT2, GL_DIFFUSE, LightConstants::distantLightDiffuse);

	glLightfv(GL_LIGHT3, GL_POSITION, LightConstants::pointLightPosition);
	glLightfv(GL_LIGHT3, GL_AMBIENT, LightConstants::pointLightAmbient);
	glLightfv(GL_LIGHT3, GL_DIFFUSE, LightConstants::pointLightDiffuse);
	glLightfv(GL_LIGHT3, GL_SPECULAR, LightConstants::pointLightSpecular);
//	glLightf(GL_LIGHT3, GL_CONSTANT_ATTENUATION, LightConstants::lightConstantAttenuation);
//	glLightf(GL_LIGHT3, GL_LINEAR_ATTENUATION, LightConstants::lightLinearAttenuation);
//	glLightf(GL_LIGHT3, GL_QUADRATIC_ATTENUATION, LightConstants::lightQuadraticAttenuation);
}

void Settings::materialInitialSettings()
{
	glMaterialfv(GL_FRONT, GL_AMBIENT, MaterialConstants::materialAmbient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, MaterialConstants::materialDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, MaterialConstants::materialSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, MaterialConstants::shininess);
}
