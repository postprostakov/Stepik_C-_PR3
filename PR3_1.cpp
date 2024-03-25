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
	int arr[8][8];
	int width = 3;
	int k;
	int* first = nullptr;
	int* ptr = nullptr;
	int* aP = nullptr;
	int n0 = sizeof(arr) / sizeof(*arr);
	int m0 = sizeof(*arr) / sizeof(**arr);
	int* end = *arr + m0 * n0 - 1;
	int iter;
	int n1, m1;

	for (int* ptr = *arr; ptr <= end; ptr++)
	{
		*ptr = GetRand(1, 36);
	}


	HANDLE hStdout;
	COORD destCoord;
	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

	
	for (aP = *arr, n1 = n0, m1 = m0, iter = 0; n1 >= 2; aP = aP + (m0+1), n1 = n1 - 2, m1 = m1 - 2, iter++)
	{
		end = aP + (n1 - 1);

		for (int* ptr = aP, k = iter; ptr <= end; ptr++, k++)

		{
			destCoord.X = width * k;
			destCoord.Y = (ptr - *arr) / m0;
			SetConsoleCursorPosition(hStdout, destCoord);
			cout<<*ptr <<" "; 
			cout.flush();
			Sleep(50);
		}

		first = end + n0;
		end = first + n0 * (m0 - 2 * (iter + 1));


		for (ptr = first; ptr <= end; ptr = ptr + n0)
		{
			k = m0 - iter - 1;
			destCoord.X = width * k;
			destCoord.Y = (ptr - *arr) / m0;
			SetConsoleCursorPosition(hStdout, destCoord);
			cout << *ptr << " ";
			cout.flush();
			Sleep(50);
		}

		first = end - 1;
		end = first - (n1 - 2);

		for (ptr = first, k = (m0 - 2-iter); ptr >= end; ptr--, k--)
		{
			destCoord.X = width * k;
			destCoord.Y = (ptr - *arr) /m0;
			SetConsoleCursorPosition(hStdout, destCoord);
			cout << *ptr << " ";
			cout.flush();
			Sleep(50);
		}


		first = end - n0;
		end = first - n0 * (m0 - 2 * (iter + 1));


		for (ptr = first; ptr > end; ptr = ptr - m0)
		{
		destCoord.X = width * iter;
		destCoord.Y = (ptr - *arr) /m0;
		SetConsoleCursorPosition(hStdout, destCoord);
	    cout << *ptr << " ";
		cout.flush();
		Sleep(50);
		}
	}
			
	cout << "\n" << "\n" << "\n" << "\n" << "\n" << "\n" << "\n" << "\n" << "\n";
	

	for (int l = 0; l < m0; l++)
	{
		for (int r = 0; r < n0; r++)
		{
			cout << arr[l][r] << " ";
			if (r == (n0 - 1))
				cout << endl;
		}
	}
}

