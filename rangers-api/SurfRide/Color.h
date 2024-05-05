#pragma once

namespace SurfRide
{
	struct Color
	{
		unsigned char r{};
		unsigned char g{};
		unsigned char b{};
		unsigned char a{};

		// Color operator+(const Color& other) const {
		// 	return { static_cast<unsigned char>(r + other.r), static_cast<unsigned char>(g + other.g), static_cast<unsigned char>(b + other.b), static_cast<unsigned char>(a + other.a) };
		// }

		// Color operator-(const Color& other) const {
		// 	return { static_cast<unsigned char>(r - other.r), static_cast<unsigned char>(g - other.g), static_cast<unsigned char>(b - other.b), static_cast<unsigned char>(a - other.a) };
		// }

		// Color operator*(const Color& other) const {
		// 	return { static_cast<unsigned char>(r * other.r), static_cast<unsigned char>(g * other.g), static_cast<unsigned char>(b * other.b), static_cast<unsigned char>(a * other.a) };
		// }

		// Color operator*(float scalar) const {
		// 	return { static_cast<unsigned char>(r * scalar), static_cast<unsigned char>(g * scalar), static_cast<unsigned char>(b * scalar), static_cast<unsigned char>(a * scalar) };
		// }
	};
}
