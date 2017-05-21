// Lab_09.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>

using namespace std;

struct MeshBud
{
	char surname[30];
	char work[30];
	int rik;
};

int main()
{
	setlocale(LC_ALL, "rus");
	int size;
	cout << "Vvedite kol."; cin >> size;
	MeshBud *mas = new MeshBud [size];

	for (int i = 0; i < size; i++)
	{
		cout << "surname:(30 simv) "; cin >> mas[i].surname;
		cout << "Work:(30 simv) "; cin >> mas[i].work;
		cout << "Rik: "; cin >> mas[i].rik;
	}

	ofstream fout("data.txt", ios::binary);
	for (int i = 0; i < size; ++i)
	{
		fout.write((char*)&mas[i], sizeof(MeshBud));
	}
	fout.close();

	ifstream fin("data.dat", ios::binary);

	system("pause");
    return 0;
}

