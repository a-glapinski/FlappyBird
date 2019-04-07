#include "stdafx.h"
#include "StateMachine.h"

StateMachine::StateMachine()
{
}

StateMachine::~StateMachine()
{
}

void StateMachine::AddState(StateRef newState, bool isReplacing)
{
	this->isAdding = true;
	this->isReplacing = isReplacing;
	this->newState = std::move(newState);
}

void StateMachine::RemoveState()
{
	this->isRemoving = true;
}

void StateMachine::ProcessStateChanges()
{
	if (this->isRemoving && !this->states.empty()) {
		this->states.pop();
		this->isRemoving = false;
		// Jesli stos nie jest pusty i jesli chcemy usunac stan, to usun stan i ustaw isRemoving na false
	}
	if (this->isAdding) {
		if (!this->states.empty()) {
			if (this->isReplacing) { // Jesli chcemy zastapic obecny stan
				this->states.pop(); // Pozbadz sie obecnego stanu - nie zastepujemy bezposrednio, lecz usuwamy obecny stan
			}
		}
		this->states.push(std::move(this->newState));
		this->states.top()->Init(); // Zainicjalizuj stan
		this->isAdding = false;
	}
}

StateRef & StateMachine::GetActiveState()
{
	return this->states.top();
}
