#include "World.h"
#include <iostream>
int main() {
	World newWorld = World();
	std::cout << "Testing \n";
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (newWorld.getWorld()[i][j].getGen()) {
				std::cout << "map generated \n";
			}
		}
	}
	

	system("pause");
	return 0;
}