#pragma once

#include"../Board/Board.h"

namespace jo {

class Square;
class SquareCollection;
class Color;

/**
*@brief 
*ボードの管理をする<br>
*Manages othello board
*@details
*ボードに正しく石を置いたり正しく石を裏返したりする<br>
*管理するボードはメンバとして持つことも,外部のボードをクラスメソッドで操作することもできる.<br>
*Puts discs correctly and recerses discs correctly.<br>
*Can manage board as member or using static methods.
*/
class BoardManager
{
	Board board_m;
public:
	/**
	*ボードマネージャーが持つボードを設定する<br>
	*Sets board which board manager has
	*@param board 設定するボード<br> board to set
	*/
	void setBoard(Board const &board);
	/**
	*ボードマネージャーが持つボードを取得する<br>
	*Gets board which board manager has
	*@return 取得するボード<br> board to get
	*/
	Board getBoard()const;

	/**
	*choiceのマスにchoiceが持つ石と同じ色の石を置く<br>
	*Puts a disc which has same color as choice has on the square choice
	*@param choice 石を置くマス<br> the square where to put
	*@throws OthelloLogicException choiceのマスにchoiceが持つ石と同じ石を置けないとき<br> when connot put disc which has same color as choice has on the square choice
	*/
	void put(Square const &choice);
	/**
	*reversiblesのマス全ての石をひっくり返す<br>
	*getReversiblesで得たマスはどれもその時点でひっくり返すことができるのでこれを利用すると良い<br>
	*Reverses discs in reversibles.<br>
	*Each square from getReversibles has disc which can be reversed, so, please use getReversibles.
	*@param reversibles ひっくり返す石の集まり<br> discs to reverse
	*@throws OthelloLogicException マスに石がないとき<br> when there was no disc to reverse
	*/
	void reverse(SquareCollection const &reversibles);
	/**
	*choiceのマスにchoiceの石と同じ色の石を置けるとき真を返す<br>
	*Returns true if can put a disc which has same color as choice has on the square choice
	*@param choice 置く色の石を持った選択されたマス<br> choice has position and color to put
	*@return choiceに石を置けるとき真<br> true if can put a disc
	*@throws OthelloLogicException choiceが石を持っていないとき<br> when choice has no disc
	*/
	bool canPut(Square const &choice)const;
	/**
	*colorの石を置く場所があるとき真を返す<br>
	*Returns true if can put a disc has the color somewhare. 
	*@param color 置こうとする石の色<br> color of disc to put
	*@return colorの石を置けるとき真<br> true if can put a disc
	*/
	bool canPut(Color const &color)const;
	/**
	*colorの石を置ける全ての石の集まりを取得する<br>
	*Gets collection of squares where can put discs which has the color.
	*@param color 置きたい石の色<br> color of disc to put
	*@return 石を置けるマスの集まり<br> available square collection
	*/
	SquareCollection getAvailables(Color const &color)const;
	/**
	*choiceのマスにchoiceの石と同じ色の石を置いた時にひっくり返すことのできる石があるマスの集まりを取得する<br>
	*Gets collection of squares where can be reversed when put a disc on the square of choice.
	*@param choice 選択されたマス<br> selected square
	*@return ひっくり返すことのできる石があるマスの集まり<br> reversible square collection
	*@throws OthelloLogicException 置く石の色が指定されていないとき<br> when no color selected
	*/
	SquareCollection getReversibles(Square const &choice)const;

	/**
	*choiceのマスにchoiceが持つ石と同じ色の石を置く<br>
	*Puts a disc which has same color as choice has on the square choice
	*@param board 石を置くボード<br> board where put a disc
	*@param choice 石を置くマス<br> the square where to put
	*@throws OthelloLogicException choiceのマスにchoiceが持つ石と同じ石を置けないとき<br> when cannot put disc which has same color as choice has on the square choice
	*/
	static void put(Board &board, Square const &choice);
	/**
	*reversiblesのマス全ての石をひっくり返す<br>
	*getReversiblesで得たマスはどれもその時点でひっくり返すことができるのでこれを利用すると良い<br>
	*Reverses discs in reversibles.<br>
	*Each square from getReversibles has disc which can be reversed, so, please use getReversibles.
	*@param board 石を置くボード<br> board where put a disc
	*@param reversibles ひっくり返す石の集まり<br> discs to reverse
	*@throws OthelloLogicException マスに石がないとき<br> when there was no disc to reverse
	*/
	static void reverse(Board &board, SquareCollection const &reversibles);
	/**
	*choiceのマスにchoiceの石と同じ色の石を置けるとき真を返す<br>
	*Returns true if can put a disc which has same color as choice has on the square choice
	*@param board 石を置くボード<br> board where put a disc
	*@param choice 置く色の石を持った選択されたマス<br> choice has position and color to put
	*@return choiceに石を置けるとき真<br> true if can put a disc
	*@throws OthelloLogicException choiceが石を持っていないとき<br> when choice has no disc
	*/
	static bool canPut(Board const &board, Square const &choice);
	/**
	*colorの石を置く場所があるとき真を返す<br>
	*Returns true if can put a disc has the color somewhare.
	*@param board 石を置くボード<br> board where put a disc
	*@param color 置こうとする石の色<br> color of disc to put
	*@return colorの石を置けるとき真<br> true if can put a disc
	*/
	static bool canPut(Board const &board, Color const &color);
	/**
	*colorの石を置ける全ての石の集まりを取得する<br>
	*Gets collection of squares where can put discs which has the color.
	*@param board 石を置くボード<br> board where put a disc
	*@param color 置きたい石の色<br> color of disc to put
	*@return 石を置けるマスの集まり<br> available square collection
	*/
	static SquareCollection getAvailables(Board const &board, Color const &color);
	/**
	*choiceのマスにchoiceの石と同じ色の石を置いた時にひっくり返すことのできる石があるマスの集まりを取得する<br>
	*Gets collection of squares where can be reversed when put a disc on the square of choice.
	*@param board 石を置くボード<br> board where put a disc
	*@param choice 選択されたマス<br> selected square
	*@return ひっくり返すことのできる石があるマスの集まり<br> reversible square collection
	*@throws OthelloLogicException 置く石の色が指定されていないとき<br> when no color selected
	*/
	static SquareCollection getReversibles(Board const &board, Square const &choice);
};

}
