
#ifndef _ENTITY_H
#define _ENTITY_H

#include "VMath.h"
#include <vector>
#include "MMath.h"
#include "Matrix.h"

namespace GAME {

	using namespace MATH;

	class Entity {

	protected:

		Vec3 pos;
		Vec3 orientation;
		Vec3 scale;

		//holds all children of parent
		std::vector<Entity*> children;
		Entity* parentNode;

		Matrix4 worldMatrix;
		Matrix4 localMatrix;

	public:

		Entity();
		virtual ~Entity();

		virtual void setPos(const Vec3& pos_) { pos = pos_; for (Entity* child : children) child->setPos(pos_); }
		virtual void setOrientation(const Vec3& orientation_) { orientation = orientation_;  for (Entity* child : children) child->setOrientation(orientation_);}
		virtual void setScale(const Vec3& scaling_) { scale = scaling_; for (Entity* child : children) child->setScale(scaling_);  }

		virtual void Translate(const Vec3& vec) { setPos(pos + vec); }
		virtual void Scale(const Vec3& vec) { setScale(scale + vec); }
		virtual void Rotate(const Vec3& vec) { setOrientation(orientation + vec); }

		//updates, renders children
		virtual void Update(const float deltaTime);
		virtual void Render() const { for (Entity* child : children) child->Render(); }

		//add object to graph
		void AddObject(Entity* obj);


		Matrix4 GetModelMatrix() const;
		void updateModelMatrix();

	};
}

#endif