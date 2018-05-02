#pragma once

// Standard Includes
#include <chrono>

class GlobalStatics 
{
public:
	//! Loads Game States
	enum State {
		MAINMENU,
		GAME,
		PAUSE,
		LOADING
	};

	//! Returns CPS Speed
	int & getCPS();
	//! Returns RunTime
	float getRunTime();
	//! Returns GameTime
	float getGameTime();
	//! Returns PauseTime
	float getPauseTime();

	//! Checks if Game is Paused
	bool isPaused();
	//! Changes Pause State
	void setPause(bool Pause);

	//! Initializes Game Time
	void InitializeTime();

	//! Returns State of Game
	GlobalStatics::State & getState();
	//! Sets the State of Game
	void setState(GlobalStatics::State st);
	
};
