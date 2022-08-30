#pragma once
#include <random>

namespace Engine
{
	inline void SeedRandom(int seed) { srand(seed); }

	inline int RandomInt() { return rand(); }
	inline int RandomInt(int max) { return RandomInt() % max; } // Exclusive, Does not include the maximum
	inline int RandomInt(int min, int max) { return min + RandomInt() % ((max - min) + 1); } // Inclusive, does include maximum

	inline float RandomFloat() { return rand() / (float)RAND_MAX; } // 0.0 - 1.0
	inline float RandomFloat(float max) { return RandomFloat() * max; } // 0.0 - MAX
	inline float RandomFloat(float min, float max) { return min + RandomFloat(max - min); }
}
