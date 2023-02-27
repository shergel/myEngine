#include <SDL.h>

#if _DEBUG
// ReSharper disable once CppUnusedIncludeDirective
#if __has_include(<vld.h>)
#include <vld.h>
#endif
#endif

#include "Minigin.h"
#include "SceneManager.h"
#include "ResourceManager.h"
#include "Scene.h"
#include "GameObject.h"
#include "Component.h"
#include "TextComponent.h"
#include "ImageComponent.h"
#include "FPS.h"
#include "Texture2D.h"

void loadDemoScene()
{
	/*SCENE*/
	auto& scene = dae::SceneManager::GetInstance().CreateScene("Demo");
	//containing...

	/*GAMEOBJECT*/
	auto go = std::make_shared<dae::GameObject>();
	scene.Add(go);
	//containing...

	/*COMPONENTS*/
	//[ImageComponent]
	std::shared_ptr<dae::Texture2D> texture1 = dae::ResourceManager::GetInstance().LoadTexture("background.tga");
	std::shared_ptr<dae::Component> image1 = std::make_shared<dae::ImageComponent>(texture1);
	go->AddComponent(image1);

	//[ImageComponent]
	std::shared_ptr<dae::Texture2D> texture2 = dae::ResourceManager::GetInstance().LoadTexture("logo.tga");
	std::shared_ptr<dae::Component> image2 = std::make_shared<dae::ImageComponent>(texture2);
	image2->SetPosition(216, 180); //todo: fix magic number
	go->AddComponent(image2);

	//[TextComponent]
	auto font = dae::ResourceManager::GetInstance().LoadFont("Lingua.otf", 36);
	std::shared_ptr<dae::Component> text = std::make_shared<dae::TextComponent>("Programming 4 Assignment", font);
	go->AddComponent(text);

	std::shared_ptr<dae::Component> fps = std::make_shared<dae::FPS>(font);
	fps->SetPosition(0, 300); //todo: fix magic number
	go->AddComponent(fps);
}

void load()
{	
	loadDemoScene();
}

int main(int, char*[]) {
	dae::Minigin engine("../Data/");
	engine.Run(load);
    return 0;
}