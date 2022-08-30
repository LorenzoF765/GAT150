#include "TextComponent.h"
#include"Engine.h"

bool Engine::TextComponent::Write(const rapidjson::Value& value) const
{
    return true;
}
bool Engine::TextComponent::Read(const rapidjson::Value& value)
{
	READ_DATA(value, text);
	READ_DATA(value, fontName);
	READ_DATA(value, fontSize);
	READ_DATA(value, registration);
	READ_DATA(value, color);

	font_ = resourceManager_g.Get<Font>(fontName, fontSize);
	texture_ = std::make_unique<Texture>();

	SetText(text);

    return true;
}
void Engine::TextComponent::Update()
{
}
void Engine::TextComponent::Draw(Renderer& renderer)
{
	renderer_g.Draw(texture_, owner_->transform_, registration);
}
void Engine::TextComponent::SetText(const std::string& text)
{
	texture_->CreateFromSurface(font_->CreateSurface(text, color), renderer_g);
}
