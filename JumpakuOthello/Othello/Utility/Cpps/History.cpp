#include"../History.h"

#include"../OthelloLogicException.h"
#include"../../Board/Square.h"
#include"../../Board/Disc.h"

using namespace jo;

void History::pushBack(Square const &choice)
{
	if (choice.empty()) {
		throw OthelloLogicException("cannot push no color choice");
	}
	history_m.emplace_back(size() + 1, choice.pos(), choice.disc().color());
}

TurnData History::popBack()
{
	if(empty()) {
		throw OthelloLogicException("history is empty");
	}
	TurnData tmp = history_m.back();
	history_m.pop_back();

	return tmp;
}

TurnData History::popFront()
{
	if(empty()) {
		throw OthelloLogicException("history is empty");
	}
	TurnData tmp = history_m.front();
	history_m.pop_front();

	return tmp;
}

TurnData History::back()const
{
	if(empty()) {
		throw OthelloLogicException("history is empty");
	}
	return history_m.back();
}

int History::size()const
{
	return history_m.size();
}

void History::clear()
{
	history_m.clear();
}

bool History::empty()const
{
	return history_m.empty();
}