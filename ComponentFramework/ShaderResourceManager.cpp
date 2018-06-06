#include "BaseResourceManager.h"
#include "ShaderResourceManager.h"
#include "ShaderResource.h"


std::unique_ptr<ShaderResourceManager> ShaderResourceManager::instance(nullptr);

ShaderResourceManager::ShaderResourceManager() {

}

ShaderResourceManager::~ShaderResourceManager() {

}

ShaderResourceManager* ShaderResourceManager::GetInstance() {
	if (instance.get() == nullptr)
		instance.reset(new ShaderResourceManager());

	return instance.get();
}

void ShaderResourceManager::AddResource(std::string name, ShaderResource* resource) {
	if (!resource)
		return;

	if (!resource->GetHasInit())
		resource->Init();

	resourceMap.insert({ name, resource });
}

ShaderResource* ShaderResourceManager::GetResource(std::string name) {
	for (auto iter : this->resourceMap) {
		if (iter.first == name)
			return iter.second;

		//else throw an exception
	}
}

ResourceType ShaderResourceManager::GetResource(ShaderResource handle) {

	for (auto iter : this->resourceMap) {
		if (iter.second == &handle)
			return iter.second->GetResourceType();

		//else throw exception
	}
}