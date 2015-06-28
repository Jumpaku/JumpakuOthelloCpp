#pragma once

#include<string>

namespace jo {
/**
*@brief
*�I�Z���̐F<br>
*Color of othello.
*@details
*�I�Z���̐F,�K����������2�F�����̂ǂ��炩�ƂȂ�<br>
*Color::dark()�܂���Color::light()���g���ĐF�𓾂�.<br>
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
	*�f�t�H���g�R���X�g���N�^<br>
	*default constructor
	*/
	Color() = default;
public:
	/**
	*@param color
	*@return color �Ɠ����F�̏ꍇ�^<br> true if same as color
	*/
	bool operator==(Color const &color)const;
	/**
	*@param color
	*@return *this != color
	*/
	bool operator!=(Color const &color)const;
	/**
	*�ʂ̐F���Ȃ킿,�������Ȃ獕,���Ȃ甒��Ԃ�<br>
	*Returns another color, light if Color is dark, dark if Color is light
	*@return ���Ȃ獕,���Ȃ甒<br> another color
	*/
	Color reversed()const;
	/**
	*������ɕϊ����ꂽ�F�𓾂�<br>
	*Gets color converted to string.<br>
	*light --> "LIGHT" : dark --> "DARK"
	*@return ������ɕϊ����ꂽ�F<br> color converted to string
	*/
	std::string toString()const;
	/**
	*@return ���F<br> dark color
	*/
	static Color dark();
	/**
	*@return ���F<br> white color
	*/
	static Color light();
};

}
