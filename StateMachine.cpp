#include "StateMachine.h"

using namespace std;

StateMachine::StateMachine()
{
}

void StateMachine::add(unique_ptr<State> newState, bool replace)
{
	isAdding = true;
	isReplacing = replace;

	this->newState = move(newState);
}

void StateMachine::remove()
{
	isRemoving = true;
}

void StateMachine::processChanges()
{
	if (isRemoving && !states.empty()) //Gdy gorny stan ma byc usuniety to
	{
		states.pop();

		if (!states.empty()) //Jesli jest jescze jakis stan to zostaje on wznowiony
			states.top()->resume();

		isRemoving = false;
	}

	if (isAdding)
	{
		if (!states.empty())
		{
			if (isReplacing)
				states.pop();
			else
				states.top()->pause();
		}

		states.push(move(newState));
		states.top()->seteup();

		isAdding = false;
	}
}

std::unique_ptr<State>& StateMachine::getActiveState()
{
	return states.top();
}
