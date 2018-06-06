#include "BaseResourceManager.h"
#include "ModelResourceManager.h"
#include "ModelResource.h"


std::unique_ptr<ModelResourceManager> ModelResourceManager::instance(nullptr);

ModelResourceManager::ModelResourceManager(){

}

ModelResourceManager::~ModelResourceManager() {

}

ModelResourceManager* ModelResourceManager::GetInstance() {
	if (instance.get() == nullptr)
		instance.reset(new ModelResourceManager());

	return instance.get();
}

void ModelResourceManager::AddResource(std::string name, ModelResource* resource) {
	if (!resource)
		return;

	if (!resource->GetHasInit())
		resource->Init();

	resourceMap.insert({ name, resource });
}

ModelResource* ModelResourceManager::GetResource(std::string name) {
	for (auto iter : this->resourceMap) {
		if (iter.first == name)
			return iter.second;

		//else throw an exception
	}
}

ResourceType ModelResourceManager::GetResource(ModelResource handle) {

	for (auto iter : this->resourceMap) {
		if (iter.second == &handle)
			return iter.second->GetResourceType();

		//else throw exception
	}
}