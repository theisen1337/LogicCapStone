#pragma once
#include "transportTemplate.h"

#include <vector>
class TransportLayer
{
public:
	TransportLayer();
	~TransportLayer();

	void Init(FastTrack & fast, SlowTrack & slow);
	void Draw();
	void Compute();
	std::vector<Transport> arrTracks;

private:

	
};

