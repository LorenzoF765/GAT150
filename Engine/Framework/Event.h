#pragma once
#include <string>
#include <iostream>
#include <functional>
#include <variant>


namespace Solas
{
	class GameObject;

	class Event
	{
	public:
		using functionPtr = std::function<void(const Event&)>;

		std::string name;
		GameObject* reciever = nullptr;
		std::variant<int, bool, float, std::string> data;
	};

	class INotify
	{
	public:
		virtual void OnNotify(const Event& event) = 0;
	};
}