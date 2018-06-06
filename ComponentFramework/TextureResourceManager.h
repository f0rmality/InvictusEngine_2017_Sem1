#pragma once
#include "BaseResourceManager.h"

class TextureResourceManager :
	public BaseResourceManager
{
private:
	TextureResourceManager();
	std::map<std::string, class TextureResource*> resourceMap;
	static std::unique_ptr<TextureResourceManager> instance;

public:
	~TextureResourceManager();

	void AddResource(std::string name, TextureResource* resource);
	TextureResource* GetResource(std::string name);
	ResourceType GetResource(TextureResource handle);
	static TextureResourceManager* GetInstance();


	//helper function
	unsigned int loadTexture(const char* filename);
};

