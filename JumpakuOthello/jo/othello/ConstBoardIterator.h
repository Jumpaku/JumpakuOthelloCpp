#pragma once

#include"Pos.h"
#include"BoardFrame.h"
#include"BoardIterator.h"

namespace jo {

template<typename Element>
class BoardFrame;

/**
*@brief
*BoardFrame�̃R���X�g�C�e���[�^<br>
*Const iterator of BoardFrame
*@details
*������E��,�ォ�牺�֔Տ���ړ����锽���q<br>
*�v�f��ύX���邱�Ƃ��ł��Ȃ�<br>
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
	*�ړ�����{�[�h�Ə����ʒu��ݒ肷��<br>
	*Sets initial position of iterator and board on which iterates.
	*@param board �ړ�����{�[�h<br> board on which iterates
	*@param pos �����ʒu<br> initial position
	*/
	ConstBoardIterator(Frame_t const *board, Pos pos)
		:Base_t(const_cast<BoardFrame<Element> *>(board), pos)
	{}
public:
	/**
	*���ݎw���Ă���v�f���Q�Ƃ���<br>
	*References current element.
	*@return �v�f�̕s�ςȎQ��<br> const reference of element
	*@throws OthelloLogicException �������v�f���w���Ă��Ȃ��Ƃ�<br>when points invalid element.
	*/
	Element const&operator*()const
	{
		if(isEnd_m || board_m == nullptr) {
			throw OthelloLogicException("access to invalid iterator");
		}
		return board_m->element(pos_m);
	}
	/**
	*���ݎw���Ă���v�f�̃����o�ɃA�N�Z�X����.<br>
	*�v�f�̕ύX�͂ł��Ȃ�<br>
	*Accesses to current element's member.<br>
	*Cannot change element.
	*@return &(operator*())
	*@throws OthelloLogicException �������v�f���w���Ă��Ȃ��Ƃ�<br> when points invalid element.
	*/
	Element const*operator->()const
	{
		return &(operator*());
	}
	/**
	*dir�̕����ɐi��<br>
	*Goes in the direction dir.
	*@param dir �i�ޕ���<br> direction in which to go
	*/
	ConstBoardIterator &move(Dir dir)
	{
		this->Base_t::move(dir);
		return *this;
	}
	/**
	*���̗v�f�ɐi��<br>
	*Goes to next element
	*@return �i�񂾌�̃C�e���[�^<br> iterator after move.
	*/
	ConstBoardIterator &operator++()
	{
		next();
		return *this;
	}
	/**
	*���̗v�f�ɐi��<br>
	*Goes to next element
	*@return �i�ޑO�̃C�e���[�^<br> iterator before move.
	*/
	ConstBoardIterator &operator++(int)
	{
		ConstBoardIterator tmp = *this;
		next();
		return tmp;
	}
};

}
