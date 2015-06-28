#pragma once

#include<algorithm>
#include"Color.h"

namespace jo {

/**
*@brief
*�I�Z���̐�<br>
*Othello disc
*@details
*�I�Z���̐�,�Б������ł����Б�����<br>
*���ݕ\�����F�Ȃ̒��ׂ���,�\�����Ђ�����Ԃ�����ł���
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
	*�f�t�H���g�ł͍����\,�������ƂȂ��Ă���<br>
	*Default color : top is dark, bottom is light.
	*/
	Disc();
	/**
	*�ŏ��̐F��ݒ肷��<br>
	*Sets initial color
	*@param color �ŏ��̐F<br> initial color
	*/
	Disc(Color const &color);
public:
	/**
	*@param disc ������̐�<br> other disc
	*@return 2�̐΂������F�̏ꍇ�^<br> true if two discs are same color
	*/
	bool operator==(Disc const &disc)const;
	/**
	*@param disc ������̐�<br> other disc
	*@return !(*this == disc)
	*/
	bool operator!=(Disc const &disc)const;
	/**
	*�΂̕\�������ւ���<br>
	* Swaps top and bottom.
	*/
	void reverse();
	/**
	*@return �\�̐F<br> top color
	*/
	Color color()const;
};

}
