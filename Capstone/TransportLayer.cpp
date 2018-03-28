#include "TransportLayer.h"


TransportLayer::TransportLayer()
{
}


TransportLayer::~TransportLayer()
{
}


void TransportLayer::Draw(ALLEGRO_BITMAP * itemAtl, std::vector<std::vector<std::string>> &itemRef)
{
	if (!arrTracks.empty())
	{
		for (int i = 0; i < arrTracks.size(); i++)
		{
			arrTracks[i].Draw(itemAtl, itemRef);
		}
	}
}

void TransportLayer::Compute()
{
	if (!arrTracks.empty())
	{
		for (int i = 0; i < arrTracks.size(); i++)
		{
			arrTracks[i].Compute();
		}
	}
}
