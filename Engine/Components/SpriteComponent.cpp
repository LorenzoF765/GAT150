#include "SpriteComponent.h"
#include "Framework/Actor.h"
#include "Renderer/Renderer.h"

namespace Solas {
	void SpriteComponent::Update() {
		//nothing here
	}

	void SpriteComponent::Draw(Renderer& renderer){
		renderer.Draw(texture_, m_owner->transform_);
	}
}