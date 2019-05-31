/*1.2. Положительные элементы массива А(N) переставить в конец массива, сохраняя порядок следования.
Отрицательные элементы расположить в порядке убывания. Дополнительный массив не использовать.*/
#include<iostream>
#include<time.h>

using namespace std;

int * pA = nullptr;

int* findMemory(int N)
{
	pA = new(nothrow) int[N];
	if (!pA)
	{
		cout << "error";
		return 0;
	}
	return pA;
}

void delMemory(int *pA)
{
	delete[] pA;
	pA = nullptr;
}

void printArr(int *arr, int n)
{
	for (int i = 0; i < n; ++i)
	{
		cout << *(arr + i) << " ";
	}
}

void random(int *arr, int n)
{
	srand(time(0));
	for (int i = 0; i < n; ++i)
	{
		*(arr + i) = rand() % (10 - (-10) + 1) + (-10);
	}
}

int main()
{
	int N{ 0 }, cnt{ 0 };
	cout << "Enter array dimension\n";
	cin >> N;

	findMemory(N);

	random(pA, N);
	cout << '\n';
	printArr(pA, N);
	cout << '\n';

	for (int i = N - 1; i >= 0; --i)			//положительные элементы в конец 
	{
		if (*(pA + i) > 0)
		{
			swap(*(pA + i), *(pA + N - 1 - cnt));
			cnt++;
		}
	}

	for (int j = 0; j < N - 1; ++j)			//отрицательные по убыванию 
	{
		int flag = 0;
		for (int i = 0; i < N - j; ++i) 
		{
			if (*(pA + i) < *(pA + i + 1))
				if (*(pA + i + 1) <= 0) 
				{
					swap(*(pA + i), *(pA + i + 1));
					flag++;
				}
		}
		if (!flag) { break; }
	}

	cout << '\n';

	printArr(pA, N);
	cout << '\n';
	delMemory(pA);

	system("pause");
	return 0;
}
