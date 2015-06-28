#pragma once

#include "BoardFrame.h"

#include"Square.h"

namespace jo{

/**
*@brief
*オセロのボード<br>
*Othello board
*@details
*オセロのボード<br>
*BoardFrameのテンプレート引数にSquareを代入したクラスを継承している<br>
*コンストラクタで中央の4マスに白と黒の石を置く<br>
*A othello board.<br>
*Inherits BoardFrame<Square>.<br>
*Constructor puts discs on the center 4 squares of the board.
*/
class Board : public BoardFrame<Square>
{
public:
	/**
	*中央の4マスに白と黒の石を置く<br>
	*Puts discs on the center 4 squares of the board.
	*/
	Board();
};

}

#include"Disc.h"
