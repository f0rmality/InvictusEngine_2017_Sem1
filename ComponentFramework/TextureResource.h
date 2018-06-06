#pragma once
#include "BaseResourceManager.h"
#include "Texture.h"

class TextureResource :
	public BaseResource
{
public:
	TextureResource(std::string name, GAME::Texture* texture);
	~TextureResource();

	GAME::Texture* texture;
};

