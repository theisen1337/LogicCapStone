#pragma once

#include <deque>
#include "Item.h"
#include "Artist.h"


class Transport
{
public:
	Transport();
	~Transport();

	void addItem(Item item);
	void removeItem(Item item);

	void layTrack();
	void removeTrack();


private:
	
	

	//
	int tracklength;
	float trackspeed;
	float anchorPointX, anchorPointY;


	//path for item to travel in float x and y
	std::deque<float, float> trackpath;

	//hold item contents, REPLACE string with item object
	std::deque<Item> itemsOntrack;

	

};

