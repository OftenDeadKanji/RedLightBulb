#include "pch.h"
#include "Color.hpp"

namespace Render
{
	const Color Color::White(1.0f, 1.0f, 1.0f);
	const Color Color::Yellow(0.0f, 1.0f, 1.0f);
	const Color Color::Red(1.0f, 0.0f, 0.0f);

	Color::Color()
	{
		x() = 0.0f;
		y() = 0.0f;
		z() = 0.0f;
	}

	Color::Color(const Math::Vec3f& v)
	{
		x() = v.x();
		y() = v.y();
		z() = v.z();
	}

	Color::Color(float r, float g, float b)
	{
		x() = r;
		y() = g;
		z() = b;
	}

	Color::Color(const Color& other)
	{
		if (this != &other)
		{
			x() = other.x();
			y() = other.y();
			z() = other.z();
		}
	}

	Color& Color::operator=(const Color& other)
	{
		if (this != &other)
		{
			x() = other.x();
			y() = other.y();
			z() = other.z();
		}

		return *this;
	}

	float& Color::r()
	{
		return x();
	}
	const float& Color::r() const
	{
		return x();
	}

	float& Color::g()
	{
		return y();
	}
	const float& Color::g() const
	{
		return y();
	}

	float& Color::b()
	{
		return z();
	}
	const float& Color::b() const
	{
		return z();
	}

	bool Color::isWith255Range() const
	{
		return m_with255Range;
	}
	void Color::setWith255Range(bool with255Range)
	{
		m_with255Range = with255Range;
	}

	Math::Vec3f Color::getAsHSV(const Math::Vec3f& hsv) const
	{
		Color rgb(*this);

		if (m_with255Range)
		{
			rgb /= 255.0f;
		}

		float cMax = rgb.maxCoeff();
		float cMin = rgb.minCoeff();
		float diff = cMax - cMin;
		float h = -1, s = -1;

		if (cMax == cMin)
		{
			h = 0.0f;
		}
		else if (cMax == rgb.r())
		{
			h = std::fmodf(60.0f * ((rgb.g() - rgb.b()) / diff) + 360.0f, 360.0f);
		}
		else if (cMax == rgb.g())
		{
			h = std::fmodf(60.0f * ((rgb.b() - rgb.r()) / diff) + 120.0f, 360.0f);
		}
		else if (cMax == rgb.b())
		{
			h = std::fmodf(60.0f * ((rgb.r() - rgb.g()) / diff) + 120.0f, 360.0f);
		}

		if (cMax == 0.0f)
		{
			s = 0.0f;
		}
		else
		{
			s = (diff / cMax);
		}

		float v = cMax;

		return Math::Vec3f(h, s, v);
	}
	void Color::setFromHSV(const Math::Vec3f& hsv)
	{
		float h = hsv.x();
		float s = hsv.y();
		float v = hsv.z();

		float c = s * v;
		float x = c * (1.0f - std::abs(fmodf(h / 60.0f, 2.0f) - 1.0f));
		float m = v - c;

		Color rgb{};

		if (h < 60.0f)
		{
			rgb = Color(c, x, 0);
		}
		else if (h < 120.0f)
		{
			rgb = Color(x, c, 0);
		}
		else if (h < 180.0f)
		{
			rgb = Color(0, c, x);
		}
		else if (h < 240.0f)
		{
			rgb = Color(0, x, c);
		}
		else if (h < 300.0f)
		{
			rgb = Color(x, 0, c);
		}
		else
		{
			rgb = Color(c, 0, x);
		}

		rgb += Color(m, m, m);

		if (m_with255Range)
		{
			rgb *= 255;
		}

		*this = rgb;
	}
}