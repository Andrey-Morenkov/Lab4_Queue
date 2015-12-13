#pragma once
#include <iostream>
// Структуры данных - очередь

template <class T>
class TQueue
{
private:
	int begin;    // начало очереди
	int end;      // конец очереди
	int len;      // длина очереди
	T* mas;       // массив очереди (сама очередь)
	int maxsize;  // макс размер кольца очереди
public:
	TQueue(int _maxsize = 10)
	{
		maxsize = _maxsize;
		mas = new T[maxsize];
		begin = 0;
		end = -1;
		len = 0;
	}
	TQueue(const TQueue& Q)
	{
		maxsize = Q.maxsize;
		mas = new T[maxsize];
		for (int i = 0; i < maxsize; i++)
			mas[i] = Q.mas[i];
		begin = Q.begin;
		end = Q.end;
		len = Q.len;
	}
	~TQueue<T>()
	{
		delete[] mas;
	}

	// Операции
	bool IsEmpty();       // Пусто?
	bool IsFull();        // Полная?
	void Push(const T n); // Добавить элемент в очередь
	T Pop();              // Извлечь из очереди

	// доступ к полям
	int GetBegin() { return begin; }
	int GetEnd(){ return end; }
	int GetLen() { return len; }
	int GetMaxsize() { return maxsize; }

	// вывод
	friend ostream& operator<<(ostream &out, const TQueue& Q)
	{
		for (int i = 0; i < Q.GetMaxsize; i++)
			out << Q.mas[i];
		return out;
	}
};

template <class T>
bool TQueue::IsEmpty()
{
	if (len == 0)
		return true;
	return false;
}

template <class T>
bool TQueue::IsFull()
{
	if (len == maxsize)
		return true;
	return false;
}

template <class T>
void Push(const T n)
{
	if (end < (maxsize - 1))
		end++;
	else
		end = 0;
	mas[end] = n;
	len++;
}

template <class T>
T Pop()
{
	if (IsEmpty())
		throw - 1;
	else
	{
		T tmp = mas[begin];
		if (begin < (maxsize - 1))
			begin++;
		else
			begin = 0;
		len--;
		return tmp;
	}
}