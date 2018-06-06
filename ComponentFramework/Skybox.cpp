#include "Skybox.h"
#include <GL/glew.h>

using namespace GAME;

Skybox::Skybox()
{
	size = -1;
	for (int i = 0; i < 6; i++)
		sides[i] = -1;
}

Skybox::Skybox(unsigned int left, unsigned int back, unsigned int right, unsigned int front, unsigned int top, unsigned int bottom, float s) {
	sides[0] = left;
	sides[1] = back;
	sides[2] = right;
	sides[3] = front;
	sides[4] = top;
	sides[5] = bottom;

	size = s;
}


Skybox::~Skybox()
{
	glDeleteTextures(6, &sides[0]);
}

void Skybox::drawSkybox() {

	glEnable(GL_TEXTURE_2D);
	glColor3f(1.0, 1.0, 1.0);

	glBindTexture(GL_TEXTURE_2D, sides[0]);

	glBegin(GL_QUADS);
	glNormal3f(0.0, 0.0, -1.0);
	glTexCoord2f(0.0, 0.0); glVertex3f(-size, size, size);
	glTexCoord2f(1.0, 0.0); glVertex3f(size, size, size);
	glTexCoord2f(1.0, 1.0); glVertex3f(size, -size, size);
	glTexCoord2f(0.0, 1.0); glVertex3f(-size, -size, size);
	glEnd();

	glEnable(GL_TEXTURE_2D);
	glColor3f(1.0, 1.0, 1.0);

	glBindTexture(GL_TEXTURE_2D, sides[1]);

	glBegin(GL_QUADS);
	glNormal3f(0.0, 0.0, -1.0);
	glTexCoord2f(0.0, 0.0); glVertex3f(-size, size, size);
	glTexCoord2f(1.0, 0.0); glVertex3f(size, size, size);
	glTexCoord2f(1.0, 1.0); glVertex3f(size, -size, size);
	glTexCoord2f(0.0, 1.0); glVertex3f(-size, -size, size);
	glEnd();

	glEnable(GL_TEXTURE_2D);
	glColor3f(1.0, 1.0, 1.0);

	glBindTexture(GL_TEXTURE_2D, sides[2]);

	glBegin(GL_QUADS);
	glNormal3f(0.0, 0.0, -1.0);
	glTexCoord2f(0.0, 0.0); glVertex3f(-size, size, size);
	glTexCoord2f(1.0, 0.0); glVertex3f(size, size, size);
	glTexCoord2f(1.0, 1.0); glVertex3f(size, -size, size);
	glTexCoord2f(0.0, 1.0); glVertex3f(-size, -size, size);
	glEnd();

	glEnable(GL_TEXTURE_2D);
	glColor3f(1.0, 1.0, 1.0);

	glBindTexture(GL_TEXTURE_2D, sides[3]);

	glBegin(GL_QUADS);
	glNormal3f(0.0, 0.0, -1.0);
	glTexCoord2f(0.0, 0.0); glVertex3f(-size, size, size);
	glTexCoord2f(1.0, 0.0); glVertex3f(size, size, size);
	glTexCoord2f(1.0, 1.0); glVertex3f(size, -size, size);
	glTexCoord2f(0.0, 1.0); glVertex3f(-size, -size, size);
	glEnd();

	glEnable(GL_TEXTURE_2D);
	glColor3f(1.0, 1.0, 1.0);

	glBindTexture(GL_TEXTURE_2D, sides[4]);

	glBegin(GL_QUADS);
	glNormal3f(0.0, 0.0, -1.0);
	glTexCoord2f(0.0, 0.0); glVertex3f(-size, size, size);
	glTexCoord2f(1.0, 0.0); glVertex3f(size, size, size);
	glTexCoord2f(1.0, 1.0); glVertex3f(size, -size, size);
	glTexCoord2f(0.0, 1.0); glVertex3f(-size, -size, size);
	glEnd();

	glEnable(GL_TEXTURE_2D);
	glColor3f(1.0, 1.0, 1.0);

	glBindTexture(GL_TEXTURE_2D, sides[5]);

	glBegin(GL_QUADS);
	glNormal3f(0.0, 0.0, -1.0);
	glTexCoord2f(0.0, 0.0); glVertex3f(-size, size, size);
	glTexCoord2f(1.0, 0.0); glVertex3f(size, size, size);
	glTexCoord2f(1.0, 1.0); glVertex3f(size, -size, size);
	glTexCoord2f(0.0, 1.0); glVertex3f(-size, -size, size);
	glEnd();
}
