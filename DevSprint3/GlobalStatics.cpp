/*




		All statics should be in this class, every object not in the one class is NOT a static!
		Why statics? well Im becuase its on the fence if we want objects to be pass throw by refference or create a static object?
		Why One Class? Well so other classes that need to implement these objects only have to call one class.
		Also in one class, so we know where every stupid static object is located in the program.

		ex. MachineLayer, why? MachineLayer Object holds every machine in game, we dont need more then one. 
		Also two different classes MainCompute and MainDraw are refferencing the same object, and instead of declaring MachineLayer
		inside StateManager and passing into both mainDraw and mainCompute




*/
#include "GlobalStatics.h"


static int TicksPerSecond;
static auto RunTime = std::chrono::high_resolution_clock::now();
static auto PauseTime = std::chrono::high_resolution_clock::now();

static bool InitialClock = true;
static bool isPausedB = false;
static float TotalPauseTime = 0;

static GlobalStatics::State gameState = GlobalStatics::MAINMENU;

void GlobalStatics::InitializeTime()
{
	//only allow the RunTime Clock to be set to zero once.
	if (InitialClock)
	{
		RunTime = std::chrono::high_resolution_clock::now();
		InitialClock = false;
	}
}




// Recieve RunTime
float GlobalStatics::getRunTime()
{
	auto current = std::chrono::high_resolution_clock::now(); //Grab time now
	float time = std::chrono::duration<float, std::chrono::seconds::period>(current - RunTime).count(); // difference between timestamp now and timestamp and beginning of Program.
	return time;
}

float GlobalStatics::getGameTime()
{
	return getRunTime() - getPauseTime();
}

float GlobalStatics::getPauseTime()
{
	if (isPausedB)
	{
		auto current = std::chrono::high_resolution_clock::now();
		TotalPauseTime += std::chrono::duration<float, std::chrono::seconds::period>(current - PauseTime).count();
		PauseTime = std::chrono::high_resolution_clock::now();
	}
	return TotalPauseTime;
}

void GlobalStatics::setPause(bool Pause)
{
	
	if (Pause && isPausedB)	//Game has been paused, after already being paused.
	{
		throw "Developer has made a mistake in calling Pause, GlobalStatics.cpp, setPause()\n";
	}
	else if (Pause)			//Game has been paused while not being paused
	{
		isPausedB = true;
		PauseTime = std::chrono::high_resolution_clock::now();
	}
	else if (!Pause && !isPausedB)
	{
		throw "Developer has made a mistake in calling Pause, GlobalStatics.cpp, setPause()\n";
	}
	else					//Game has been unpaused.
	{
		getPauseTime();
		isPausedB = false;
	}
}

bool GlobalStatics::isPaused()
{ 
	return isPausedB; 
}

int & GlobalStatics::getCPS()
{
	return TicksPerSecond;
}

GlobalStatics::State & GlobalStatics::getState()
{
	return gameState;
}

void GlobalStatics::setState(GlobalStatics::State st)
{
	gameState = st;
}