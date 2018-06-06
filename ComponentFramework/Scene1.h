#ifndef Scene1_H
#define Scene1_H

#include "Scene.h"
#include "Model.h"
#include "Camera.h"

namespace GAME {
	class Window; /// Forward declaration

	class Scene1 : public Scene  {
	protected:

		void addObject(Entity* object);
		Entity* createModel(const char* filename, const char* materialName = nullptr);
		
	public:
		explicit Scene1(Window& windowRef);
		virtual ~Scene1();

		//static class MatrixStack* matrices;

		/// Delete these possible default constructors and operators  
		Scene1(const Scene1&) = delete;
		Scene1(Scene1 &&) = delete;
		Scene1& operator=(const Scene1 &) = delete;
		Scene1& operator=(Scene1 &&) = delete;

		virtual bool OnCreate() ;
		virtual void OnDestroy();
		virtual void Update(const float deltaTime);
		virtual void Render() const;
		virtual void HandleEvents(const SDL_Event &SDLEvent);
		virtual void OnResize(const int, const int);
	
	private:
		std::vector<Model*> models;
		
		//vector to hold all parent nodes
		std::vector<Entity*> objects;
		Camera* camera;
		class Skybox* skybox;

		//managers
		class BaseResourceManager* manager;
		class ModelResourceManager* modelManager;
		class ShaderResourceManager* shaderManager;
		class TextureResourceManager* textureManager;
		class MaterialResourceManager* materialManager;

		class Entity* earth;
		Entity* moon;
		Entity* moonHolder;

		std::string defaultShaderName;
		std::string defaultMaterialName;
	};
}
#endif