#include "Transport.h"



Transport::Transport()
{
}


Transport::~Transport()
{
}

void Transport::addItem(Item item)
{
	itemsOntrack.push_back(item);
}

void Transport::removeItem(Item item)
{
	itemsOntrack.pop_front();
}

void Transport::layTrack()
{
}

void Transport::removeTrack()
{
}



