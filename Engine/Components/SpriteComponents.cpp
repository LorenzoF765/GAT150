#include "SpriteComponents.h"
#include "Renderer/Renderer.h"
#include "Framework/Actor.h"
#include <Framework/Components.h>

void Solas::SpriteComponent::Update()
{
}

void Solas::SpriteComponent::Draw(Renderer& renderer)
{
	renderer.Draw(texture_, m_owner->transform_);
}
