// Файл HeapInt.h
#pragma once // 1
#include <cassert>

class HeapInt
{
private:
    int* heapValue; // 2

public:
    // 3
    inline HeapInt(int val)
        // 4
        : heapValue(new int{ val })
    {
    }

    inline ~HeapInt()
    {
        // Заметка: delete проверяет на nullptr сам.
        delete heapValue; // 5
    }

    inline int& asRef()
    {
        assert(heapValue != nullptr); // 6
        return *heapValue;
    }

    HeapInt(const HeapInt& hello); // 7
    HeapInt(HeapInt&& hello);
    void operator=(const HeapInt& hello);
    void operator=(HeapInt&& hello);
};

// Файл main.cpp
#include "HeapInt.h"

void constructors()
{
    HeapInt a{ 5 }; // 8
    HeapInt b{ a }; // 9
    HeapInt c{ std::move(a) }; // 10
    HeapInt d = b; // 11
    HeapInt e = std::move(b); // 12
    d = std::move(c); // 13
    d = e; // 14
}

// Файл HeapInt.cpp
#include "HeapInt.h"

// ... 15



/*
1.Поле heapValue приватное чтобы защитить данные от изменения.

2.Этот синтаксис означает список инициализации.

3.g++ main.cpp HeapInt.cpp -o Main


4.#pragma нужно для того чтобы предотвратить многократное включение одного и того же хэдера.


5.(3) определён как inline для того чтобы избегать ошибок линковки.


6.Перенести определение функции в файл HeapInt.cpp.


7.-


8.
(8) - Конструктор с параметром HeapInt(int)
(9) - Конструктор с копирования HeapInt(const HeapInt&)
(10) - Конструктор с перемещения HeapInt(HeapInt&&)
(11) - Эквивалентен вызову конструктора копирования HeapInt(const HeapInt&)
(12) - Эквивалентен вызову конструктора перемещения HeapInt(HeapInt&&)
(13) - Оператор перемещения operator=(HeapInt&&)
(14) - Оператор копирования operator=(const HeapInt&)


9.Использовать explicit перед названием конструктора.


11.
Конструкторы
HeapInt::HeapInt(const HeapInt& hello)
    : heapValue(new int{ *hello.heapValue }) 
    {
    }

HeapInt::HeapInt(HeapInt&& hello)
    : heapValue(hello.heapValue) 
    {
    hello.heapValue = nullptr;
    }


Операторы
void HeapInt::operator=(const HeapInt& hello) 
{
    if (this != &hello) 
    {
        delete heapValue;
        heapValue = new int{ *hello.heapValue };
    }
}

void HeapInt::operator=(HeapInt&& hello) 
{
    if (this != &hello) 
    {
        delete heapValue;
        heapValue = hello.heapValue;
        hello.heapValue = nullptr;
    }
}


12.-

13.Деконструктор вызовется 5 раз.


14.-


15.Использовать объект после std::move неправильно поскольку он будет считаться пустым.


16.
void swap(HeapInt& a, HeapInt& b) 
{
    std::swap(a.heapValue, b.heapValue);
}

*/