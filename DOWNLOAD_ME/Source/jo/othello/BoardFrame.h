#pragma once

#include<array>
#include"Pos.h"
#include"BoardIterator.h"
#include"ConstBoardIterator.h"

namespace jo {

template<typename Element>
class BoardIterator;

/**
*@brief
*オセロボードのデータ構造の骨格<br>
*Frame of othello board data structure
*@details
*オセロのボードのデータ構造(64=8x8個)の骨格を提供するクラステンプレート<br>
*実装では100=10x10の要素が2次元配列でまとめられている<br>
*イテレータやランダムアクセスを利用できる.<br>
*Gives Othello Board data structure.<br>
*In implementation, contains 2d array of 100=10x10 elements.<br>
*you can use iterator or random access.
*/
template<typename Element>
class BoardFrame
{
public:
	/**
	*イテレータの型<br>
	*Type of iterator.<br>
	*BoardIterator<Element>
	*/
	typedef BoardIterator<Element> Iterator_t;
	/**
	*コンストイテレータの型 イテレータの保持する値が不変である<br>
	*Type of const iterator. Iterator has const value.<br>
	*ConstBoardIterator<Element>
	*/
	typedef ConstBoardIterator<Element> ConstIterator_t;
protected:
	/**
	*2次元配列の型<br>
	*Type of 2d array.<br>
	*std::array<std::array<Element, 10>, 10>
	*/
	typedef std::array<std::array<Element, 10>, 10> Array2_t;
	/**
	*2次元配列の実体<br>
	*Instance of 2d array.
	*/
	Array2_t board_m;
public:
	/**
	*デストラクタ
	*destructor
	*/
	virtual ~BoardFrame() = default;
public:
	/**
	*@param pos イテレータが指す要素の位置<br> position of element which iterator points
	*@return element (pos)のイテレータ<br> iterator of element (pos)
	*/
	Iterator_t iterator(Pos const &pos)
	{
		return Iterator_t(this, pos);
	}
	/**
	*@param i 行番号<br> index of row
	*@param j 列番号<br> index of column
	*@return iterator (Pos (i, j))
	*/
	Iterator_t iterator(int const &i, int const &j)
	{
		return iterator(Pos(i, j));
	}
	/**
	*データ構造の先頭の要素を指すイテレータを返す<br>
	*Returns iterator which points first element
	*@return iterator (1,1)
	*/
	Iterator_t begin()
	{
		return iterator(1, 1);
	}
	/**
	*データ構造の末尾の次の要素を指すイテレータを返す<br>
	*Returns iterator which points next of last element
	*@return iterator(8,9)
	*/
	Iterator_t end()
	{
		return iterator(8, 9);
	}
	
	/**
	*@param pos コンストイテレータが指す要素の位置<br> position of element which const iterator points
	*@return element (pos)のコンストイテレータ<br> const iterator of element (pos)
	*/
	ConstIterator_t iterator(Pos const &pos)const
	{
		return ConstIterator_t(this, pos);
	}
	/**
	*@param i 行番号<br> index of row
	*@param j 列番号<br> index of column
	*@return iterator (Pos (i, j))
	*/
	ConstIterator_t iterator(int const &i, int const &j)const
	{
		return iterator(Pos(i, j ));
	}
	/**
	*データ構造の先頭の要素を指すコンストイテレータを返す<br>
	*Returns const iterator which points first element
	*@return iterator (1,1)
	*/
	ConstIterator_t begin()const
	{
		return iterator(Pos(1, 1 ));
	}
	/**
	*データ構造の末尾の次の要素を指すコンストイテレータを返す<br>
	*Returns const iterator which points next of last element
	*@return iterator(8,9)
	*/
	ConstIterator_t end()const
	{
		return iterator(Pos(8, 9));
	}
	
	/**
	*@param i 行番号<br> index of row
	*@param j 列番号<br> index of column
	*@return i行j列の要素への参照を返す<br> reference of element row i, column j
	*@throws OthelloLogicException iかjがボードの範囲外の時<br> when i or j are out of bound of the board<br> !(0 <= i && i <= 9 && 0 <= j && j <= 9)
	*/
	Element &element(int const &i, int const &j)
	{
		if (!(0 <= i && i <= 9 && 0 <= j && j <= 9)) {
			throw OthelloLogicException(
				"must be 0 <= i && i <= 9 && 0 <= j && j <= 9");
		}
		return board_m[i][j];
	}
	/**
	*@param pos 盤上の位置<br> position on the board 
	*@return element(pos.i(), pos.j()) 
	*@throws OthelloLogicException iかjがボードの範囲外の時<br> when i or j are out of bound of the board<br> !(0 <= i && i <= 9 && 0 <= j && j <= 9)
	*/
	Element &element(Pos const &pos)
	{
		return element(pos.i(), pos.j());
	}
	/**
	*@param pos 盤上の位置<br> position on the board
	*@return element(pos.i(), pos.j())
	*@throws OthelloLogicException iかjがボードの範囲外の時<br> when i or j are out of bound of the board<br> !(0 <= i && i <= 9 && 0 <= j && j <= 9)
	*/
	Element const &element(Pos const &pos)const
	{
		return element(pos.i(), pos.j());
	}
	/**
	*@param i 行番号<br>index of row
	*@param j 列番号<br>index of column
	*@return i行j列の要素への不変な参照を返す<br> const reference of element row i, column j
	*@throws OthelloLogicException iかjがボードの範囲外の時<br> when i or j are out of bound of the board<br> !(0 <= i && i <= 9 && 0 <= j && j <= 9)
	*/
	Element const &element(int const &i, int const &j)const
	{
		if(!(0 <= i && i <= 9 && 0 <= j && j <= 9)) {
			throw OthelloLogicException(
				"must be 0 <= i && i <= 9 && 0 <= j && j <= 9");
		}
		return board_m[i][j];
	}
	/**
	*@param pos 盤上の位置<br> position on the board
	*@return element(pos)
	*@throws OthelloLogicException iかjがボードの範囲外の時<br> when i or j are out of bound of the board<br> !(0 <= i && i <= 9 && 0 <= j && j <= 9)
	*/
	Element &operator()(Pos const &pos)
	{
		return element(pos);
	}
	/**
	*@param i 行番号<br> index of row
	*@param j 列番号<br> index of column
	*@return element(i, j)
	*@throws OthelloLogicException iかjがボードの範囲外の時<br> when i or j are out of bound of the board<br> !(0 <= i && i <= 9 && 0 <= j && j <= 9)
	*/
	Element &operator()(int const &i, int const &j)
	{
		return element(i, j);
	}
	/**
	*@param pos 盤上の位置<br> position on the board 
	*@return element(pos)
	*@throws OthelloLogicException iかjがボードの範囲外の時<br> when i or j are out of bound of the board<br> !(0 <= i && i <= 9 && 0 <= j && j <= 9)
	*/
	Element const&operator()(Pos const &pos)const
	{
		return element(pos);
	}
	/**
	*@param i 行番号<br> index of row
	*@param j 列番号<br> index of column
	*@return element(i, j)
	*@throws OthelloLogicException iかjがボードの範囲外の時<br> when i or j are out of bound of the board<br> !(0 <= i && i <= 9 && 0 <= j && j <= 9)
	*/
	Element const&operator()(int const &i, int const &j)const
	{
		return element(i, j);
	}
};

}
