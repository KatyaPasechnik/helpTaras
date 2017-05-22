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

void funk(MeshBud mas, char *sur)
{
	if (strcmp(mas.surname, sur) == 0)
	{
		cout << mas.surname << endl;
		cout << mas.work << endl;
		cout << mas.rik << endl;
	}
}

	int main()
{
		setlocale(LC_ALL, "rus");
	/*	int size;
		cout << "Vvedite kol."; cin >> size;
		MeshBud *mas = new MeshBud[size];

		for (int i = 0; i < size; i++)
		{
			cout << "surname:(30 simv) "; cin >> mas[i].surname;
			cout << "Work:(30 simv) "; cin >> mas[i].work;
			cout << "Rik: "; cin >> mas[i].rik;
		}

		ofstream fout("data.dat", ios::out | ios::binary);
		for (int i = 0; i < size; ++i)
		{
			fout.write((char*)&mas[i], sizeof(MeshBud));
		}
		fout.close();*/

		MeshBud mass [50];
		ifstream fin("data.dat", ios::in | ios::binary);
		int index = 0;
  		for (int i = 0; fin.peek() != EOF; i++)
		{
			fin.read((char*)&mass[i], sizeof(MeshBud));
			index++;
		}
		fin.close();

		char sur[1024];
		cin >> sur;
		for (int i = 0; i < index; i++)
		{
			funk(mass[i], sur);
		}
		system("pause");
		return 0;
}

