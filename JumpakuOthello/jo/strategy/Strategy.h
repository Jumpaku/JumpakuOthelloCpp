#pragma once

#include<memory>

namespace jo {

class Othello;
class Square;

/**
*@brief
*�΂�u���헪<br>
*Strategy where put disc
*@details
*�΂�u���헪�����<br>
*�h���N���X�ł�think���I�[�o���C�h����<br>
*Thinks position to put a disc <br>
*You must override think method
*/
class Strategy
{
public:
	/**
	*othello�̏������ɑł���l����,���̌��ʂ�Ԃ��悤�ɃI�[�o���C�h����<br>
	*You must override think method such that <br>
	* using information from othello, thinks position to put a disc<br>
	* returns square which was set position to put and turn color.
	*@param othello
	*@return �ł�̃f�[�^<br> result data(position and color)
	*/
	virtual Square think(Othello const &othello) = 0;
	/**
	*�f�X�g���N�^<br>
	*destoructor
	*/
	virtual ~Strategy() = default;
};

/***/
typedef std::shared_ptr<Strategy> Strategy_p;

}
