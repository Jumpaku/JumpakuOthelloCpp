#pragma once

#include"Color.h"
#include"Pos.h"

namespace jo {

class Disc;
class Square;

/**
*@brief
*1�^�[���̃f�[�^<br>
*Data of a turn
*@details
*�^�[���J�E���g�₻�̃^�[���ɒu���ꂽ�΂̐F�ƈʒu�̃f�[�^<br>
*Has a turn count and choice of the turn.
*/
class TurnData
{
private:
	int turnCount_m;
	Pos pos_m;
	Color color_m;
public:
	/**
	*�f�t�H���g�R���X�g���N�^<br>
	*default constructor
	*/
	TurnData() = default;
	/**
	*�^�[���J�E���g�ƑI����e��ݒ肷��<br>
	*Sets turn count and choice data.
	*@param count 
	*@param pos
	*@param color 
	*/
	TurnData(int const &count, Pos const &pos, Color const&color);
	/**@return �^�[���J�E���g<br>turn count*/
	int count()const;
	/**@return ��(�I��)�̃f�[�^<br> disc position and disc color*/
	Square choice()const;
	/**@return �΂̐F<br> disc color of choice*/
	Color color()const;
	/**@return �΂�u�����}�X�̈ʒu<br> disc position of choice*/
	Pos pos()const;
	/**@return pos().i()*/
	int i()const;
	/**@return pos().j()*/
	int j()const;
};

}
