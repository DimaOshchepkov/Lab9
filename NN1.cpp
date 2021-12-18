// NN1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include "array.h"

/*int* createArrKeyBoard(int);
int* createArrRandom(int, int, int);
void printArr(int*, int);
int seachElement(int*, int, int);
int searchMin(int*, int);
int searchMax(int*, int);
int* searchEntry(int* arr, int num, int n);
int* deleteElement(int* arr, int* n, int index);
int* addElement(int* arr, int* n, int index, int num);
int* deleteKElement(int* arr, int* n, int index, int k);
int* addKElement(int* arr, int* n, int index, int k);
int searchMaxElmentCond(int* arr, int n);
bool cond(int* arr, int i);
int searchMinElmentCond(int* arr, int n);
int* deleteKElementCond(int* arr, int* n);*/
int main()
{
	std::cout << "Creat array\n";
	int n;
	std::cout << "Input n = ";
	std::cin >> n;
	int* arr = new int[n];
	int* entry;
	int nn = 0, z, k = 0, min, max;
	std::cout <<
		"1)createArrKeyBoard\n2)createArrRandom\n3)printArr\n4)seachElement\n";
	std::cout << "5)searchMin\\searchMax\n6)searchMaxElmentCond\\searchMinElmentCond\n";
	std::cout <<
		"7)searchEntry\n9)deleteElement\n10)deleteElements\n11)addElement\n12)deleteKElement\n13)deleteKElementCond\n14)addKElement\n";
	while (true)
	{
		std::cin >> z;
		switch (z)
		{
		case 1:
			std::cout << "Input n = ";
			std::cin >> n;
			arr = createArrKeyBoard(n);
			printArr(arr, n);
			break;

		case 2:
			int k1, k2;
			std::cout << "Input diaposon [k1, k2] for random generation:\n";
			std::cin >> k1 >> k2;
			arr = createArrRandom(n, k1, k2);
			printArr(arr, n);
			break;
		case 3:
			printArr(arr, n);
			break;
		case 4:
			int element;
			std::cout << "Input elemen that you want to search = ";
			std::cin >> element;
			std::cout << seachElement(arr, n, element) << '\n';
			break;
		case 5:
			std::cout << "Min element = " << searchMin(arr, n) << '\n';
			std::cout << "Max element = " << searchMax(arr, n) << '\n';
			break;
		case 6:
			std::cout << "Max element = ";
			max = searchMaxElmentCond(arr, n);
			(max != -1) ? std::cout << max << '\n' : std::cout << "Error\n";
			std::cout << "Min element = ";
			min = searchMinElmentCond(arr, n);
			(min != -1) ? std::cout << min << '\n' : std::cout << "Error\n";
			break;
		case 7:
			int num;
			std::cout << "Input number = ";
			std::cin >> num;
			std::cout << "Entrys of number " << num << ":\n";
			entry = searchEntry(arr, num, n, &nn);
			if (nn != 0)
				printArr(entry, nn);
			else
				std::cout << "No this element\n";
			nn = 0;
			break;
		case 9:
			int index;
			std::cout << "Input index = ";
			std::cin >> index;
			arr = deleteElement(arr, &n, index);
			printArr(arr, n);
			break;
		case 10:
			std::cout << "Input number = ";
			std::cin >> num;
			entry = searchEntry(arr, num, n, &nn);
			for (int i = nn-1; i >= 0; i--)
				arr = deleteElement(arr, &n, entry[i]);
			delete[] entry;
			printArr(arr, n);
			nn = 0;
			break;
		case 11:
			std::cout << "Input index and number:\n";
			std::cin >> index >> num;
			arr = addElement(arr, &n, index, num);
			printArr(arr, n);
			break;
		case 12:
			std::cout << "Intput index and K:\n";
			std::cin >> index >> k;
			if (index + k <= n && k > 0 && index > 0)
			{
				arr = deleteKElement(arr, &n, index, k);
				printArr(arr, n);
			}
			else
				std::cout << "Incorrect index or K\n";
			break;
		case 13:
			arr = deleteKElementCond(arr, &n);
			printArr(arr, n);
			break;
		case 14:
			std::cout << "Input index and K:\n";
			std::cin >> index >> k;
			arr = addKElement(arr, &n, index, k);
			printArr(arr, n);
			break;
		}	
	}



}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
