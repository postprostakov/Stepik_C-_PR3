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
	const int N = 3;
	int arr[M][M];
	int arr1[N][N];
	int arr2[N][N];
	int arr3[N][N];
	int arr4[N][N];
	int width = 3;
	int k;
	int* first = nullptr;
	int* ptr = nullptr;
	int* ptr1 = nullptr;
	int* aP = nullptr;
	int* aP1 = nullptr;
	int n0 = sizeof(arr) / sizeof(*arr);
	int m0 = sizeof(*arr) / sizeof(**arr);
	int* end = *arr + m0 * n0 - 1;
	int* end1 = nullptr;
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

	cout << "\n" << "\n" << "\n" << "\n";

	//Сборка первой коробки

	for (aP = *arr, end = *arr + n0 / 2 - 1, aP1 = *arr1, k = 1; k <= n0/2; aP = aP + n0, end = end+n0, aP1=aP1+(n0/2), k++)
	{
				
		for (ptr = aP, ptr1 = aP1; ptr <= end; ptr++, ptr1++)
		{
			*ptr1 = *ptr;

		}
	}

	//Сборка второй коробки

	for (aP = *arr+n0/2, end = *arr + n0 - 1, aP1 = *arr2, k = 1; k <= n0 /2; aP = aP + n0, end = end + n0, aP1 = aP1 + (n0 / 2), k++)
	{

		for (ptr = aP, ptr1 = aP1; ptr <= end; ptr++, ptr1++)
		{
			*ptr1 = *ptr;

		}
	}

	//Сборка третьей коробки

	for (aP = *arr + n0*n0/2, end = *arr +n0*n0/2+n0/2-1, aP1 = *arr3, k = 1; k <= n0 / 2; aP = aP + n0, end = end + n0, aP1 = aP1 + (n0 / 2), k++)
	{

		for (ptr = aP, ptr1 = aP1; ptr <= end; ptr++, ptr1++)
		{
			*ptr1 = *ptr;

		}
	}

	//Сборка четвертой коробки

	for (aP = *arr + n0 * n0 / 2+n0/2, end = *arr + n0 * n0 / 2 + n0 / 2 + n0 / 2 - 1, aP1 = *arr4, k = 1; k <= n0 / 2; aP = aP + n0, end = end + n0, aP1 = aP1 + (n0 / 2), k++)
	{

		for (ptr = aP, ptr1 = aP1; ptr <= end; ptr++, ptr1++)
		{
			*ptr1 = *ptr;

		}
	}
	

	//Запись первой коробки

	for (aP = *arr, end = *arr + n0 / 2 - 1, aP1 = *arr3, k = 1; k <= n0 / 2; aP = aP + n0, end = end + n0, aP1 = aP1 + (n0 / 2), k++)
	{

		for (ptr = aP, ptr1 = aP1; ptr <= end; ptr++, ptr1++)
		{
			*ptr = *ptr1;

		}
	}

	//Запись второй коробки

	for (aP = *arr + n0 / 2, end = *arr + n0 - 1, aP1 = *arr4, k = 1; k <= n0 / 2; aP = aP + n0, end = end + n0, aP1 = aP1 + (n0 / 2), k++)
	{

		for (ptr = aP, ptr1 = aP1; ptr <= end; ptr++, ptr1++)
		{
			*ptr = *ptr1;

		}
	}

	//Запись третьей коробки

	for (aP = *arr + n0 * n0 / 2, end = *arr + n0 * n0 / 2 + n0 / 2 - 1, aP1 = *arr1, k = 1; k <= n0 / 2; aP = aP + n0, end = end + n0, aP1 = aP1 + (n0 / 2), k++)
	{

		for (ptr = aP, ptr1 = aP1; ptr <= end; ptr++, ptr1++)
		{
			*ptr = *ptr1;

		}
	}

	//Запись четвертой коробки

	for (aP = *arr + n0 * n0 / 2 + n0 / 2, end = *arr + n0 * n0 / 2 + n0 / 2 + n0 / 2 - 1, aP1 = *arr2, k = 1; k <= n0 / 2; aP = aP + n0, end = end + n0, aP1 = aP1 + (n0 / 2), k++)
	{

		for (ptr = aP, ptr1 = aP1; ptr <= end; ptr++, ptr1++)
		{
			*ptr = *ptr1;

		}
	}

			
		for (int l = 0; l < n0/2; l++)
		{
			for (int r = 0; r < n0/2; r++)
			{
				cout << arr1[l][r] << " ";
				if (r == (n0/2 - 1))
					cout << endl;

			}
		}

		cout << "\n" << "\n" << "\n" << "\n";


			for (int l = 0; l < n0/2; l++)
			{
				for (int r = 0; r < n0/2; r++)
				{
					cout << arr2[l][r] << " ";
					if (r == (n0 / 2 - 1))
						cout << endl;

				}
			}

			cout << "\n" << "\n" << "\n" << "\n";


			for (int l = 0; l < n0 / 2; l++)
			{
				for (int r = 0; r < n0 / 2; r++)
				{
					cout << arr3[l][r] << " ";
					if (r == (n0 / 2 - 1))
						cout << endl;

				}
			}

			cout << "\n" << "\n" << "\n" << "\n";


			for (int l = 0; l < n0 / 2; l++)
			{
				for (int r = 0; r < n0 / 2; r++)
				{
					cout << arr4[l][r] << " ";
					if (r == (n0 / 2 - 1))
						cout << endl;

				}
			}

			cout << "\n" << "\n" << "\n" << "\n";

			cout << "Вид массива после перестановки" << endl;

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
