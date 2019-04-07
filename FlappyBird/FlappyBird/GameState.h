#pragma once
#include <SFML/Graphics.hpp>
#include "State.h"
#include "Game.h"
#include "Pipe.h"
#include "Ground.h"
#include "Bird.h"
#include "Collision.h"
#include "HUD.h"

class GameState : public State {
private:
	GameDataRef data; // Referencja do danych gry; okno i system zdarzen
	sf::Clock clock; // Sprawdzenie w metodzie Update, czy minal okreslony czas (PIPE_SPAWN_FREQUENCY)
	sf::Sprite background; // Tlo
	Pipe *pipe;
	Ground *ground;
	Bird *bird;
	Collision collision;
	HUD *hud;

	int gameState; // stan gry
	int score; // liczba punktow
public:
	GameState(GameDataRef data);
	void Init(); // Inicjalizacja
	void HandleInput(); // Obsluga wejscia i zdarzen 
	void Update(float dt); // Aktualizacja logiki gry - dt: roznica miedzy klatkami
	void Draw(float dt); // Rysowanie zawartosci
};