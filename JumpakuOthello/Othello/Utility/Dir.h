#pragma once

namespace jo {

/**
*@brief
*�i�ޕ���<br>
*Direction in which to go
*@details
*BoardIterator��ConstBoardIterator��Pos���i�ޕ���<br>
*Direction in which BoardIterator, ConstBoardIterator or Pos goes.
*/
enum class Dir : int
{
	/**��<br>north*/
	N,
	/**�E��<br>northeast*/
	NE,
	/**�E<br>east*/
	E,
	/**�E��<br>southeast*/
	SE,
	/**��<br>south*/
	S,
	/**����<br>southwest*/
	SW,
	/**��<br>west*/
	W,
	/**����<br>northwest*/
	NW,
	/**�ǂ�ł��Ȃ�<br>other*/
	NO_DIR,
};

/**
*���������v����45�x���炷<br>
*Rotates direction 45 degree clockwise.<br>
*N-->NE-->E-->SE-->S-->SW-->W-->NW-->NO_DIR-->N-->...
*@param dir ���̕��p<br> source direction
*@return ��]������̕���<br> direction rotated
*/
Dir operator++(Dir &dir);

/**
*���������v����45�x���炷<br>
*Rotates direction 45 degree clockwise.<br>
*N-->NE-->E-->SE-->S-->SW-->W-->NW-->NO_DIR-->N-->...
*@param dir ���̕��p<br> source direction
*@return ��]����O�̕���<br> direction not rotated
*/
Dir operator++(Dir &dir, int);

}
