#include "LightService.h"

GLboolean LightService::spotlightDirection = true;
GLboolean LightService::isRadialFading = true;

void LightService::radialFading()
{
	if (isRadialFading == true)
	{
		glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, 1.0);
		glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, 0.05);
		glLightf(GL_LIGHT0, GL_QUADRATIC_ATTENUATION, 0.001);
	}
}

void LightService::updateLights()
{
	if (spotlightDirection && LightConstants::getSpotlightPosition() < 0.3 || spotlightDirection == false && LightConstants::getSpotlightPosition() < -0.4)
		spotlightDirection = true;
	else
		spotlightDirection = false;

	if (spotlightDirection)
		LightConstants::setNewSpotlightPosition(LightConstants::getSpotlightPosition() + 0.0005f);
	else
		LightConstants::setNewSpotlightPosition(LightConstants::getSpotlightPosition() - 0.0005f);

	glPushMatrix();
	glLightfv(GL_LIGHT1, GL_POSITION, LightConstants::spotlightPosition);
	glPopMatrix();
}

GLboolean LightService::getSpotlightDirection()
{
	return LightService::spotlightDirection;
}

void LightService::setSpotlightDirection(const GLboolean spotlightDirection)
{
	LightService::spotlightDirection = spotlightDirection;
}

void LightService::setRadialFading(const GLboolean isRadialFading)
{
	LightService::isRadialFading = isRadialFading;
}

GLboolean LightService::getRadialFading()
{
	return LightService::isRadialFading;
}
