#include <iostream>
#include <list>
#include <random>
#include <algorithm>

void algorithmsOfSearch() {
    std::cout << "Generating the list...\n";

    std::list<int> L;

    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<> distrib(6, 20);
    int length = distrib(gen);

    std::uniform_int_distribution<> distrib1(0, length);
    int zeroes = distrib1(gen);

    std::uniform_int_distribution<> distrib2(-99, 100);
    std::uniform_int_distribution<> distrib3(zeroes, length);
    for (int i = 0; i < length; i++) {
        if (distrib3(gen) == zeroes)
            L.push_back(0);
        else
            L.push_back(distrib2(gen));
    }

    std::cout << "Generated the list.\n";

    std::cout << "The list: ";
    int oi = 0;
    for (std::list<int>::iterator iter = L.begin(); iter != L.end(); iter++) {
        if (oi == 0)
            oi = 1;
        else
            std::cout << ", ";
        std::cout << *iter;
    }
    std::cout << ".\n";

    try {
        std::list<int>::iterator iter = std::find(L.begin(), L.end(), 0);
        L.erase(iter);
    }
    catch (std::exception) {

    }

    try
    {
        std::list<int>::iterator iter = --std::find(L.rbegin(), L.rend(), 0).base();
        L.erase(iter);
    }
    catch  (std::exception)
    {

    }

    std::cout << "The new list: ";
    oi = 0;
    for (std::list<int>::iterator iter1 = L.begin(); iter1 != L.end(); iter1++)
    {
        if (oi == 0)
            oi = 1;
        else
            std::cout << ", ";
        std::cout << *iter1;
    }
    std::cout << ".\n";
}