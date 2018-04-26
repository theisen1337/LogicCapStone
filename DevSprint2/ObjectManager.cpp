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

}

MachineBase & ObjectManager::getMLMachine(std::vector<MachineBase> & Machines, int index)
{
	return Machines[index];
}

#pragma region Machines
void ObjectManager::addMachine(float X, float Y)
{
}

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










