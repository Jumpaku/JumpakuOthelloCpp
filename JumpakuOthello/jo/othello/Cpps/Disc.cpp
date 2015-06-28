#include"../Disc.h"

using namespace jo;

Disc::Disc()
	:top_m(Color::dark()),bottom_m(Color::light()){}

Disc::Disc(Color const &color)
	: top_m(color), bottom_m(color.reversed()){}

bool Disc::operator==(Disc const &disc)const
{
	return color() == disc.color();
}

bool Disc::operator!=(Disc const &disc)const
{
	return !operator==(disc);
}

void Disc::reverse()
{
	std::swap(top_m, bottom_m);
}

Color Disc::color()const
{
	return top_m;
}

