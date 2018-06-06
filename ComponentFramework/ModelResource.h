#pragma once
#include "BaseResourceManager.h"
#include "Model.h"

class ModelResource :
	public BaseResource
{
public:
	ModelResource(std::string name, GAME::Model* model);
	~ModelResource();

	GAME::Model* model;
};

