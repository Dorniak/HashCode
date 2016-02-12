#include "Warehouse.h"



Warehouse::Warehouse(int tipos, int id, int posX, int posY)
{
	idWarehouse = id;
	Inventary = new int[tipos, 2];
	position[0] = posX;
	position[1] = posY;
}


Warehouse::~Warehouse()
{
}
