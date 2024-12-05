#include <iostream>

int main()
{
    int i = 69, number = 72;
    i+=number;

    int arr[3] = {0};
    arr[0];
    arr[2];

    int* pi = &i;
    number = *pi;

    *pi = &arr[0];
    pi = pi + 2;

    arr[0] = 5;
    *pi = 6;
}