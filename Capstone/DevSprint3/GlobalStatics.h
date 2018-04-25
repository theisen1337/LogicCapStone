#pragma once

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

	GlobalStatics::State & getState();

	void setState(GlobalStatics::State st);
};




