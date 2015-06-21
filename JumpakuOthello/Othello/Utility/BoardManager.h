#pragma once

#include"../Board/Board.h"

namespace jo {

class Square;
class SquareCollection;
class Color;

/**
*@brief 
*�{�[�h�̊Ǘ�������<br>
*Manages othello board
*@details
*�{�[�h�ɐ������΂�u�����萳�����΂𗠕Ԃ����肷��<br>
*�Ǘ�����{�[�h�̓����o�Ƃ��Ď����Ƃ�,�O���̃{�[�h���N���X���\�b�h�ő��삷�邱�Ƃ��ł���.<br>
*Puts discs correctly and recerses discs correctly.<br>
*Can manage board as member or using static methods.
*/
class BoardManager
{
	Board board_m;
public:
	/**
	*�{�[�h�}�l�[�W���[�����{�[�h��ݒ肷��<br>
	*Sets board which board manager has
	*@param board �ݒ肷��{�[�h<br> board to set
	*/
	void setBoard(Board const &board);
	/**
	*�{�[�h�}�l�[�W���[�����{�[�h���擾����<br>
	*Gets board which board manager has
	*@return �擾����{�[�h<br> board to get
	*/
	Board getBoard()const;

	/**
	*choice�̃}�X��choice�����΂Ɠ����F�̐΂�u��<br>
	*Puts a disc which has same color as choice has on the square choice
	*@param choice �΂�u���}�X<br> the square where to put
	*@throws OthelloLogicException choice�̃}�X��choice�����΂Ɠ����΂�u���Ȃ��Ƃ�<br> when connot put disc which has same color as choice has on the square choice
	*/
	void put(Square const &choice);
	/**
	*reversibles�̃}�X�S�Ă̐΂��Ђ�����Ԃ�<br>
	*getReversibles�œ����}�X�͂ǂ�����̎��_�łЂ�����Ԃ����Ƃ��ł���̂ł���𗘗p����Ɨǂ�<br>
	*Reverses discs in reversibles.<br>
	*Each square from getReversibles has disc which can be reversed, so, please use getReversibles.
	*@param reversibles �Ђ�����Ԃ��΂̏W�܂�<br> discs to reverse
	*@throws OthelloLogicException �}�X�ɐ΂��Ȃ��Ƃ�<br> when there was no disc to reverse
	*/
	void reverse(SquareCollection const &reversibles);
	/**
	*choice�̃}�X��choice�̐΂Ɠ����F�̐΂�u����Ƃ��^��Ԃ�<br>
	*Returns true if can put a disc which has same color as choice has on the square choice
	*@param choice �u���F�̐΂��������I�����ꂽ�}�X<br> choice has position and color to put
	*@return choice�ɐ΂�u����Ƃ��^<br> true if can put a disc
	*@throws OthelloLogicException choice���΂������Ă��Ȃ��Ƃ�<br> when choice has no disc
	*/
	bool canPut(Square const &choice)const;
	/**
	*color�̐΂�u���ꏊ������Ƃ��^��Ԃ�<br>
	*Returns true if can put a disc has the color somewhare. 
	*@param color �u�����Ƃ���΂̐F<br> color of disc to put
	*@return color�̐΂�u����Ƃ��^<br> true if can put a disc
	*/
	bool canPut(Color const &color)const;
	/**
	*color�̐΂�u����S�Ă̐΂̏W�܂���擾����<br>
	*Gets collection of squares where can put discs which has the color.
	*@param color �u�������΂̐F<br> color of disc to put
	*@return �΂�u����}�X�̏W�܂�<br> available square collection
	*/
	SquareCollection getAvailables(Color const &color)const;
	/**
	*choice�̃}�X��choice�̐΂Ɠ����F�̐΂�u�������ɂЂ�����Ԃ����Ƃ̂ł���΂�����}�X�̏W�܂���擾����<br>
	*Gets collection of squares where can be reversed when put a disc on the square of choice.
	*@param choice �I�����ꂽ�}�X<br> selected square
	*@return �Ђ�����Ԃ����Ƃ̂ł���΂�����}�X�̏W�܂�<br> reversible square collection
	*@throws OthelloLogicException �u���΂̐F���w�肳��Ă��Ȃ��Ƃ�<br> when no color selected
	*/
	SquareCollection getReversibles(Square const &choice)const;

	/**
	*choice�̃}�X��choice�����΂Ɠ����F�̐΂�u��<br>
	*Puts a disc which has same color as choice has on the square choice
	*@param board �΂�u���{�[�h<br> board where put a disc
	*@param choice �΂�u���}�X<br> the square where to put
	*@throws OthelloLogicException choice�̃}�X��choice�����΂Ɠ����΂�u���Ȃ��Ƃ�<br> when cannot put disc which has same color as choice has on the square choice
	*/
	static void put(Board &board, Square const &choice);
	/**
	*reversibles�̃}�X�S�Ă̐΂��Ђ�����Ԃ�<br>
	*getReversibles�œ����}�X�͂ǂ�����̎��_�łЂ�����Ԃ����Ƃ��ł���̂ł���𗘗p����Ɨǂ�<br>
	*Reverses discs in reversibles.<br>
	*Each square from getReversibles has disc which can be reversed, so, please use getReversibles.
	*@param board �΂�u���{�[�h<br> board where put a disc
	*@param reversibles �Ђ�����Ԃ��΂̏W�܂�<br> discs to reverse
	*@throws OthelloLogicException �}�X�ɐ΂��Ȃ��Ƃ�<br> when there was no disc to reverse
	*/
	static void reverse(Board &board, SquareCollection const &reversibles);
	/**
	*choice�̃}�X��choice�̐΂Ɠ����F�̐΂�u����Ƃ��^��Ԃ�<br>
	*Returns true if can put a disc which has same color as choice has on the square choice
	*@param board �΂�u���{�[�h<br> board where put a disc
	*@param choice �u���F�̐΂��������I�����ꂽ�}�X<br> choice has position and color to put
	*@return choice�ɐ΂�u����Ƃ��^<br> true if can put a disc
	*@throws OthelloLogicException choice���΂������Ă��Ȃ��Ƃ�<br> when choice has no disc
	*/
	static bool canPut(Board const &board, Square const &choice);
	/**
	*color�̐΂�u���ꏊ������Ƃ��^��Ԃ�<br>
	*Returns true if can put a disc has the color somewhare.
	*@param board �΂�u���{�[�h<br> board where put a disc
	*@param color �u�����Ƃ���΂̐F<br> color of disc to put
	*@return color�̐΂�u����Ƃ��^<br> true if can put a disc
	*/
	static bool canPut(Board const &board, Color const &color);
	/**
	*color�̐΂�u����S�Ă̐΂̏W�܂���擾����<br>
	*Gets collection of squares where can put discs which has the color.
	*@param board �΂�u���{�[�h<br> board where put a disc
	*@param color �u�������΂̐F<br> color of disc to put
	*@return �΂�u����}�X�̏W�܂�<br> available square collection
	*/
	static SquareCollection getAvailables(Board const &board, Color const &color);
	/**
	*choice�̃}�X��choice�̐΂Ɠ����F�̐΂�u�������ɂЂ�����Ԃ����Ƃ̂ł���΂�����}�X�̏W�܂���擾����<br>
	*Gets collection of squares where can be reversed when put a disc on the square of choice.
	*@param board �΂�u���{�[�h<br> board where put a disc
	*@param choice �I�����ꂽ�}�X<br> selected square
	*@return �Ђ�����Ԃ����Ƃ̂ł���΂�����}�X�̏W�܂�<br> reversible square collection
	*@throws OthelloLogicException �u���΂̐F���w�肳��Ă��Ȃ��Ƃ�<br> when no color selected
	*/
	static SquareCollection getReversibles(Board const &board, Square const &choice);
};

}
