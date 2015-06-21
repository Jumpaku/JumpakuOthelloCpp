#include"../Color.h"

#include"../OthelloLogicException.h"

using namespace jo;

Color::Color(Color::Color_e color)
	:color_m(color){}

Color Color::reversed()const
{
	return color_m == Color_e::DARK ?
		Color_e::LIGHT : Color_e::DARK;
}

std::string Color::toString()const
{
	return color_m == Color_e::DARK ?
		"DARK" : "LIGHT";
}

bool Color::operator==(Color const &color)const
{
	return color_m == color.color_m;
}

bool Color::operator!=(Color const &color)const
{
	return !operator==(color);
}

Color Color::dark()
{
	static Color dark(Color_e::DARK);
	return dark;
}

Color Color::light()
{
	static Color light(Color_e::LIGHT);
	return light;
}
