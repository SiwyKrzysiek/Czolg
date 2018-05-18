#pragma once

/**
 * \brief Klasa wirtualna stanu rozgrywki
 */
class State
{
public:
	virtual void steup() = 0;

	virtual void handleInput() = 0;
	virtual void update(float dt) = 0;
	virtual void draw(float dt) = 0;

	virtual void pause() { }
	virtual void resume() { }
};
