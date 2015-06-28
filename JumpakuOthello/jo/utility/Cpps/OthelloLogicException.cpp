#include"../OthelloLogicException.h"

using namespace jo;

OthelloLogicException::OthelloLogicException(char const *message)
	:logic_error(message) {}
