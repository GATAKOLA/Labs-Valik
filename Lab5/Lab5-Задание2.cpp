#include <iostream>
#include <string_view>
#include <cassert>

std::string_view Find(std::string_view str) 
{
    size_t a = str.find(' ');
    if (a == std::string_view::npos)
    {
        return "";
    }

    size_t b = str.find(' ', a + 1);

    if (b == std::string_view::npos) 
    {
        return str.substr(a + 1);
    }

    return str.substr(a + 1, b - (a + 1));
}

void runTests() 
{
    assert(Find("Volvo audi test") == "audi"); //2 �������
    assert(Find("Volvo audi") == "audi"); //1 ������
    assert(Find("Volvo ") == ""); //������ � �����
    assert(Find("Volvoaudi") == ""); //��� ��������
    assert(Find(" Volvoaudi") == "Volvoaudi"); //������ ������
    assert(Find("") == ""); //�����
}

int main() 
{
    runTests();
    std::cout << "Done" << std::endl;
    return 0;
}
