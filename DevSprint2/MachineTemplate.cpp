#include "MachineTemplate.h"

Miner::Miner()
{
	CoalOreItem coal;
	setAnimateSheet_OFF("Terrain//Machine//Miner//Miner_OFF.png");
	setAnimateSheet_ON("Terrain//Machine//Miner//Miner_ON.png");
	setCraftRecipe({ { coal, 1, 1 } });
	setInBuffer({ {coal,50,50} });
	setOutBuffer({ coal,1,1 });
	setTotalWork(100);
	setWorkPerSecond(33);
}

Smith::Smith()
{
	IronOreItem iron;
	CoalOreItem coal;
	setAnimateSheet_ON("Terrain//Machine//Smith//Smith_ON.png");
	setAnimateSheet_OFF("Terrain//Machine//Smith//Smith_OFF.png");
	setCraftRecipe({{coal, 1, 1}});
	setOutBuffer({iron,1,1});

	setTotalWork(100);
	setWorkPerSecond(20);
}

Chest::Chest()
{
}
