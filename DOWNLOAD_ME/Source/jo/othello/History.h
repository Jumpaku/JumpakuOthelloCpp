#pragma once

#include<deque>
#include"TurnData.h"

namespace jo {

class Square;

/**
*@brief
*1�����̗���<br>
*History of a othello Game
*@details
*1�������Ɋe�^�[���̗������L�^����<br>
*�O(front)�̃f�[�^�قǌÂ�,��̃f�[�^�قǐV����<br>
*Stores a game history which contains all turn data.<br>
*Front data is older than back, back data is newer than front. 
*/
class History
{
private:
	std::deque<TurnData> history_m;
public:
	/**
	*�Ō�̗v�f��Ԃ��ăR���N�V��������폜����<br>
	*returns back and erases back 
	*@return �Ō�̗v�f<br> back before erase
	*@throws OthelloLogicException �R���N�V��������̂Ƃ�<br> when empty
	*/
	TurnData popBack();
	/**
	*�ŏ��̗v�f��Ԃ��ăR���N�V��������폜����<br>
	*returns front and erases front
	*@return �ŏ��̗v�f<br> front before erase
	*@throws OthelloLogicException �R���N�V��������̂Ƃ�<br> when empty
	*/
	TurnData popFront();
	/**
	*�����ɗv�f��ǉ�����<br>
	*Adds element to end.
	*@param choice �ǉ�����v�f<br> element to add
	*/
	void pushBack(Square const &choice);
	/**
	*@return �Ō�̗v�f<br> last element
	*@throws OthelloLogicException �R���N�V��������̂Ƃ�<br> when empty
	*/
	TurnData back()const;
	/**
	@return �R���N�V�����̃T�C�Y(����܂ł̃^�[����)<br> size of collection(equals turn count)
	*/
	int size()const;
	/**
	*�v�f��S�č폜����<br>
	*erases all.
	*/
	void clear();
	/**
	*@return �R���N�V��������̏ꍇ�^<br> true if empty
	*/
	bool empty()const;
};

}
