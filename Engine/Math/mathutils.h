#pragma once
namespace Math {

	constexpr float pi = 3.14159265359f;
	constexpr float twoPi = 6.28318530718f;
	constexpr float halfPi = 1.57079632679f;

	constexpr float DegToRad(float degrees) {
		return degrees * (pi / 180);
	}

	constexpr float RadToDeg(float radians) {
		return radians * (180 / pi);
	}

	int sqr(int v);
	//Inline doesnt really call the funtion, it replaces the word for blocks of code.
	inline int half(int v) { return v / 2; }
}