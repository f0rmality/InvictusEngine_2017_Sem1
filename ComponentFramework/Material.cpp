#include "Material.h"
#include <GL/glew.h>
#include "ShaderResource.h"
#include "TextureResource.h"

using namespace GAME;
using namespace MATH;

Material::Material(Vec4 Color_) {
	//if no shader, apply phong, take in a color here?
	Color = Color_;
	
	if (!shader)
		shader = new Shader("phongVert.glsl", "phongFrag.glsl", 3, 0, "vVertex", 1, "vNormal", 2, "vColor");

}

Material::Material(ShaderResource* shader_)
{
	shader = shader_->shader;
	//add a color or something?
}

Material::Material(Shader* shader_, Texture* diffuseTexture_) {
	shader = shader_;
	diffuseTexture = diffuseTexture_;

	shaderName = "defaultShader";
	textureName = "defaultShader";
}

Material::Material(ShaderResource* shader_, TextureResource* texture_) {
	shader = shader_->shader;
	shaderName = shader_->GetResourceName();

	diffuseTexture = texture_->texture;
	textureName = texture_->GetResourceName();
}

//constructor to take in shader and color?

Material::~Material()
{
}
