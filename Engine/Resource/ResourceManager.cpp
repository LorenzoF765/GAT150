#include "ResourceManager.h"

namespace Engine
{
	void ResourceManager::Initialize() {}

	void ResourceManager::ShutDown()
	{
		resources_.clear();
	}
}