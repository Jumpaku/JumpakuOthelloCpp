#include "../BoardManager.h"

#include"../Square.h"
#include"../Pos.h"
#include"../Board.h"
#include"../../Utility/OthelloLogicException.h"
#include"../Dir.h"
#include"../SquareCollection.h"

using namespace jo;

void BoardManager::setBoard(Board const &board)
{
	board_m = board;
}

Board BoardManager::getBoard()const
{
	return board_m;
}

void BoardManager::put(Square const &choice)
{
	try {
		put(board_m, choice);
	}
	catch (OthelloLogicException &) {
		throw;
	}
}

void BoardManager::reverse(SquareCollection const &reversibles)
{
	try {
		reverse(board_m, reversibles);
	}
	catch (OthelloLogicException &) {
		throw;
	}
}

bool BoardManager::canPut(Square const &choice)const
{
	try {
		return canPut(board_m, choice);
	}
	catch (OthelloLogicException &) {
		throw;
	}
}

bool BoardManager::canPut(Color const &color)const
{
	return canPut(board_m, color);
}

SquareCollection BoardManager::getAvailables(Color const &color)const
{
	return getAvailables(board_m, color);
}

SquareCollection BoardManager::getReversibles(Square const &choice)const
{
	try {
		return getReversibles(board_m, choice);
	}
	catch (OthelloLogicException &) {
		throw;
	}
}


void BoardManager::put(Board &board, Square const &choice)
{
	if (!canPut(board, choice)) {
		throw OthelloLogicException("can not put disc here");
	}
	board.element(choice.pos()).put(choice.disc().color());
}

void BoardManager::reverse(Board &board, SquareCollection const &reversibles)
{
	std::for_each(reversibles.begin(), reversibles.end(), [&board](Square const &square)
	{
		if (board(square.pos()).empty()) {
			throw OthelloLogicException("there is no disc to reverse");
		}
		board(square.pos()).reverse();
	});
}

bool BoardManager::canPut(Board const &board, Square const &choice)
{
	try {
		return !getReversibles(board, choice).empty();
	}
	catch (OthelloLogicException &) {
		throw;
	}
}

bool BoardManager::canPut(Board const &board, Color const &color)
{
	return !getAvailables(board, color).empty();
}

SquareCollection BoardManager::getAvailables(Board const &board, Color const &color)
{
	SquareCollection availables;

	std::for_each(board.begin(), board.end(), [&availables, board, color](Square const &square)
	{
		Square choice(square.pos(), color);
		if (!getReversibles(board, choice).empty()) {
			availables.pushBack(choice);
		}
	});
	return availables;
}

SquareCollection BoardManager::getReversibles(Board const &board, Square const &choice)
{
	if (choice.empty()) {
		throw OthelloLogicException("no color selected");
	}
	Square const center = board.element(choice.pos());
	if ((!center.empty()) || center.out()) { return SquareCollection(); }

	SquareCollection reversibles;
	//dirの方向でひっくり返せる石の数を数える
	auto countReversibles = [board, choice] (Dir const &dir) -> int
	{
		Board::ConstIterator_t itr = board.iterator(choice.pos());
		if (itr.move(dir) == board.end()) { return 0; }

		int num = 0;
		if (!itr->empty()) {
			while (itr->disc().color() == choice.disc().color().reversed()) {
				if (itr.move(dir) == board.end()) { return 0; }
				if (itr->empty()) { return 0; }
				++num;
				if (itr->disc().color() == choice.disc().color()) { break; }
			}
		}
		return num;
	};
	//dirの方向でひっくり返せるnum個のマスのデータ(座標と色)をreversiblesのプッシュする
	auto addReversibles = [&reversibles, board, choice] (int const num, Dir const & dir)
	{
		Board::ConstIterator_t itr = board.iterator(choice.pos());
		for (int n = 0; n < num; ++n) {
			itr.move(dir);			
			reversibles.pushBack(Square(itr->pos(), choice.disc().color().reversed()));
		}
	};

	//8方向でcountReversiblesとaddReversiblesを実行する
	for (Dir dir = Dir::N; dir != Dir::NO_DIR; ++dir) {
		int const num = countReversibles(dir);
		addReversibles(num, dir);
	}
	return reversibles;
}

