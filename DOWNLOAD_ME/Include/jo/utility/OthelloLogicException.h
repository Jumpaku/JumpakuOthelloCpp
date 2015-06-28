#pragma once

#include<stdexcept>

namespace jo{


/**
*@brief
*othello�Ŕ������郍�W�b�N��O<br>
*Logic exception in othello
*@details
*�v���O�����̘_���I�ȗ�O�ł���,�v���O���}�̌��Ŕ�������<br>
*�����[�X�łł̔����̓f�o�b�O���Ɍ��o���C�����邱�ƂŖ��R�ɖh����<br>
*Logic exception is thrown when programmer missed.<br>
*To prevent occurence of this exception with release version,<br>
*you should detect and fix this exception at debug.
*/
class OthelloLogicException : public std::logic_error
{
public:
	/**
	*@param message �G���[���b�Z�[�W<br> error message 
	*/
	OthelloLogicException(char const *message);
	/**
	*�f�X�g���N�^<br> destructor
	*/
	virtual ~OthelloLogicException() = default;
};

}
