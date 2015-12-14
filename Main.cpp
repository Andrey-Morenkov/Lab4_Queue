// Queue.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Queue.h"
#include <iostream>
#include <conio.h>

int _tmain(int argc, _TCHAR* argv[])
{
	srand(time(0));
	double p, p1, q, q1,rand;

	setlocale(LC_ALL, "Russian");
	cout << "������� ���� ���������� � ������� (double) 0<p1<1" << endl;
	cin >> p1;
	cout << "������� ���� ���������� �� ������� (double) 0<q1<1" << endl;
	cin >> q1;
	TQueue<int> Q;
	cout << "�������� �������" << endl;
	cout << "����� �������: " << Q.GetLen() << endl;
	cout << "������������ ������:" << Q.GetMaxsize() << endl;
	cout << endl;
	for (int k=1;;k++)
	{
		rand=GenerateRand();
		cout << "------------�������� "<< k <<"------------"<<endl;
		cout << "INFO:" << endl;
		cout << "������������� ��������� ����� "<< rand << endl;
		cout << "����� ���������� � ������� p1= " << p1 << endl;
		cout << "����� ���������� �� ������� q1= " << q1 << endl;   // ����! ����� ����� �������
		cout << endl;
		cout << "Action:" << endl;
		if (rand <= p1)
		{
			if (!Q.IsFull())
			{
				Q.Push(1);
				cout << "������� ���������" << endl;
			}
			else
			{
				cout << "������� �� ����� ���� ���������" << endl;
			}
		}
		if (rand <= q1)
		{
			if (!Q.IsEmpty())
			{
				Q.Pop();
				cout << "������� ���������" << endl;
			}
			else
			{
				cout << "������� �� ����� ���� ���������" << endl;
			}
		}
		cout << endl;
		cout << "Status:" << endl;
		cout << "����� �������= " << Q.GetLen() << endl;
		cout << "���� �����= " << Q.GetMaxsize() << endl;
		cout << "----------------------------------" << endl;
		getch();
	}
	return 0;
}

