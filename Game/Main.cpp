#include "Engine.h"
#include "SolGame.h"
#include <iostream>

using namespace std;

int main()
{
	Solas::InitializeMemory();

	Solas::SetFilePath("../Assets");

	// initialize systems
	Solas::g_renderer.Initialize();
	Solas::g_inputSystem.Initialize();
	Solas::g_audio.Initialize();
	Solas::g_resources.Initialize();
	Solas::g_physicsSystem.Initialize();
	Solas::g_eventManager.Initialize();

	Solas::Engine::Instance().Register();

	// create window
	Solas::g_renderer.CreateWindow("Solas", 800, 600);
	Solas::g_renderer.setClearColor(Solas::Color{ 20, 20, 20, 0 });

	// create scene
	unique_ptr<MyGame> game = make_unique<MyGame>();
	game->Initialize();

	bool quit = false;
	while (!quit)
	{

		//update (engine)
		Solas::g_time.Tick();
		Solas::g_inputSystem.Update();
		Solas::g_audio.Update();
		Solas::g_physicsSystem.Update();
		Solas::g_eventManager.Update();

		if (Solas::g_inputSystem.GetKeyDown(Solas::key_escape)) { quit = true; }

		// update Scene
		game->Update();

		// renderer

		Solas::g_renderer.BeginFrame();

		game->Draw(Solas::g_renderer);

		Solas::g_renderer.EndFrame();
	}

	game->Shutdown();
	game.reset();

	Solas::Factory::Instance().Shutdown();

	Solas::g_physicsSystem.Shutdown();
	Solas::g_resources.Shutdown();
	Solas::g_inputSystem.Shutdown();
	Solas::g_audio.Shutdown();
	Solas::g_renderer.Shutdown();
	Solas::g_eventManager.Shutdown();
}