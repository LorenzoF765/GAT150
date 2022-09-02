#include "SolGame.h"
#include "Engine.h"
#include "GameComponents/EnemyComponent.h"

void MyGame::Initialize()
{
	REGISTER_CLASS(EnemyComponent);


	m_scene = std::make_unique<Solas::Scene>();

	rapidjson::Document document;
	std::vector<std::string> sceneNames = { "scenes/prefabs.txt", "scenes/level.txt", "scenes/tilemap.txt" };

	for (auto sceneName : sceneNames)
	{
		bool success = Solas::json::Load(sceneName, document);
		if (!success)
		{
			LOG("error could not load scene %s", sceneName.c_str());
			continue;
		}

		m_scene->Read(document);
	}
	m_scene->Initialize();



	Solas::g_eventManager.Subscribe("EVENT_ADD_POINTS", std::bind(&MyGame::OnAddPoints, this, std::placeholders::_1));
	Solas::g_eventManager.Subscribe("EVENT_PLAYER_DEAD", std::bind(&MyGame::OnAddPoints, this, std::placeholders::_1));
}

void MyGame::Shutdown()
{
	m_scene->RemoveAll();
}

void MyGame::Update()
{
	switch (m_gameState)
	{
	case gameState::titleScreen:
		m_scene->GetActorFromName("Title")->SetActive(true);
		m_lives = 3;

		if (Solas::g_inputSystem.GetKeyState(Solas::key_enter) == Solas::InputSystem::State::Pressed)
		{
			m_scene->GetActorFromName("Title")->SetActive(false);

			m_gameState = gameState::startLevel;
		}

		break;

	case gameState::startLevel:
		m_scene->GetActorFromName("Score")->SetActive(true);
		m_scene->GetActorFromName("Health")->SetActive(true);

		for (int i = 0; i < 10; i++)
		{
			auto actor = Solas::Factory::Instance().Create<Solas::Actor>("Coin");
			actor->m_transform.position = { Solas::Randomf(0, 800), 100.0f };
			actor->Initialize();

			m_scene->AddActor(std::move(actor));
		}
		for (int i = 0; i < 3; i++)
		{
			auto actor = Solas::Factory::Instance().Create<Solas::Actor>("Demon");
			actor->m_transform.position = { Solas::Randomf(0, 800), 100.0f };
			actor->Initialize();

			m_scene->AddActor(std::move(actor));
		}
		{
			auto actor = Solas::Factory::Instance().Create<Solas::Actor>("Player");
			actor->m_transform.position = { 400.0f, 250.0f };
			actor->Initialize();

			m_scene->AddActor(std::move(actor));
		}
		m_gameState = gameState::game;
		break;

	case gameState::game:
	{
		auto score = m_scene->GetActorFromName("Score");
		auto component = score->GetComponent<Solas::TextComponent>();
		if (component)
		{
			component->SetText(std::to_string(m_score));
		}
	}
	{
		auto score = m_scene->GetActorFromName("Health");
		auto component = score->GetComponent<Solas::TextComponent>();
		auto player = m_scene->GetActorFromName("Player");
		auto pcomponent = player->GetComponent<Solas::PlayerComponent>();
		if (component)
		{
			component->SetText(std::to_string((int)pcomponent->health));
		}
	}
	break;

	case gameState::playerDead:
		m_stateTimer -= Solas::g_time.deltaTime;
		if (m_stateTimer <= 0)
		{
			m_gameState = (m_lives > 0) ? gameState::startLevel : gameState::gameOver;
		}
		break;

	case gameState::gameOver:
		break;

	default:
		break;
	}

	m_scene->Update();
}

void MyGame::Draw(Solas::Renderer& renderer)
{
	m_scene->Draw(renderer);
}

void MyGame::OnAddPoints(const Solas::Event& event)
{
	AddPoints(std::get<int>(event.data));
}

void MyGame::OnPlayerDead(const Solas::Event& event)
{
	m_gameState = gameState::playerDead;
	m_lives--;
	m_stateTimer = 3;
}

void MyGame::OnNotify(const Solas::Event& event)
{
	if (event.name == "EVENT_ADD_POINTS")
	{
		OnAddPoints(event);
	}

	if (event.name == "EVENT_PLAYER_DEAD")
	{
		m_gameState = gameState::playerDead;
		m_lives--;
		m_stateTimer = 3;
	}
}
