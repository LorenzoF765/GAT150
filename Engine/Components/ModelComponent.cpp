#include "ModelComponent.h"
#include "Renderer/Model.h"
#include "Framework/Actor.h"

namespace Solas {
	void Solas::ModelComponent::Update()
	{
		//
	}

	void Solas::ModelComponent::Draw(Renderer& renderer)
	{
		m_model->Draw(renderer, m_owner->transform_);
	}

}
