#include <iostream>
#include <cassert>

enum class Portrait 
{ 
    Lenin, 
    Washington, 
    Hitler 
};
enum class LampColor 
{ 
    Blue,
    White,
    Red 
};
enum class WireColor 
{ 
    Red, 
    Yellow, 
    Green 
};

WireColor WireToCut(Portrait portrait, LampColor lamp, bool isSwitchOn, int Clock) 
{
    if (portrait == Portrait::Lenin) 
    {
        return WireColor::Green;
    }

    int lampValue = 0;
    switch (lamp) 
    {
        case LampColor::Blue:lampValue = 11; break;
        case LampColor::White:lampValue = 15; break;
        case LampColor::Red:lampValue = 35; break;
    }

    if (portrait == Portrait::Hitler) 
    {
        switch (lamp) 
        {
            case LampColor::Blue:lampValue = 15; break;
            case LampColor::White:lampValue = 35; break;
            case LampColor::Red:lampValue = 11; break;
        }
    }

    WireColor wireToCut;

    if (Clock < lampValue)
    {
        wireToCut = WireColor::Red;
    }
    else if (Clock == lampValue)
    {
        wireToCut = WireColor::Green;
    }
    else 
    {
        wireToCut = WireColor::Yellow;
    }

    if (isSwitchOn) 
    {
        switch (wireToCut) 
        {
            case WireColor::Green:wireToCut = WireColor::Yellow; break;
            case WireColor::Yellow:wireToCut = WireColor::Red; break;
            case WireColor::Red:wireToCut = WireColor::Green; break;
        }
    }

    if (Clock % 4 == 0)
    {
        for (int i = 0; i < (Clock / 4); ++i)
        {
            switch (wireToCut) 
            {
                case WireColor::Green:wireToCut = WireColor::Red; break;
                case WireColor::Red:wireToCut = WireColor::Yellow; break;
                case WireColor::Yellow:wireToCut = WireColor::Green; break;
            }
        }
    }

    return wireToCut;
}

void test() 
{
    assert(WireToCut(Portrait::Lenin, LampColor::Blue, false, 10) == WireColor::Green);
    assert(WireToCut(Portrait::Washington, LampColor::Blue, false, 10) == WireColor::Red);
    assert(WireToCut(Portrait::Hitler, LampColor::Red, false, 11) == WireColor::Green);
    assert(WireToCut(Portrait::Washington, LampColor::White, true, 20) == WireColor::Green);
    assert(WireToCut(Portrait::Washington, LampColor::Blue, false, 24) == WireColor::Yellow);
    std::cout << "All tests passed!\n";
}

int main() 
{
    test();
    return 0;
}
