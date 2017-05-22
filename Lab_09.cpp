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
	if (_stricmp(mas.surname, sur) == 0)
	{
		cout << "Фалимия: " << mas.surname << endl;
		cout << "Место работы: " << mas.work << endl;
		cout << "Год рождения: " <<mas.rik << endl;
	}
}

	int main()
{
		setlocale(LC_ALL, "rus");
		int size;
		cout << "Введите количество людей: "; cin >> size;
		MeshBud *mas = new MeshBud[size];

		for (int i = 0; i < size; i++)
		{
			cout << "Введите фамилию(до 30 символов, только Англ буквами): "; cin >> mas[i].surname;
			cout << "Введите место работы(до 30 символов, только Англ буквами): "; cin >> mas[i].work;
			cout << "Введите год рождения: "; cin >> mas[i].rik;
			while (mas[i].rik > 2017 || mas[i].rik <= 0)
			{
				cout << "Вы ввели неправильно год, введите год в промежутке от 0 до 2017" << endl;
				cout << "Введите год рождения: "; cin >> mas[i].rik;
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
			 cout << "Ошибка при открытии файла " << endl;
			 exit(0);
		}
		else
		{
			cout << "Идет считывание с файла..." << endl;
			int index = 0;
			for (int i = 0; fin.peek() != EOF; i++)
			{
				fin.read((char*)&mass[i], sizeof(MeshBud));
				index++;
			}
			fin.close();
			cout << "Введите фамилию для поиска информации: ";
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

