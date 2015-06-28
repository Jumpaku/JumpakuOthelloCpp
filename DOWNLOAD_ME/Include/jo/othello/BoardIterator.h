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
*BoardFrame�̃C�e���[�^<br>
*Iterator of BoardFrame
*@details
*������E��,�ォ�牺�֔Տ���ړ����锽���q<br>
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
	*�ړ�����{�[�h�Ə����ʒu��ݒ肷��<br>
	*Sets initial position of iterator and board on which iterates.
	*@param board �ړ�����{�[�h<br> board on which iterates
	*@param pos �����ʒu<br> initial position
	*/
	BoardIterator(Frame_t *board, Pos pos)
		:board_m(board), pos_m(pos), isEnd_m(pos.out())
	{}
	/**
	*�f�t�H���g�R���X�g���N�^<br>
	*default constructor
	*/
	BoardIterator() = default;
	/**
	*�R�s�[�R���X�g���N�^<br>
	*copy constructor
	*@param iterator
	*/
	BoardIterator(BoardIterator const &) = default;
	/**
	*�R�s�[������Z�q<br>
	*copy assignment operator
	*@param iterator
	*@return iterator
	*/
	BoardIterator &operator=(BoardIterator const &iterator) = default;
public:
	/**
	*���ݎw���Ă���v�f���Q�Ƃ���<br>
	*References current element.
	*@return �v�f�̎Q��<br> reference of element
	*@throws OthelloLogicException �������v�f���w���Ă��Ȃ��Ƃ�<br>when points invalid element.
	*/
	Element &operator*()const
	{
		if(isEnd_m || board_m == nullptr) {
			throw OthelloLogicException("access to invalid iterator");
		}
		return board_m->element(pos_m);
	}
	/**
	*���ݎw���Ă���v�f�̃����o�ɃA�N�Z�X����.<br>
	*Accesses to current element's member. 
	*@return &(operator*())
	*@throws OthelloLogicException �������v�f���w���Ă��Ȃ��Ƃ�<br> when points invalid element.
	*/
	Element *operator->()const
	{
		return &(operator*());
	}
	/**
	*@param itr
	*@return itr�Ɠ������Ƃ��^<br> true if equals itr
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
	*���̗v�f�ɐi��<br>
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
	*dir�̕����ɐi��<br>
	*Goes in the direction dir.
	*@param dir �i�ޕ���<br> direction in which to go
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
	*���̗v�f�ɐi��<br>
	*Goes to next element
	*@return �i�񂾌�̃C�e���[�^<br> iterator after move.
	*/
	BoardIterator &operator++()
	{
		next();
		return *this;
	}
	/**
	*���̗v�f�ɐi��<br>
	*Goes to next element
	*@return �i�ޑO�̃C�e���[�^<br> iterator before move.
	*/
	BoardIterator operator++(int)
	{
		BoardIterator tmp = *this;
		next();
		return tmp;
	}
	/*
	*���[�u�R���X�g���N�^<br>
	*move constructor
	*@param iterator
	*
	BoardIterator(BoardIterator &&) = default;
	*
	**
	*���[�u������Z�q<br>
	*move assignment operator
	*@param iterator
	*@return iterator
	*
	BoardIterator &operator=(BoardIterator &&iterator) = default;
	*/
};

}
