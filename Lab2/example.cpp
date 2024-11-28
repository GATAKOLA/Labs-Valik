#include <string.h>
#include <iostream>

struct TwoInts //������ ��������� � �������������� ����������� a � b
{
    int a;
    int b;
};

struct StructWithArray //������ ��������� � �������������� ����������� arr � someNumber, ��� arr ��� ������ � �������� 4 ����������, � someNumber ��� ���������
{
    int arr[4];
    int* someNumber;
};

int main()
{
    TwoInts i2 = { }; //������ ���������� i2 ���� TwoInts
    //����������� ��������
    i2.a = 5;
    i2.b = 7;

    //������� �� �����
    std::cout << i2.a << std::endl;
    std::cout << i2.b << std::endl;
    
    StructWithArray s = { }; //������ ���������� s ���� StructWithArray
    //����������� �������� ������� �������� �������
    s.arr[0] = 10;

    StructWithArray s1 = { }; //������ ���������� s1 ���� StructWithArray
    //����������� �������� ������� �������� �������
    s1.arr[0] = 15;

    StructWithArray* sPointer = &s; //������ ��������� sPointer ���� StructWithArray � ����������� ��� ����� ��������� s
    //������ �������� ������� �������� ������� �� 20
    sPointer->arr[0] = 20;
    
    std::cout << s.arr[0] << std::endl; //��������� 20
    s.arr[0] = 25;
    std::cout << s.arr[0] << std::endl; //��������� 25
    sPointer->arr[0] = 30;
    std::cout << s.arr[0] << std::endl; //��������� 30

    sPointer = &s1; //����������� ����� ��������� s1
    //������ �������� ������� �������� ������� �� 35
    sPointer->arr[0] = 35;
    std::cout << s.arr[0] << std::endl; //��������� 30
    std::cout << s1.arr[0] << std::endl; //��������� 35

    StructWithArray structArray[2] = { }; //������ ������ structArray ���� StructWithArray
    structArray[0].arr[3] = 77; //����������� �������� 77 ��������� �������� ������� � ������ ���������
    structArray[1].someNumber = &structArray[0].arr[3]; //����������� ����� ��������� �������� ������� ������ ���������

    sPointer = &s; //����������� ����� ��������� s
    int* pointer = &sPointer->arr[3]; //������ ��������� pointer � ����������� ��� ����� ��������� �������� ������� ��������� s
    //����������� �������� ��������� �������� �������
    s.arr[3] = 72;
    std::cout << *pointer; //��������� 72

    StructWithArray memory; //������ ������ memory ���� StructWithArray
    memset(&memory, 0, sizeof(StructWithArray)); //��������� ������ ������
    return 0;
}
