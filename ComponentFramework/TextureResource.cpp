#include "TextureResource.h"
#include <string>
#include "BasicTypes.h"

using namespace GAME;

TextureResource::TextureResource(std::string name_, Texture* texture_) : BaseResource(name_, ResourceType::RESOURCE_TEXTURE), texture(texture_)
{
}


TextureResource::~TextureResource()
{
}
