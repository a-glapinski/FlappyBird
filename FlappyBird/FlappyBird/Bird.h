#pragma once
#include <SFML/Graphics.hpp>
#include "DEFINITIONS.h"
#include "Game.h"

class Bird {
private:
	GameDataRef data;
	sf::Sprite birdSprite;
	// Animacja
	std::vector<sf::Texture> frames;
	unsigned int animationIter;
	sf::Clock clock;

	sf::Clock movementClock; // Sledzi ruch ptaka, aby zresetowac timer i pozwolic naciskac LPM 
	int birdState; // Obecny stan ptaka (1/2/3)
	float rotation; // Wartosc obrotu
public:
	Bird(GameDataRef data);
	void Draw();
	void Animate(float dt);

	void Update(float dt);
	void Tap(); // Uaktywniona po wcisnieciu LPM

	const sf::Sprite& GetSprite() const; // Zwraca referencje do sprite'a ptaka
};