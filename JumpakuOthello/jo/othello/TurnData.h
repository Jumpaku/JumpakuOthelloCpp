#pragma once

#include"Color.h"
#include"Pos.h"

namespace jo {

class Disc;
class Square;

/**
*@brief
*1ターンのデータ<br>
*Data of a turn
*@details
*ターンカウントやそのターンに置かれた石の色と位置のデータ<br>
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
	*デフォルトコンストラクタ<br>
	*default constructor
	*/
	TurnData() = default;
	/**
	*ターンカウントと選択内容を設定する<br>
	*Sets turn count and choice data.
	*@param count 
	*@param pos
	*@param color 
	*/
	TurnData(int const &count, Pos const &pos, Color const&color);
	/**@return ターンカウント<br>turn count*/
	int count()const;
	/**@return 手(選択)のデータ<br> disc position and disc color*/
	Square choice()const;
	/**@return 石の色<br> disc color of choice*/
	Color color()const;
	/**@return 石を置いたマスの位置<br> disc position of choice*/
	Pos pos()const;
	/**@return pos().i()*/
	int i()const;
	/**@return pos().j()*/
	int j()const;
};

}
