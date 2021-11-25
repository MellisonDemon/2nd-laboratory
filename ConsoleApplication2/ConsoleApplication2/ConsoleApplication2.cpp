#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;


int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	system_clock::time_point start;
	system_clock::time_point end;
	duration<double> sec;
	bool firstFlag = false, secondFlag = false;
	int action;

	cout << "Выберите пункт, который хотите выполнить:" << endl << "1. Создать массив" << endl << "2. Отсортировать массив" << endl << "3. Найти максимальный и минимальный элемент массива" << endl << "4. Вывести среднее значение минимального и максимального элемента массива" << endl << "5. Вывести количество элементов, меньших чем число А" << endl << "6. Вывести количество элементов, большмх чем чисто В" << endl << "7. Поменять местами элементы массива" << endl;

	while (true)
	{
		cin >> action;

		switch (action) {
		case(1):
			//------1. СОЗДАНИЕ МАССИВА------//	
			int arr[100], agg[100], pause;
			for (int i = 0; i < 100; i++)
			{
				arr[i] = (rand() % 199) - 99;
				agg[i] = arr[i];
			}
			cout << "Ваш массив для работы: ";
			for (int i = 0; i < 100; i++)
			{
				cout << arr[i] << " ";
			}
			cout << endl;
			firstFlag = true;
			secondFlag = false;
			break;
		case(2):
			if (firstFlag == true)
			{
				//------2. СОРТИРОВКА МАССИВА------//
				int sort;
				cout << "Выберите номер способа, которым хотите отсортировать массив:" << endl << "1. Пузырьковая сортировка" << endl << "2. Шейкер-сортировка" << endl << "3. Сортировка расчёской" << endl << "4. Сортировка вставками" << endl;
				cin >> sort;
				switch (sort) {
				case(1):
					start = system_clock::now();
					for (int i = 0; i < 100; i++) {
						for (int j = 1; j < (100 - i); j++)
						{
							if (arr[j - 1] > arr[j])
							{
								swap(arr[j - 1], arr[j]);
							}
						}
					}
					end = system_clock::now();
					break;
				case(2):
					start = system_clock::now();
					for (int i = 0; i < 50; i++)
					{
						for (int j = 1; j < (100 - i); j++)
						{
							if (arr[j - 1] > arr[j])
							{
								swap(arr[j - 1], arr[j]);
							}
						}
						for (int k = 100 - 1; k > i; k--)
						{
							if (arr[k] < arr[k - 1])
							{
								swap(arr[k - 1], arr[k]);
							}
						}
					}
					end = system_clock::now();
					break;
				case(3):
					start = system_clock::now();
					for (int k = 100 - 1; k > 0; k = int(k / 1.2))
					{
						for (int j = k; j < 100; j++)
						{
							if (arr[j] < arr[j - k])
							{
								swap(arr[j], arr[j - k]);
							}
						}
					}
					end = system_clock::now();
					break;
				case(4):
					int n;
					start = system_clock::now();
					for (int i = 1; i < 100; i++)
					{
						n = arr[i];
						for (int j = i - 1; j >= 0; j--)
						{
							if (n < arr[j])
							{
								swap(arr[j], arr[j + 1]);
							}

						}
					}
					end = system_clock::now();
					break;
				default: cout << "Ошибка. Введи номер заново." << endl;
				}
				sec = end - start;
				cout << "Время сортировки: " << sec.count() << endl;
				secondFlag = true;
				cout << "Ваш отсортированный массив: ";
				for (int i = 0; i < 100; i++)
				{
					cout << arr[i] << " ";
				}
				cout << endl;
			}
			else { cout << "Выполните пункт 1 чтобы продолжить" << endl; }
			break;
		case(3):
			if (firstFlag == true && secondFlag == true)
			{
				//------3. MAX & MIN------//
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
			}
			else
			{
				if (firstFlag == false) { cout << "Выполните пункт 1 чтобы продолжить" << endl; }
				if (secondFlag == false) { cout << "Выполните пункт 2 чтобы продолжить" << endl; }
			}
			break;
		case(4):
			if (firstFlag == true && secondFlag == true)
			{
				//------4. СРЕДНЕЕ ЗНАЧЕНИЕ------//
				int average, countAverage = 0, maxim = arr[99], minim = arr[0];
				average = (maxim + minim) / 2;
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
			}
			else
			{
				if (firstFlag == false) { cout << "Выполните пункт 1 чтобы продолжить" << endl; }
				if (secondFlag == false) { cout << "Выполните пункт 2 чтобы продолжить" << endl; }
			}
			break;
		case(5):
			if (firstFlag == true && secondFlag == true)
			{
				//------5. МЕНЬШЕ А------//
				{int a, pointA = 100;
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
				cout << "количество элементов, которые меньше числа a: " << pointA << endl; }
			}
			else
			{
				if (firstFlag == false) { cout << "Выполните пункт 1 чтобы продолжить" << endl; }
				if (secondFlag == false) { cout << "Выполните пункт 2 чтобы продолжить" << endl; }
			}
			break;
		case(6):
			if (firstFlag == true && secondFlag == true)
			{
				//------6. БОЛЬШЕ B------//
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
				cout << "количество элементов, которые больше числа b: " << 100 - pointB << endl;
			}
			else
			{
				if (firstFlag == false) { cout << "Выполните пункт 1 чтобы продолжить" << endl; }
				if (secondFlag == false) { cout << "Выполните пункт 2 чтобы продолжить" << endl; }
			}
			break;
		case(7):
			if (firstFlag == true && secondFlag == true)
			{
				//------7. ОБМЕН ЗНАЧЕНИЯМИ------//
				int changeOne, changeTwo, changer, arg[100];
				for (int i = 0; i < 100; i++)
				{
					arg[i] = arr[i];
				}
				cout << "введитете индексы элементов: ";
				cin >> changeOne >> changeTwo;
				start = system_clock::now();
				changer = arr[changeOne];
				arr[changeOne] = arr[changeTwo];
				arr[changeTwo] = changer;
				end = system_clock::now();
				sec = end - start;
				cout << "время перестановки элементов: " << sec.count() << endl;
			}
			else
			{
				if (firstFlag == false) { cout << "Выполните пункт 1 чтобы продолжить" << endl; }
				if (secondFlag == false) { cout << "Выполните пункт 2 чтобы продолжить" << endl; }
			}
			break;
		default:
			//------ОШИБКА------//
			cout << "Ошибка ввода. Повторите попытку." << endl;
			break;
		}
	}
	return 0;
}