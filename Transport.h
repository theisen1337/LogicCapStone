#pragma once

#include <deque>
#include "Items.h"
#include "Draw.h"

struct XYPoint
{
	float x;
	float y;
};

class Transport
{
public:
	Transport();
	~Transport();

	void addItems(Items Items);
	void removeItems(Items Items);

	void layTrack();
	void removeTrack();


private:
	
	

	//
	int tracklength;
	float trackspeed;
	float anchorPointX, anchorPointY;


	//path for Items to travel in float x and y
	std::deque<XYPoint> trackpath;

	//hold Items contents, REPLACE string with Items object
	std::deque<Items> ItemsOntrack;

	

};

