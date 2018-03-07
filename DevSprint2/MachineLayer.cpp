#include "MachineLayer.h"
#include "vector"
#include "ItemTemplate.h"


//struct Stack
//{
//	Items i;
//	int n;
//	int max;
//};

//struct movement {
//	float scroll_x;
//	float scroll_y;
//	float zoom;
//	float rotate;
//
//};
#include "transportTemplate.h"

MachineLayer::MachineLayer()
{
	
}

void MachineLayer::Init(FastTrack & fast, SlowTrack & slow)
{
	CoalOreItem coal;
	IronOreItem iron;
	Miner mine1 = Miner();
	mine1.setCraftRecipe({ { coal,1,1 } });
	mine1.setPlacement(128*8, 128*8);
	mine1.setOutBuffer({iron,0,10});

	Miner mine2 = Miner();
	mine2.setCraftRecipe({ { iron,1,1 } });
	mine2.setPlacement((64*2) * 8, (64*2) * 12);



	Smith smith1 = Smith();
	smith1.setCraftRecipe({ { coal,1,1 },{ iron,1,1 } });
	smith1.setPlacement(128*12,128*12);
	arrMachines.push_back(mine1);
	arrMachines.push_back(mine2);
	arrMachines.push_back(smith1);


	fast.startingNode(mine2);
	fast.enddingNode(smith1);
	fast.layTrack(mine2.getPlacementX(),mine2.getPlacementY(),smith1.getPlacementX(),smith1.getPlacementY());

	slow.startingNode(mine1);
	slow.enddingNode(smith1);
	slow.layTrack(mine1.getPlacementX(), mine1.getPlacementY(), smith1.getPlacementX(), smith1.getPlacementY());
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
