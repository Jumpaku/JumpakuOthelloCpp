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
*�I�Z���{�[�h�̃f�[�^�\���̍��i<br>
*Frame of othello board data structure
*@details
*�I�Z���̃{�[�h�̃f�[�^�\��(64=8x8��)�̍��i��񋟂���N���X�e���v���[�g<br>
*�����ł�100=10x10�̗v�f��2�����z��ł܂Ƃ߂��Ă���<br>
*�C�e���[�^�⃉���_���A�N�Z�X�𗘗p�ł���.<br>
*Gives Othello Board data structure.<br>
*In implementation, contains 2d array of 100=10x10 elements.<br>
*you can use iterator or random access.
*/
template<typename Element>
class BoardFrame
{
public:
	/**
	*�C�e���[�^�̌^<br>
	*Type of iterator.<br>
	*BoardIterator<Element>
	*/
	typedef BoardIterator<Element> Iterator_t;
	/**
	*�R���X�g�C�e���[�^�̌^ �C�e���[�^�̕ێ�����l���s�ςł���<br>
	*Type of const iterator. Iterator has const value.<br>
	*ConstBoardIterator<Element>
	*/
	typedef ConstBoardIterator<Element> ConstIterator_t;
protected:
	/**
	*2�����z��̌^<br>
	*Type of 2d array.<br>
	*std::array<std::array<Element, 10>, 10>
	*/
	typedef std::array<std::array<Element, 10>, 10> Array2_t;
	/**
	*2�����z��̎���<br>
	*Instance of 2d array.
	*/
	Array2_t board_m;
public:
	/**
	*�f�X�g���N�^
	*destructor
	*/
	virtual ~BoardFrame() = default;
public:
	/**
	*@param pos �C�e���[�^���w���v�f�̈ʒu<br> position of element which iterator points
	*@return element (pos)�̃C�e���[�^<br> iterator of element (pos)
	*/
	Iterator_t iterator(Pos const &pos)
	{
		return Iterator_t(this, pos);
	}
	/**
	*@param i �s�ԍ�<br> index of row
	*@param j ��ԍ�<br> index of column
	*@return iterator (Pos (i, j))
	*/
	Iterator_t iterator(int const &i, int const &j)
	{
		return iterator(Pos(i, j));
	}
	/**
	*�f�[�^�\���̐擪�̗v�f���w���C�e���[�^��Ԃ�<br>
	*Returns iterator which points first element
	*@return iterator (1,1)
	*/
	Iterator_t begin()
	{
		return iterator(1, 1);
	}
	/**
	*�f�[�^�\���̖����̎��̗v�f���w���C�e���[�^��Ԃ�<br>
	*Returns iterator which points next of last element
	*@return iterator(8,9)
	*/
	Iterator_t end()
	{
		return iterator(8, 9);
	}
	
	/**
	*@param pos �R���X�g�C�e���[�^���w���v�f�̈ʒu<br> position of element which const iterator points
	*@return element (pos)�̃R���X�g�C�e���[�^<br> const iterator of element (pos)
	*/
	ConstIterator_t iterator(Pos const &pos)const
	{
		return ConstIterator_t(this, pos);
	}
	/**
	*@param i �s�ԍ�<br> index of row
	*@param j ��ԍ�<br> index of column
	*@return iterator (Pos (i, j))
	*/
	ConstIterator_t iterator(int const &i, int const &j)const
	{
		return iterator(Pos(i, j ));
	}
	/**
	*�f�[�^�\���̐擪�̗v�f���w���R���X�g�C�e���[�^��Ԃ�<br>
	*Returns const iterator which points first element
	*@return iterator (1,1)
	*/
	ConstIterator_t begin()const
	{
		return iterator(Pos(1, 1 ));
	}
	/**
	*�f�[�^�\���̖����̎��̗v�f���w���R���X�g�C�e���[�^��Ԃ�<br>
	*Returns const iterator which points next of last element
	*@return iterator(8,9)
	*/
	ConstIterator_t end()const
	{
		return iterator(Pos(8, 9));
	}
	
	/**
	*@param i �s�ԍ�<br> index of row
	*@param j ��ԍ�<br> index of column
	*@return i�sj��̗v�f�ւ̎Q�Ƃ�Ԃ�<br> reference of element row i, column j
	*@throws OthelloLogicException i��j���{�[�h�͈̔͊O�̎�<br> when i or j are out of bound of the board<br> !(0 <= i && i <= 9 && 0 <= j && j <= 9)
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
	*@param pos �Տ�̈ʒu<br> position on the board 
	*@return element(pos.i(), pos.j()) 
	*@throws OthelloLogicException i��j���{�[�h�͈̔͊O�̎�<br> when i or j are out of bound of the board<br> !(0 <= i && i <= 9 && 0 <= j && j <= 9)
	*/
	Element &element(Pos const &pos)
	{
		return element(pos.i(), pos.j());
	}
	/**
	*@param pos �Տ�̈ʒu<br> position on the board
	*@return element(pos.i(), pos.j())
	*@throws OthelloLogicException i��j���{�[�h�͈̔͊O�̎�<br> when i or j are out of bound of the board<br> !(0 <= i && i <= 9 && 0 <= j && j <= 9)
	*/
	Element const &element(Pos const &pos)const
	{
		return element(pos.i(), pos.j());
	}
	/**
	*@param i �s�ԍ�<br>index of row
	*@param j ��ԍ�<br>index of column
	*@return i�sj��̗v�f�ւ̕s�ςȎQ�Ƃ�Ԃ�<br> const reference of element row i, column j
	*@throws OthelloLogicException i��j���{�[�h�͈̔͊O�̎�<br> when i or j are out of bound of the board<br> !(0 <= i && i <= 9 && 0 <= j && j <= 9)
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
	*@param pos �Տ�̈ʒu<br> position on the board
	*@return element(pos)
	*@throws OthelloLogicException i��j���{�[�h�͈̔͊O�̎�<br> when i or j are out of bound of the board<br> !(0 <= i && i <= 9 && 0 <= j && j <= 9)
	*/
	Element &operator()(Pos const &pos)
	{
		return element(pos);
	}
	/**
	*@param i �s�ԍ�<br> index of row
	*@param j ��ԍ�<br> index of column
	*@return element(i, j)
	*@throws OthelloLogicException i��j���{�[�h�͈̔͊O�̎�<br> when i or j are out of bound of the board<br> !(0 <= i && i <= 9 && 0 <= j && j <= 9)
	*/
	Element &operator()(int const &i, int const &j)
	{
		return element(i, j);
	}
	/**
	*@param pos �Տ�̈ʒu<br> position on the board 
	*@return element(pos)
	*@throws OthelloLogicException i��j���{�[�h�͈̔͊O�̎�<br> when i or j are out of bound of the board<br> !(0 <= i && i <= 9 && 0 <= j && j <= 9)
	*/
	Element const&operator()(Pos const &pos)const
	{
		return element(pos);
	}
	/**
	*@param i �s�ԍ�<br> index of row
	*@param j ��ԍ�<br> index of column
	*@return element(i, j)
	*@throws OthelloLogicException i��j���{�[�h�͈̔͊O�̎�<br> when i or j are out of bound of the board<br> !(0 <= i && i <= 9 && 0 <= j && j <= 9)
	*/
	Element const&operator()(int const &i, int const &j)const
	{
		return element(i, j);
	}
};

}
