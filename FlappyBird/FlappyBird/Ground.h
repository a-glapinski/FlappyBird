#pragma once
#include <SFML/Graphics.hpp>
#include "Game.h"
#include <vector>

class Ground {
private:
	GameDataRef data;
	std::vector<sf::Sprite> groundSprites; // Wektor przechowujacy 2 sprite'y ziemi
public:
	Ground(GameDataRef data);

	void MoveGround(float dt);
	void DrawGround();

	const std::vector<sf::Sprite> &GetSprites() const; // Zwraca wektor 2 sprite'ow ziemi
};