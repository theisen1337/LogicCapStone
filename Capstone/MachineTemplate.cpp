#include "MachineTemplate.h"

Miner::Miner()
{
	
}

Smith::Smith()
{
	setAnimateSheet_ON("Terrain//Machine//Smith_ON.png");
	setAnimateSheet_OFF("Terrain//Machine//Smith_OFF.png");
	setTotalWork(100);
	setWorkPerSecond(20);
}

Chest::Chest()
{
}
