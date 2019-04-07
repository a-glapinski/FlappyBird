#include "stdafx.h"
#include "Collision.h"

Collision::Collision()
{
}

bool Collision::CheckSpriteCollision(sf::Sprite  sprite1, const float & scale1, sf::Sprite sprite2, const float & scale2)
{
	// Zeskalowanie sprite'ow - scale1 horyzontalnie, scale2 wertykalnie
	sprite1.setScale(scale1, scale1);
	sprite2.setScale(scale2, scale2);

	// getGlobalBounds() zwraca prostokat wokol danego sprite'a
	sf::Rect<float> rect1 = sprite1.getGlobalBounds(); // Prostokat "wokol" sprite'a
	sf::Rect<float> rect2 = sprite2.getGlobalBounds();

	if (rect1.intersects(rect2)) // Jesli rect1 nachodzi na rect2
		return true;
	else
		return false;
}
