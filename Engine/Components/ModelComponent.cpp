#include "ModelComponent.h"
#include "Framework/Actor.h"
#include "Renderer/Renderer.h"
#include "Resource/ResourceManager.h"
#include "Engine.h"


namespace Engine
{
	void ModelComponent::Update() {}

	void ModelComponent::Draw(Renderer& renderer)
	{
		model_->Draw(renderer, owner_->transform_);
	}

	bool ModelComponent::Write(const rapidjson::Value& value)const { return true; }
	bool ModelComponent::Read(const rapidjson::Value& value)
	{
		std::string modelName_;
		READ_DATA(value, modelName_);
		model_ = resourceManager_g.Get<Model>(modelName_);

		return true;
	}
}