#pragma once

#include <stdexcept>

/**
 * \brief Klasa bledu wczytania potrzebnego pliku
 */
class MissingFileException : std::runtime_error
{
public:
	explicit MissingFileException(const char* what_arg);
	const char* what() const override;
};

