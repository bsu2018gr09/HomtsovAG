/*1.3. Элементы массива А(N), значения которых – простые числа, расположить в порядке возрастания, 
не нарушая порядка следования других элементов.*/
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

void initArr(int *arr, int n) 
{
	for (int i = 0; i < n; ++i) 
	{
		*(arr + i) = i;
	}

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
		*(arr + i) = rand() % 50;
	}
}

bool isPrimeNumber(int number)
{
	if (number <= 1)
	{
		return false;
	}

	bool isPrime = true;

	for (int i = 2; i <= sqrt(number); ++i)
	{
		if (!(number % i))
		{
			isPrime = false;
			break; //Очевиднее так: return false; И быстрее!!!!
		}
	}
	return isPrime;//Очевиднее так: return true;
}

void transpositionLeft(int *arr,  int N, int i, int k)
{

	for (int j = N - 1 - k; j < N ; ++j)
	{
		*(arr + j) = *(arr + j + 1);
	}
}

int main() 
{
	int N(0), cnt(0), tmp(0), k(0);
	cout << "Enter array dimension\n";
	cin >> N;

	findMemory(N);
	random(pA,N);
	printArr(pA, N);
	cout << '\n';

	for (int i = N - 1; i >= 0; --i)			//простые вправо 
	{
		if (isPrimeNumber(*(pA + i))) 
		{
			tmp = *(pA + i);
			transpositionLeft(pA, N, i, k);
			*(pA + N - 1) = tmp;
			cnt++;
		}
		k++;
	}

	printArr(pA, N);
	cout << '\n';

	for (int i = 0 ; i < cnt; ++i)			//простые по возрастанию
	for (int j = N - cnt; j < N-1; ++j)
		if(*(pA + j) > *(pA + j +1))
			swap(*(pA + j), *(pA + j + 1));//никакой оптимизации (((
	
	printArr(pA, N);
	cout << '\n';
	delMemory(pA);

	system("pause");
	return 0;
}
