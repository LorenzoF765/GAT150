#include "Actor.h"
#include "Components/RendererComponent.h"

namespace Solas
{
	void Actor::Draw(Renderer& renderer)
	{
		for (auto& component : m_components) {
			auto renderComponent = dynamic_cast<RendererComponent*>(component.get());
			if (renderComponent) {
				renderComponent->Draw(renderer);
			}
		}

		for (auto& child : m_children) {
			child->Draw(renderer);
		}
	}

	//add child broken
	/*void Actor::AddChild(std::unique_ptr<Actor> child){
		child->m_parent = this;
		child->m_scene = this->m_scene;
		m_children.push_back(child);
	}*/

	void Actor::AddComponent(std::unique_ptr<Component> component) {
		//component->m_owner = this;

		m_components.push_back(std::move(component));
	}

	void Actor::Update() {
		for (auto& component : m_components) {
			//component->Update();
		}

		for (auto& child : m_children) {
			child->Update();
		}

		if (m_parent != nullptr) {
			transform_.Update(m_parent->transform_.matrix);
		}
		else {
			transform_.Update();
		}

		transform_.Update();
	}
}
