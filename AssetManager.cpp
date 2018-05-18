#include "AssetManager.h"

using namespace std;
using namespace sf;

AssetManager::AssetManager() = default;

void AssetManager::loadFont(string name, string fileName)
{
	Font font;

	if (font.loadFromFile(fileName))
		fonts[name] = font;
}

Font& AssetManager::getFont(string name)
{
	return fonts.at(name);
}

void AssetManager::loadTexture(string name, string fileName)
{
	Texture texture;

	if (texture.loadFromFile(fileName))
		textures[name] = texture;
}

sf::Texture& AssetManager::getTexture(string name)
{
	return textures.at(name);
}
