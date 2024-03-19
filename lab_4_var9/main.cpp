#include <GL/glut.h>
#include "Settings.h"
#include "LightService.h"
#include "FogService.h"
#include "RotationService.h"
#include "stb_image.h"
#include <iostream>
#include "TorusDrawerService.h"

//намалювати об'єкт, складений із двох переплетених торів, один із яких покритий текстурою дерева.
//Реалізувати обертання об'єкта навколо горизонтальної осі

GLuint textureID;

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glShadeModel(GL_SMOOTH);

	glLoadIdentity();

	if(LightService::getRadialFading())
		LightService::radialFading();

	LightService::updateLights();

	FogService::drawFog(0.5, 0.5, 0.5);

	glTranslatef(0.0, -1.0, -9.0);

	if (RotationService::getRotationEnabled())
		glRotatef(RotationService::getRotationAngle(), 1.0, 0.0, 0.0);

	glPushMatrix();
	glRotatef(90, 0.0, 1.0, 0.0);
	glTranslatef(0.0, 1.8, 0.0);
	glColor3f(0.3, 0.3, 0.3);
	glutSolidTorus(0.3, 1.0, 50, 50);
	glPopMatrix();
	TorusDrawerService service;
	service.drawTorus(1.0, 0.3, textureID);

	glutSwapBuffers();
}

void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 1.0);

	Settings::lightInitialSettings();
	Settings::materialInitialSettings();

	TorusDrawerService::loadTexture("Texture.jpg", textureID);

	glEnable(GL_NORMALIZE);
}

void reshape(const GLint width, const GLint height)
{
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, static_cast<GLdouble>(width) / static_cast<GLdouble>(height), 1.0, 100.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void idle()
{
	RotationService::setRotationAngle(RotationService::getRotationAngle() + 0.05f);

	if (RotationService::getRotationAngle() > 360.0f)
		RotationService::setRotationAngle(RotationService::getRotationAngle() - 360.0f);

	glutPostRedisplay();
}

GLfloat fogColor[] = { 0.5, 0.5, 0.5, 1.0 };

void keyboard(unsigned char key, GLint x, GLint y)
{
	switch (key)
	{
	case 'f':
		if (glIsEnabled(GL_FOG))
			glDisable(GL_FOG);
		else
			glEnable(GL_FOG);
		break;
	case 'r':
		LightService::setRadialFading(!LightService::getRadialFading());
		break;
	case 'y':
		FogService::setFogType(!FogService::getFogType());
		break;
	case 'a':
		if (glIsEnabled(GL_LIGHT0))
			glDisable(GL_LIGHT0);
		else
			glEnable(GL_LIGHT0);
		break;
	case 's':
		if (glIsEnabled(GL_LIGHT1))
			glDisable(GL_LIGHT1);
		else
			glEnable(GL_LIGHT1);
		break;
	case 'd':
		if (glIsEnabled(GL_LIGHT2))
			glDisable(GL_LIGHT2);
		else
			glEnable(GL_LIGHT2);
		break;
	case 't':
		if (glIsEnabled(GL_LIGHT3))
			glDisable(GL_LIGHT3);
		else
			glEnable(GL_LIGHT3);
		break;
	default:
		break;
	}

	glutPostRedisplay();
}

void mainMenuHandler(int choice)
{
	switch (choice)
	{
	case 1:
		if (glIsEnabled(GL_LIGHT0))
			glDisable(GL_LIGHT0);
		else
			glEnable(GL_LIGHT0);
		break;
	case 2:
		if (glIsEnabled(GL_LIGHT1))
			glDisable(GL_LIGHT1);
		else
			glEnable(GL_LIGHT1);
		break;
	case 3:
		if (glIsEnabled(GL_LIGHT2))
			glDisable(GL_LIGHT2);
		else
			glEnable(GL_LIGHT2);
		break;
	case 4:
		if (glIsEnabled(GL_LIGHT3))
			glDisable(GL_LIGHT3);
		else
			glEnable(GL_LIGHT3);
		break;
	case 5:
		if (glIsEnabled(GL_FOG))
			glDisable(GL_FOG);
		else
			glEnable(GL_FOG);
		break;
	case 6:
		LightService::setRadialFading(!LightService::getRadialFading());
		break;
	case 7:
		FogService::setFogType(!FogService::getFogType());
		break;
	default:
		break;
	}
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(800, 600);
	glutCreateWindow(*argv);

	init();

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutCreateMenu(mainMenuHandler);
	glutAddMenuEntry("Fon", 1);
	glutAddMenuEntry("Spotlight", 2);
	glutAddMenuEntry("Distant", 3);
	glutAddMenuEntry("Point", 4);
	glutAddMenuEntry("Fog", 5);
	//glutAddMenuEntry("Radial", 6);
	glutAddMenuEntry("Fog type", 7);
	glutAttachMenu(GLUT_RIGHT_BUTTON);

	glutIdleFunc(idle);
	glutMainLoop();

	return 0;
}