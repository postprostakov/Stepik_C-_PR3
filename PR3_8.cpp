    #include <iostream>
#include <iomanip>
#include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>
#include <chrono>
using namespace std;


int GetRand(int min, int max)
{
	int num = min + rand() % (max - min + 1);
	return num;
}

int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "ru");
	const int M = 6;
	const int N = 6;
	int arr[M][M];
	int k;
	int* first = nullptr;
	int* ptr = nullptr;
	int* aP = nullptr;
	int n0 = sizeof(arr) / sizeof(*arr);
	int m0 = sizeof(*arr) / sizeof(**arr);
	int* end = *arr + m0 * n0 - 1;
	int iter;
	int n1, m1;
	


	for (ptr = *arr; ptr <= end; ptr++)
	{
		*ptr = GetRand(1, 36);
	}
	
	cout << "Исходный вид массива" << endl;

	for (int l = 0; l < n0; l++)
	{
		for (int r = 0; r < m0; r++)
		{
			cout << arr[l][r] << " ";
			if (r == (n0 - 1))
				cout << endl;
		}
	}

	cout << "\n" << "\n";

	cout << "Введите произвольное целое число";
	cin >> k;
	
	
	for (ptr =*arr; ptr <= end; ptr++)
	{
		*ptr = *ptr+k;

	}


	

	cout << "\n" << "\n";

			cout << "Вид массива после увеличения на заданное число" << endl;

			for (int l = 0; l < n0; l++)
			{
				for (int r = 0; r < m0; r++)
				{
					cout << arr[l][r] << " ";
					if (r == (n0 - 1))
						cout << endl;
				}
			}

			cout << "\n" << "\n";


			for (ptr = *arr; ptr <= end; ptr++)
			{
				*ptr = *ptr -2*k;

			}

			cout << "Вид массива после уменьшения на заданное число" << endl;

			for (int l = 0; l < n0; l++)
			{
				for (int r = 0; r < m0; r++)
				{
					cout << arr[l][r] << " ";
					if (r == (n0 - 1))
						cout << endl;
				}
			}

			cout << "\n" << "\n";

			for (ptr = *arr; ptr <= end; ptr++)
			{
				*ptr = (*ptr + k)*k;

			}

			cout << "Вид массива после умножения на заданное число" << endl;

			for (int l = 0; l < n0; l++)
			{
				for (int r = 0; r < m0; r++)
				{
					cout << arr[l][r] << " ";
					if (r == (n0 - 1))
						cout << endl;
				}
			}

			cout << "\n" << "\n";

			for (ptr = *arr; ptr <= end; ptr++)
			{
				*ptr = *ptr/k/k;

			}

			cout << "Вид массива после деления на заданное число" << endl;

			for (int l = 0; l < n0; l++)
			{
				for (int r = 0; r < m0; r++)
				{
					cout << arr[l][r] << " ";
					if (r == (n0 - 1))
						cout << endl;
				}
			}
		
}
