#pragma once

#include <SFML/Graphics.hpp>

class InputManager {
public:
	InputManager();
	~InputManager();
	bool IsSpriteClicked(sf::Sprite object, sf::Mouse::Button button,
		sf::RenderWindow& window); // Czy wcisnieto LPM na teksturze
	sf::Vector2i GetMousePosition(sf::RenderWindow &window); // Zwroc Vector2i - wektor (x, y) typu int zawierajacy pozycje
};