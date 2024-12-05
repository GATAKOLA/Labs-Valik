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

    size_t secondpos = str.find(' ', firstpos + 1);

    if (secondpos == std::string_view::npos) 
    {
        return str.substr(firstpos + 1);
    }

    return str.substr(firstpos + 1, secondpos - (firstpos + 1));
}

void runTests() 
{
    assert(Find("Volvo audi test") == "audi"); //2 пробела
    assert(Find("Volvo audi") == "audi"); //1 пробел
    assert(Find("Volvo ") == ""); //пробел в конце
    assert(Find("Volvoaudi") == ""); //нет пробелов
    assert(Find(" Volvoaudi") == "Volvoaudi"); //пробел первый
    assert(Find("") == ""); //пусто
}

int main() 
{
    runTests();
    std::cout << "Done" << std::endl;
    return 0;
}
