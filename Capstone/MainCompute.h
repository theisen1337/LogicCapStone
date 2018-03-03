#pragma once

#include "ObjectManager.h"
#include "GlobalStatics.h"

class MainCompute
{
public:
	void Compute(ObjectManager OM);
	void ComputeTPS();


private:
	GlobalStatics GS;
	int CPSaccum =0;
	double waitticks = 0;

};

