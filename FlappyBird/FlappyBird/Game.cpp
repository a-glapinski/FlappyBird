#include "stdafx.h"
#include "Game.h"
#include "MainMenuState.h"

Game::Game(int width, int height, std::string title)
{
	data->window.create(sf::VideoMode(width, height), title,
		sf::Style::Close | sf::Style::Titlebar);
	data->machine.AddState(StateRef(new MainMenuState(this->data))); // Uruchom Menu Glowne
	this->Run();	
}

void Game::Run() {
	float newTime, frameTime, interpolation;
	float currentTime = this->clock.getElapsedTime().asSeconds(); // Czas, jaki minal od momentu uruchomienia zegara
	float accumulator = 0.0f; // Sluzy do sumowania czasu pomiedzy klatkami
	while (this->data->window.isOpen()) { // Jesli okno jest otwarte
		this->data->machine.ProcessStateChanges(); // Przetwarzanie stanow gry (ekranow)
		newTime = this->clock.getElapsedTime().asSeconds();
		frameTime = newTime - currentTime; // Czas pomiedzy kolejnymi klatkami
		if (frameTime > 0.25f) {
			frameTime = 0.25f; // Ogranicza czas pomiedzy klatkami do 0.25
		}
		currentTime = newTime;
		accumulator += frameTime; // Suma czasu pomiedzy kolejnymi klatkami

		while (accumulator >= dt) { // Obsluga myszki i odswiezanie danych gry
			this->data->machine.GetActiveState()->HandleInput();
			this->data->machine.GetActiveState()->Update(dt);
			accumulator -= dt;
		}
		interpolation = accumulator / dt; // Zapewnia plynnosc animacji
		this->data->machine.GetActiveState()->Draw(interpolation);
	}
}
