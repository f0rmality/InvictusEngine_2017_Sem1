#pragma once
#include <string>
#include "MMath.h"

class ShaderResource;
class TextureResource;

namespace GAME {

	using namespace MATH;

	class Material
	{
	public:
		Material(Vec4 Color_);
		Material(ShaderResource* shader_); // make one to take in just a color ?
		Material(class Shader* shader_, class Texture* diffuseTexture_);
		Material(ShaderResource* shader_, TextureResource* diffuseTexture_);
		~Material();

		std::string shaderName;
		std::string textureName;
		std::string materialName;

		//textures
		Texture* diffuseTexture;
		Texture* normalTexture;
		Texture* alphaTexture;
		Texture* emmissiveTexture;
		Texture* specularTexture;

		Vec4 Color;
		Shader* shader;
	};
}

