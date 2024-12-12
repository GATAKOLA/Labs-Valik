struct Leg
{
    int length;
};

struct Arm
{
    int power;
};

struct Person
{
    std::array<Leg, 2> legs;
    Arm arms[2];
};

int main()
{
    Person person;
}


/*
Типы данных: int, Leg, Arm, Person, std::array
Объект: person, length, power, legs, arms

я бы перезаписал первый Leg вот так: person.legs[0].length = 100;
*/