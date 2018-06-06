#include "ShaderResource.h"
#include <string>
#include "BasicTypes.h"

using namespace GAME;

ShaderResource::ShaderResource(std::string name_, Shader* shader_) : BaseResource(name_, ResourceType::RESOURCE_SHADER), shader(shader_)
{
}


ShaderResource::~ShaderResource()
{
}
