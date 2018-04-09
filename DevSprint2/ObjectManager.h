#pragma once

#include "MachineLayer.h"
#include "TransportLayer.h"
#include "ItemLayer.h"
#include "OreLayer.h" 
// #include "PlayerLayer"

#include "MachineTemplate.h"

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

private:
	OreLayer OL;
	MachineLayer ML;
	TransportLayer TL;
	ItemLayer IL;



};

