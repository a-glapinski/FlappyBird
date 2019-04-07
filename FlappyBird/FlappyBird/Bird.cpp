#include "stdafx.h"
#include "Bird.h"
#include "DEFINITIONS.h"

Bird::Bird(GameDataRef data) : data(data)
{
	animationIter = 0;
	frames.push_back(data->assets.GetTexture("Ptak"));
	frames.push_back(data->assets.GetTexture("Ptak 2"));
	frames.push_back(data->assets.GetTexture("Ptak 3"));
	frames.push_back(data->assets.GetTexture("Ptak 4"));

	birdSprite.setTexture(frames.at(animationIter));

	// Ustawienie ptaka na szerokosci 25 % okna (zaczynajac od lewej) i od srodka w pionie
	birdSprite.setPosition((data->window.getSize().x / 4) - (birdSprite.getGlobalBounds().width / 2),
		(data->window.getSize().y / 2) - (birdSprite.getGlobalBounds().height / 2)); 
	birdState = BIRD_STATE_STILL;

	sf::Vector2f origin = sf::Vector2f(birdSprite.getGlobalBounds().width / 2,
		birdSprite.getGlobalBounds().height / 2); // Srodek sprite'a ptaka, wzgledem ktorego bedzie sie obracal
	birdSprite.setOrigin(origin);
	rotation = 0; // Domyslny kat rotacji
}

void Bird::Draw() {
	data->window.draw(birdSprite);
}

void Bird::Animate(float dt) {
	if (clock.getElapsedTime().asSeconds() > BIRD_ANIMATION_DURATION / frames.size()) {
		if (animationIter < frames.size() - 1) {
			animationIter++;
		}
		else {
			animationIter = 0;
		}

		birdSprite.setTexture(frames.at(animationIter));
		clock.restart();
	}
}

void Bird::Update(float dt)
{
	if (BIRD_STATE_FALLING == birdState) {
		birdSprite.move(0, GRAVITY*dt); // Ptak nie porusza sie w osi x, reszta obiektow tak
		rotation += ROTATION_SPEED * dt;
		if (rotation > 25.0f) {
			rotation = 25.0f; // Zapobiegniecie obrocenia ptaka powyzej danego kata
		}
		birdSprite.setRotation(rotation);
	}
	else if (BIRD_STATE_FLYING==birdState) {
		birdSprite.move(0, - FLYING_SPEED*dt); // (0,0) w lewym gornym rogu, dlatego jest -
		rotation -= ROTATION_SPEED * dt;
		if (rotation < -25.0f) {
			rotation = -25.0f; // Zapobiegniecie obrocenia ptaka powyzej danego kata
		}
		birdSprite.setRotation(rotation);
	}
	if (movementClock.getElapsedTime().asSeconds() > FLYING_DURATION) {
		movementClock.restart();
		birdState = BIRD_STATE_FALLING;
	} // Zrestartuj zegar i spowoduj, ze ptak zacznie opadac
}

void Bird::Tap() {
	movementClock.restart(); // Restartujemy zegar, bo nie wiemy jak dlugo czekac na wcisniecie LPM, przez uzytkownika
	birdState = BIRD_STATE_FLYING;
}

const sf::Sprite & Bird::GetSprite() const
{
	return birdSprite;
}
