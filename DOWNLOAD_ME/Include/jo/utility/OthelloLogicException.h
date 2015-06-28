#pragma once

#include<stdexcept>

namespace jo{


/**
*@brief
*othelloで発生するロジック例外<br>
*Logic exception in othello
*@details
*プログラムの論理的な例外であり,プログラマの誤りで発生する<br>
*リリース版での発生はデバッグ時に検出し修正することで未然に防げる<br>
*Logic exception is thrown when programmer missed.<br>
*To prevent occurence of this exception with release version,<br>
*you should detect and fix this exception at debug.
*/
class OthelloLogicException : public std::logic_error
{
public:
	/**
	*@param message エラーメッセージ<br> error message 
	*/
	OthelloLogicException(char const *message);
	/**
	*デストラクタ<br> destructor
	*/
	virtual ~OthelloLogicException() = default;
};

}
