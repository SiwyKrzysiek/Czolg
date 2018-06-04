#pragma once

/**
 * \brief Klasa wirtualna stanu rozgrywki
 */
class State
{
public:
	virtual ~State() = default;
	virtual void seteup() = 0;

	virtual void handleInput() = 0;
	virtual void update() = 0;
	virtual void draw() = 0;

	virtual void pause() { }
	virtual void resume() { }
};
