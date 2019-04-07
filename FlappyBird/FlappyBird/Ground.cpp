#include "stdafx.h"
#include "Ground.h"
#include "DEFINITIONS.h"

// Stworzenie pary sprite'ow, jeden ktory porusza sie caly czas na ekranie i resetuje sie, gdy wychodzi poza ekran i drugi ktory wchodzi na ekran
Ground::Ground(GameDataRef data) : data(data)
{
	sf::Sprite sprite1(data->assets.GetTexture("Ziemia"));
	sf::Sprite sprite2(data->assets.GetTexture("Ziemia"));
	sprite1.setPosition(0, data->window.getSize().y - sprite1.getGlobalBounds().height);
	sprite2.setPosition(sprite1.getGlobalBounds().width, data->window.getSize().y - sprite2.getGlobalBounds().height); // Sprite2 dotyka sprite1
	groundSprites.push_back(sprite1);
	groundSprites.push_back(sprite2);
}

void Ground::MoveGround(float dt) {
	for (unsigned short int i = 0; i < groundSprites.size(); i++) {
		float movement = PIPE_MOVEMENT_SPEED * dt; // Pomnozone * dt, aby uniezaleznic od FPS
		groundSprites[i].move(-movement, 0.0f);

		if (groundSprites[i].getPosition().x < 0 - groundSprites[i].getGlobalBounds().width) { // Jesli tekstura wychodzi poza ekran
			sf::Vector2f position(data->window.getSize().x, groundSprites[i].getPosition().y); 
			groundSprites[i].setPosition(position);
			// to ustaw teksture na srodek ekranu
		}
	}
}

void Ground::DrawGround()
{
	for (unsigned short int i = 0; i < groundSprites.size(); i++) {
		data->window.draw(groundSprites[i]);
	}
}

const std::vector<sf::Sprite>& Ground::GetSprites() const
{
	return groundSprites;
}
