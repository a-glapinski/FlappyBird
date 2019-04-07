#include "stdafx.h"
#include "HUD.h"
#include <string>

HUD::HUD(GameDataRef data) : data(data)
{
	scoreText.setFont(data->assets.GetFont("Czcionka Flappy"));
	scoreText.setString("0"); // Wartosc poczatkowa
	scoreText.setCharacterSize(128); // Wielkosc czcionki, w pikselach
	scoreText.setFillColor(sf::Color::White); // Bialy kolor czcionki
	scoreText.setOrigin(scoreText.getGlobalBounds().width / 2, scoreText.getGlobalBounds().height / 2); // Ustawiamy pozycje,
	// wzgledem ktorej przesuwamy obiekt, aby po przekroczeniu 9 tekst nadal byl wysrodkowany i zeby nie trzeba bylo go przestawiac
	scoreText.setPosition(data->window.getSize().x / 2, data->window.getSize().y / 5);
}

void HUD::Draw()
{
	data->window.draw(scoreText);
}

void HUD::UpdateScore(int & score)
{
	scoreText.setString(std::to_string(score)); // std::to_string zamienia liczbe na string
}
