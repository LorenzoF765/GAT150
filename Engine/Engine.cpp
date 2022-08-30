#include "Engine.h"

namespace Solas
{
	InputSystem inputSystem_g;
	Renderer renderer_g;

	Time time_g;

	AudioSystem audioSystem_g;

	ResourceManager resourceManager_g;

	void Engine::Register() {
		REGISTER_CLASS(Actor);
		REGISTER_CLASS(AudioComponent);
		REGISTER_CLASS(ModelComponent);
		REGISTER_CLASS(PhysicsComponent);
		REGISTER_CLASS(PlayerComponent);
		REGISTER_CLASS(SpriteComponent);
	}
}