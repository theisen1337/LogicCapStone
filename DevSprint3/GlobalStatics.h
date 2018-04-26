#pragma once
#include <chrono>

class GlobalStatics 
{
public:

	enum State {
		MAINMENU,
		GAME,
		PAUSE,
		LOADING
	};

	int & getCPS();

	float getRunTime();
	float getGameTime();
	float getPauseTime();

	bool isPaused();

	void setPause(bool Pause);


	void InitializeTime();

	GlobalStatics::State & getState();

	void setState(GlobalStatics::State st);
private:

	

	
};
