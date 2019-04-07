#pragma once
#include <SFML/Graphics.hpp>
#include "DEFINITIONS.h"
#include "Game.h"

class HUD {
private:
	GameDataRef data;
	sf::Text scoreText; // Obiekt wyswietlajacy tekst
public:
	HUD(GameDataRef data);
	void Draw();
	void UpdateScore(int &score); // Zaktualizuj wynik
};