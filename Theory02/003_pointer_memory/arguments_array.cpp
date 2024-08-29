#include <iostream>

int average(int _arr[], int count);

int main()
{
    int arr[5] = {10, 20, 30, 40, 50};
    int arr_len = sizeof(arr) / sizeof(int);

    std::cout << "평균 점수: " << average(arr, arr_len) << std::endl;

    return 0;
}

int average(int _arr[], int count)
{
    int sum = 0;
    for (int i = 0; i < count; i++)
    {
        sum += _arr[i];
    }
    return sum / count;
}