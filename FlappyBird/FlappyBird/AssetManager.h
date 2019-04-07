#pragma once

#include <map>
#include <SFML/Graphics.hpp>

class AssetManager {
private:
	std::map<std::string, sf::Texture> textures; // Przechowywanie tekstur o danej nazwie w std::map
	std::map<std::string, sf::Font> fonts; // Przechowywanie czcionek o danej nazwie w std::map
public:
	AssetManager();
	~AssetManager();

	void LoadTexture(std::string name, std::string fileName);
	sf::Texture &GetTexture(std::string name);

	void LoadFont(std::string name, std::string fileName);
	sf::Font &GetFont(std::string name);
};