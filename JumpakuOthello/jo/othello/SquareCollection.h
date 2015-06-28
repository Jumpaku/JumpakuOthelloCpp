#pragma once

#include<list>

namespace jo {

class Square;

/**
*@brief
*�}�X�̏W�܂�<br>
*Collection of squares
*@details
*�}�X�̏W�܂���������ɂ��̃N���X���g�p�����<br>
*�}�X�̏W�܂�Ƃ͗Ⴆ�ΐ΂�u�����Ƃ̂ł���S�Ẵ}�X,�u���Ă���΂𗠕Ԃ��S�Ẵ}�X�Ȃǂł���<br>
*std::list<Square>�Ŏ�������Ă���<br>
*Utilized when you want to use some squares together.<br>
*For example, squares to put discs, or squares to reverse discs on.<br>
*Implemented using std::list<Square>.
*/
class SquareCollection
{
	typedef std::list<Square> List_t;
public:
	/**
	*�C�e���[�^�̌^<br>
	*Type of iteraror.
	*/
	typedef std::list<Square>::iterator Iterator_t;
	/**
	*�R���X�g�C�e���[�^�̌^<br>
	*�R���X�g�C�e���[�^�̓C�e���[�^���w���v�]�����������鎖���ł��Ȃ�<br>
	*Type of const iterator.<br>
	*Const iterator cannot overwrite element
	*/
	typedef std::list<Square>::const_iterator ConstIterator_t;
private:
	List_t dataList_m;
public:
	/**
	*@return �ŏ��̗v�f�̃C�e���[�^<br> iterator of first element
	*/
	Iterator_t begin();
	/**
	*@return �Ō�̗v�f�̎��̗v�f�̃C�e���[�^<br> iterator of next of last element
	*/
	Iterator_t end();
	/**
	*@return �ŏ��̗v�f�̃R���X�g�C�e���[�^<br> const iterator of first element
	*/
	ConstIterator_t begin()const;
	/**
	*@return �Ō�̗v�f�̎��̗v�f�̃R���X�g�C�e���[�^<br> const iterator of next of last element
	*/
	ConstIterator_t end()const;
	/**
	*�V�����v�f�𖖔��ɒǉ�����<br>
	*Adds new element to end of collection.
	*@param square �ǉ�����v�f<br> element to add
	*/
	void pushBack(Square const &square);
	/**
	*@return �v�f�����������ꍇ�^<br> true if has no element
	*/
	bool empty()const;
	/**
	*@return �v�f�̐�<br> number of elements
	*/
	int size()const;
};


}