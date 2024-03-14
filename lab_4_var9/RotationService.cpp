#include "RotationService.h"

GLboolean RotationService::rotationEnabled = true;
GLfloat RotationService::rotationAngle = 0.0f;

void RotationService::setRotationEnabled(const GLboolean roatationEnabled)
{
	RotationService::rotationEnabled = roatationEnabled;
}

GLboolean RotationService::getRotationEnabled()
{
	return RotationService::rotationEnabled;
}

void RotationService::setRotationAngle(const GLfloat rotationAngle)
{
	RotationService::rotationAngle = rotationAngle;
}

GLfloat RotationService::getRotationAngle()
{
	return RotationService::rotationAngle;
}
