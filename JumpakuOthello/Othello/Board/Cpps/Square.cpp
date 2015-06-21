#include"../Square.h"

#include"../../Utility/OthelloLogicException.h"
#include"../Disc.h"

using namespace jo;

Square::Square(Pos const&pos)
	:pos_m(pos)
{}

Square::Square(int const &i, int const &j)
	:Square(Pos{ i, j }){}

Square::Square(Square const &square)
	: pos_m(square.pos_m),
	disc_m(square.empty() ? nullptr : make(square.disc())){}

Square::Square(Pos const &pos, Color const &color)
	: Square(pos)
{
	put(Disc(color));
}

Square::Square(int const &i, int const &j, Color const &color)
	: Square(i, j)
{
	put(Disc(color));
}

Square &Square::operator=(Square const &square)
{
	pos_m = square.pos_m;
	disc_m = square.empty() ?
		nullptr : make(square.disc());

	return *this;
}

void Square::reverse()
{
	if(empty()) {
		throw OthelloLogicException("no disc on the square");
	}
	disc_m->reverse();
}

void Square::put(Disc const &disc)
{
	disc_m = make(disc);
}

void Square::unput()
{
	disc_m = nullptr;
}

Disc Square::disc() const
{
	if(empty()) {
		throw OthelloLogicException("no disc on the square");
	}
	return *disc_m;
}

bool Square::empty()const
{
	return disc_m == nullptr;
}

bool Square::out()const
{
	return pos().out();
}

Square::Disc_p Square::make(Disc const &disc)
{
	return std::make_unique<Disc>(disc);
}

Pos Square::pos()const
{
	return pos_m;
}
int Square::i()const
{
	return pos().i();
}

int Square::j()const
{
	return pos().j();
}
