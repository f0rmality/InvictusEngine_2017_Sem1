#pragma once
#include "BaseResourceManager.h"
#include "Material.h"

class MaterialResource :
	public BaseResource
{
public:
	MaterialResource(std::string name, GAME::Material* material);
	~MaterialResource();

	GAME::Material* material;
};

