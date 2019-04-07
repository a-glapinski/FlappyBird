#pragma once
#include "State.h"
#include "Game.h"
class MainMenuState : public State
{
private:
	GameDataRef data; // Referencja do danych gry; okno i system zdarzen
					   // Sprite - reprezentacja tekstury, ktora mozna narysowac
	sf::Sprite background; // Tlo
	sf::Sprite title; // Tytul
	sf::Sprite playButton; // Przycisk Play
public:
	MainMenuState(GameDataRef data);

	void Init(); // Inicjalizacja
	void HandleInput(); // Obsluga wejscia i zdarzen 
	void Update(float dt); // Aktualizacja logiki gry - dt: roznica miedzy klatkami
	void Draw(float dt); // Rysowanie zawartosci
};