#include "stdafx.h"
#include "Pipe.h"
#include <iostream>

Pipe::Pipe(GameDataRef data) : data(data)
{
	groundHeight = data->assets.GetTexture("Ziemia").getSize().y;
	pipeSpawnYOffset = 0;
}

void Pipe::SpawnBottomPipe()
{
	sf::Sprite sprite(data->assets.GetTexture("Rura Gora")); // Rura z "wyjsciem" u gory
	sprite.setPosition(data->window.getSize().x, data->window.getSize().y - sprite.getGlobalBounds().height - pipeSpawnYOffset);
	pipeSprites.push_back(sprite);
}

void Pipe::SpawnTopPipe()
{
	sf::Sprite sprite(data->assets.GetTexture("Rura Dol")); // Rura z "wyjsciem" u gory
	sprite.setPosition(data->window.getSize().x, -pipeSpawnYOffset);
	pipeSprites.push_back(sprite);
}

void Pipe::SpawnInvisiblePipe()
{
	sf::Sprite sprite(data->assets.GetTexture("Rura Dol")); // Rura z "wyjsciem" u gory
	sprite.setPosition(data->window.getSize().x, data->window.getSize().y - sprite.getGlobalBounds().height);
	sprite.setColor(sf::Color(0, 0, 0, 0)); // Sprawienie ze rura jest niewidzialna
	pipeSprites.push_back(sprite);
}

void Pipe::SpawnScoringPipe()
{
	sf::Sprite sprite(data->assets.GetTexture("Rura Punkty")); // Niewidzialna rura, na calej wysokosci ekranu, po dotknieciu ktorej wartosc punktow wzrosnie o 1
	sprite.setPosition(data->window.getSize().x, 0);
	sprite.setColor(sf::Color(0, 0, 0, 0)); // Sprawienie ze rura jest niewidzialna
	scoringSprites.push_back(sprite);
}

void Pipe::MovePipes(float dt)
{
	for (unsigned short int i = 0; i < pipeSprites.size(); i++) {
		if (pipeSprites[i].getPosition().x < 0 - pipeSprites[i].getGlobalBounds().width) { // Granica jest w lewym gornym rogu, nie chcemy zeby rura zniknela w momencie, gdy dotknie brzeg ekranu
			pipeSprites.erase(pipeSprites.begin() + i);
		}
		else {
			float movement = PIPE_MOVEMENT_SPEED * dt; // Pomnozenie przez roznice czasu dt miedzy kolejnymi klatkami umozliwia uniezaleznienie od FPS
			pipeSprites[i].move(-movement, 0); // -movement: porusza w lewo, 0: w pionie 
		}
	}
	// System punktow
	for (unsigned short int i = 0; i < scoringSprites.size(); i++) {
		if (scoringSprites[i].getPosition().x < 0 - scoringSprites[i].getGlobalBounds().width) {
			scoringSprites.erase(scoringSprites.begin() + i);
		}
		else {
			float movement = PIPE_MOVEMENT_SPEED * dt; 
			scoringSprites[i].move(-movement, 0);
		}
	}
}

void Pipe::drawPipes() {
	for (unsigned short int i = 0; i < pipeSprites.size(); i++) {
		data->window.draw(pipeSprites[i]);
	}
}

void Pipe::RandomisePipeOffset()
{
	pipeSpawnYOffset = rand() % (groundHeight + 1);
}

const std::vector<sf::Sprite>& Pipe::GetSprites() const
{
	return pipeSprites;
}

std::vector<sf::Sprite>& Pipe::GetScoringSprites()
{
	return scoringSprites;
}
