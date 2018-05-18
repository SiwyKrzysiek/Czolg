#pragma once

#include <memory>
#include <stack>
#include "State.h"

/**
 * \brief Klasa realizujaca wzorzec projektowy State Pattern
 */
class StateMachine
{
private:
	std::stack<std::unique_ptr<State>> states;
	std::unique_ptr<State> newState;

	//Zmienne opisujace stan automatu
	bool isRemoving;
	bool isAdding;
	bool isReplacing;

public:
	StateMachine();
	~StateMachine();

	/**
	 * \brief Dodanie nowego stanu na gore stosu
	 * \param newState Stan do dodania
	 * \param replace Czy ma on zastopic aktualny stan
	 */
	void add(std::unique_ptr<State> newState, bool replace = true);
	void remove();

	void processChanges();

	std::unique_ptr<State> getActiveState() const;
};

