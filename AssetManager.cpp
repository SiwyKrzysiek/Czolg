#include "AssetManager.h"

using namespace std;
using namespace sf;

AssetManager::AssetManager() = default;

void AssetManager::loadFont(const string& name, const string& fileName)
{
	Font font;

	if (font.loadFromFile(fileName))
		fonts[name] = font;
}

const Font& AssetManager::getFont(const string& name) const
{
	return fonts.at(name);
}

void AssetManager::loadTexture(const string& name, const string& fileName)
{
	Texture texture;

	if (texture.loadFromFile(fileName))
		textures[name] = texture;
}

const sf::Texture& AssetManager::getTexture(const string& name) const
{
	return textures.at(name);
}
