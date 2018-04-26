#include "ObjectManager.h"

ObjectManager::ObjectManager()
{
}

//Method for testing/debugging will be removed..
void ObjectManager::Init()
{
	Smith smith1;
	smith1.setPlacement(64 * 20, 64 * 12);
	smith1;

	Miner mine1;
	mine1.setPlacement(64 * 12, 64 * 12);

	ML.arrMachines.push_back(mine1);
	ML.arrMachines.push_back(smith1);

	SlowTrack track1;
	//track1.setConnection(mine1, smith1); // null refference.
	track1.setConnection(ML.arrMachines.at(0),ML.arrMachines.at(1));
	TL.arrTracks.push_back(track1);

	// SETUP HOTBAR ITEMS

	// Add Machine to Hotbar
	hotbar[0].machine = true;
	hotbar[0].machineType = "Miner";
	hotbar[0].num = 2;

	hotbar[1].machine = true;
	hotbar[1].machineType = "Smith";
	hotbar[1].num = 1;
}

MachineBase & ObjectManager::getMLMachine(std::vector<MachineBase> & Machines, int index)
{
	return Machines[index];
}

#pragma region Machines
void ObjectManager::addMachine(float X, float Y)
{
}

void ObjectManager::addMachine(float X, float Y, int i)
{
	if (hotbar[i].machineType == "Smith")
	{
		Smith smith;

		smith.setPlacement(X, Y);

		ML.arrMachines.push_back(smith);
	}
	if (hotbar[i].machineType == "Miner")
	{
		Miner miner;

		miner.setPlacement(X, Y);

		ML.arrMachines.push_back(miner);
	}
}

// CURRENTLY NOT NEEDED
void ObjectManager::addSmith(float X, float Y)
{
}

void ObjectManager::addMiner(float X, float Y)
{
}
#pragma endregion

#pragma region Transport
void ObjectManager::addTransport(float sX, float sY, float eX, float eY)
{
}

void ObjectManager::addTransportFast(float sX, float sY, float eX, float eY)
{
}

void ObjectManager::addTransportFast(float sX, float sY, float eX, float eY, MachineBase Start, MachineBase Finish)
{
}

void ObjectManager::addTransportSlow(float sX, float sY, float eX, float eY)
{
}

void ObjectManager::addTransportSlow(float sX, float sY, float eX, float eY, MachineBase Start, MachineBase Finish)
{
}
#pragma endregion

#pragma region Items
void ObjectManager::addItem(float X, float Y)
{
}

void ObjectManager::addItem(float X, float Y, ItemBase item)
{
}

void ObjectManager::addItem(float X, float Y, int i)
{
	/*if (hotbar[i].itemType == "Coal")
	{
		Coal coal;

		coal.setPlacement(X, Y);

		IL.arrItems.push_back(coal);
	}
	if (hotbar[i].itemType == "Iron")
	{
		Iron iron;

		iron.setPlacement(X, Y);

		IL.arrItems.push_back(iron);
	}*/
}
#pragma endregion

#pragma region Layer Vectors
ObjectManager::~ObjectManager()
{
}

//Go through the drawing of each of the layers of the game.
void ObjectManager::Draw()
{
	OL.Draw();
	ML.Draw();
	TL.Draw(); // later this should be drawn before ML, only for testing is it draw second.
	IL.Draw();
}

void ObjectManager::Compute()
{
	ML.Compute();
	TL.Compute(); // TL should be drawn second, so it can get contents on this tick.
				  // IL.Compute(); //No compute clas for Items since items should not need to be computed as of now.
}

void ObjectManager::removeML()
{

}

void ObjectManager::removeTL()
{
}

void ObjectManager::removeIL()
{

}
#pragma endregion










