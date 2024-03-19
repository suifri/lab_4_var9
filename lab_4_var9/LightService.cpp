#include "LightService.h"

GLboolean LightService::spotlightDirection = true;
GLboolean LightService::isRadialFading = true;

void LightService::radialFading()
{
		glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, 1.0);
		glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, 0.1);
		glLightf(GL_LIGHT0, GL_QUADRATIC_ATTENUATION, 0.1);
}

void LightService::updateLights()
{
	if (spotlightDirection && LightConstants::getSpotlightPosition() < 30 || spotlightDirection == false && LightConstants::getSpotlightPosition() < -30)
		spotlightDirection = true;
	else
		spotlightDirection = false;

	if (spotlightDirection)
		LightConstants::setNewSpotlightPosition(LightConstants::getSpotlightPosition() + 0.05f);
	else
		LightConstants::setNewSpotlightPosition(LightConstants::getSpotlightPosition() - 0.05f);

	//if (LightConstants::lightPosition[1] <= -15)
	//	LightConstants::lightPosition[1] += 0.05;
	//else
	//	LightConstants::lightPosition[1] -= 0.05;

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
