#pragma once

#include <map>
#include <string>
#include <SFML/Graphics.hpp>
#include "MissingFileException.h"

/**
 * \brief Klasa do zarzadania zasobami takimi jak tekstury i czcionki. 
 */
class AssetManager
{
private:
	AssetManager();

	std::map<std::string, sf::Font> fonts;
	std::map<std::string, sf::Texture> textures;

public:
	AssetManager(AssetManager& a) = delete;

	static AssetManager& getInstance()
	{
		static AssetManager instance;
		return instance;
	}

	void loadFont(const std::string& name, const std::string& fileName);
	const sf::Font& getFont(const std::string& name) const;

	void loadTexture(const std::string& name, const std::string& fileName);
	const sf::Texture& getTexture(const std::string& name) const;
};

