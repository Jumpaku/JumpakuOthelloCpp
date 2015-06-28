#pragma once

#include"Pos.h"
#include"BoardFrame.h"
#include"BoardIterator.h"

namespace jo {

template<typename Element>
class BoardFrame;

/**
*@brief
*BoardFrameのコンストイテレータ<br>
*Const iterator of BoardFrame
*@details
*左から右へ,上から下へ盤上を移動する反復子<br>
*要素を変更することができない<br>
*Iterates square on othello board.<br>
*Order:from left to right, from top to bottom.<br>
*Cannot change element.
*/
template<typename Element>
class ConstBoardIterator
	: public BoardIterator<Element>
{
private:
	typedef BoardIterator<Element> Base_t;
public:
	/**
	*移動するボードと初期位置を設定する<br>
	*Sets initial position of iterator and board on which iterates.
	*@param board 移動するボード<br> board on which iterates
	*@param pos 初期位置<br> initial position
	*/
	ConstBoardIterator(Frame_t const *board, Pos pos)
		:Base_t(const_cast<BoardFrame<Element> *>(board), pos)
	{}
public:
	/**
	*現在指している要素を参照する<br>
	*References current element.
	*@return 要素の不変な参照<br> const reference of element
	*@throws OthelloLogicException 正しい要素を指していないとき<br>when points invalid element.
	*/
	Element const&operator*()const
	{
		if(isEnd_m || board_m == nullptr) {
			throw OthelloLogicException("access to invalid iterator");
		}
		return board_m->element(pos_m);
	}
	/**
	*現在指している要素のメンバにアクセスする.<br>
	*要素の変更はできない<br>
	*Accesses to current element's member.<br>
	*Cannot change element.
	*@return &(operator*())
	*@throws OthelloLogicException 正しい要素を指していないとき<br> when points invalid element.
	*/
	Element const*operator->()const
	{
		return &(operator*());
	}
	/**
	*dirの方向に進む<br>
	*Goes in the direction dir.
	*@param dir 進む方向<br> direction in which to go
	*/
	ConstBoardIterator &move(Dir dir)
	{
		this->Base_t::move(dir);
		return *this;
	}
	/**
	*次の要素に進む<br>
	*Goes to next element
	*@return 進んだ後のイテレータ<br> iterator after move.
	*/
	ConstBoardIterator &operator++()
	{
		next();
		return *this;
	}
	/**
	*次の要素に進む<br>
	*Goes to next element
	*@return 進む前のイテレータ<br> iterator before move.
	*/
	ConstBoardIterator &operator++(int)
	{
		ConstBoardIterator tmp = *this;
		next();
		return tmp;
	}
};

}
