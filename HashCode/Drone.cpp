#include "Drone.h"


Drone::Drone()
{
}


Drone::~Drone()
{
}

void Drone::setCaracters(int id, int Load, int posX, int posY)
{
	idDrone = id;
	maxLoad = Load;
	position[0] = posX;
	position[1] = posY;
}
