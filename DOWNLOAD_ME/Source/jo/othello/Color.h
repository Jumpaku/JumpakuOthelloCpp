#pragma once

#include<string>

namespace jo {
/**
*@brief
*オセロの色<br>
*Color of othello.
*@details
*オセロの色,必ず白か黒の2色うちのどちらかとなる<br>
*Color::dark()またはColor::light()を使って色を得る.<br>
*Color in othello must be dark or light.<br>
*You can get color from Color::dark() or Color::light().
*/
class Color
{
private:
	enum class Color_e : char
	{
		DARK,
		LIGHT,
	};
	Color_e color_m = Color_e::DARK;
	Color(Color_e color);
public:
	/**
	*デフォルトコンストラクタ<br>
	*default constructor
	*/
	Color() = default;
public:
	/**
	*@param color
	*@return color と同じ色の場合真<br> true if same as color
	*/
	bool operator==(Color const &color)const;
	/**
	*@param color
	*@return *this != color
	*/
	bool operator!=(Color const &color)const;
	/**
	*別の色すなわち,もし白なら黒,黒なら白を返す<br>
	*Returns another color, light if Color is dark, dark if Color is light
	*@return 白なら黒,黒なら白<br> another color
	*/
	Color reversed()const;
	/**
	*文字列に変換された色を得る<br>
	*Gets color converted to string.<br>
	*light --> "LIGHT" : dark --> "DARK"
	*@return 文字列に変換された色<br> color converted to string
	*/
	std::string toString()const;
	/**
	*@return 黒色<br> dark color
	*/
	static Color dark();
	/**
	*@return 白色<br> white color
	*/
	static Color light();
};

}
