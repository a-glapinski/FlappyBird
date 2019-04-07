#pragma once

#include <memory>
#include <stack>
#include "State.h"

typedef std::unique_ptr<State> StateRef; // Unique pointer do stanu gry

// Sluzy do przelaczania sie miedzy ekranami gry
class StateMachine {
private:
	std::stack<StateRef> states; // Stos, na ktorym znajduja sie wszystkie zainicjalizowane stany
	StateRef newState; // Najnowszy stan do dodania na stos
	bool isRemoving; // Czy usuwamy, dodajemy, zastepujemy stan (ekran gry) 
	bool isAdding;
	bool isReplacing;
public:
	StateMachine();
	~StateMachine();

	void AddState(StateRef newState, bool isReplacing = true); // Dodaj stan na stos
	void RemoveState(); // Usun stan ze stosu
	void ProcessStateChanges(); // Uruchamiane na poczatku kazdej petli gry

	StateRef& GetActiveState(); // Zwraca stan gry na wierzcholku stosu
};
