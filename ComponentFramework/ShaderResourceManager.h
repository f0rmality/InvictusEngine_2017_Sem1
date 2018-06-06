#pragma once
#include "BaseResourceManager.h"

class ShaderResourceManager :
	public BaseResourceManager
{
private:
	ShaderResourceManager();
	std::map<std::string, class ShaderResource*> resourceMap;
	static std::unique_ptr<ShaderResourceManager> instance;

public:
	~ShaderResourceManager();

	void AddResource(std::string name, ShaderResource* resource);
	ShaderResource* GetResource(std::string name);
	ResourceType GetResource(ShaderResource handle);
	static ShaderResourceManager* GetInstance();

};
