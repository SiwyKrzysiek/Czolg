#pragma once

#include <map>
#include <string>
#include <SFML/Graphics.hpp>

/**
 * \brief Klasa do zarzadania zasobami takimi jak tekstury i czcionki. 
 */
//ToDo Wzorzec projektowy Singleton
class AssetManager //ToDo Wykorzystac Map
{
private:
	std::map<std::string, sf::Font> fonts;
	std::map<std::string, sf::Texture> textures;

public:
	AssetManager();

	void loadFont(std::string name, std::string fileName);
	sf::Font& getFont(std::string name);

	void loadTexture(std::string name, std::string fileName);
	sf::Texture& getTexture(std::string name);
};

