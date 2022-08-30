#pragma once

#include "Serialization/Json.h"

#include "Core/Memory.h"
#include "Core/File.h"
#include "Core/Time.h"
#include "Core/Logger.h"

#include "Components/PlayerComponent.h"
#include "Components/SpriteComponent.h"
#include "Components/SpriteAnimateComponent.h"
#include "Components/AudioComponent.h"
#include "Components/PhysicsComponent.h"
#include "Components/RBPhysicsComponent.h"
#include "Components/CollisionComponent.h"
#include "Components/TextComponent.h"
#include "Components/ModelComponent.h"
#include "Components/TileMapComponent.h"

#include "Input/InputSystem.h"
#include "Audio/AudioSystem.h"

#include "Renderer/Renderer.h"
#include "Renderer/Font.h"
#include "Renderer/Text.h"
#include "Renderer/Texture.h"
#include "Renderer/Model.h"

#include "Math/MathUtils.h"
#include "Math/Random.h"
#include "Math/Vector2.h"

#include "Framework/Scene.h"
#include "Framework/Game.h"
#include "Framework/GameObject.h"
#include "Framework/Singleton.h"
#include "Framework/Factory.h"

#include "Resource/ResourceManager.h"

#include "Physics/PhysicsSystem.h"

#include <memory>
#include <vector>
#include <list>


namespace Engine
{
	extern InputSystem inputSystem_g;
	extern Renderer renderer_g;
	extern Time timer_g;
	extern AudioSystem audioSystem_g;
	extern ResourceManager resourceManager_g;
	extern PhysicsSystem physics_g;

	class Engine : public Singleton<Engine>
	{
	public:
		void Register();
	};
}
