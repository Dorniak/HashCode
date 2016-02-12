#pragma once
#include "Drone.h"
#include "Warehouse.h"
#include "Customer.h"
#include <math.h>

using namespace std;
using namespace System;


ref class HashCode {
public:
	HashCode(int Turnos,int Tipos,int Load, array<Drone^>^ DroneArray, array<Warehouse^>^ WareArray, array<Customer^>^ CustArray, array<int^>^ Weigt);
	int numDrones, numWarehouse, numCustomer, maxTurnos, numTurnos, numTipos,maxLoad;
	HashCode(int Drones,int Warehouses,int Customers);
	array<Drone^>^ ArrayDrones;
	array<Warehouse^>^ ArrayWarehouse;
	array<Customer^>^ ArrayCustomers;
	array<int^>^ Weigth;

private:
	void tratamiento();
	int* NearWarhouse(int* pos);
	int DistanceCalcul(int* a, int* b);
	bool ControlItem(Warehouse Ware,int typeProduct,int cantidad);
	//bool ControlWeigth(Customer cust,);
};