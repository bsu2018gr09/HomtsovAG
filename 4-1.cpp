/*В каждой строке удалить восклицательные предложения.*/

#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>
#include<fstream>
#include <cstring>

using namespace std;

int main() 
{
	const int N = 900;
	char *buff = new char[N];											   

	setlocale(LC_ALL, "rus");

	ifstream input("C:/Study/C++/input.txt");
	ofstream output("C:/Study/C++/output.txt");
	if (!input) { cout << "No file C:/Study/C++/input.txt. Can't open\n"; exit(1); }
	if (!output) { cout << "  file C:/Study/C++/output.txt. Can't create\n"; exit(1); }

	int count = 0;
	while (1) 
	{
		input.getline(buff, N - 1);
		if (input.fail()) input.clear();

		if (strchr(buff, '!') != nullptr)
		{
			
			char *buff1 = new char[strchr(buff, '!') - buff];
			char *buff2 = new char[N];

			strncpy(buff1, buff, (strchr(buff, '!') - buff));
			buff1[strchr(buff, '!') - buff] = '\0';
			buff = buff + (strchr(buff, '!') - buff + 1);

			if (!strrchr(buff1, '.') && !strrchr(buff1, '?'))
			{
				strcpy(buff2, buff);
				buff2[buff - buff2] = '\0';
			}
			else
			{
				if (strrchr(buff1, '.') > strrchr(buff1, '?'))
				{
					strncpy(buff2, buff1, (strrchr(buff1, '.') - buff1 + 1));
					buff2[strrchr(buff1, '.') - buff1 + 1] = '\0';
				}

				if (strrchr(buff1, '.') < strrchr(buff1, '?'))
				{
					strncpy(buff2, buff1, (strrchr(buff1, '?') - buff + 1));
					buff2[strrchr(buff1, '?') - buff1 + 1] = '\0';
				}

				strcat(buff2, buff);
			}

			cout << buff2 << '\n';
			output << buff2;

			delete[] buff2;
			
		}
		else
		{
			cout << buff << '\n';
			output << buff;
		}
		
		if (input.eof()) break; 
		output << '\n';
	}

	input.close();
	output.close();

	system("pause");
}