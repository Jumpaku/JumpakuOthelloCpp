#include "../Dir.h"

using namespace jo;

Dir jo::operator++(Dir &dir)
{
	return dir = dir != Dir::NO_DIR ?
		static_cast<Dir>(static_cast<int>(dir)+1) : Dir::N;
}

Dir jo::operator++(Dir &dir, int)
{
	Dir tmp = dir;
	++dir;
	return tmp;
}
