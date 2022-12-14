#pragma once
#include "Components/CharacterComponent.h"

class EnemyComponent : public Solas::CharacterComponent
{
public:
	CLASS_DECLARATION(EnemyComponent)

		virtual void Initialize() override;
	virtual void Update() override;

	virtual void OnCollisionEnter(Solas::Actor* other) override;
	virtual void OnCollisionExit(Solas::Actor* other) override;

	virtual void OnNotify(const Solas::Event& event) override;

	virtual bool Write(const rapidjson::Value& value) const override;
	virtual bool Read(const rapidjson::Value& value) override;

protected:
};