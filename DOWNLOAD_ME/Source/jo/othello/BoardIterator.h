#pragma once

#include"Pos.h"
#include"Dir.h"
#include"BoardFrame.h"
#include<iterator>

namespace jo {

template<typename Element>
class BoardFrame;

/**
*@brief
*BoardFrameのイテレータ<br>
*Iterator of BoardFrame
*@details
*左から右へ,上から下へ盤上を移動する反復子<br>
*Iterates square on othello board.Order:from left to right, from top to bottom.  
*/
template<typename Element>
class BoardIterator
	: public std::iterator<std::forward_iterator_tag, Element>
{
protected:
	typedef BoardFrame<Element> Frame_t;
	Frame_t *board_m;
	Pos pos_m;
	bool isEnd_m = false;
public:
	/**
	*移動するボードと初期位置を設定する<br>
	*Sets initial position of iterator and board on which iterates.
	*@param board 移動するボード<br> board on which iterates
	*@param pos 初期位置<br> initial position
	*/
	BoardIterator(Frame_t *board, Pos pos)
		:board_m(board), pos_m(pos), isEnd_m(pos.out())
	{}
	/**
	*デフォルトコンストラクタ<br>
	*default constructor
	*/
	BoardIterator() = default;
	/**
	*コピーコンストラクタ<br>
	*copy constructor
	*@param iterator
	*/
	BoardIterator(BoardIterator const &) = default;
	/**
	*コピー代入演算子<br>
	*copy assignment operator
	*@param iterator
	*@return iterator
	*/
	BoardIterator &operator=(BoardIterator const &iterator) = default;
public:
	/**
	*現在指している要素を参照する<br>
	*References current element.
	*@return 要素の参照<br> reference of element
	*@throws OthelloLogicException 正しい要素を指していないとき<br>when points invalid element.
	*/
	Element &operator*()const
	{
		if(isEnd_m || board_m == nullptr) {
			throw OthelloLogicException("access to invalid iterator");
		}
		return board_m->element(pos_m);
	}
	/**
	*現在指している要素のメンバにアクセスする.<br>
	*Accesses to current element's member. 
	*@return &(operator*())
	*@throws OthelloLogicException 正しい要素を指していないとき<br> when points invalid element.
	*/
	Element *operator->()const
	{
		return &(operator*());
	}
	/**
	*@param itr
	*@return itrと等しいとき真<br> true if equals itr
	*/
	bool operator==(BoardIterator const &itr)const
	{
		return isEnd_m == itr.isEnd_m &&
			board_m == itr.board_m &&
			pos_m == itr.pos_m;
	}
	/**
	*@param itr
	*@return !(*this == itr)
	*/
	bool operator!=(BoardIterator const &itr)const
	{
		return !(*this == itr);
	}

	/**
	*次の要素に進む<br>
	*Goes to next element
	*/
	void next()
	{
		if(isEnd_m || board_m == nullptr) {
			throw OthelloLogicException("access to invalid iterator");
		}
		if(pos_m == Pos{ 8, 8 }) {
			pos_m = { 8, 9 };
			isEnd_m = true;
		}
		else if(pos_m.j() == 8) {
			pos_m.move(Dir::S);
			pos_m.j(1);
		}
		else {
			pos_m.move(Dir::E);
		}
	}
	/**
	*dirの方向に進む<br>
	*Goes in the direction dir.
	*@param dir 進む方向<br> direction in which to go
	*/
	BoardIterator &move(Dir const &dir)
	{
		if(isEnd_m || board_m == nullptr) {
			throw OthelloLogicException("access to invalid iterator");
		}
		pos_m.move(dir);
		if(board_m->element(pos_m).out()) {
			isEnd_m = true;
			pos_m = { 8, 9 };
		}
		return *this;
	}

	/**
	*次の要素に進む<br>
	*Goes to next element
	*@return 進んだ後のイテレータ<br> iterator after move.
	*/
	BoardIterator &operator++()
	{
		next();
		return *this;
	}
	/**
	*次の要素に進む<br>
	*Goes to next element
	*@return 進む前のイテレータ<br> iterator before move.
	*/
	BoardIterator operator++(int)
	{
		BoardIterator tmp = *this;
		next();
		return tmp;
	}
	/*
	*ムーブコンストラクタ<br>
	*move constructor
	*@param iterator
	*
	BoardIterator(BoardIterator &&) = default;
	*
	**
	*ムーブ代入演算子<br>
	*move assignment operator
	*@param iterator
	*@return iterator
	*
	BoardIterator &operator=(BoardIterator &&iterator) = default;
	*/
};

}
