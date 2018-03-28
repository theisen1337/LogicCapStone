#pragma once
#include "transportTemplate.h"

#include <vector>
class TransportLayer
{
public:
	TransportLayer();
	~TransportLayer();

	void Draw(ALLEGRO_BITMAP * itemAtl, std::vector<std::vector<std::string>> &itemRef);
	void Compute();
	std::vector<Transport> arrTracks;

private:

	
};

