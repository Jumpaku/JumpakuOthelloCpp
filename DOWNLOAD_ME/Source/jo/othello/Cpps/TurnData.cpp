#include"../TurnData.h"

#include"../Square.h"
#include"../Disc.h"

using namespace jo;

TurnData::TurnData(int const &count, Pos const &pos, Color const&color)
	:turnCount_m(count), pos_m(pos),color_m(color){}

int TurnData::count()const
{
	return turnCount_m;
}

Pos TurnData::pos()const
{
	return pos_m;
}

int TurnData::i()const
{
	return pos().i();
}

int TurnData::j()const
{
	return pos().j();
}

Color TurnData::color()const
{
	return color_m;
}

Square TurnData::choice()const
{
	Square square(pos_m);
	square.put(Disc(color_m));
	return square;
}
