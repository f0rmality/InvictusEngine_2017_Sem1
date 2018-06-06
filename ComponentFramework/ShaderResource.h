#pragma once
#include "BaseResourceManager.h"
#include "Shader.h"

class ShaderResource :
	public BaseResource
{
public:
	ShaderResource(std::string name, GAME::Shader* shader);
	~ShaderResource();

	GAME::Shader* shader;
};

