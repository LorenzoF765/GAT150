#include "Engine.h"
#include "Math/MathUtils.h"
#include <iostream>

int main()
{
	Solas::InitializeMemory();

	Solas::setFilePath("../Assets");

	Solas::renderer_g.Initialize();
	Solas::inputSystem_g.Initialize();
	Solas::audioSystem_g.Initialize();
	Solas::resourceManager_g.Initialize();

	Solas::Engine::Instance().Register();

	Solas::renderer_g.CreateWindow("Engine", 800, 600); // Creates the window with parameters
	Solas::renderer_g.SetClearColor(Solas::Color{ 0, 0, 0, 255 });

	//load assets
	//Texture
	/*std::shared_ptr<JREngine::Texture> texture = std::make_shared<JREngine::Texture>();
	texture->Create(JREngine::renderer_g, "Sprites/spaceShips_004.png");*/
	std::shared_ptr<Solas::Texture> texture = Solas::resourceManager_g.Get<Solas::Texture>("Sprites/spaceShips_004.png", &Solas::renderer_g);
	//Model
	/*std::shared_ptr<JREngine::Model> model = std::make_shared<JREngine::Model>();
	model->Create("Text-Models/Player.txt");*/
	//Audio
	Solas::audioSystem_g.AddAudio("lazer", "Audio/temp-lazer.wav");

	//Scene & actor component
	Solas::Scene scene;
	Solas::Transform transform{ Solas::Vector2{400, 300}, 90, {3, 3} };
	//std::unique_ptr<JREngine::Actor> actor = std::make_unique<JREngine::Actor>(transform);
	std::unique_ptr <Solas::Actor> actor = Solas::Factory::Instance().Create<Solas::Actor>("Actor");
	actor->transform_ = transform;
	//Player component
	std::unique_ptr<Solas::Component> playerComponent = Solas::Factory::Instance().Create<Solas::Component>("Player");
	actor->AddComponent(std::move(playerComponent));
	//Sprite component
	/*std::unique_ptr<JREngine::SpriteComponent> sprComponent = std::make_unique<JREngine::SpriteComponent>();
	sprComponent->texture_ = texture;
	actor->AddComponent(std::move(sprComponent));*/
	//Model Component
	std::unique_ptr<Solas::ModelComponent> modelComponent = std::make_unique<Solas::ModelComponent>();
	modelComponent->m_model = Solas::resourceManager_g.Get<Solas::Model>("Text-Models/Player.txt");
	actor->AddComponent(std::move(modelComponent));
	//Audio component
	std::unique_ptr<Solas::AudioComponent> acomponent = std::make_unique<Solas::AudioComponent>();
	actor->AddComponent(std::move(acomponent));
	//Physics component
	std::unique_ptr<Solas::PhysicsComponent> phcomponent = std::make_unique<Solas::PhysicsComponent>();
	actor->AddComponent(std::move(phcomponent));
	//Child component broken
	//JREngine::Transform transformC{ JREngine::Vector2{40, 30}, 0, {1, 1} };
	//std::unique_ptr<JREngine::Actor> child = std::make_unique<JREngine::Actor>(transformC);
	////Child Model
	//std::unique_ptr<JREngine::ModelComponent> modelComponentC = std::make_unique<JREngine::ModelComponent>();
	//modelComponentC->m_model = JREngine::resourceManager_g.Get<JREngine::Model>("Text-Models/Player.txt");
	//child->AddComponent(std::move(modelComponentC));
	//actor->AddChild(std::move(child));

	scene.Add(move(actor));



	bool quit = false;
	while (!quit)
	{
		// Update
		Solas::time_g.Tick();
		Solas::inputSystem_g.Update();
		Solas::audioSystem_g.Update();

		if (Solas::inputSystem_g.onKeyEsc(Solas::InputSystem::KeyState::Pressed)) {
			quit = true;
		}

		//angle += 360.0f * time_g;

		scene.Update();

		// Render
		Solas::renderer_g.BeginFrame();

		//JREngine::renderer_g.Draw(texture, { 400, 300 }, angle, { 2.0f, 2.0f }, { 0.5f, 0.5f });
		scene.Draw(Solas::renderer_g);

		Solas::renderer_g.EndFrame();
	}

	Solas::inputSystem_g.Shutdown();
	Solas::audioSystem_g.Shutdown();
	Solas::renderer_g.Shutdown();
}