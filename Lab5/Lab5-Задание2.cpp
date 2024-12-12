#include <iostream>
#include <string_view>
#include <cassert>

std::string_view Find(std::string_view str) 
{
    size_t firstpos = str.find(' ');
    if (firstpos == std::string_view::npos)
    {
        return "";
    }

    str.remove_prefix(firstpos + 1);

    size_t secondpos = str.find(' ');
    if (secondpos == std::string_view::npos) 
    {
        return str;
    }

    return str.substr(0, secondpos);
}

void runTests() 
{
    assert(Find("Volvo audi test") == "audi"); //2 пробела
    assert(Find("Volvo audi") == "audi"); //1 пробел
    assert(Find("Volvo ") == ""); //пробел в конце
    assert(Find("Volvoaudi") == ""); //нет пробелов
    assert(Find(" Volvoaudi") == "Volvoaudi"); //пробел первый
    assert(Find("") == ""); //пусто
    assert(Find("Volvo  audi  test") == ""); //2 пробела подряд
}

int main() 
{
    runTests();
    std::cout << "Done" << std::endl;
    return 0;
}
