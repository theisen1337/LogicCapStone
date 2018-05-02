#pragma once

// Custom Includes
#include "ObjectManager.h"
#include "GlobalStatics.h"

class MainCompute
{
public:
	//! Perform Computations
	void Compute(ObjectManager &OM);
	void ComputeTPS();

private:
	GlobalStatics GS;
	int CPSaccum =0;
	double waitticks = 0;

};
