// parser.cpp : main project file.
#include <string.h>
#include "HashCode.h"
using namespace System;
using namespace System::IO;
#define INPUT_NAME "input.in"
int Main(array<System::String ^> ^args)
{
    Console::WriteLine(L"Hello World");
	int rows,columns,drones,deadline,maxLoad,types,warehouse;
	array<String^>^ data;
	array<Drone^>^ ArrayDrones;
	array<Warehouse^>^ ArrayWarehouse;
	array<Customer^>^ ArrayCustomers;

	try
	{
		Console::WriteLine("trying to open file {0}...", INPUT_NAME);
		StreamReader^ data_in = File::OpenText(INPUT_NAME);

		String^ str;

		while ((str = data_in->ReadLine()) != nullptr)
		{
			data = str->Split(' ');	
			rows = Convert::ToInt32(data[0]);
			columns = Convert::ToInt32(data[1]);
			drones = Convert::ToInt32(data[2]);
			deadline = Convert::ToInt32(data[3]);
			maxLoad = Convert::ToInt32(data[4]);
			

			//We get the types
			types = Convert::ToInt32(data_in->ReadLine());
			array<int>^ weights = gcnew array<int>(types);

			//get the weights
			for (int i = 0; i < types; i++)
			{
				data = data_in->ReadLine()->Split(' ');
				for (int k = 0; k < data->Length; k++)
				{
					weights[i] = Convert::ToInt32(data[k]);
					Console::Write(weights[i]);
				}
				Console::WriteLine();
			}

			//Get warehouse number
			ArrayWarehouse = gcnew array<Warehouse^>(Convert::ToInt32(data_in->Read()));

			Console::WriteLine("filas: {0}  columnas: {1}  drones: {2}  deadline: {3}  maxload: {4}  typos {5}",rows,columns,drones,deadline,maxLoad,types);
			
			for (int i = 0; i < warehouse; i++)
			{
				ArrayWarehouse[i] = gcnew Warehouse(types,i, Convert::ToInt32(data_in->Read()), Convert::ToInt32(data_in->Read()));
				for (int k = 0; k < types; k++)
				{
					data = data_in->ReadLine()->Split(' ');
					for (int j = 0; j < data->Length; j++)
					{
						ArrayWarehouse[i]->Inventary[k,1] = Convert::ToInt32(data[j]);
					}
					
				}
			}
			ArrayCustomers = gcnew array<Customer^>(Convert::ToInt32(data_in->Read()));
			for (int i; i<ArrayCustomers->Length; i++) {

				data = data_in->ReadLine()->Split(' ');
				ArrayCustomers[i]->position[0] = Convert::ToInt32(data[0]);
				ArrayCustomers[i]->position[1] = Convert::ToInt32(data[1]);
				ArrayCustomers[i]->Order = Convert::ToInt32(data_in->ReadLine());
				data = data_in->ReadLine()->Split(' ');
				ArrayCustomers[i]->products = gcnew array<int>(ArrayCustomers[i]->Order);
				for (int k; k < data->Length; k++) {
					ArrayCustomers[i]->products[k] = Convert::ToInt32(data[k]);
				}
			}
			HashCode^ test = gcnew HashCode(deadline,types,ArrayDrones, ArrayWarehouse, ArrayCustomers, weights);
		}
	}
	catch (Exception^ e)
	{
		/*if (dynamic_cast<FileNotFoundException^>(e))
			Console::WriteLine("file '{0}' not found", INPUT_NAME);
		else
			Console::WriteLine("problem reading file '{0}'", INPUT_NAME);*/
		Console::WriteLine(e->ToString());
	}

    return 0;
}
