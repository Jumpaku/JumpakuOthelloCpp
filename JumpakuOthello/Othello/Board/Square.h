#pragma once

#include<memory>
#include"../Utility/Pos.h"
#include"../Board/Disc.h"

namespace jo {

class Disc;

/**
*@brief
*オセロのマス<br>
*Othello square, cell
*@details
*Squareはオセロの盤(Board)上に8x8で並んだ正方形のマスである<br>
*実際には盤上に10x10で並べられ,(i == 0 || i == 9 || j == 0 || j == 9)のとき盤上に無いとされる<br>
*石を置いたり取り除いたり置いてある石をひっくり返したりできる<br>
*Square is othell cell shaped square. Squares are arranged 8x8 on the othello board.<br>
*Actualy Squares are arrangeed 10x10 on the board. if(i == 0 || i == 9 || j == 0 || j == 9), square is out of board.<br>
*You can put, reverse, unput a disc on the square.
*/
class Square final
{
private:
	typedef std::unique_ptr<Disc> Disc_p;
	Disc_p disc_m;
	Pos pos_m;
public:
	/**
	*デフォルトコンストラクタ<br>
	*default constructor.
	*/
	Square() = default;
	/**
	*Squareの位置を決める<br>
	*desides position.
	*@param pos Squareの位置<br> square position
	*/
	Square(Pos const &pos);
	/**
	*Squareの位置を決める<br>
	*desides position.
	*@param i 行番号<br> index of row
	*@param j 列番号<br> index of column
	*/
	Square(int const &i, int  const &j);
	/**
	*Squareの位置と置く石の色を決める<br>
	*desides position.
	*@param pos Squareの位置<br> square position
	*@param color 置く石の色<br> disc color to put
	*/
	Square(Pos const &pos, Color const &color);
	/**
	*Squareの位置を決める<br>
	*desides position.
	*@param i 行番号<br> index of row
	*@param j 列番号<br> index of column
	*@param color 置く石の色<br> disc color to put
	*/
	Square(int const &i, int const &j, Color const &color);
	/**
	*squareをコピーする<br>
	*copies square.
	*@param square コピー元のsquare<br> source square
	*/
	Square(Square const &square);
	/**
	*squareからムーブする<br>
	*moves square.
	*@param square ムーブ元のsquare<br> source square
	*/
	Square(Square &&) = default;
	/**
	*squareをコピー代入する<br>
	*copy assigns square.
	*@param square コピー元のSquare<br> source square
	*@return コピー代入されたオブジェクト(*this)<br> copy assigned object(*this)
	*/
	Square &operator=(Square const &square);
	/**
	*squareをムーブ代入する<br>
	*move assigns square.
	*@param square コピー元のSquare<br> source square
	*@return ムーブ代入されたオブジェクト(*this)<br> move assigned object(*this)
	*/
	Square &operator=(Square &&) = default;
private:
	static Disc_p make(Disc const &disc);
public:
	/**
	*square上の石をひっくり返す<br>
	*reverses the disc on the square.
	*@throws OthelloLogicException Square上に石がない時(empty() == true)<br>when has no disc  
	*/
	void reverse();
	/**
	*square上に石を置く<br>
	*既に別の石が置かれている場合新しい石で上書きされる<br>
	*puts disc.<br>
	*when other disc had already been put, old disc is overwriten with new disc.
	*@param disc
	*/
	void put(Disc const &disc);
	/**
	*石がsquare上にあればそれを取り除く<br>
	*unputs disc from the square if present.
	*/
	void unput();
	/**
	*@return square上の石<br> the disc on the square 
	*@throws OthelloLogicException Square上に石がない時(empty() == true) <br> if has no disc
	*/
	Disc disc()const;
	/**
	*@return square上に石がない場合真<br> true if has no disc
	*/
	bool empty()const;
	/**
	*squareが盤上の外にある時真を返す<br> returns true if out of the board
	*@return pos().out()
	*/
	bool out()const;
	/**
	*@return squareの位置<br> position of square
	*/
	Pos pos()const;
	/**
	*@return squareの行番号<br> row index of square
	*/
	int i()const;
	/**
	*@return squareの列番号<br> column index of square
	*/
	int j()const;
};

}
