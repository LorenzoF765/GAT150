#pragma once
#include <random>

namespace Solas {
	inline void SeedRandom(int seed) { srand(seed); }

	inline int Random() { return rand(); }
	inline int Random(int max) { return Random() % max; }
	inline int Random(int min, int max) { return min + Random() % ((max - min) + 1); }

	inline float Randomf() { return rand() / (float)RAND_MAX; }
	inline float Randomf(float max) { return Randomf() * max; }
	inline float Randomf(float min, float max) { return min + Randomf(max - min); }


}