#include <iostream>
#include <string_view>
#include <cassert>

int countOnes(std::string_view str) 
{
    int count = 0;
    for (char a : str) 
    {
        if (a == '1') 
        {
            ++count;
        }
    }
    return count;
}

void runTests() 
{
    assert(countOnes("001100") == 2);
    assert(countOnes("000000") == 0);
    assert(countOnes("111111") == 6);
    assert(countOnes("000111") == 3);
}

int main() 
{
    runTests();
    std::cout << "Done" << std::endl;
    return 0;
}
