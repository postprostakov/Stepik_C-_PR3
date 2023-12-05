#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <chrono>
using namespace std;
using namespace chrono;



int GetRand(int min, int max)
{


	int num = min + rand() % (max - min + 1);
	return num;
}

void Sort(int *mass, int N)
{
    system_clock::time_point start = system_clock::now();
    int temp;
    temp = mass[0];
    temp = 0;
    for (int i = 0; i < N; i++)
    {
        for (int k = i + 1; k < N; k++)
        {
            if (mass[k] < mass[i])
            {
                temp = mass[k];
                mass[k] = mass[i];
                mass[i] = temp;
            }
        }


    }
    cout << "\n\n";
    
    system_clock::time_point end = system_clock::now();
    duration<double> sec = end - start;
    cout << "Время, затраченное на сортировку массива: " << sec.count() << " сек." << endl;
    cout << "Отсортированный массив: " << endl;
    for (int i = 0; i < N; i++)
    {

         cout << mass[i] << "\t";
    }
   
   }

int Minmax(int * mass, int N)
{
    int min;
    int max;
    int average;
    int k = 0;

    system_clock::time_point start = system_clock::now();
    min = mass[0];
    max = mass[0];
        for (int i = 1; i < N; i++)
    {
        if (mass[i] < min)
            min = mass[i];
        if (mass[i] > max)
            max = mass[i];
        
     }
        cout << "\n\n";
        system_clock::time_point end = system_clock::now();
        duration<double> sec = end - start;
        cout << "Время, затраченное на поиск максимального/минимального элемента в отсортированном массиве: " << sec.count() << " сек." << endl;
    cout << "Минимальное значение =" << min << endl;
    cout << "Максимальное значение = " << max << endl;
    average = 0.5 * (max + min);
    cout << "Среднее значение элементов в массиве: " << average << endl;

    cout << "\n\n";
    cout << "Номера элементов массива, равные среднему значению: " << endl;
    system_clock::time_point start1 = system_clock::now();
    for (int i = 0; i < N; i++)
    {
        if (mass[i] == average)
        {
            cout << i << endl;
            k = k + 1;
        }

    }
    system_clock::time_point end1 = system_clock::now();
    duration<double> sec1 = end1 - start1;
    cout << "Количество элементов в неотсортированном массиве, равное среднему: " << k << endl;
    cout << "Время, затраченное на поиск элементов, равных среднему в отсортированном массиве: " << sec1.count() << " сек." << endl;
    return 0;
}

void Mina(int* mass, int N, int a)
{
    int k = 0;
    for (int i = 0; i < N; i++)
    {
        if (mass[i] < a)
            k = k + 1;
    }
    cout << "Количество элементов, значение которых меньше а: " << k << endl;
}

void Maxb(int* mass, int N, int b)
{
    int k = 0;
    for (int i = 0; i < N; i++)
    {
        if (mass[i] > b)
            k = k + 1;
    }
    cout << "Количество элементов, значение которых больше b: " << k << endl;
}

int binarySearch(int *arr, int value, int start, int end)
{
   
    if (end >= start) {
        int mid = start + (end - start) / 2;

        if (arr[mid] == value) {
            return mid;
        }

        if (arr[mid] > value) {
            return binarySearch(arr, value, start, mid - 1);
        }

        return binarySearch(arr, value, mid + 1, end);
    }

    return -1;
    
}

void Swap(int * mass, int n1, int n2)
{
    system_clock::time_point start = system_clock::now();
    int temp;
    temp = mass[n2];
    mass[n2] = mass[n1];
    mass[n1] = temp;
       system_clock::time_point end = system_clock::now();
    duration<double> sec = end - start;
    cout << "\n\n";
    cout << "Время, затраченное на изменения положения элементов массива: " << sec.count() << " сек." << endl;
   
}


int main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "ru");
    const int N = 100;
    int mass[N];
    int min;
    int max;
    int average;
    int k = 0;
    int a, b;
    int value, result;
    int n1, n2;
    
    cout << "Неотсортированный массив: " << endl;
    for (int i = 0; i < N; i++)
    {
        
        mass[i] = GetRand(-99, 99);
        cout << mass[i] << "\t";
    }

    system_clock::time_point start = system_clock::now();
    min = mass[0];
    max = mass[0];
    for (int i = 1; i < N; i++)
    {
        if (mass[i] < min)
            min = mass[i];
        if (mass[i] > max)
            max = mass[i];
    }
    cout << "\n\n";
    system_clock::time_point end = system_clock::now();
    duration<double> sec = end - start;
    cout << "Время, затраченное на поиск максимального/минимального элемента в неотсортированном массиве: " << sec.count() << " сек." << endl;
    cout << "Минимальное значение =" << min << endl;
    cout << "Максимальное значение = "<< max << endl;
    average = 0.5 * (max + min);
    cout << "Среднее значение элементов в массиве: " << average << endl;
   
    cout << "\n\n";
    cout << "Номера элементов массива, равные среднему значению: " << endl;
    system_clock::time_point start1 = system_clock::now();
    for (int i = 0; i < N; i++)
    {
        if (mass[i] == average)
        {
            cout <<  i << endl;
            k = k + 1;
        }

    }
    system_clock::time_point end1 = system_clock::now();
    duration<double> sec1 = end1 - start1;
    cout << "Количество элементов в неотсортированном массиве, равное среднему: " << k << endl;
    cout << "Время, затраченное на поиск элементов, равных среднему: " << sec1.count() << " сек." << endl;




    Sort(mass, N);
    Minmax(mass, N);
    cout << "\n\n";
    cout << "Введите число а, согласно заданию: " << endl;
    cin >> a;
    Mina(mass, N, a);
    cout << "\n\n";
    cout << "Введите число b, согласно заданию: " << endl;
    cin >> b;
    Maxb(mass, N, b);
    cout << "\n\n";
    cout << "Введите число для бинарного поиска согласно заданию: " << endl;
    cin >> value;
    system_clock::time_point start2 = system_clock::now();
    result=binarySearch(mass, value, 0, N - 1);
   

    if (result == -1) 
    {
        cout << "Элемент не найден" << endl;
    }
    else 
    {
        cout << "Элемент находится в позиции " << result << endl;
    }
    system_clock::time_point end2 = system_clock::now();
    duration<double> sec2 = end2 - start2;
    cout << "Время, затраченное на поиск элемента при бинарном поиске: " << sec2.count() << " сек." << endl;

    cout << "\n\n";
    cout << "Введите индексы элементов массива согласно заданию 8"<< endl;
    cin >> n1;
    cin >> n2;

    Swap(mass, n1, n2);
    cout << "\n\n";
    cout << "Массив после изменения положения двух элементов" << endl;


        for (int i = 0; i < N; i++)
        {
          cout << mass[i] << "\t";
        }
}
