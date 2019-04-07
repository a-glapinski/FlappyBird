#include "stdafx.h"
#include "GameState.h"
#include "DEFINITIONS.h"
#include <iostream>
#include "GameOverState.h"

GameState::GameState(GameDataRef data) : data(data)
{
}

void GameState::Init()
{
	std::cout << "Gra zainicjalizowana" << std::endl;
	this->data->assets.LoadTexture("Tlo Gry", GAME_BG_FILEPATH); // Wczytywanie tekstury tla gry
	this->data->assets.LoadTexture("Rura Gora", PIPE_UP_FILEPATH); 
	this->data->assets.LoadTexture("Rura Dol", PIPE_DOWN_FILEPATH); 
	this->data->assets.LoadTexture("Ziemia", GROUND_FILEPATH); 

	this->data->assets.LoadTexture("Ptak", BIRD_FRAME_1_FILEPATH);
	this->data->assets.LoadTexture("Ptak 2", BIRD_FRAME_2_FILEPATH);
	this->data->assets.LoadTexture("Ptak 3", BIRD_FRAME_3_FILEPATH);
	this->data->assets.LoadTexture("Ptak 4", BIRD_FRAME_4_FILEPATH);


	this->data->assets.LoadTexture("Rura Punkty", SCORING_PIPE_FILEPATH);
	this->data->assets.LoadFont("Czcionka Flappy", FONT_FILEPATH);

	pipe = new Pipe(data); // Tworzenie obiektu rury
	ground = new Ground(data);
	bird = new Bird(data);
	hud = new HUD(data);
	
	background.setTexture(this->data->assets.GetTexture("Tlo Gry"));

	score = 0;
	hud->UpdateScore(score); // Ustawianie poczatkowej wartosci punktow

	gameState = GameStates::Playing; // Stan - podczas gry
}

void GameState::HandleInput()
{
	sf::Event event; // Zdarzenie
	while (this->data->window.pollEvent(event)) // Podczas gdy zdarzenie jest przeprowadzane
	{
		if (sf::Event::Closed == event.type) // Jeœli wcisnelismy x
		{
			this->data->window.close();
		}
		if (data->input.IsSpriteClicked(background, sf::Mouse::Left, data->window)) { // Jesli wcisniemy na tlo
			if (GameStates::GameOver != gameState) { // Uniemozliwienie dzialania po game over
				bird->Tap();
			}
		}
	}
}

void GameState::Update(float dt)
{
	if (GameStates::Playing == gameState) {
		ground->MoveGround(dt);
		pipe->MovePipes(dt);
		if (clock.getElapsedTime().asSeconds() > PIPE_SPAWN_INTERVAL) {
			// Tworzenie rur
			pipe->RandomisePipeOffset(); // Generowanie losowych wysokosci rur
			pipe->SpawnInvisiblePipe();
			pipe->SpawnBottomPipe();
			pipe->SpawnTopPipe();
			pipe->SpawnScoringPipe();
			//std::cout << "Utworzono rury" << std::endl;
			clock.restart();
		}
		bird->Animate(dt);
		bird->Update(dt);
		
		// Kolizje
		std::vector<sf::Sprite> groundSprites = ground->GetSprites();
		for (unsigned int i = 0; i < groundSprites.size(); i++) { // Petla sprawdzajaca czy ptak koliduje z ziemia
			if (collision.CheckSpriteCollision(bird->GetSprite(), 0.7f, groundSprites[i], 1.0f)) {
				gameState = GameStates::GameOver; // Jesli tak, ustaw stan gry na Game Over
				std::cout << "Uderzono w ziemie" << std::endl;
				clock.restart();
			}
		}
		std::vector<sf::Sprite> pipeSprites = pipe->GetSprites();
		for (unsigned int i = 0; i < pipeSprites.size(); i++) { // Petla sprawdzajaca czy ptak koliduje z rura
			if (collision.CheckSpriteCollision(bird->GetSprite(), 0.625f, pipeSprites[i], 1.0f)) {
				gameState = GameStates::GameOver; // Jesli tak, ustaw stan gry na Game Over
				std::cout << "Uderzono w rure" << std::endl;
				clock.restart();
			}
		}
		// System punktow - kolizje
		if (GameStates::Playing == gameState) { // Sprawdzamy ponownie czy stan gry jest na Podczas gry, poniewaz powyzej widac, ze moze on przejsc na Game Over
			// Ten warunek zapobiega dodawaniu punktu po uderzeniu w rure, poniewaz niewidzialna rura punktow jest tej samej szerokosci co widoczna rura
			std::vector<sf::Sprite> &scoringSprites = pipe->GetScoringSprites(); // System punktow; referencja, zeby moc usuwac 
			for (int i = 0; i < scoringSprites.size(); i++) { // Petla sprawdzajaca czy ptak koliduje z rura
				if (collision.CheckSpriteCollision(bird->GetSprite(), 0.625f, scoringSprites[i], 1.0f)) {
					score++;
					std::cout << score << std::endl;
					hud->UpdateScore(score);
					scoringSprites.erase(scoringSprites.begin() + i);
				}
			}
		}
	}
	if (GameStates::GameOver == gameState) {
		if (clock.getElapsedTime().asSeconds() > TIME_BEFORE_GAME_OVER) {
			data->machine.AddState(StateRef(new GameOverState(data, score)), true); // Zastap stan Podczas gry stanem Game Over
		}
	}
}

// Rysowanie obiektow
void GameState::Draw(float dt)
{
	this->data->window.clear(sf::Color::Red); // Wyczyszczenie zawartosci okna (tlo koloru czerwonego)
	this->data->window.draw(this->background); // Rysowanie tla, potem rur
	pipe->drawPipes();
	ground->DrawGround();
	bird->Draw();
	hud->Draw();
	this->data->window.display();
}