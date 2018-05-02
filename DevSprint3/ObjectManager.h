#pragma once

// Standard Includes
#include <array>

// Custom Includes
#include "MachineLayer.h"
#include "TransportLayer.h"
#include "ItemLayer.h"
#include "OreLayer.h" 
#include "MachineTemplate.h"
#include "GlobalConstants.h"

class ObjectManager
{
public:
	ObjectManager();
	~ObjectManager();

	void Init();

	void Draw();
	void Compute();

	void addMachine(float X, float Y); //TODO create Template class to store recipes
	void addSmith(float X, float Y);
	void addMiner(float X, float Y);

	void addTransport(float sX, float sY, float eX, float eY);
	void addTransportFast(float sX, float sY, float eX, float eY);
	void addTransportFast(float sX, float sY, float eX, float eY,MachineBase Start, MachineBase Finish);
	void addTransportSlow(float sX, float sY, float eX, float eY);
	void addTransportSlow(float sX, float sY, float eX, float eY, MachineBase Start, MachineBase Finish);

	void addItem(float X, float Y);
	void addItem(float X, float Y, ItemBase item);

	
	
	
	void removeML();
	void removeTL();
	void removeIL();

	MachineBase & getMLMachine(std::vector<MachineBase> & Machines, int index);

	OreLayer & getOL() { return OL; }
	MachineLayer & getML() { return ML; }
	TransportLayer & getTL() { return TL; }
	ItemLayer & getIL() { return IL; }

	struct hotbarItems
	{
		bool machine = false;
		std::string machineType = "";
		bool item = false;
		std::string itemType = "";
		int num = 0;
	};

	void addMachine(float X, float Y, int i);
	void addItem(float X, float Y, int i);

	std::vector<hotbarItems> hotbar = std::vector<hotbarItems>(8); // CHECK SIZE IN MEMORY

private:
	OreLayer OL;
	MachineLayer ML;
	TransportLayer TL;
	ItemLayer IL;
};