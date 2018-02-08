#pragma once

#include "Config.h"

namespace Tan
{
	class Color
	{
	public:
		union
		{
			struct { coord r, g, b; };
			coord c[3];
		};

	public:
		Color() : r(0.0f), g(0.0f), b(0.0f) {}
		Color(coord r, coord g, coord b) : r(r), g(g), b(b) {}
		Color(const Color& rhs) : r(rhs.r), g(rhs.g), b(rhs.b) {}
		~Color() = default;

	public:
		Color operator* (float k)
		{
			return Color
			(
				r * k,
				g * k,
				b * k
			);
		}
		void operator*= (float k)
		{
			r *= k;
			g *= k;
			b *= k;
		}

	public:
		UINT ToUINT()
		{
			int R = static_cast<int>(r * 255.0f);
			int G = static_cast<int>(g * 255.0f);
			int B = static_cast<int>(b * 255.0f);
			return (R << 16) | (G << 8) | (B);
		}
	};

	namespace Colors
	{
		const static Color White   = { 1.00000000f, 1.00000000f, 1.00000000f };
		const static Color Black   = { 0.00000000f, 0.00000000f, 0.00000000f };
		const static Color Red     = { 1.00000000f, 0.00000000f, 0.00000000f };
		const static Color Green   = { 0.00000000f, 1.00000000f, 0.00000000f };
		const static Color Blue    = { 0.00000000f, 0.00000000f, 1.00000000f };
		const static Color Yellow  = { 1.00000000f, 1.00000000f, 0.00000000f };
		const static Color Cyan    = { 0.00000000f, 1.00000000f, 1.00000000f };
		const static Color Magenta = { 1.00000000f, 0.00000000f, 1.00000000f };
	}
}