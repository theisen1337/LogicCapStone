/*




		All statics should be in this class, every object not in the one class is NOT a static!
		Why statics? well Im becuase its on the fence if we want objects to be pass throw by refference or create a static object?
		Why One Class? Well so other classes that need to implement these objects only have to call one class.
		Also in one class, so we know where every stupid static object is located in the program.

		ex. MachineLayer, why? MachineLayer Object holds every machine in game, we dont need more then one. 
		Also two different classes MainCompute and MainDraw are refferencing the same object, and instead of declaring MachineLayer
		inside StateManager and passing into both mainDraw and mainCompute




*/
#include "InitStatics.h"
#include "MachineLayer.h" 

static MachineLayer ML;

MachineLayer & InitStatics::getML()
{
	return ML;
}

