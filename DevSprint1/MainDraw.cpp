#include "MainDraw.h"


	
void MainDraw::Init()
{							//"Terrain//Machine//Miner//Miner_ON.png"

}

	
void MainDraw::Draw(MachineLayer & ML, TransportLayer &TL)
{		
	ML.Draw();

	TL.Compute();
}
