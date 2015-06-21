#pragma once

#include"Utility/History.h"
#include"Utility\Color.h"
#include"Strategy\Strategy.h"
#include"Utility\BoardManager.h"

namespace jo {

class Color;
class Square;
class SquareCollection;

/**
*@brief
*�I�Z��1�����̊Ǘ�<br>
*Management of a othello game
*@details
*�I�Z���̃Q�[��1�������R���g���[��, �Ǘ�����<br>
*�l�X�ȏ��, �΂̐�, �^�[���J���[, �{�[�h, �΂�u����}�X, �΂��Ђ�����Ԃ���}�X�Ȃǂ𓾂邱�Ƃ��ł���<br>
*�΂�u���Ђ�����Ԃ��ă^�[������シ���A�̏�����playTurn�ōs��.<br>
*Controlls or anages a othello game.<br>
*Provides various informaion of the game, disc count, turn color, board, squares to put, squares to reverse discs.<br>
*Using playTurn method, puts discs, reverses discs and changes turn.
*/
class Othello
{
private:
	bool hasFinished_m = false;
	History history_m;
	BoardManager boardManager_m;
	Color turnColor_m;
private:
	Othello &operator=(Othello const &) = delete;
	Othello &operator=(Othello &&) = delete;
public:
	/**
	*�f�t�H���g�R���X�g���N�^<br>
	*default constructor
	*/
	Othello() = default;
	/**
	*�R�s�[�R���X�g���N�^<br>
	*copy constructor
	*/
	Othello(Othello const &) = default;
	/**
	*���[�u�R���X�g���N�^<br>
	*move constructor
	*/
	Othello(Othello &&) = default;
private:
	void select(Square const &choice);
	void changeTurn();
public:
	/**
	*@return ���݂̃{�[�h<br> current board
	*/
	Board board()const;
	/**
	*@return �^�[���v���C���̐F<br> current turn color
	*/
	Color turnColor()const;
	/**
	*@return �Q�[�����I�����Ă���ΐ^<br> true if game has finished
	*/
	bool hasFinished()const;
	/**
	*@param color ������΂̐F<br> color to count
	*@return color�̐F�̐΂̐�<br> number of disc which has the color
	*/
	int discCount(Color const &color)const;
	/**
	*@return ���݂̃^�[����<br> current turn count
	*/
	int turnCount()const;
	/**
	*@return �΂̒u���ꂽ����<br> history of game, recent
	*/
	History history()const;
	/**
	*�^�[���v���C�����΂�u����}�X�̏W�܂���擾����<br>
	*Gets available squares on which can be put  
	*@return �΂�u����}�X�̏W�܂�<br> available squares
	*/
	SquareCollection getAvailables()const;
	/**
	*����choice�ɐ΂�u�������ɂЂ�����Ԃ����}�X�̏W�܂�<br>
	*Gets squares which are reversed if the choice is selected
	*@param choice ���̐΂�u���}�X<br> temporary square to put disc
	*@return �Ђ�����Ԃ����}�X�̏W�܂�<br> reversible discs
	*/
	SquareCollection getReversibles(Square const &choice)const;
	/**
	*choice�̃}�X�Ƀ^�[���v���C�����΂�u���邩���ׂ�
	*Checks the square choice whether turn player can put a disc 
	*@param choice ���ׂ�}�X<br> square to check
	*@return �����΂�u����Ȃ�^<br> true if available
	*/
	bool isAvailable(Square const &choice)const;
	/**
	*�^�[���v���C���̐΂�u��,�^�[���v���C������シ��<br>
	*Puts disc and reverse discs and changes turn.
	*@param choice
	*@throws OthelloLogicException �F���������Ȃ��܂��͑I�����ꂽ�ꏊ�ɐ΂�u���Ȃ��Ƃ�<br> when choice was wrong color or not available position
	*/
	void playTurn(Square const &choice);
	/**
	*
	*Puts disc and reverses discs and changes turn
	*@param strategy
	*@exception when choice solved by the strategy was wrong color or not available position, throws OthelloLogicException
	*/
	void playTurn(Strategy_p strategy);
	/**
	*1�^�[���O�ɖ߂�<br>
	*undo a turn
	**/
	void undo();
	/**
	*�Q�[�����n�߂ɖ߂�<br>
	*reset and start the game
	*/
	void restart();

	/*
	���̂����ǉ�
	coming soon.

	Othello::Result getResult();
	void playTurn();
	void strategy(Strategy_p strategy, Color color);
	Strategy_p strategy(Color color);
	*/
};

}

#include"Utility\BoardFrame.h"
#include"Utility\BoardIterator.h"
#include"Utility\Color.h"
#include"Utility\History.h"
#include"Utility\OthelloLogicException.h"
#include"Utility\Pos.h"
#include"Board\Square.h"
#include"Utility\TurnData.h"
#include"Utility\Dir.h"
#include"Utility\SquareCollection.h"
