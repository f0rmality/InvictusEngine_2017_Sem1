#pragma once
#include <string>
#include "MMath.h"
#include <SDL_image.h>
#include <SDL_opengl.h>

namespace GAME {

	class Texture
	{
	public:
		Texture();
		Texture(std::string filename);
		~Texture();

		bool OnCreate();

		std::string name;

		int getWidth();
		int getHeight();
		int getImageFormat();
		std::string getName();
		
		int height, width, imageFormat;
		SDL_Surface* texturedSurface;

		GLuint texture0;
		GLuint texture0ID;

	};
}

