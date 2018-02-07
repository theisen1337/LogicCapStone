#pragma once

#include <vector>



class Transport
{
public:
	Transport();
	~Transport();

	void addItem(string item);
	void removeItem();

	void layTrack();
	void removeTrack();


private:
	
	//
	int tracklength;
	float trackspeed;
	float anchorPointX, anchorPointY;


	//path for item to travel in float x and y
	std::vector<float, float> trackpath;

	//hold item contents, REPLACE string with item object
	std::vector<string> itemontrack;

	

};

