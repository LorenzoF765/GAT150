#pragma once
#include "Framework/Game.h"
#include "Framework/Event.h"



class MyGame : public Solas::Game, public Solas::INotify
{
public:
	enum class gameState
	{
		titleScreen,
		startLevel,
		game,
		playerDead,
		gameOver
	};

public:
	virtual void Initialize() override;
	virtual void Shutdown() override;

	virtual void Update() override;
	virtual void Draw(Solas::Renderer& renderer) override;

	virtual void OnNotify(const Solas::Event& event) override;
	void OnAddPoints(const Solas::Event& event);
	void OnPlayerDead(const Solas::Event& event);

private:
	gameState m_gameState = gameState::titleScreen;
	float m_stateTimer = 0;
	int m_lives = 3;
};