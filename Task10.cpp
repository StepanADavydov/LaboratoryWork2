#include <iostream>
#include <vector>
#include <map>
#include <random>

void mappings()
{
    std::cout << "Generating V...\n";
    std::vector<int> V;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(1, 200);
    int length = distrib(gen);
    //int length0 = 1;
    std::uniform_int_distribution<> distrib1(-200, 200);
    for (int i = 0; i < length; i++)
    {
        V.push_back(distrib1(gen));
    }
    std::cout << "Done.\nV: ";
    int oi = 0;
    for (std::vector<int>::iterator iter1 = V.begin(); iter1 != V.end(); iter1++)
    {
        if (oi == 0)
            oi = 1;
        else
            std::cout << ", ";
        std::cout << *iter1;
    }
    std::cout << ".\n";

    std::cout << "Grouping vector V with last numbers of its elements as its keys...\n";
    std::vector<int>::iterator iter = V.begin();
    for (int number = 0; number < 10; number++)
    {
        for (std::vector<int>::iterator iter1 = iter; iter1 != V.end(); iter1++)
        {
            if (*iter1 % 10 == number || *iter1 % 10 == -number)
            {
                int temp = *iter1;
                V.erase(iter1);
                V.insert(iter, temp);
                iter++;
            }
        }
    }
    std::cout << "Done.\nThe new V: ";
    oi = 0;
    for (std::vector<int>::iterator iter1 = V.begin(); iter1 != V.end(); iter1++)
    {
        if (oi == 0)
            oi = 1;
        else
            std::cout << ", ";
        std::cout << *iter1;
    }
    std::cout << ".\n";

    std::cout << "Making multimap M...\n";
    std::multimap<int, int> M;
    std::vector<int>::iterator iter2 = V.begin();
    for (int number = 0; number < 10;)
    {
        if (*iter2 % 10 != number && *iter2 % 10 != -number)
        {
            number++;
            continue;
        }
        M.insert({number, *iter2});
        iter2++;
    }
    std::cout << "Done.\nM: ";
    oi = 0;
    for (std::multimap<int, int>::iterator iter1 = M.begin(); iter1 != M.end(); iter1++)
    {
        if (oi == 0)
            oi = 1;
        else
            std::cout << ", ";

        std::cout << (*iter1).first << ": " << (*iter1).second;
    }
    std::cout << ".\n";
}