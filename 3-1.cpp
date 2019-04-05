#define _CRT_SECURE_NO_WARNINGS //не вижу задания. Проверять не буду
#include <iostream> 
#include <cstring> 
#include <clocale>

using namespace std;

const int MAX = 255;

int k = 0; // количество слов

int giveWords(char *str, char **mass) 
{
	char *p = str;
	char str1[] = ",.; \t";
	for (int i = 0; *p; ++i) 
	{
		p += strspn(p, str1);

		int len = strcspn(p, str1);
		if (len == 0) break;

		mass[i] = new(nothrow) char[len + 1];
		if (!mass)
		{
			cout << "No memory";
			exit(1);
		}
		strncpy(mass[i], p, len);

		mass[i][len] = '\0';

		k++;
		p += len;
	}
	return k;
}

void freeMemory(char **&arr, int k) 
{
	for (int i = 0; i < k; ++i) 
	{
		delete[] arr[i];
		arr[i] = nullptr;
	}

	delete[] arr;
	arr = nullptr;
}

int main() {
	const int N(100);

	setlocale(LC_ALL, "RUS");

	char buf[MAX];
	char *massOfWords[N];

	cout << "Введите строку\n";
	cin.getline(buf, MAX);

	char *str = new(nothrow) char[strlen(buf) + 1];
	if (!str)
	{
		cout << "No memory";
		exit(1);
	}
	strcpy(str, buf);

	giveWords(str, massOfWords);
	cout << "Words:\n";

	for (int i = 0; i < k; i+=2) 
	{
		if (massOfWords[i] == massOfWords[k - 1])
		{
			cout << massOfWords[i];
			break;
		}

		if (strlen(massOfWords[i]) == strlen(massOfWords[i + 1]))
		{
			swap(massOfWords[i], massOfWords[i + 1]);
			cout << massOfWords[i] << ' ';
			cout << massOfWords[i + 1] << ' ';
		}
		else
		{
			memset(massOfWords[i], '*', strlen(massOfWords[i]));
			memset(massOfWords[i+1], '*', strlen(massOfWords[i+1]));
			cout << massOfWords[i] << ' ';
			cout << massOfWords[i + 1] << ' ';
		}
	}

	cout << '\n';

	system("pause");
	return 0;
}
