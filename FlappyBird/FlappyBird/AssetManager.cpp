#include "stdafx.h"
#include "AssetManager.h"

AssetManager::AssetManager()
{
}

AssetManager::~AssetManager()
{
}

void AssetManager::LoadTexture(std::string name, std::string fileName)
{
	sf::Texture tex;
	if (tex.loadFromFile(fileName)) {
		this->textures[name] = tex;
	}
}

sf::Texture & AssetManager::GetTexture(std::string name)
{
	return this->textures.at(name); // .at() dziala podobnie do [], lecz nie tworzy nowego klucza w wypadku, gdy danego obiektu nie ma w mapie
}

void AssetManager::LoadFont(std::string name, std::string fileName)
{
	sf::Font font;
	if (font.loadFromFile(fileName)) {
		this->fonts[name] = font;
	}
}

sf::Font & AssetManager::GetFont(std::string name)
{
	return this->fonts.at(name);
}
