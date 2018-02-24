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
	if (!arrMachines.empty())
	{
		for (int i = 0; i < arrMachines.size(); i++)
			arrMachines.at(i).Compute();
	}
}

void MachineLayer::Draw()
{
	if (!arrMachines.empty())
	{
		for (int i = 0; i < arrMachines.size(); i++)
			arrMachines.at(i).Draw();
	}
}


MachineLayer::~MachineLayer()
{
}
