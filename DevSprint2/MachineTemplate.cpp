#include "MachineTemplate.h"

Miner::Miner()
{
	CoalOreItem coal;
	setAnimateSheet_OFF("Resources//Machine//Miner_OFF.png");
	setAnimateSheet_ON("Resources//Machine//Miner_ON.png");
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
	setAnimateSheet_ON("Resources//Machine//Smith_ON.png");
	setAnimateSheet_OFF("Resources//Machine//Smith_OFF.png");
	setCraftRecipe({{coal, 1, 1}});
	setOutBuffer({iron,1,1});

	setTotalWork(100);
	setWorkPerSecond(20);
}

Chest::Chest()
{
}
