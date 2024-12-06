#include <list>
#include <iostream>
#include <random>

void deletingElements()
{
    std::cout << "Generating the first list...\n";

    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<> distrib(6, 20);
    int length1 = distrib(gen);

    std::uniform_int_distribution<> distrib2(-99, 100);

    std::list<int> L1;
    for (int i = 0; i < length1; i++)
        L1.push_back(distrib2(gen));

    std::cout << "Generated the first list.\n";

    std::cout << "Generating the second list...\n";

    int length2 = distrib(gen);
    if (length2 % 2 != 0)
        length2--;

    std::list<int> L2;
    for (int i = 0; i < length2; i++)
        L2.push_back(distrib2(gen));

    std::cout << "Generated the second list.\n";

    std::cout << "The first list: ";
    int oi = 0;
    for (std::list<int>::iterator iter = L1.begin(); iter != L1.end(); iter++)
    {
        if (oi == 0)
            oi = 1;
        else
            std::cout << ", ";
        std::cout << *iter;
    }
    std::cout << ".\n";

    std::cout << "The second list: ";
    oi = 0;
    for (std::list<int>::iterator iter = L2.begin(); iter != L2.end(); iter++)
    {
        if (oi == 0)
            oi = 1;
        else
            std::cout << ", ";
        std::cout << *iter;
    }
    std::cout << ".\n";

    std::list<int>::iterator i2 = L2.begin();
    for (int j = 0; j < length2 / 2; j++)
    {
        i2++;
    }

    for (int j = 0; j < length2 / 2; j++)
    {
        L2.erase(i2);
        i2 = L2.begin();
        for (int l = 0; l < length2 / 2; l++)
        {
            i2++;
        }
    }

    std::cout << "Putting the first half of the second list to the beginning of the first list...\n";
    L1.splice(L1.begin(), L2);
    std::cout << "Done.\n";

    std::cout << "The first list: ";
    oi = 0;
    for (std::list<int>::iterator iter = L1.begin(); iter != L1.end(); iter++)
    {
        if (oi == 0)
            oi = 1;
        else
            std::cout << ", ";
        std::cout << *iter;
    }
    std::cout << ".\n";
}