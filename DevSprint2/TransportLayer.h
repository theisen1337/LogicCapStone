#pragma once
#include "TransportTemplate.h"

#include <vector>
class TransportLayer
{
public:
	TransportLayer();
	~TransportLayer();

	void Draw();
	void Compute();
	std::vector<TransportBase> arrTracks;

private:

	
};

