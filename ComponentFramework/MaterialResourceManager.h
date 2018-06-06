#pragma once
#include "BaseResourceManager.h"
#include <string>

class MaterialResourceManager :
	public BaseResourceManager
{
private:
	MaterialResourceManager();
	std::map<std::string, class MaterialResource*> resourceMap;
	static std::unique_ptr<MaterialResourceManager> instance;

public:
	~MaterialResourceManager();

	void AddResource(std::string name, MaterialResource* resource);
	MaterialResource* GetResource(std::string name);
	ResourceType GetResource(MaterialResource handle);
	static MaterialResourceManager* GetInstance();

};

