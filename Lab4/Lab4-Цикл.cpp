#include <iostream>
#include <cassert>
#include <span>
#include <array>


void product(std::span<int> inputOutput, std::span<int> coeff)
{
    assert(inputOutput.size() == coeff.size());

    size_t i = 0;
    while (true)
    {
        int a, b, c;
        if (i == inputOutput.size())
        {
            return;
        }
        a = inputOutput[i];
        b = coeff[i];
        c = a * b;
        inputOutput[i] = c;
        i++;
    }
}

void product1(std::span<int> inputOutput, std::span<int> coeff)
{
    assert(inputOutput.size() == coeff.size());

    size_t i = 0; // a
    while (i != inputOutput.size()) // b
    {
        int a, b, c; // body
        a = inputOutput[i];
        b = coeff[i];
        c = a * b;
        inputOutput[i] = c;
        i++; // c
    }
}

void product2(std::span<int> inputOutput, std::span<int> coeff)
{
    assert(inputOutput.size() == coeff.size());

    
    for (size_t i = 0; i != inputOutput.size(); i++)
    {
        int a, b, c;
        a = inputOutput[i];
        b = coeff[i];
        c = a * b;
        inputOutput[i] = c;
    }
}

int main()
{
    std::array first{ 2,1,6,2,8 };
    std::array second{ 4,5,2,7,9 };

    //product(first, second);
    //product1(first, second);
    product2(first, second);

    std::cout << first[0] << std::endl;
}