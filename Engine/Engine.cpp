#include "Engine.h"

namespace Engine
{
	InputSystem inputSystem_g;
	Renderer renderer_g;
	Time timer_g;
	AudioSystem audioSystem_g;
	ResourceManager resourceManager_g;
	PhysicsSystem physics_g;

	void Engine::Register()
	{
		REGISTER_CLASS(Actor);
		REGISTER_CLASS(AudioComponent);
		REGISTER_CLASS(CollisionComponent);
		REGISTER_CLASS(ModelComponent);
		REGISTER_CLASS(PhysicsComponent);
		REGISTER_CLASS(RBPhysicsComponent);
		REGISTER_CLASS(PlayerComponent);
		REGISTER_CLASS(SpriteComponent);
		REGISTER_CLASS(TextComponent);
		REGISTER_CLASS(SpriteAnimateComponent);
		REGISTER_CLASS(TilemapComponent);
	}
}