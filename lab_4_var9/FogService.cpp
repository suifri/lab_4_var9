#include "FogService.h"

GLboolean FogService::isFogLinear = true;

void FogService::drawFog(const GLfloat r, const GLfloat g, const GLfloat b)
{
	if (FogService::isFogLinear)
	{
		glFogf(GL_FOG_START, 10.0f);
		glFogf(GL_FOG_END, 5.0);
		glFogi(GL_FOG_MODE, GL_LINEAR);
	}
	else
		glFogi(GL_FOG_MODE, GL_EXP2);

	glFogf(GL_FOG_DENSITY, 0.2);

	GLfloat fogColor[] = { r, g, b, 1.0 };
	glFogfv(GL_FOG_COLOR, fogColor);
	glClearColor(r, g, b, 1.0);
}

void FogService::setFogType(const GLboolean isFogLinear)
{
	FogService::isFogLinear = isFogLinear;
}

GLboolean FogService::getFogType()
{
	return FogService::isFogLinear;
}
