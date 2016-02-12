#include "HashCode.h"


HashCode::HashCode(int Turnos, int Tipos, int Load, array<Drone^>^ DroneArray, array<Warehouse^>^ WareArray, array<Customer^>^ CustArray, array<int^>^ Weigt)
{
	numDrones = DroneArray->Length;
	numWarehouse = WareArray->Length;
	numCustomer = CustArray->Length;
	maxTurnos = Turnos;
	numTipos = Tipos;
	maxLoad=Load;
	ArrayDrones = DroneArray;
	ArrayWarehouse = WareArray;
	ArrayCustomers = CustArray;
	Weigth = Weigt;
}

HashCode::HashCode(int Drones, int Warehouses, int Customers)
{
	tratamiento();
	ArrayDrones;
	ArrayCustomers;
	ArrayWarehouse;
}

int* HashCode::NearWarhouse(int* pos) 
{

	int* result= new int [2];
	int* poslect = new int[2];
	int resultdistance = 0;

	for (int i = 0; i < ArrayWarehouse->Length; i++) {

		poslect = ArrayWarehouse[i]->position;
		if (resultdistance < DistanceCalcul(pos, poslect)) {
			result = poslect;
		}
	}
	return result;
}

int HashCode::DistanceCalcul(int* a, int* b) {

	int ax = a[0];
	int ay = a[1];
	int bx = b[0];
	int by = b[1];

	int result;

	result = sqrt((abs(bx - ax) ^ 2) + (abs(by - ay) ^ 2));

	return result;
}

bool HashCode::ControlItem(Warehouse Ware, int typeProduct,int cantidad)
{
	if (Ware.Inventary[typeProduct] >= cantidad) {
		return true;
	}
	return false;
}

void HashCode::tratamiento()
{
	
	Console::WriteLine("Hoal");
}
