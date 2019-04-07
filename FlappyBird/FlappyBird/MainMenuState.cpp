#include "stdafx.h"
#include "MainMenuState.h"
#include "GameState.h"
#include "DEFINITIONS.h"
#include <iostream>

MainMenuState::MainMenuState(GameDataRef data) : data(data)
{
}

void MainMenuState::Init()
{
	this->data->assets.LoadTexture("Tlo Menu Glownego", MAIN_MENU_BG_FILEPATH);
	this->data->assets.LoadTexture("Tytul Gry", TITLE_FILEPATH);
	this->data->assets.LoadTexture("Przycisk Play", PLAY_BUTTON_FILEPATH);

	background.setTexture(this->data->assets.GetTexture("Tlo Menu Glownego"));
	title.setTexture(this->data->assets.GetTexture("Tytul Gry"));
	playButton.setTexture(this->data->assets.GetTexture("Przycisk Play"));

	title.setPosition((SCREEN_WIDTH / 2) - (title.getGlobalBounds().width / 2), title.getGlobalBounds().height / 2);
	playButton.setPosition((SCREEN_WIDTH / 2) - (playButton.getGlobalBounds().width / 2), (SCREEN_HEIGHT / 2) - (playButton.getGlobalBounds().height / 2));
}

void MainMenuState::HandleInput()
{
	sf::Event event; // Zdarzenie
	while (this->data->window.pollEvent(event)) // Podczas gdy zdarzenie jest przeprowadzane
	{
		if (sf::Event::Closed == event.type) // Jesli wcisnelismy X
		{
			this->data->window.close();
		}
		if (this->data->input.IsSpriteClicked(this->playButton, sf::Mouse::Left, this->data->window)) // Jesli wcisnelismy przycisk Play
		{
			std::cout << "Idz do Ekranu Gry" << std::endl;
			this->data->machine.AddState(StateRef(new GameState(data)), true);
		}
	}
}

void MainMenuState::Update(float dt)
{
	// Nie robi nic
}

void MainMenuState::Draw(float dt)
{
	this->data->window.clear(sf::Color::Red); // Wyczyszczenie zawartosci okna (tlo koloru czerwonego)

	this->data->window.draw(this->background);
	this->data->window.draw(this->title);
	this->data->window.draw(this->playButton);

	this->data->window.display();
}