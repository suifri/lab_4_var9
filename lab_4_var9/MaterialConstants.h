#pragma once
#include <GL/glut.h>

static class MaterialConstants
{
private:
	static const GLint membersSize = 4;
public:
	static const GLfloat materialAmbient[membersSize];
	static const GLfloat materialDiffuse[membersSize];
	static const GLfloat materialSpecular[membersSize];
	static const GLfloat shininess[1];
};

