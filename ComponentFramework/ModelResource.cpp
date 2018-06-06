#include "ModelResource.h"
#include <string>
#include "BasicTypes.h"

using namespace GAME;

ModelResource::ModelResource(std::string name_, Model* model_) : BaseResource(name_, ResourceType::RESOURCE_MESH), model(model_)
{
	
}


ModelResource::~ModelResource()
{

}
