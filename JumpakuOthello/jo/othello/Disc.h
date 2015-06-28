#pragma once

#include<algorithm>
#include"Color.h"

namespace jo {

/**
*@brief
*オセロの石<br>
*Othello disc
*@details
*オセロの石,片側が黒でもう片側が白<br>
*現在表が何色なの調べたり,表裏をひっくり返したりできる
*Disc of othello.Has two sides,top and bottom which have deffelent color, one is dark, the other is white
*You can get current top side color,or reverse.
*/
class Disc
{
private:
	Color top_m;
	Color bottom_m;
public:
	/**
	*デフォルトでは黒が表,白が裏となっている<br>
	*Default color : top is dark, bottom is light.
	*/
	Disc();
	/**
	*最初の色を設定する<br>
	*Sets initial color
	*@param color 最初の色<br> initial color
	*/
	Disc(Color const &color);
public:
	/**
	*@param disc もう一つの石<br> other disc
	*@return 2つの石が同じ色の場合真<br> true if two discs are same color
	*/
	bool operator==(Disc const &disc)const;
	/**
	*@param disc もう一つの石<br> other disc
	*@return !(*this == disc)
	*/
	bool operator!=(Disc const &disc)const;
	/**
	*石の表裏を入れ替える<br>
	* Swaps top and bottom.
	*/
	void reverse();
	/**
	*@return 表の色<br> top color
	*/
	Color color()const;
};

}
