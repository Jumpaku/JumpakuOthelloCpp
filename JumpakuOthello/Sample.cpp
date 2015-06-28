#include"JumpakuOthello.h"
#include<random>
#include<iostream>

void printBoard(jo::Board const &board)
{
	auto printDisc = [board] (int i, int j) -> std::string
	{
		if (board(i, j).empty()) {
			return "   ";
		}
		else {
			return board(i, j).disc().color() == jo::Color::dark() ?
				" X " : " O ";
		}
	};
	std::cout <<
		"-------------------------------------  \n"
		"|   | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 |  \n"
		"-------------------------------------  \n";
	for (int i = 1; i <= 8; ++i) {
		std::cout << "| " << i << " |";
		for (int j = 1; j <= 8; ++j) {
			std::cout << printDisc(i, j) << "|";
		}
		std::cout << "\n"
			"-------------------------------------  \n";
	}
}

class RandomStrategy : public jo::Strategy
{
public:
	jo::Square think(jo::Othello const &othello)override
	{
		jo::SquareCollection availables = othello.getAvailables();
		int random = std::uniform_int_distribution<>(0, availables.size() - 1)(std::mt19937(std::random_device()()));
		jo::SquareCollection::ConstIterator_t choice = availables.begin();
		std::advance(choice, random);

		return *choice;
	}
};

int main()
{	
	jo::Othello othello;
	jo::Color player = jo::randomColor();

	while (!othello.hasFinished()) {
		printBoard(othello.board());
		if (othello.turnColor() == player) {
			int i, j;
			std::cout << "your turn -->";
			scanf_s("%1d%1d", &i, &j);
			try {
				othello.playTurn(jo::Square(i, j, player));
			}
			catch (jo::OthelloLogicException &e) {
				std::cout << e.what() << "\n";
				continue;
			}
		}
		else {
			othello.playTurn(std::make_shared<RandomStrategy>());
		}
	}

	std::cout << "DARK " << othello.discCount(jo::Color::dark()) << " : "
		<< "LIGHT " << othello.discCount(jo::Color::light()) << "\n";
}
