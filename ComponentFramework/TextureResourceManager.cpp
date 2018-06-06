#include "BaseResourceManager.h"
#include "TextureResourceManager.h"
#include "TextureResource.h"


std::unique_ptr<TextureResourceManager> TextureResourceManager::instance(nullptr);

TextureResourceManager::TextureResourceManager() {

}

TextureResourceManager::~TextureResourceManager() {

}

TextureResourceManager* TextureResourceManager::GetInstance() {
	if (instance.get() == nullptr)
		instance.reset(new TextureResourceManager());

	return instance.get();
}

void TextureResourceManager::AddResource(std::string name, TextureResource* resource) {
	if (!resource)
		return;

	if (!resource->GetHasInit())
		resource->Init();

	resourceMap.insert({ name, resource });
}

TextureResource* TextureResourceManager::GetResource(std::string name) {
	for (auto iter : this->resourceMap) {
		if (iter.first == name)
			return iter.second;

		//else throw an exception
	}
}

ResourceType TextureResourceManager::GetResource(TextureResource handle) {

	for (auto iter : this->resourceMap) {
		if (iter.second == &handle)
			return iter.second->GetResourceType();

		//else throw exception
	}
}

unsigned int TextureResourceManager::loadTexture(const char* filename)
{
	unsigned int num;
	glGenTextures(1, &num);
	SDL_Surface* img = SDL_LoadBMP(filename);
	glBindTexture(GL_TEXTURE_2D, num);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->w, img->h, 0, GL_RGB, GL_UNSIGNED_SHORT_5_6_5, img->pixels);
	SDL_FreeSurface(img);
	return num;
}
