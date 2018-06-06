#pragma once
#include "BaseResourceManager.h"

class ModelResourceManager :
	public BaseResourceManager
{
private:
	ModelResourceManager();
	std::map<std::string, class ModelResource*> resourceMap;
	static std::unique_ptr<ModelResourceManager> instance;

public:
	~ModelResourceManager();

	void AddResource(std::string name, ModelResource* resource);
	ModelResource* GetResource(std::string name);
	ResourceType GetResource(ModelResource handle);
	static ModelResourceManager* GetInstance();

};

