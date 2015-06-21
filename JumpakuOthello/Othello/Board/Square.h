#pragma once

#include<memory>
#include"../Utility/Pos.h"
#include"../Board/Disc.h"

namespace jo {

class Disc;

/**
*@brief
*�I�Z���̃}�X<br>
*Othello square, cell
*@details
*Square�̓I�Z���̔�(Board)���8x8�ŕ��񂾐����`�̃}�X�ł���<br>
*���ۂɂ͔Տ��10x10�ŕ��ׂ��,(i == 0 || i == 9 || j == 0 || j == 9)�̂Ƃ��Տ�ɖ����Ƃ����<br>
*�΂�u�������菜������u���Ă���΂��Ђ�����Ԃ�����ł���<br>
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
	*�f�t�H���g�R���X�g���N�^<br>
	*default constructor.
	*/
	Square() = default;
	/**
	*Square�̈ʒu�����߂�<br>
	*desides position.
	*@param pos Square�̈ʒu<br> square position
	*/
	Square(Pos const &pos);
	/**
	*Square�̈ʒu�����߂�<br>
	*desides position.
	*@param i �s�ԍ�<br> index of row
	*@param j ��ԍ�<br> index of column
	*/
	Square(int const &i, int  const &j);
	/**
	*Square�̈ʒu�ƒu���΂̐F�����߂�<br>
	*desides position.
	*@param pos Square�̈ʒu<br> square position
	*@param color �u���΂̐F<br> disc color to put
	*/
	Square(Pos const &pos, Color const &color);
	/**
	*Square�̈ʒu�����߂�<br>
	*desides position.
	*@param i �s�ԍ�<br> index of row
	*@param j ��ԍ�<br> index of column
	*@param color �u���΂̐F<br> disc color to put
	*/
	Square(int const &i, int const &j, Color const &color);
	/**
	*square���R�s�[����<br>
	*copies square.
	*@param square �R�s�[����square<br> source square
	*/
	Square(Square const &square);
	/**
	*square���烀�[�u����<br>
	*moves square.
	*@param square ���[�u����square<br> source square
	*/
	Square(Square &&) = default;
	/**
	*square���R�s�[�������<br>
	*copy assigns square.
	*@param square �R�s�[����Square<br> source square
	*@return �R�s�[������ꂽ�I�u�W�F�N�g(*this)<br> copy assigned object(*this)
	*/
	Square &operator=(Square const &square);
	/**
	*square�����[�u�������<br>
	*move assigns square.
	*@param square �R�s�[����Square<br> source square
	*@return ���[�u������ꂽ�I�u�W�F�N�g(*this)<br> move assigned object(*this)
	*/
	Square &operator=(Square &&) = default;
private:
	static Disc_p make(Disc const &disc);
public:
	/**
	*square��̐΂��Ђ�����Ԃ�<br>
	*reverses the disc on the square.
	*@throws OthelloLogicException Square��ɐ΂��Ȃ���(empty() == true)<br>when has no disc  
	*/
	void reverse();
	/**
	*square��ɐ΂�u��<br>
	*���ɕʂ̐΂��u����Ă���ꍇ�V�����΂ŏ㏑�������<br>
	*puts disc.<br>
	*when other disc had already been put, old disc is overwriten with new disc.
	*@param disc
	*/
	void put(Disc const &disc);
	/**
	*�΂�square��ɂ���΂������菜��<br>
	*unputs disc from the square if present.
	*/
	void unput();
	/**
	*@return square��̐�<br> the disc on the square 
	*@throws OthelloLogicException Square��ɐ΂��Ȃ���(empty() == true) <br> if has no disc
	*/
	Disc disc()const;
	/**
	*@return square��ɐ΂��Ȃ��ꍇ�^<br> true if has no disc
	*/
	bool empty()const;
	/**
	*square���Տ�̊O�ɂ��鎞�^��Ԃ�<br> returns true if out of the board
	*@return pos().out()
	*/
	bool out()const;
	/**
	*@return square�̈ʒu<br> position of square
	*/
	Pos pos()const;
	/**
	*@return square�̍s�ԍ�<br> row index of square
	*/
	int i()const;
	/**
	*@return square�̗�ԍ�<br> column index of square
	*/
	int j()const;
};

}
