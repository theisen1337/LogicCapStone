#include "TransportTemplate.h"


SlowTrack::SlowTrack()
{
	ALLEGRO_COLOR slow = al_map_rgb(60, 60, 60);
	//TransportBase(1.0, slow); why doesn't this work?
	trackColor = slow;
	trackspeed = 1.0;
}



FastTrack::FastTrack()
{
	ALLEGRO_COLOR fast = al_map_rgb(55, 391, 157);
	//TransportBase(0.5, fast);
	trackColor = fast;
	trackspeed = 0.5;

}

