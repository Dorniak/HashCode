#pragma once
ref class Customer
{
public:
	int idCustomer;
	int* position = new int[2];
	int Order;
	array<int>^ products;
	Customer(int id, int posX, int posY);
	~Customer();
};

