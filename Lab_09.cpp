// Lab_09.cpp: ���������� ����� ����� ��� ����������� ����������.
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
	if (_stricmp(mas.surname, sur) == 0)
	{
		cout << "�������: " << mas.surname << endl;
		cout << "����� ������: " << mas.work << endl;
		cout << "��� ��������: " <<mas.rik << endl;
	}
}

	int main()
{
		setlocale(LC_ALL, "rus");
		int size;
		cout << "������� ���������� �����: "; cin >> size;
		MeshBud *mas = new MeshBud[size];

		for (int i = 0; i < size; i++)
		{
			cout << "������� �������(�� 30 ��������, ������ ���� �������): "; cin >> mas[i].surname;
			cout << "������� ����� ������(�� 30 ��������, ������ ���� �������): "; cin >> mas[i].work;
			cout << "������� ��� ��������: "; cin >> mas[i].rik;
			while (mas[i].rik > 2017 || mas[i].rik <= 0)
			{
				cout << "�� ����� ����������� ���, ������� ��� � ���������� �� 0 �� 2017" << endl;
				cout << "������� ��� ��������: "; cin >> mas[i].rik;
			}
		}

		ofstream fout("data.dat", ios::out | ios::binary);
		for (int i = 0; i < size; ++i)
		{
			fout.write((char*)&mas[i], sizeof(MeshBud));
		}
		fout.close();
		delete[] mas;

		cout << endl;
		MeshBud mass [50];
		ifstream fin("data.dat", ios::in | ios::binary);
		if (!fin)
		{
			 cout << "������ ��� �������� ����� " << endl;
			 exit(0);
		}
		else
		{
			cout << "���� ���������� � �����..." << endl;
			int index = 0;
			for (int i = 0; fin.peek() != EOF; i++)
			{
				fin.read((char*)&mass[i], sizeof(MeshBud));
				index++;
			}
			fin.close();
			cout << "������� ������� ��� ������ ����������: ";
			char sur[30];
			cin >> sur;
			for (int i = 0; i < index; i++)
			{
				funk(mass[i], sur);
			}
			system("pause");
			return 0;
		}
}

