#include "TransportLayer.h"


TransportLayer::TransportLayer()
{
}


TransportLayer::~TransportLayer()
{
}


void TransportLayer::Draw()
{
	if (!arrTracks.empty())
	{
		for (int i = 0; i < arrTracks.size(); i++)
		{
			arrTracks[i].Draw();
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
