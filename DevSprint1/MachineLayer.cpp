#include "MachineLayer.h"



MachineLayer::MachineLayer()
{

	//Miner mine1 = Miner();
	//Smith smith1 = Smith();

	//Layer.push_back(Miner());
	//Layer.push_back(smith1);
}



void MachineLayer::Compute()
{
	if (!Layer.empty())
	{
		for (int i = 0; i < Layer.size(); i++)
			Layer.at(i).Compute();
	}
}

void MachineLayer::Draw()
{
	if (!Layer.empty())
	{
		for (int i = 0; i < Layer.size(); i++)
			Layer.at(i).Draw();
	}
}


MachineLayer::~MachineLayer()
{
}