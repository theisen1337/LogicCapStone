#include "MachineTemplate.h"

Miner::Miner()
{
	CoalOreItem coal;
	//coal.setName("I am Coal");
	setAnimateSheet_OFF("Resources//Machine//Miner_OFF.png");
	setAnimateSheet_ON("Resources//Machine//Miner_ON.png");
	setCraftRecipe({ { coal, 1, 1 } });
	setInBuffer({ {coal,50,50} });
	setOutBuffer({ coal,1,1 });
	setTotalWork(100);
	setWorkPerSecond(20);
}

Smith::Smith()
{
	IronOreItem iron;
	CoalOreItem coal;
	//coal.setName("I am Coal in Smith");
	//iron.setName("I am Iron in Smith");

	setAnimateSheet_ON("Resources//Machine//Smith_ON.png");
	setAnimateSheet_OFF("Resources//Machine//Smith_OFF.png");
	setCraftRecipe({{coal, 1, 1}});
	setOutBuffer({iron,1,5});

	setTotalWork(100);
	setWorkPerSecond(20);
}

Chest::Chest()
{
}
