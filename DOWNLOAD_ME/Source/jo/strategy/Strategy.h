#pragma once

#include<memory>

namespace jo {

class Othello;
class Square;

/**
*@brief
*石を置く戦略<br>
*Strategy where put disc
*@details
*石を置く戦略を練る<br>
*派生クラスではthinkをオーバライドする<br>
*Thinks position to put a disc <br>
*You must override think method
*/
class Strategy
{
public:
	/**
	*othelloの情報を元に打つ手を考えて,その結果を返すようにオーバライドする<br>
	*You must override think method such that <br>
	* using information from othello, thinks position to put a disc<br>
	* returns square which was set position to put and turn color.
	*@param othello
	*@return 打つ手のデータ<br> result data(position and color)
	*/
	virtual Square think(Othello const &othello) = 0;
	/**
	*デストラクタ<br>
	*destoructor
	*/
	virtual ~Strategy() = default;
};

/***/
typedef std::shared_ptr<Strategy> Strategy_p;

}
