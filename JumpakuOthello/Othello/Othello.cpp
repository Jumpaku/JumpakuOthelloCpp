#include"Othello.h"

#include"Utility/BoardManager.h"
#include"Board/Square.h"
#include"Utility/OthelloLogicException.h"

using namespace jo;

Board Othello::board()const
{
	return boardManager_m.getBoard();
}

Color Othello::turnColor()const
{
	return turnColor_m;
}

bool Othello::hasFinished()const
{
	return hasFinished_m;
}

int Othello::discCount(Color const &color)const
{
	Board b = board();
	Board::Iterator_t begin = b.begin(), end = b.end();

	auto sameColor = [color](Square s)
	{
		return s.empty() ? false : s.disc().color() == color;
	};

	return std::count_if(begin, end, sameColor);
}

int Othello::turnCount()const
{
	return history_m.back().count();
}

History Othello::history()const
{
	return history_m;
}

SquareCollection Othello::getAvailables()const
{
	return boardManager_m.getAvailables(turnColor());
}

SquareCollection Othello::getReversibles(Square const &choice)const
{
	return boardManager_m.getReversibles(choice);
}

bool Othello::isAvailable(Square const &choice)const
{
	try {
		return boardManager_m.canPut(choice);
	}
	catch (OthelloLogicException &) {
		throw;
	}
}

void Othello::select(Square const &choice)
{
	try {
		SquareCollection reversibles = getReversibles(choice);
		boardManager_m.put(choice);
		boardManager_m.reverse(reversibles);
	}
	catch(OthelloLogicException &) {
		throw;
	}
	history_m.pushBack(choice);
}

void Othello::changeTurn()
{
	turnColor_m = turnColor_m.reversed();
	if (!boardManager_m.canPut(turnColor_m)) {
		turnColor_m = turnColor_m.reversed();
		if (!boardManager_m.canPut(turnColor_m)) {
			hasFinished_m = true;
		}
	}
}

void Othello::playTurn(Square const &choice)
{
	if(turnColor_m != choice.disc().color()) {
		throw OthelloLogicException("invalid choice : wrong color");
	}
	if(!isAvailable(choice)) {
		throw OthelloLogicException("invalid choice : not available position");
	}
	try {
		select(choice);
	}
	catch(OthelloLogicException &) {
		throw;
	}
	changeTurn();
}


void Othello::playTurn(Strategy_p strategy)
{
	try {
		playTurn(strategy->think(*this));
	}
	catch (OthelloLogicException &) {
		throw;
	}
}

void Othello::undo()
{
	try {
		history_m.popBack();
	}
	catch(OthelloLogicException &) {
		return;
	}
	History tmpHistory = history_m;

	restart();
	while(!tmpHistory.empty()) {
		playTurn(tmpHistory.popFront().choice());
	}
}

void Othello::restart()
{
	hasFinished_m = false;
	history_m.clear();
	boardManager_m.setBoard(Board());
	turnColor_m = Color::dark();
}
