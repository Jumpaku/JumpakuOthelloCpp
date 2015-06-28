#include"../SquareCollection.h"

#include"../Square.h"

using namespace jo;


SquareCollection::Iterator_t SquareCollection::begin()
{
	return dataList_m.begin();
}

SquareCollection::Iterator_t SquareCollection::end()
{
	return dataList_m.end();
}

SquareCollection::ConstIterator_t SquareCollection::begin()const
{
	return dataList_m.cbegin();
}

SquareCollection::ConstIterator_t SquareCollection::end()const
{
	return dataList_m.cend();
}

void SquareCollection::pushBack(Square const &data)
{
	dataList_m.emplace_back(data);
}

bool SquareCollection::empty()const
{
	return dataList_m.empty();
}

int SquareCollection::size()const
{
	return dataList_m.size();
}