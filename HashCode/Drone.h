#pragma once
ref class Drone
{
public:
	Drone();
	~Drone();
	int idDrone, maxLoad;
	int blockTurns = 0;
	int* position = new int[2];
	void setCaracters(int id, int Load, int posX, int posY);
};

