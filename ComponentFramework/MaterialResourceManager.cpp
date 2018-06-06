#include "BaseResourceManager.h"
#include "MaterialResourceManager.h"
#include "MaterialResource.h"


std::unique_ptr<MaterialResourceManager> MaterialResourceManager::instance(nullptr);

MaterialResourceManager::MaterialResourceManager() {

}

MaterialResourceManager::~MaterialResourceManager() {

}

MaterialResourceManager* MaterialResourceManager::GetInstance() {
	if (instance.get() == nullptr)
		instance.reset(new MaterialResourceManager());

	return instance.get();
}

void MaterialResourceManager::AddResource(std::string name, MaterialResource* resource) {
	if (!resource)
		return;

	if (!resource->GetHasInit())
		resource->Init();

	resourceMap.insert({ name, resource });
}

MaterialResource* MaterialResourceManager::GetResource(std::string name) {
	for (auto iter : this->resourceMap) {
		if (iter.first == name)
			return iter.second;

		//else throw an exception
	}
}

ResourceType MaterialResourceManager::GetResource(MaterialResource handle) {

	for (auto iter : this->resourceMap) {
		if (iter.second == &handle)
			return iter.second->GetResourceType();

		//else throw exception
	}
}
