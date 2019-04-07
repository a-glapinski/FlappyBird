#pragma once
#include <SFML/Graphics.hpp>

class Collision {
public:
	Collision();
	bool CheckSpriteCollision(sf::Sprite sprite1, const float &scale1, sf::Sprite sprite2, const float &scale2); // Jesli nachodza na siebie, zwracamy true
	// potrzebna skala, aby zeskalowac sprite'y, by uzyskac odpowiednia kolizje obiektow (w przeciwnym wypadku nie dotykaja sie)
};