#ifndef MODEL_H
#define MODEL_H
#include <vector>
#include "MMath.h"
#include "Mesh.h"
#include "Entity.h"

namespace GAME {

using namespace MATH;

class Model : public Entity {

protected:

	class Shader *shader;
	class Texture *texture;
	class Material *material;

	Matrix4 modelMatrix;
	std::vector<Mesh*> meshes;

public:

	Model(const Vec3 _pos, const Vec3 _orientation);
	Model(const Model&) = delete;
	Model(Model&&) = delete;
	Model& operator = (const Model&) = delete;
	Model& operator = (Model&&) = delete;

	virtual ~Model();
	virtual bool OnCreate();
	virtual bool OnCreate(Shader* shader_, Texture* texture_);
	virtual bool OnCreate(Material* material);
	virtual void OnDestroy();
	virtual void Render() const override;
	virtual void Update(const float deltaTime) override;

	virtual bool LoadMesh(const char* filename);
	virtual bool CreateMesh(Vertices vs);
};
} /// end of namespace

#endif