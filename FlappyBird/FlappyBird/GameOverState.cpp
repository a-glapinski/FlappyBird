#include "stdafx.h"
#include "GameOverState.h"
#include "DEFINITIONS.h"
#include <iostream>
#include "GameState.h"

GameOverState::GameOverState(GameDataRef data, int score) : data(data), score(score)
{
}

void GameOverState::Init()
{
	std::cout << "Koniec gry" << std::endl;
	this->data->assets.LoadTexture("Tlo Koniec Gry", GAME_OVER_BG_FILEPATH);
	this->data->assets.LoadTexture("Tytul Koniec Gry", GAME_OVER_TITLE_FILEPATH);
	this->data->assets.LoadTexture("Ramka Koniec Gry", GAME_OVER_FRAME_FILEPATH);
	// Przycisk Play jest juz wczytany

	background.setTexture(this->data->assets.GetTexture("Tlo Koniec Gry"));	
	gameOverTitle.setTexture(this->data->assets.GetTexture("Tytul Koniec Gry"));
	gameOverFrame.setTexture(this->data->assets.GetTexture("Ramka Koniec Gry"));
	playButton.setTexture(this->data->assets.GetTexture("Przycisk Play"));

	// Pozycja ramki
	gameOverFrame.setPosition((data->window.getSize().x / 2 - gameOverFrame.getGlobalBounds().width/2),
		(data->window.getSize().y / 2 - gameOverFrame.getGlobalBounds().height / 2));
	// Pozycja napisu Game Over
	gameOverTitle.setPosition((data->window.getSize().x / 2 - gameOverTitle.getGlobalBounds().width / 2),
		(gameOverFrame.getPosition().y - gameOverTitle.getGlobalBounds().height * 1.2f)); // Zapewnia, ze napis Game Over jest zawsze nad ramka
	// Pozycja przycisku Play
	playButton.setPosition(data->window.getSize().x / 2 - playButton.getGlobalBounds().width / 2,
		gameOverFrame.getPosition().y + gameOverFrame.getGlobalBounds().height + playButton.getGlobalBounds().height*0.2f);
	// Wynik
	scoreText.setFont(data->assets.GetFont("Czcionka Flappy"));
	scoreText.setString(std::to_string(score));
	scoreText.setCharacterSize(128);
	scoreText.setFillColor(sf::Color::White);
	scoreText.setOrigin(scoreText.getGlobalBounds().width / 2, scoreText.getGlobalBounds().height / 2); // Srodek tekstu
	scoreText.setPosition(data->window.getSize().x / 2, data->window.getSize().y / 2);
}

void GameOverState::HandleInput()	
{
	sf::Event event; // Zdarzenie
	while (this->data->window.pollEvent(event)) // Podczas gdy zdarzenie jest przeprowadzane
	{
		if (sf::Event::Closed == event.type) // Jeœli wcisnelismy x
		{
			this->data->window.close();
		}
		if (data->input.IsSpriteClicked(playButton, sf::Mouse::Left, data->window)) {
			data->machine.AddState(StateRef(new GameState(data)), true); // Podmien stan na Podczas gry
		}
	}
}

void GameOverState::Update(float dt)
{
	// Nie robi nic
}

void GameOverState::Draw(float dt)
{
	this->data->window.clear(sf::Color::Black); // Wyczyszczenie zawartosci okna (tlo koloru czarnego)
	this->data->window.draw(this->background);
	this->data->window.draw(this->gameOverTitle);
	this->data->window.draw(this->gameOverFrame);
	this->data->window.draw(this->playButton);
	this->data->window.draw(this->scoreText);

	this->data->window.display();
}
