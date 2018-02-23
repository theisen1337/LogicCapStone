#include "Transport.h"
#include "Items.h"


Transport::Transport()
{
}


Transport::~Transport()
{
}

void Transport::addItems(Items Items)
{
	ItemsOntrack.push_back(Items);
}

void Transport::removeItems(Items Items)
{
	ItemsOntrack.pop_front();
}

void Transport::layTrack()
{
}

void Transport::removeTrack()
{
}



