#pragma once

#include <vector>
#include "ItemBase.h"
#include "MachineTemplate.h"
#include "allegro5/allegro_primitives.h"
#include "math.h"

struct XYPoint
{
	float x;
	float y;
};


class TransportBase
{
public:
	TransportBase();
	~TransportBase();
	TransportBase(float speed, ALLEGRO_COLOR color);

	void setConnection(MachineBase &start, MachineBase &end);

	void addItems(ItemBase &Items);
	void removeItems();

	void startingNode(MachineBase &start);
	void enddingNode(MachineBase &end);


	void Compute();
	void Draw();

	void layTrack(float sx, float sy, float ex, float ey);
	void removeTrack();


private:

	void MoveObject(int index);
	bool TrackStop = false;

	void checkEndMachine();
	
	MachineBase * startMachine;
	MachineBase * endMachine;

	void TransportItems();

	//
	float trackDistance;
	float trackLength;
	float trackHeight;

	int trackSegments;

	float start_x, start_y , end_x, end_y;


	//path for Items to travel in float x and y
	//std::deque<XYPoint> trackpath;

	//hold Items contents, REPLACE string with Items object
	std::vector<ItemBase> ItemsOntrack;

protected:
	ALLEGRO_COLOR trackColor;
	float trackspeed;

};

