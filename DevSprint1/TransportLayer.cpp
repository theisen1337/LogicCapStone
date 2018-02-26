#include "TransportLayer.h"
#include "transportTemplate.h"


TransportLayer::TransportLayer()
{
}


TransportLayer::~TransportLayer()
{
}

void TransportLayer::Init(FastTrack & fast, SlowTrack & slow)
{
	
	arrTracks.push_back(fast);
	arrTracks.push_back(slow);
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
