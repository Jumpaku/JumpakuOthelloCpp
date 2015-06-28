#pragma once

#include<map>

namespace jo {

enum class Dir;

/**
*@brief
*マスの位置<br>
*Position of square
*@details
*盤上のマスの位置 (i, j) --> i行j列<br>
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
	*デフォルトコンストラクタ<br>
	*default constructor
	*/
	Pos() = default;
	/**
	*i行j列の位置を設定する<br>
	*もし i < 0 なら 0, 9 < i なら 9 を設定する<br>
	*もし j < 0 なら 0, 9 < j なら 9 を設定する<br>
	*Sets position row i, column j.<br>
	*If i < 0 then Sets 0, else if 9 < i then Sets 9.<br>
	*If j < 0 then Sets 0, else if 9 < j then Sets 9. 
	*@param i 行番号 <br> index of row
	*@param j 列番号 <br> index of column
	*/
	Pos(int i, int j);
	/**@return 行番号<br> index of row*/
	int i()const;
	/**@return 列番号<br> index of column*/
	int j()const;
	/**
	*列を設定する<br> もし i < 0 なら 0, 9 < i なら 9 を設定する<br>
	*Sets column.If i < 0 then Sets 0, else if 9 < i then Sets 9.
	*@param i 行番号 <br> index of row
	*/
	void i(int i);
	/**
	*列を設定する<br> もし j < 0 なら 0, 9 < j なら 9 を設定する<br>
	*Sets column. If j < 0 then Sets 0, else if 9 < j then Sets 9. 
	*@param j 列番号 <br> index of column
	*/
	void j(int j);
	/**
	*位置ベクトルの和を求める<br>
	*Gets position added positon vector p.
	*@param p 位置ベクトル<br> position vectpr
	*@return { i_m + p.i_m, j_m + p.j_m }
	*/
	Pos operator+(Pos const &p)const;
	/**
	*位置ベクトルを加える<br> Adds position vector p.
	*@param p 位置ベクトル<br> position vectpr
	*@return *this = *this + p
	*/
	Pos operator+=(Pos const &p);
	/**
	*pと等しいとき真を返す<br> Returns true if equals p.
	*@param p 位置<br> position
	*@return i_m == p.i_m && j_m == p.j_m
	*/
	bool operator==(Pos const &p)const;
	/**
	*pと等しいくないとき真を返す<br> Returns true if	 not equals p.
	*@param p 位置<br> position
	*@return !(*this == p)
	*/
	bool operator!=(Pos const &p)const;
	/**
	*dirの方向に1マス進む<br>
	*Goes one square in the direction dir.
	*@param dir 進む方向<br> direction in which to go
	*/
	void move(Dir dir);
	/**
	*位置が盤上に無い時真を返す<br>
	*Returns true if is not on the board.
	*@return !(1 <= i_m && i_m <= 8 && 1 <= j_m && j_m <= 8)
	*/
	bool out()const;
}; 

}
