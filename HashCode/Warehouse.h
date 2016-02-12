#pragma once
ref class Warehouse
{
public:
	Warehouse(int tipos, int id, int posX, int posY);
	~Warehouse();
	int* position = new int[2];
	int idWarehouse;
	int *Inventary;
};

