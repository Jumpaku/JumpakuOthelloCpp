#pragma once

#include "BoardFrame.h"

#include"Square.h"

namespace jo{

/**
*@brief
*�I�Z���̃{�[�h<br>
*Othello board
*@details
*�I�Z���̃{�[�h<br>
*BoardFrame�̃e���v���[�g������Square���������N���X���p�����Ă���<br>
*�R���X�g���N�^�Œ�����4�}�X�ɔ��ƍ��̐΂�u��<br>
*A othello board.<br>
*Inherits BoardFrame<Square>.<br>
*Constructor puts discs on the center 4 squares of the board.
*/
class Board : public BoardFrame<Square>
{
public:
	/**
	*������4�}�X�ɔ��ƍ��̐΂�u��<br>
	*Puts discs on the center 4 squares of the board.
	*/
	Board();
};

}

#include"Disc.h"
