#include "MachineTemplate.h"

Miner::Miner()
{
	setAnimateSheet_OFF("Terrain//Machine//Miner//Miner_OFF.png");
	setAnimateSheet_ON("Terrain//Machine//Miner//Miner_ON.png");
	setTotalWork(100);
	setWorkPerSecond(50);
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
