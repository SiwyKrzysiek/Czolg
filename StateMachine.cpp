#include "StateMachine.h"

using namespace std;

StateMachine::StateMachine()
{
}


StateMachine::~StateMachine()
{
}

void StateMachine::add(unique_ptr<State> newState, bool replace)
{
	isAdding = true;
	isReplacing = replace;

	this->newState = move(newState);
}
