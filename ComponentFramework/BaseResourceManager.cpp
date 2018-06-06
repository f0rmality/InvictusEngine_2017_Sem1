#include "BaseResourceManager.h"
#include "Mesh.h"

int BaseResource::idCounter = 0;

BaseResource::BaseResource(std::string path, ResourceType type)
{
	resourceType = type;
	resourcePath = path;
	id = ++idCounter;
	hasInit = true;
	hasShutdown = false;
}

BaseResource::~BaseResource() {

}

bool BaseResource::Init() {
	hasInit = true;
	return hasInit;
}

bool BaseResource::Shutdown() {
	hasShutdown = true;
	return hasShutdown;
}

std::string BaseResource::GetResourcePath() {
	return this->resourcePath;
}

std::string BaseResource::GetResourceName() {
	return this->resourceName;
}

ResourceType BaseResource::GetResourceType() {
	return this->resourceType;
}

std::unique_ptr<BaseResourceManager> BaseResourceManager::instance(nullptr);

BaseResourceManager::BaseResourceManager() {

}

BaseResourceManager::~BaseResourceManager() {

}

BaseResourceManager* BaseResourceManager::GetInstance() {
	if (instance.get() == nullptr)
		instance.reset(new BaseResourceManager());

	return instance.get();
}

bool BaseResourceManager::Init() {
	return true;
}

bool BaseResourceManager::Shutdown() {
	for (auto iter : this->resourceMap)
	{
		if (!iter.second->Shutdown())
			return false;

		iter.second = NULL;
	}

	resourceMap.clear();

	return true;
}

void BaseResourceManager::Update() {

}

void BaseResourceManager::AddResource(std::string name, BaseResource* resource) {
	if (!resource)
		return;

	if (!resource->GetHasInit())
		resource->Init();

	resourceMap.insert({ name, resource });
}

BaseResource* BaseResourceManager::GetResource(std::string name) {
	for (auto iter : this->resourceMap) {
		if (iter.first == name)
			return iter.second;

		//else throw an exception
	}
}

ResourceType BaseResourceManager::GetResource(BaseResource handle) {

	for (auto iter : this->resourceMap) {
		if (iter.second == &handle)
			return iter.second->GetResourceType();

		//else throw exception
	}
}

void BaseResourceManager::RemoveResource(std::string name) {
	for (auto iter : this->resourceMap) {
		if (iter.first == name) {
			iter.second = NULL;
			resourceMap.erase(iter.first);
		}

		//else throw exception
	}
}