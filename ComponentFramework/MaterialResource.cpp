#include "MaterialResource.h"
#include "Material.h"
#include <string>
#include "BasicTypes.h"

using namespace GAME;


MaterialResource::MaterialResource(std::string name_, Material* material_) : BaseResource(name_, ResourceType::RESOURCE_MATERIAL), material(material_)
{

}


MaterialResource::~MaterialResource()
{
}
