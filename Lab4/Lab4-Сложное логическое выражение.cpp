#include <iostream>

struct Fruit
{
    int apples;
    int pears;
    int oranges;
};

void main()
{
    Fruit fructs;
    bool result;

    std::cout << "Apples:";
    std::cin >> fructs.apples;

    std::cout << "Pears:";
    std::cin >> fructs.pears;

    std::cout << "Oranges:";
    std::cin >> fructs.oranges;

    {
        bool apleif = fructs.apples > 5;
        bool pearsf = fructs.pears < 8;
        bool orangesif = (fructs.oranges == 2 * fructs.apples);

        result = apleif && pearsf && orangesif;

        if (result)
        {
            std::cout << "Hello" << std::endl;
        }
    }
}