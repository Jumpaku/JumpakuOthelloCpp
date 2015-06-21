#pragma once

#include"Utility/History.h"
#include"Utility\Color.h"
#include"Strategy\Strategy.h"
#include"Utility\BoardManager.h"

namespace jo {

class Color;
class Square;
class SquareCollection;

/**
*@brief
*オセロ1試合の管理<br>
*Management of a othello game
*@details
*オセロのゲーム1試合をコントロール, 管理する<br>
*様々な情報, 石の数, ターンカラー, ボード, 石を置けるマス, 石をひっくり返せるマスなどを得ることができる<br>
*石を置きひっくり返してターンを交代する一連の処理をplayTurnで行う.<br>
*Controlls or anages a othello game.<br>
*Provides various informaion of the game, disc count, turn color, board, squares to put, squares to reverse discs.<br>
*Using playTurn method, puts discs, reverses discs and changes turn.
*/
class Othello
{
private:
	bool hasFinished_m = false;
	History history_m;
	BoardManager boardManager_m;
	Color turnColor_m;
private:
	Othello &operator=(Othello const &) = delete;
	Othello &operator=(Othello &&) = delete;
public:
	/**
	*デフォルトコンストラクタ<br>
	*default constructor
	*/
	Othello() = default;
	/**
	*コピーコンストラクタ<br>
	*copy constructor
	*/
	Othello(Othello const &) = default;
	/**
	*ムーブコンストラクタ<br>
	*move constructor
	*/
	Othello(Othello &&) = default;
private:
	void select(Square const &choice);
	void changeTurn();
public:
	/**
	*@return 現在のボード<br> current board
	*/
	Board board()const;
	/**
	*@return ターンプレイヤの色<br> current turn color
	*/
	Color turnColor()const;
	/**
	*@return ゲームが終了していれば真<br> true if game has finished
	*/
	bool hasFinished()const;
	/**
	*@param color 数える石の色<br> color to count
	*@return colorの色の石の数<br> number of disc which has the color
	*/
	int discCount(Color const &color)const;
	/**
	*@return 現在のターン数<br> current turn count
	*/
	int turnCount()const;
	/**
	*@return 石の置かれた履歴<br> history of game, recent
	*/
	History history()const;
	/**
	*ターンプレイヤが石を置けるマスの集まりを取得する<br>
	*Gets available squares on which can be put  
	*@return 石を置けるマスの集まり<br> available squares
	*/
	SquareCollection getAvailables()const;
	/**
	*もしchoiceに石を置いた時にひっくり返されるマスの集まり<br>
	*Gets squares which are reversed if the choice is selected
	*@param choice 仮の石を置くマス<br> temporary square to put disc
	*@return ひっくり返されるマスの集まり<br> reversible discs
	*/
	SquareCollection getReversibles(Square const &choice)const;
	/**
	*choiceのマスにターンプレイヤが石を置けるか調べる
	*Checks the square choice whether turn player can put a disc 
	*@param choice 調べるマス<br> square to check
	*@return もし石を置けるなら真<br> true if available
	*/
	bool isAvailable(Square const &choice)const;
	/**
	*ターンプレイヤの石を置き,ターンプレイヤを交代する<br>
	*Puts disc and reverse discs and changes turn.
	*@param choice
	*@throws OthelloLogicException 色が正しくないまたは選択された場所に石を置けないとき<br> when choice was wrong color or not available position
	*/
	void playTurn(Square const &choice);
	/**
	*
	*Puts disc and reverses discs and changes turn
	*@param strategy
	*@exception when choice solved by the strategy was wrong color or not available position, throws OthelloLogicException
	*/
	void playTurn(Strategy_p strategy);
	/**
	*1ターン前に戻る<br>
	*undo a turn
	**/
	void undo();
	/**
	*ゲームを始めに戻す<br>
	*reset and start the game
	*/
	void restart();

	/*
	そのうち追加
	coming soon.

	Othello::Result getResult();
	void playTurn();
	void strategy(Strategy_p strategy, Color color);
	Strategy_p strategy(Color color);
	*/
};

}

#include"Utility\BoardFrame.h"
#include"Utility\BoardIterator.h"
#include"Utility\Color.h"
#include"Utility\History.h"
#include"Utility\OthelloLogicException.h"
#include"Utility\Pos.h"
#include"Board\Square.h"
#include"Utility\TurnData.h"
#include"Utility\Dir.h"
#include"Utility\SquareCollection.h"
