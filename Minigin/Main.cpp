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
	//[Texture2D]

	//[TextComponent]
	auto font = dae::ResourceManager::GetInstance().LoadFont("Lingua.otf", 36);
	std::shared_ptr<dae::Component> text = std::make_shared<dae::TextComponent>("Programming 4 Assignment", font);
	go->AddComponent(text);


}


void load()
{	

	loadDemoScene();

	//go->SetTexture("background.tga");
	//go->SetTexture("logo.tga");
	//go->SetPosition(216, 180);
	//scene.Add(go);



	//std::shared_ptr<Texture2D> m_texture{};

	//void dae::GameObject::SetTexture(const std::string & filename)
	//{
	//	m_texture = ResourceManager::GetInstance().LoadTexture(filename);
	//}
}

int main(int, char*[]) {
	dae::Minigin engine("../Data/");
	engine.Run(load);
    return 0;
}

