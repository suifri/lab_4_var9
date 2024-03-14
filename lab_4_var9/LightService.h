#pragma once
#include <GL/glut.h>
#include "LightConstants.h"

static class LightService
{
private:
	static GLboolean spotlightDirection;
	static GLboolean isRadialFading;
public:
	static void radialFading();
	static void updateLights();

	static GLboolean getSpotlightDirection();
	static void setSpotlightDirection(const GLboolean spotlightDirection);
	static void setRadialFading(const GLboolean isRadialFading);
	static GLboolean getRadialFading();
};

