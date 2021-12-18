#include <iostream>
int* createArrKeyBoard(int n)
{
    int* arr = new int[n];
    for (int i = 0; i < n; i++)
        std::cin >> arr[i];
    return arr;
}
int* createArrRandom(int n, int k1, int k2)
{
    int* arr = new int[n];
    for (int i = 0; i < n; i++)
        arr[i] = rand() % (k2 - k1 + 1) + k1;
    return arr;
}
void printArr(int* arr, int n)
{
    std::cout << "Array now:\n";
    for (int i = 0; i < n; i++)
        std::cout << arr[i] << " ";
    std::cout << '\n';
}
int seachElement(int* arr, int n, int element)
{
    int count = -1;
    for (int i = 0; i < n; i++)
        if (arr[i] == element)
            count = i;
    return count;
}
int searchMin(int* arr, int n)
{
    int min = 0;
    for (int i = 1; i < n; i++)
        if (arr[i] < arr[min])
            min = i;
    return min;
}
int searchMax(int* arr, int n)
{
    int max = 0;
    for (int i = 1; i < n; i++)
        if (arr[i] > arr[max])
            max = i;
    return max;
}
int* searchEntry(int* arr, int num,  int n, int* nn)
{
    int* entry = new int[n];
    int* t = entry;
    for (int i = 0; i < n; i++)
        if (*(arr + i) == num)
        {
            *t++ = i;
            (*nn)++;
        }
    if (*nn == 0)
        return nullptr;
    else
        return entry;
}
int* deleteElement(int* arr, int* n, int index)
{
    int* newArr = new int[*n - 1];
    for (int i = 0; i < index; i++)
        newArr[i] = arr[i];
    for (int i = index; i < *n - 1; i++)
        newArr[i] = arr[i + 1];
    *n -= 1;
    delete[] arr;
    return newArr;
}
int* addElement(int* arr, int* n, int index, int num)
{
    int* newArr = new int[*n + 1];
    for (int i = 0; i < index; i++)
        newArr[i] = arr[i];
    newArr[index] = num;
    for (int i = index; i < *n; i++)
        newArr[i + 1] = arr[i];
    *n += 1;
    return newArr;
}
int* deleteKElement(int* arr, int* n, int index, int k)
{
    for (int i = 0; i < k; i++)
        arr = deleteElement(arr, n, index);
    return arr;
}
int* addKElement(int* arr, int* n, int index, int k)
{
    int num = 0;
    for (int i = 0; i < k; i++)
    {
        std::cin >> num;
        arr = addElement(arr, n, index, num);
        index += 1;
    }
    return arr;
}
bool cond(int* arr, int i)
{
    return (i % 2 == 0 && arr[i] > 0);
}
bool cond1(int x)
{
    return x % 2 == 0;
}
bool cond2(int x)
{
    return x > 0;
}
int searchMaxElmentCond(int* arr, int n)//переделать
{
    int max = INT_MIN, index = -1;
    for (int i = 0; i < n; i++)
        if (max < arr[i] && cond1(i) && cond2(arr[i]))
        {
            max = arr[i];
            index = i;
        }
        return index;

}
int searchMinElmentCond(int* arr, int n)
{
    int min = INT_MAX, index = -1;
    for (int i = 0; i < n; i++)
        if (min > arr[i] && cond1(i) && cond2(arr[i]))
        {
            min = arr[i];
            index = i;
        }
        return index;
}
int* deleteKElementCond(int* arr, int* n)
{
    for (int index = *n - 1; index >= 0; index--)
        if (cond1(index) && cond2(arr[index]))
            arr = deleteElement(arr, n, index);
    return arr;
}