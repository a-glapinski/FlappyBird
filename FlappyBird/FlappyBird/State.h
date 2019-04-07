#pragma once

// Stan - ekran gry
class State {
public:
	// Inicjalizacja
	virtual void Init() = 0; 
	// Obsluga wprowadzanych danych (myszka)
	virtual void HandleInput() = 0;
	// Aktualizacja danych gry po otrzymaniu danych od uzytkownika
	virtual void Update(float dt) = 0;
	// Rysowanie
	virtual void Draw(float dt) = 0;
	// dt - roznica miedzy klatkami, umozliwia uniezaleznienie od liczby klatek na sekunde
};