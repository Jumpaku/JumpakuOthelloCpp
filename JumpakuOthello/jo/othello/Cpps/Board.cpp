#include "../Board.h"

#include"../Color.h"
#include"../Disc.h"

using namespace jo;

Board::Board()
{
	for(int i = 0; i < 10; ++i) {
		for(int j = 0; j < 10; ++j) {
			board_m[i][j] = Square(i, j);
		}
	}
	board_m[4][4].put(Color::light());
	board_m[5][5].put(Color::light());
	board_m[4][5].put(Color::dark());
	board_m[5][4].put(Color::dark());
}
