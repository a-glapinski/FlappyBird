#pragma once

#include <memory>
#include <string>
#include <SFML/Graphics.hpp>
#include "StateMachine.h"
#include "AssetManager.h"
#include "InputManager.h"

// Struktura przechowujaca dane gry, maja do niej dostep wszystkie klasy
struct GameData {
	StateMachine machine;
	sf::RenderWindow window;
	AssetManager assets;
	InputManager input;
};

// Umozliwia dostep do GameData poprzez wskaznik
typedef std::shared_ptr<GameData> GameDataRef;

class Game {
private:
	const float dt = 1.0f / 60.0f; // FPS - 60 klatek na sekunde
	sf::Clock clock; // Zegar

	GameDataRef data = std::make_shared<GameData>();
	void Run();
public:
	Game(int width, int height, std::string title);
};