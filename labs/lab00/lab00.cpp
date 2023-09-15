#include <iostream>
#include <ctime>

int main()
{
    srand(time(0));
    double x, y;
    int times = 1000000;
    int zone1 = 0, zone2 = 0, zone3 = 0, zone4 = 0;

    for (int i = 0; i < times; i++)
    {
        x = (rand() % 201 - 100) / 100.0;
        y = (rand() % 201 - 100) / 100.0;

        if (x < 0)
        {
            zone1++;
        }
        else if (y < 0)
        {
            zone4++;
        }
        else if (y < 1 - x)
        {
            zone3++;
        }
        else
        {
            zone2++;
        }
    }

    std::cout << "Zone 1: " << zone1 / (times * 1.0) * 100 << "%" << std::endl;
    std::cout << "Zone 2: " << zone1 / (times * 1.0) * 100 << "%" << std::endl;
    std::cout << "Zone 3: " << zone1 / (times * 1.0) * 100 << "%" << std::endl;
    std::cout << "Zone 4: " << zone1 / (times * 1.0) * 100 << "%" << std::endl;
    return 0;
}