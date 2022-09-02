#include "EventManager.h"


namespace Solas
{
	void EventManager::Initialize()
	{
	}

	void EventManager::Shutdown()
	{
	}

	void EventManager::Update()
	{
	}

	void EventManager::Subscribe(const std::string& name, Event::functionPtr function, GameObject* reciever)
	{
		Observer observer;
		observer.reciever = reciever;
		observer.function = function;

		m_events[name].push_back(observer);
	}

	void EventManager::Unsubscribe(const std::string& name, GameObject* reciever)
	{
		//
	}

	void EventManager::Notify(const Event& event)
	{
		auto& observers = m_events[event.name];
		for (auto& observer : observers)
		{
			if (event.reciever == nullptr || event.reciever == observer.reciever)
			{
				observer.function(event);
			}
		}
	}
}
