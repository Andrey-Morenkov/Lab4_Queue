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
	cout << "Введите шанс добавления в очередь (double) 0<p1<1" << endl;
	cin >> p1;
	cout << "Введите шанс извлечения из очереди (double) 0<q1<1" << endl;
	cin >> q1;
	TQueue<int> Q;
	cout << "Исходная очередь" << endl;
	cout << "Длина очереди: " << Q.GetLen() << endl;
	cout << "Максимальный размер:" << Q.GetMaxsize() << endl;
	cout << endl;
	for (int k=1;;k++)
	{
		rand=GenerateRand();
		cout << "------------Итерация "<< k <<"------------"<<endl;
		cout << "INFO:" << endl;
		cout << "Сгенерировано случайное число "<< rand << endl;
		cout << "Порог добавления в очередь p1= " << p1 << endl;
		cout << "Порог извлечения из очереди q1= " << q1 << endl;   // Цвет! вывод новой очереди
		cout << endl;
		cout << "Action:" << endl;
		if (rand <= p1)
		{
			if (!Q.IsFull())
			{
				Q.Push(1);
				cout << "Очередь пополнена" << endl;
			}
			else
			{
				cout << "Очередь не может быть пополнена" << endl;
			}
		}
		if (rand <= q1)
		{
			if (!Q.IsEmpty())
			{
				Q.Pop();
				cout << "Очередь уменьшена" << endl;
			}
			else
			{
				cout << "Очередь не может быть уменьшена" << endl;
			}
		}
		cout << endl;
		cout << "Status:" << endl;
		cout << "Длина очереди= " << Q.GetLen() << endl;
		cout << "Макс длина= " << Q.GetMaxsize() << endl;
		cout << "----------------------------------" << endl;
		getch();
	}
	return 0;
}

