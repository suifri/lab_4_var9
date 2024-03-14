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
	glLightf(GL_LIGHT2, GL_SPOT_EXPONENT, LightConstants::spotlightExponent);

	////distant settings
	glLightfv(GL_LIGHT2, GL_POSITION, LightConstants::distantLightDirection);
	glLightfv(GL_LIGHT2, GL_AMBIENT, LightConstants::distantLightAmbient);
	glLightfv(GL_LIGHT2, GL_DIFFUSE, LightConstants::distantLightDiffuse);
}

void Settings::materialInitialSettings()
{
	glMaterialfv(GL_FRONT, GL_AMBIENT, MaterialConstants::materialAmbient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, MaterialConstants::materialDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, MaterialConstants::materialSpecular);
	glMaterialf(GL_FRONT, GL_SHININESS, MaterialConstants::shininess);
}
