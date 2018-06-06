#include <GL/glew.h>
#include <SDL.h>
#include <iostream>
#include "BaseResourceManager.h"
#include "ModelResourceManager.h"
#include "ShaderResourceManager.h"
#include "TextureResourceManager.h"
#include "MaterialResourceManager.h"
#include "MaterialResource.h"
#include "ModelResource.h"
#include "ShaderResource.h"
#include "TextureResource.h"
#include "MMath.h"
#include "Matrix.h"
#include "MatrixStack.h"
#include "Window.h"
#include "Scene1.h"
#include "SceneEnvironment.h"
#include "Shader.h"
#include "Skybox.h"
#include "Entity.h"
#include "ObjLoader.h"

using namespace GAME;
using namespace MATH;


Scene1::Scene1(Window& windowRef):Scene(windowRef) {

	//get managers
	manager = BaseResourceManager::GetInstance();
	modelManager = ModelResourceManager::GetInstance();
	shaderManager = ShaderResourceManager::GetInstance();
	textureManager = TextureResourceManager::GetInstance();
	materialManager = MaterialResourceManager::GetInstance();
}


bool Scene1::OnCreate() {
	
	camera = nullptr;
	skybox = nullptr;

	defaultShaderName = "defaultShader";
	defaultMaterialName = "defaultMaterial";
	OnResize(windowPtr->GetWidth(),windowPtr->GetHeight());

	//add a texture shader to the manager
	shaderManager->AddResource(defaultShaderName, new ShaderResource(defaultShaderName,
		new Shader("textureVert.glsl", "textureFrag.glsl", 3, 0, "vVertex", 1, "vNormal", 2, "texCoords")));

	//add a phong shader
	shaderManager->AddResource("phongShader", new ShaderResource("phongShader", 
		new Shader("phongVert.glsl", "phongFrag.glsl", 3, 0, "vVertex", 1, "vNormal", 2, "texCoords", 3, "vColor")));

	//add a texture to the manager
	textureManager->AddResource("moon.jpg", new TextureResource("moon.jpg", new Texture("moon.jpg")));
	textureManager->AddResource("earthclouds.jpeg", new TextureResource("earthclouds.jpeg", new Texture("earthclouds.jpeg")));

	//add texture material to the manager
	materialManager->AddResource("moonMaterial", new MaterialResource("moonMaterial", 
		new Material(shaderManager->GetResource(defaultShaderName), textureManager->GetResource("moon.jpg"))));

	materialManager->AddResource("earthMaterial", new MaterialResource("earthMaterial",
		new Material(shaderManager->GetResource(defaultShaderName), textureManager->GetResource("earthclouds.jpeg"))));

	materialManager->AddResource("coloredMaterial", new MaterialResource("coloredMaterial", 
		new Material(Vec4(0.0f, 1.0f, 1.0f, 1.0f))));

	//SKYBOX INITIALIZATION

	skybox = new Skybox(textureManager->loadTexture("left.bmp"), textureManager->loadTexture("back.bmp"), textureManager->loadTexture("right.bmp"),
		textureManager->loadTexture("front.bmp"), textureManager->loadTexture("top.bmp"), textureManager->loadTexture("bottom.bmp"), 100.0f);
	
	//create parent "sun" and add a child to it
	moon = createModel("sphereTwo.obj", "moonMaterial");
	earth = createModel("sphere.obj", "earthMaterial");
	earth->AddObject(moon);
	
	//to show just child moving
	earth->setOrientation(Vec3(180.0f, 0.0f, 0.0f));
	moon->setPos(Vec3(15.0f, 0.0f, 0.0f));
	moon->setScale(Vec3(0.25f));
	
	
	//uncomment to show parent moving the child with it
	//sun->setPos(Vec3(2.0f, 2.0f, 2.0f));

	//add parents to scene graph
	addObject(earth);

	/// set lighting
	SceneEnvironment::getInstance()->setLight(Vec3(0.0f, 3.0f, 7.0f));

	return true;
}

Entity* GAME::Scene1::createModel(const char* filename, const char* materialName) {

	modelManager->AddResource(filename, new ModelResource(filename, new Model(Vec3(0.0f, 0.0f, 0.0f), Vec3(0.0f, 0.0f, 0.0f))));

	//check for material
	if(materialName)
		modelManager->GetResource(filename)->model->OnCreate(materialManager->GetResource(materialName)->material);
	if (!materialName)
		modelManager->GetResource(filename)->model->OnCreate();

	modelManager->GetResource(filename)->model->LoadMesh(filename);

	//return entity
	return modelManager->GetResource(filename)->model;
}

void GAME::Scene1::addObject(Entity* obj) {
	objects.push_back(obj);
}

void Scene1::OnResize(int w_, int h_){
	windowPtr->SetWindowSize(w_,h_);
	glViewport(0,0,windowPtr->GetWidth(),windowPtr->GetHeight());
	if (camera) delete camera;
	camera = new Camera(w_, h_, Vec3(0.0f, 0.0f, 10.0f));
	Camera::currentCamera = camera;
}

void Scene1::Update(const float deltaTime) {

	earth->Rotate(Vec3(0.0f, -1.0f, 0.0f));
	moon->Rotate(Vec3(0.0f, 1.0f, 0.0f));

	for (Entity* obj : objects) {
		obj->Update(deltaTime);
		//obj->Rotate(Vec3(0.0f, 1.0f, 0.0f));
	}

	//CAMERA MOVEMENT
//	if (camera)
	//	camera->Translate(Vec3(0.1f, 0.1f, 0.0f));
}

void Scene1::Render() const{

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

	if (skybox)
		skybox->drawSkybox();

	/// Draw your scene here
	for (Entity* obj : objects) {
		obj->Render();
	}


	SDL_GL_SwapWindow(windowPtr->getSDLWindow());
	
}

void Scene1::HandleEvents(const SDL_Event& SDLEvent){
	if(SDLEvent.type == SDL_EventType::SDL_MOUSEBUTTONDOWN){
		
	}
	if (SDLEvent.type == SDL_EventType::SDL_MOUSEMOTION && 
		SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_LEFT)) {
		
	}

	if (SDLEvent.type == SDL_EventType::SDL_KEYDOWN && SDLEvent.key.keysym.sym == SDLK_LEFT) {
		camera->Translate(Vec3(-1.0f, 0.0f, 0.0f));
	}

	if (SDLEvent.type == SDL_EventType::SDL_KEYDOWN && SDLEvent.key.keysym.sym == SDLK_RIGHT) {
		camera->Translate(Vec3(1.0f, 0.0f, 0.0f));
	}

	if (SDLEvent.type == SDL_EventType::SDL_KEYDOWN && SDLEvent.key.keysym.sym == SDLK_UP) {
		camera->Translate(Vec3(1.0f, 0.0f, 0.0f));
	}

	if (SDLEvent.type == SDL_EventType::SDL_KEYDOWN && SDLEvent.key.keysym.sym == SDLK_DOWN) {
		camera->Translate(Vec3(-1.0f, 0.0f, 0.0f));
	}
		
}

Scene1::~Scene1() {
	OnDestroy();
}

void Scene1::OnDestroy() {
	/// Cleanup Assets
	if (camera) delete camera;
	for (Model* model : models) {
		if (model) delete model;
	}

	if (skybox)
		delete skybox;
}
