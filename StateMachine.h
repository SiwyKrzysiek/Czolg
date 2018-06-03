#pragma once

#include <memory>
#include <stack>
#include "State.h"

/**
 * \brief Klasa realizujaca wzorzec projektowy State Pattern
 * Zarzadza stanem w kturym jest program
 */
class StateMachine
{
private:
	StateMachine();

	std::stack<std::unique_ptr<State>> states;
	std::unique_ptr<State> newState;
	
	//Zmienne opisujace stan automatu
	bool isRemoving;
	bool isAdding;
	bool isReplacing;

public:
	StateMachine(StateMachine& a) = delete;

	static StateMachine & getInstance()
	{
		static StateMachine instance;
		return instance;
	}

	/**
	 * \brief Dodanie nowego stanu na gore stosu
	 * \param newState Stan do dodania
	 * \param replace Czy ma on zastopic aktualny stan
	 */
	void add(std::unique_ptr<State> newState, bool replace = true);
	void remove();

	void processChanges();

	std::unique_ptr<State>& getActiveState();
};

