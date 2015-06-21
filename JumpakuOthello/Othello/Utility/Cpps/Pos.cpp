#include "../Pos.h"

#include"../Dir.h"
#include<algorithm>

using namespace jo;

int Pos::clamp(int x)
{
	return (std::min)((std::max)(0, x), 9);
}

Pos::Pos(int i, int j)
	:i_m(clamp(i)), j_m(clamp(j))
{}

Pos Pos::operator+(Pos const &p)const
{
	return Pos(i_m + p.i_m, j_m + p.j_m);
}

Pos Pos::operator+=(Pos const &p)
{
	return *this = *this + p;
}

bool Pos::operator==(Pos const &p)const
{
	return i_m == p.i_m && j_m == p.j_m;
}

bool Pos::operator!=(Pos const &p)const
{
	return !(*this == p);
}

void Pos::move(Dir dir)
{
	struct DeltaPos {
		int i_m;
		int j_m;
		Pos plus(Pos const &p)
		{
			return Pos(p.i() + i_m, p.j() + j_m);
		}
	};
	static std::map<Dir, DeltaPos> delta = {
		{ Dir::N, { -1, 0 } },
		{ Dir::NE, { -1, 1 } },
		{ Dir::E, { 0, 1 } },
		{ Dir::SE, { 1, 1 } },
		{ Dir::S, { 1, 0 } },
		{ Dir::SW, { 1, -1 } },
		{ Dir::W, { 0, -1 } },
		{ Dir::NW, { -1, -1 } },
	};
	*this = delta[dir].plus(*this);
}

bool Pos::out()const
{
	return !(1 <= i_m && i_m <= 8 && 1 <= j_m && j_m <= 8);
}


int Pos::i()const
{
	return i_m;
}

int Pos::j()const
{
	return j_m;
}

void Pos::i(int i)
{
	i_m = clamp(i);
}

void Pos::j(int j)
{
	j_m = clamp(j);
}
