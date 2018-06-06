#include "Model.h"
#include "Shader.h"
#include "Texture.h"
#include "Material.h"
#include "ObjLoader.h"
#include "Camera.h"
#include "SceneEnvironment.h"

namespace GAME {

	Model::Model(const Vec3 pos_, const Vec3 orientation_) : Entity()
	{
		pos = pos_;
		orientation = orientation_;
		shader = nullptr;
	}

	Model::~Model() {
		OnDestroy();
	}

	bool Model::OnCreate() {
		return true;
	}

	bool Model::OnCreate(Shader* shader_, Texture* texture_) {
		shader = shader_;
		texture = texture_;
		return true;
	}

	bool Model::OnCreate(Material* material_) {
		material = material_;
		
		if(material->shader)
			shader = material->shader;

		if(material->diffuseTexture)
			texture = material->diffuseTexture;

		return true;
	}

	

	bool Model::LoadMesh(const char* filename) {
		if (ObjLoader::loadOBJ(filename) == false) {
			return false;
		}
		/// Get the data out of the ObjLoader and into our own mesh
		std::vector<Vec4> colors;
		//colors.push_back(Vec4(0.0f, 0.0f, 1.0f, 1.0f));
		
		if (material->Color) {
			colors.push_back(material->Color);

			Vertices vs(ObjLoader::vertices, ObjLoader::normals, ObjLoader::uvCoords, colors);
			meshes.push_back(new Mesh(GL_TRIANGLES, vs));
		}

		else {
			Vertices vs(ObjLoader::vertices, ObjLoader::normals, ObjLoader::uvCoords);
			meshes.push_back(new Mesh(GL_TRIANGLES, vs));
		}

		return true;
	}

	bool Model::CreateMesh(Vertices vs) {
		meshes.push_back(new Mesh(GL_TRIANGLES, vs));
		return true;
	}

	void Model::Update(const float deltaTime) {
		Entity::Update(deltaTime);
	}

	void Model::Render() const {


		if(texture)
			GLint textureID = glGetUniformLocation(shader->getProgram(), "myTexture0");

		GLint projectionMatrixID = glGetUniformLocation(shader->getProgram(), "projectionMatrix");
		GLint viewMatrixID = glGetUniformLocation(shader->getProgram(), "viewMatrix");
		GLint modelMatrixID = glGetUniformLocation(shader->getProgram(), "modelMatrix");
		GLint normalMatrixID = glGetUniformLocation(shader->getProgram(), "normalMatrix");
		GLint lightPosID = glGetUniformLocation(shader->getProgram(), "lightPos");

		glUseProgram(shader->getProgram());

		if(texture)
			glBindTexture(GL_TEXTURE_2D, texture->texture0ID);

		glUniformMatrix4fv(projectionMatrixID, 1, GL_FALSE, Camera::currentCamera->getProjectionMatrix());
		glUniformMatrix4fv(viewMatrixID, 1, GL_FALSE, Camera::currentCamera->getViewMatrix());
		glUniformMatrix4fv(modelMatrixID, 1, GL_FALSE, GetModelMatrix());

		/// Assigning the 4x4 modelMatrix to the 3x3 normalMatrix 
		/// copies just the upper 3x3 of the modelMatrix
		Matrix3 normalMatrix = GetModelMatrix(); 
		glUniformMatrix3fv(normalMatrixID, 1, GL_FALSE, normalMatrix);

		glUniform3fv(lightPosID, 1, SceneEnvironment::getInstance()->getLight());

		for (Mesh* mesh : meshes) {
			mesh->Render();
		}

		Entity::Render();
	}
	void Model::OnDestroy() {
		if (shader) delete shader;

		for (Mesh* mesh : meshes) {
			if (mesh) delete mesh;
		}
	}
}