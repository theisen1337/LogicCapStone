#pragma once

class GlobalStatics 
{
public:

	enum State {
		MAINMENU,
		GAME,
		PAUSE
	};


	int & getCPS();

	GlobalStatics::State & getState();

	void setState(GlobalStatics::State st);
};



