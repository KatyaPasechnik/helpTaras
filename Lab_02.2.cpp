// Lab_02.2.cpp: ���������� ����� ����� ��� ����������� ����������.
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
	cout << "������� �������� ������ (����� ����� ������������� 0): ";
	IntegerListReadTillZero(a, cin);
	cout << "C���������...\n������ ����� ����������:\n";
	mergeSort(a);
	IntegerListPrint(a,cout);
	cout << endl;
	system("pause");
}