#ifndef BASERESOURCEMANAGER_H
#define BASERESOURCEMANAGER_H

#include "BasicTypes.h"
#include <string>
#include <vector>
#include <map>
#include <memory>
#include <thread>
#include <iterator>
#include <iostream>

class BaseResource
{
public:
	BaseResource(std::string path, ResourceType type);
	virtual ~BaseResource();

	virtual bool Init();
	virtual bool Shutdown();
	virtual std::string GetResourcePath();
	virtual std::string GetResourceName();

	virtual int GetID() {
		return id;
	}

	virtual bool GetHasInit() {
		return hasInit;
	}

	virtual bool GetHasShutdown() {
		return hasShutdown;
	}

	virtual ResourceType GetResourceType();

protected:
	std::string resourcePath;
	std::string resourceName;
	int id;
	bool hasInit;
	bool hasShutdown;
	ResourceType resourceType;

	static int idCounter;

};

class BaseResourceManager {

private:
	std::map<std::string, class BaseResource*> resourceMap;
	static std::unique_ptr<BaseResourceManager> instance;
	
protected:
	BaseResourceManager();

public:
	~BaseResourceManager();

	bool Init();
	void Update();
	bool Shutdown();
	virtual void AddResource(std::string name, BaseResource* resource);
	BaseResource* GetResource(std::string name);
	virtual ResourceType GetResource(BaseResource handle);
	void RemoveResource(std::string name);
	static BaseResourceManager* GetInstance();

};

#endif