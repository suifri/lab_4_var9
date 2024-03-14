#include "TorusDrawerService.h"

Vector3 TorusDrawerService::getPoint(float out_angle, float int_angle, float out_radius, float int_radius)
{
	return	Vector3((out_radius + int_radius * cos(int_angle)) * cos(out_angle),
		(out_radius + int_radius * cos(int_angle)) * sin(out_angle),
		int_radius * sin(int_angle));
}

Vector3 TorusDrawerService::getPointNormal(float out_angle, float int_angle, float out_radius, float int_radius)
{
	Vector3 tangentOut(-sin(out_angle),
		cos(out_angle),
		0);

	Vector3 tangentInt(cos(out_angle) * (-sin(int_angle)),
		sin(out_angle) * (-sin(int_angle)),
		cos(int_angle));

	Vector3 normal = tangentOut ^ tangentInt;

	return normal.Normalize();
}

void TorusDrawerService::glTorusTexCoord(float out_angle, float int_angle, int tx)
{
	glTexCoord2f(out_angle / PI, (int_angle) / PI);
}

void TorusDrawerService::drawTorus(GLfloat out_radius, GLfloat int_radius, GLint textureId)
{
	//angular step in degree
	float angle_step = 5;
	//torus out. angle 
	float out_angle = 0;
	//increasing value for out. angle (in radiants)
	float delta_out_angle = (angle_step / 180.f) * PI;

	//torus int. angle
	float int_angle = 0;
	//increasing value for int. angle (in radiants)
	float delta_int_angle = (angle_step / 180.f) * PI;

	glEnable(GL_TEXTURE_2D);
	glShadeModel(GL_SMOOTH);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

	glBindTexture(GL_TEXTURE_2D, textureId);

	/*Rotation angle around the center of the tube section*/
	for (int_angle = 0; int_angle <= 2 * PI; int_angle += delta_int_angle) {

		glBegin(GL_TRIANGLE_STRIP);
		/*Rotation angle around the center of the torus*/
		for (out_angle = 0; out_angle <= 2 * PI; out_angle += delta_out_angle) {

			/*Point for (int_angle+delta_int_angle) angle*/
			Vector3 point_up = getPoint(out_angle,
				int_angle + delta_int_angle,
				out_radius,
				int_radius);
			/*Get the normal*/
			Vector3 normal_up = getPointNormal(out_angle,
				int_angle + delta_int_angle,
				out_radius,
				int_radius);
			/*Set the normal*/
			glNormal3f(normal_up.x,
				normal_up.y,
				normal_up.z);

			/*Set texture coordinates*/
			glTorusTexCoord(out_angle,
				int_angle + delta_int_angle,
				textureId);

			/*Set the vertex*/
			glVertex3f(point_up.x,
				point_up.y,
				point_up.z);


			/*Point for int_angle angle*/
			Vector3 point_down = getPoint(out_angle,
				int_angle,
				out_radius,
				int_radius);
			/*Get the normal*/
			Vector3 normal_down = getPointNormal(out_angle,
				int_angle,
				out_radius,
				int_radius);
			/*Set the normal*/
			glNormal3f(normal_down.x,
				normal_down.y,
				normal_down.z);

			/*Set texture coordinates*/
			glTorusTexCoord(out_angle,
				int_angle,
				textureId);

			/*Set the vertex*/
			glVertex3f(point_down.x,
				point_down.y,
				point_down.z);


		}

		glEnd();
	}

	glDisable(GL_TEXTURE_2D);
}

void TorusDrawerService::loadTexture(const char* filename, GLuint& textureID)
{
	GLint width, height, nrChannels;
	unsigned char* data = stbi_load(filename, &width, &height, &nrChannels, 0);

	glGenTextures(0, &textureID);
	glBindTexture(GL_TEXTURE_2D, textureID);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	if (data)
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
	else
		std::cout << "Failed to load texture" << std::endl;

	stbi_image_free(data);
}
