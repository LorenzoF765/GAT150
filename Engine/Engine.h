#pragma once
#include "Core/Memory.h"
#include "Core/File.h"
#include "Core/Time.h"

#include "Components/PlayerComponent.h"
#include "Components/SpriteComponent.h"
#include "Components/ModelComponent.h"
#include "Components/AudioComponent.h"
#include "Components/PhysicsComponent.h"

#include "Input/InputSystem.h"

#include "Renderer/Renderer.h"
#include "Renderer/Text.h"
#include "Renderer/Font.h"
#include "Renderer/Texture.h"
#include "Renderer/Model.h"

#include "Math/MathUtils.h"
#include "Math/Random.h"

#include "Framework/Scene.h"
#include "Framework/Game.h"
#include "Framework/Singleton.h"
#include "Framework/Factory.h"

#include "Resource/ResourceManager.h"

#include "Audio/AudioSystem.h"

#include <memory>
#include <vector>
#include <list>

namespace Solas
{
	extern InputSystem inputSystem_g;
	extern Renderer renderer_g;

	extern Time time_g;

	extern AudioSystem audioSystem_g;

	extern ResourceManager resourceManager_g;

	class Engine : public Singleton<Engine> {
	public:
		void Register();
	};
}
