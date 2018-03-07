#pragma once
#include "transportTemplate.h"

#include <vector>
class TransportLayer
{
public:
	TransportLayer();
	~TransportLayer();

	void Draw();
	void Compute();
	std::vector<Transport> arrTracks;

private:

	
};

