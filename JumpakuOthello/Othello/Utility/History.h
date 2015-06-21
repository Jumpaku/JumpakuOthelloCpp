#pragma once

#include<deque>
#include"TurnData.h"

namespace jo {

class Square;

/**
*@brief
*1試合の履歴<br>
*History of a othello Game
*@details
*1試合分に各ターンの履歴を記録する<br>
*前(front)のデータほど古く,後のデータほど新しい<br>
*Stores a game history which contains all turn data.<br>
*Front data is older than back, back data is newer than front. 
*/
class History
{
private:
	std::deque<TurnData> history_m;
public:
	/**
	*最後の要素を返してコレクションから削除する<br>
	*returns back and erases back 
	*@return 最後の要素<br> back before erase
	*@throws OthelloLogicException コレクションが空のとき<br> when empty
	*/
	TurnData popBack();
	/**
	*最初の要素を返してコレクションから削除する<br>
	*returns front and erases front
	*@return 最初の要素<br> front before erase
	*@throws OthelloLogicException コレクションが空のとき<br> when empty
	*/
	TurnData popFront();
	/**
	*末尾に要素を追加する<br>
	*Adds element to end.
	*@param choice 追加する要素<br> element to add
	*/
	void pushBack(Square const &choice);
	/**
	*@return 最後の要素<br> last element
	*@throws OthelloLogicException コレクションが空のとき<br> when empty
	*/
	TurnData back()const;
	/**
	@return コレクションのサイズ(それまでのターン数)<br> size of collection(equals turn count)
	*/
	int size()const;
	/**
	*要素を全て削除する<br>
	*erases all.
	*/
	void clear();
	/**
	*@return コレクションが空の場合真<br> true if empty
	*/
	bool empty()const;
};

}
