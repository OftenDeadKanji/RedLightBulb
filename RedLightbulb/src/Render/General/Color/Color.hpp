#ifndef __COLOR_HPP__
#define __COLOR_HPP__

namespace Render
{
	class Color 
		: public Math::Vec3f
	{
	public:
		Color();
		Color(const Math::Vec3f& v);
		Color(float r, float g, float b);

		Color(const Color&);
		Color& operator=(const Color&);

		float& r();
		const float& r() const;

		float& g();
		const float& g() const;

		float& b();
		const float& b() const;

		bool isWith255Range() const;
		void setWith255Range(bool with255Range);

		Math::Vec3f getAsHSV(const Math::Vec3f& hsv) const;
		void setFromHSV(const Math::Vec3f& hsv);

		static const Color White;
		static const Color Yellow;
		static const Color Red;
	private:
		bool m_with255Range{ false };
	};
}

#endif
