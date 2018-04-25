#pragma once
#include <chrono>

class GlobalStatics 
{
public:
	int & getCPS();

	float getRunTime();
	float getGameTime();
	float getPauseTime();

	bool isPaused();

	void setPause(bool Pause);


	void InitializeTime();
private:

	

	
};
