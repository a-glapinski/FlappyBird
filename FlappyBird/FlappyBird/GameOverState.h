#pragma once
#include <SFML/Graphics.hpp>
#include "State.h"
#include "Game.h"

class GameOverState : public State {
private:
	GameDataRef data; // Referencja do danych gry; okno i system zdarzen
	sf::Sprite background; // Tlo
	sf::Sprite gameOverTitle;
	sf::Sprite gameOverFrame;
	sf::Sprite playButton;
	sf::Text scoreText;

	int score;
public:
	GameOverState(GameDataRef data, int score);
	void Init(); // Inicjalizacja
	void HandleInput(); // Obsluga wejscia i zdarzen 
	void Update(float dt); // Aktualizacja logiki gry - dt: roznica miedzy klatkami
	void Draw(float dt); // Rysowanie zawartosci
};