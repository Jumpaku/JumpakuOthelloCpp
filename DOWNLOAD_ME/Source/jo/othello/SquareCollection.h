#pragma once

#include<list>

namespace jo {

class Square;

/**
*@brief
*マスの集まり<br>
*Collection of squares
*@details
*マスの集まりを扱う時にこのクラスが使用される<br>
*マスの集まりとは例えば石を置くことのできる全てのマス,置いてある石を裏返す全てのマスなどである<br>
*std::list<Square>で実装されている<br>
*Utilized when you want to use some squares together.<br>
*For example, squares to put discs, or squares to reverse discs on.<br>
*Implemented using std::list<Square>.
*/
class SquareCollection
{
	typedef std::list<Square> List_t;
public:
	/**
	*イテレータの型<br>
	*Type of iteraror.
	*/
	typedef std::list<Square>::iterator Iterator_t;
	/**
	*コンストイテレータの型<br>
	*コンストイテレータはイテレータが指す要望を書き換える事ができない<br>
	*Type of const iterator.<br>
	*Const iterator cannot overwrite element
	*/
	typedef std::list<Square>::const_iterator ConstIterator_t;
private:
	List_t dataList_m;
public:
	/**
	*@return 最初の要素のイテレータ<br> iterator of first element
	*/
	Iterator_t begin();
	/**
	*@return 最後の要素の次の要素のイテレータ<br> iterator of next of last element
	*/
	Iterator_t end();
	/**
	*@return 最初の要素のコンストイテレータ<br> const iterator of first element
	*/
	ConstIterator_t begin()const;
	/**
	*@return 最後の要素の次の要素のコンストイテレータ<br> const iterator of next of last element
	*/
	ConstIterator_t end()const;
	/**
	*新しい要素を末尾に追加する<br>
	*Adds new element to end of collection.
	*@param square 追加する要素<br> element to add
	*/
	void pushBack(Square const &square);
	/**
	*@return 要素が何も無い場合真<br> true if has no element
	*/
	bool empty()const;
	/**
	*@return 要素の数<br> number of elements
	*/
	int size()const;
};


}