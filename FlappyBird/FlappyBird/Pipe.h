#pragma once

#include <SFML/Graphics.hpp>
#include "Game.h"
#include <vector>
#include "DEFINITIONS.h"

class Pipe {
private:
	GameDataRef data;
	std::vector<sf::Sprite> pipeSprites; // Wektor przechowujacy rury
	std::vector<sf::Sprite> scoringSprites; // Wektor przechowujacy rury uzywane do systemu punktowego
	int groundHeight; // Wysokosc sprite'a ziemi
	int pipeSpawnYOffset; // Okresla jak bardzo chcemy przeniesc zestaw rur w gore lub w dol
public:
	Pipe(GameDataRef data);
	
	void SpawnBottomPipe();
	void SpawnTopPipe();
	void SpawnInvisiblePipe();
	void SpawnScoringPipe(); // Utworzenie rury potrzebnej do systemu punktowego
	void MovePipes(float dt);
	void drawPipes(); // Rysowanie rur
	void RandomisePipeOffset();

	const std::vector<sf::Sprite> &GetSprites() const; // Zwroc referencje do wektora sprite'ow
	std::vector<sf::Sprite> &GetScoringSprites();
};