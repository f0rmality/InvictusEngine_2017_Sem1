#include "Texture.h"
#include <SDL_image.h>
#include <SDL_opengl.h>

using namespace GAME;
using namespace MATH;

Texture::Texture() {

}

Texture::Texture(std::string filename)
{
	name = filename;
	OnCreate();
}


Texture::~Texture()
{
}

bool Texture::OnCreate() {
	
	texturedSurface = IMG_Load(name.c_str());

	if (texturedSurface == nullptr)
		return false;

	imageFormat = (texturedSurface->format->BytesPerPixel == 4) ? GL_RGBA : GL_RGB;

	glGenTextures(1, &texture0ID);
	glBindTexture(GL_TEXTURE_2D, texture0ID);
	glTexImage2D(GL_TEXTURE_2D, 0, imageFormat, texturedSurface->w, texturedSurface->h, 0, imageFormat, GL_UNSIGNED_BYTE, texturedSurface->pixels);

	SDL_FreeSurface(texturedSurface);

	/// Wrapping and filtering options
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
}

int Texture::getImageFormat() {
	if (imageFormat)
		return imageFormat;

	else
		return 0;
}

int Texture::getHeight() {
	if (texturedSurface)
		return texturedSurface->h;
	else
		return 0;
}


int Texture::getWidth() {
	if (texturedSurface)
		return texturedSurface->w;
	else
		return 0;
}

std::string Texture::getName() {
	if (texturedSurface)
		return name;
	else
		return 0;
}


