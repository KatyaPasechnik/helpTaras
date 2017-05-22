// Lab_02.2.cpp: определяет точку входа для консольного приложения.
//

#include <iostream>
#include "stdafx.h"
#include "list.h"
#include "sort.h"

using namespace std;

void main()
{
	setlocale(LC_ALL, "rus");
	IntegerList a;
	IntegerListInit(a);
	cout << "Введите значение списка (конец ввода заканчивается 0): ";
	IntegerListReadTillZero(a, cin);
	cout << "Cортировка...\nСписок после сортировки:\n";
	mergeSort(a);
	IntegerListPrint(a,cout);
	cout << endl;
	system("pause");
}