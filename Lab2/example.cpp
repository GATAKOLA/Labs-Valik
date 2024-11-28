#include <string.h>
#include <iostream>

struct TwoInts //создаём структуру с целочистенными переменными a и b
{
    int a;
    int b;
};

struct StructWithArray //создаём структуру с целочистенными переменными arr и someNumber, где arr это массив с максимум 4 элементами, а someNumber это указатель
{
    int arr[4];
    int* someNumber;
};

int main()
{
    TwoInts i2 = { }; //создаём переменную i2 типа TwoInts
    //присваеваем значения
    i2.a = 5;
    i2.b = 7;

    //выводим на экран
    std::cout << i2.a << std::endl;
    std::cout << i2.b << std::endl;
    
    StructWithArray s = { }; //создаём переменную s типа StructWithArray
    //присваеваем значение первому элементу массива
    s.arr[0] = 10;

    StructWithArray s1 = { }; //создаём переменную s1 типа StructWithArray
    //присваеваем значение первому элементу массива
    s1.arr[0] = 15;

    StructWithArray* sPointer = &s; //создаём указатель sPointer типа StructWithArray и присваиваем ему адрес структуры s
    //меняем значение первого элемента массива на 20
    sPointer->arr[0] = 20;
    
    std::cout << s.arr[0] << std::endl; //выводится 20
    s.arr[0] = 25;
    std::cout << s.arr[0] << std::endl; //выводится 25
    sPointer->arr[0] = 30;
    std::cout << s.arr[0] << std::endl; //выводится 30

    sPointer = &s1; //присваеваем адрес структуры s1
    //меняем значение первого элемента массива на 35
    sPointer->arr[0] = 35;
    std::cout << s.arr[0] << std::endl; //выводится 30
    std::cout << s1.arr[0] << std::endl; //выводится 35

    StructWithArray structArray[2] = { }; //создаём массив structArray типа StructWithArray
    structArray[0].arr[3] = 77; //присваеваем значение 77 четвёртому элементу массива в первой структуре
    structArray[1].someNumber = &structArray[0].arr[3]; //присваеваем адрес четвёртого элемента массива первой структуры

    sPointer = &s; //присваеваем адрес структуры s
    int* pointer = &sPointer->arr[3]; //создаём указатель pointer и присваеваем ему адрес четвёртого элемента массива структуры s
    //присваеваем значение четвёртому элементу массива
    s.arr[3] = 72;
    std::cout << *pointer; //выводится 72

    StructWithArray memory; //создаём массив memory типа StructWithArray
    memset(&memory, 0, sizeof(StructWithArray)); //заполняем нулями память
    return 0;
}
