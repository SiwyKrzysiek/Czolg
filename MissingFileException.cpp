#include "MissingFileException.h"

MissingFileException::MissingFileException(const char* what_arg) : runtime_error(what_arg)
{
}

const char* MissingFileException::what() const
{
	return  runtime_error::what();
}
