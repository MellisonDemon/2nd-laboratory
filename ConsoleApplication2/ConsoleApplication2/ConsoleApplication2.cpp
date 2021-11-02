#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	//------СОЗДАНИЕ МАССИВА------//	
	int arr[100], agg[100];
		for (int i = 0; i < 100; i++)
		{
			arr[i] = (rand() % 199) - 99;
			agg[i] = arr[i];
		}

	//------СОРТИРОВКА МАССИВА------//
	
	system_clock::time_point start = system_clock::now();
	for (int i = 0; i < 100; i++)
	{
		for (int j = 1; j < (100 - i); j++)
		{
			if (arr[j - 1] > arr[j])
			{
				swap(arr[j - 1], arr[j]);
			}
		}
	}
	system_clock::time_point end = system_clock::now();
	duration<double> sec = end - start;
	cout << "sort time: " << sec.count() << endl;
	
	
	//------MAX & MIN------//
	
	int minimum = 100, maximum = -100, mi, ma;
	
	start = system_clock::now();
	arr[0];
	end = system_clock::now();
	sec = end - start;
	cout << "время поиска минимального элемента в отсортиванном массиве: " << sec.count() << endl;

	start = system_clock::now();
	arr[99];
	end = system_clock::now();
	sec = end - start;
	cout << "время поиска максимального элемента в отсортиванном массиве: " << sec.count() << endl;
	
	start = system_clock::now();
	for (int i = 0; i < 100; i++)
	{
		if (agg[i] > maximum)
		{
			maximum = agg[i];
		}
	}
	end = system_clock::now();
	sec = end - start;
	cout << "время поиска максимального элемента в неотсортиванном массиве: " << sec.count() << endl;

	start = system_clock::now();
	for (int i = 0; i < 100; i++)
	{
		if (agg[i] < minimum)
		{
			minimum = agg[i];
		}
	}
	end = system_clock::now();
	sec = end - start;
	cout << "время поиска минимального элемента в неотсортиванном массиве: " << sec.count() << endl;
	
	//------СРЕДНЕЕ ЗНАЧЕНИЕ------//

	int average, countAverage = 0;
	average = (maximum + minimum) / 2;
	cout << "индексы элементов, соответствующие среднему значению максимального и минимального значения: ";
	for (int i = 0; i < 100; i++)
	{
		if (agg[i] == average)
		{
			cout << i << " ";
			countAverage += 1;
		}
	}
	cout << endl << "количество элементов, соответствующие среднему значению максимального и минимального значения: " << countAverage << endl;

	//------МЕНЬШЕ А------//
	int a, pointA = 100;
	cout << "введитете значение a: ";
	cin >> a;
	for (int i = 0; i < 100; i++)
	{
		if (arr[i] > a)
		{
			pointA = i;
			break;
		}
	}
	cout << "количество элементов, которые меньше числа a: " << pointA << endl;

	//------БОЛЬШЕ B------//
	int b, pointB = 100;
	cout << "введитете значение b: ";
	cin >> b;
	for (int i = 0; i < 100; i++)
	{
		if (arr[i] > b)
		{
			pointB = i;
			break;
		}
	}
	cout << "количество элементов, которые больше числа b: " << 100-pointB << endl;

	//------ОБМЕН ЗНАЧЕНИЯМИ------//
	int changeOne, changeTwo, changer;
	cout << "введитете индексы элементов: ";
	cin >> changeOne >> changeTwo;
	start = system_clock::now();
	changer = arr[changeOne];
	arr[changeOne] = arr[changeTwo];
	arr[changeTwo] = changer;
	end = system_clock::now();
	sec = end - start;
	cout << "время перестановки элементов: " << sec.count() << endl;
	return 0;
}