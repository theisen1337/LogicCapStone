#include "TransportTemplate.h"


SlowTrack::SlowTrack()
{
	
}

void SlowTrack::Init()
{
	ALLEGRO_COLOR slow = al_map_rgb(60, 60, 60);
	TransportBase(1.0, slow);
}



void FastTrack::Init()
{
	ALLEGRO_COLOR fast = al_map_rgb(55, 391, 157);
	TransportBase(0.5, fast);
}
FastTrack::FastTrack()
{
	
}

