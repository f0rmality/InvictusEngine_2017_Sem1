#include "Entity.h"
#include "VMath.h"
#include <vector>
#include "MMath.h"
#include "Matrix.h"

using namespace GAME;
using namespace MATH;

Entity::Entity() : worldMatrix(), localMatrix()
{
	scale = Vec3(1.0f, 1.0f, 1.0f);
}

Entity::~Entity() {

	for(auto x : children)
	{
		delete x;
	}

	children.clear();
}

void Entity::Update(const float deltaTime) {
	updateModelMatrix();

	if (parentNode)
		worldMatrix = parentNode->GetModelMatrix();

	for (Entity* child : children) {
		child->Update(deltaTime);
	}
}

Matrix4 Entity::GetModelMatrix() const {

	return worldMatrix * localMatrix;
	
}

void Entity::AddObject(Entity* obj) {
	obj->parentNode = this;
	obj->worldMatrix = this->GetModelMatrix();
	children.push_back(obj);
}

void Entity::updateModelMatrix() {
	localMatrix = MMath::scale(scale) * MMath::translate(pos) *
		MMath::rotate(orientation.z, Vec3(0.0f, 0.0f, 1.0f)) *
		MMath::rotate(orientation.x, Vec3(1.0f, 0.0f, 0.0f)) *
		MMath::rotate(orientation.y, Vec3(0.0f, 1.0f, 0.0f));
};