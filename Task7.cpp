#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

void sortingAndMerging()
{
    std::cout << "Generating the vector...\n";
    std::vector<int> V;
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<> distrib(6, 22);
    int length = distrib(gen);
    if (length % 3 != 0)
        length--;
    if (length % 3 != 0)
        length--;

    std::uniform_int_distribution<> distrib2(-99, 30);
    std::uniform_int_distribution<> distrib3(0, 30);

    for (int i = 0; i < 3; i++)
    {
        int member;
        for (int j = 0; j < length/3; j++)
        {
            if (j == 0)
            {
                member = distrib2(gen);
                V.push_back(member);
            }
            else
            {
                member += distrib3(gen);
                V.push_back(member);
            }
        }
    }
    std::cout << "Generated the vector.\n";

    std::cout << "The vector: ";
    int oi = 0;
    for (std::vector<int>::iterator iter = V.begin(); iter != V.end(); iter++)
    {
        if (oi == 0)
            oi = 1;
        else
            std::cout << ", ";
        std::cout << *iter;
    }
    std::cout << ".\n";

    std::cout << "Sorting the vector...\n";
    std::inplace_merge(V.begin(), V.begin()+length/3, V.end()-length/3);
    std::inplace_merge(V.begin(), V.end()-length/3, V.end());
    std::cout << "Done.\n";

    std::cout << "The new vector: ";
    oi = 0;
    for (std::vector<int>::iterator iter = V.begin(); iter != V.end(); iter++)
    {
        if (oi == 0)
            oi = 1;
        else
            std::cout << ", ";
        std::cout << *iter;
    }
    std::cout << ".\n";
}