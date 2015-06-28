#pragma once

#include<map>

namespace jo {

enum class Dir;

/**
*@brief
*�}�X�̈ʒu<br>
*Position of square
*@details
*�Տ�̃}�X�̈ʒu (i, j) --> i�sj��<br>
*Square position on the othello board. (i, j) --> row i, column j
*/
class Pos
{
private:
	int i_m;
	int j_m;
	int clamp(int x);
public:
	/**
	*�f�t�H���g�R���X�g���N�^<br>
	*default constructor
	*/
	Pos() = default;
	/**
	*i�sj��̈ʒu��ݒ肷��<br>
	*���� i < 0 �Ȃ� 0, 9 < i �Ȃ� 9 ��ݒ肷��<br>
	*���� j < 0 �Ȃ� 0, 9 < j �Ȃ� 9 ��ݒ肷��<br>
	*Sets position row i, column j.<br>
	*If i < 0 then Sets 0, else if 9 < i then Sets 9.<br>
	*If j < 0 then Sets 0, else if 9 < j then Sets 9. 
	*@param i �s�ԍ� <br> index of row
	*@param j ��ԍ� <br> index of column
	*/
	Pos(int i, int j);
	/**@return �s�ԍ�<br> index of row*/
	int i()const;
	/**@return ��ԍ�<br> index of column*/
	int j()const;
	/**
	*���ݒ肷��<br> ���� i < 0 �Ȃ� 0, 9 < i �Ȃ� 9 ��ݒ肷��<br>
	*Sets column.If i < 0 then Sets 0, else if 9 < i then Sets 9.
	*@param i �s�ԍ� <br> index of row
	*/
	void i(int i);
	/**
	*���ݒ肷��<br> ���� j < 0 �Ȃ� 0, 9 < j �Ȃ� 9 ��ݒ肷��<br>
	*Sets column. If j < 0 then Sets 0, else if 9 < j then Sets 9. 
	*@param j ��ԍ� <br> index of column
	*/
	void j(int j);
	/**
	*�ʒu�x�N�g���̘a�����߂�<br>
	*Gets position added positon vector p.
	*@param p �ʒu�x�N�g��<br> position vectpr
	*@return { i_m + p.i_m, j_m + p.j_m }
	*/
	Pos operator+(Pos const &p)const;
	/**
	*�ʒu�x�N�g����������<br> Adds position vector p.
	*@param p �ʒu�x�N�g��<br> position vectpr
	*@return *this = *this + p
	*/
	Pos operator+=(Pos const &p);
	/**
	*p�Ɠ������Ƃ��^��Ԃ�<br> Returns true if equals p.
	*@param p �ʒu<br> position
	*@return i_m == p.i_m && j_m == p.j_m
	*/
	bool operator==(Pos const &p)const;
	/**
	*p�Ɠ��������Ȃ��Ƃ��^��Ԃ�<br> Returns true if	 not equals p.
	*@param p �ʒu<br> position
	*@return !(*this == p)
	*/
	bool operator!=(Pos const &p)const;
	/**
	*dir�̕�����1�}�X�i��<br>
	*Goes one square in the direction dir.
	*@param dir �i�ޕ���<br> direction in which to go
	*/
	void move(Dir dir);
	/**
	*�ʒu���Տ�ɖ������^��Ԃ�<br>
	*Returns true if is not on the board.
	*@return !(1 <= i_m && i_m <= 8 && 1 <= j_m && j_m <= 8)
	*/
	bool out()const;
}; 

}
