#pragma once

namespace jo {

/**
*@brief
*進む方向<br>
*Direction in which to go
*@details
*BoardIteratorやConstBoardIteratorやPosが進む方向<br>
*Direction in which BoardIterator, ConstBoardIterator or Pos goes.
*/
enum class Dir : int
{
	/**上<br>north*/
	N,
	/**右上<br>northeast*/
	NE,
	/**右<br>east*/
	E,
	/**右下<br>southeast*/
	SE,
	/**下<br>south*/
	S,
	/**左下<br>southwest*/
	SW,
	/**左<br>west*/
	W,
	/**左上<br>northwest*/
	NW,
	/**どれでもない<br>other*/
	NO_DIR,
};

/**
*方向を時計回りに45度ずらす<br>
*Rotates direction 45 degree clockwise.<br>
*N-->NE-->E-->SE-->S-->SW-->W-->NW-->NO_DIR-->N-->...
*@param dir 元の方角<br> source direction
*@return 回転した後の方向<br> direction rotated
*/
Dir operator++(Dir &dir);

/**
*方向を時計回りに45度ずらす<br>
*Rotates direction 45 degree clockwise.<br>
*N-->NE-->E-->SE-->S-->SW-->W-->NW-->NO_DIR-->N-->...
*@param dir 元の方角<br> source direction
*@return 回転する前の方向<br> direction not rotated
*/
Dir operator++(Dir &dir, int);

}
