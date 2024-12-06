#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <random>

void sets()
{
    std::cout << "Generating V0...\n";
    std::vector<int> V0;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(1, 20);
    int length0 = distrib(gen);
    //int length0 = 1;
    std::uniform_int_distribution<> distrib1(-20, 20);
    for (int i = 0; i < length0; i++)
    {
        V0.push_back(distrib1(gen));
    }
    std::cout << "Done.\nV0: ";
    int oi = 0;
    for (std::vector<int>::iterator iter1 = V0.begin(); iter1 != V0.end(); iter1++)
    {
        if (oi == 0)
            oi = 1;
        else
            std::cout << ", ";
        std::cout << *iter1;
    }
    std::cout << ".\n";

    std::cout << "Generating N...\n";
    int N = distrib(gen);
    std::cout << "Done.\nN = " << N << ".\n";

    std::cout << "Generating V1, ..., VN...\n";
    std::set<std::vector<int>> VN;
    std::uniform_int_distribution<> distrib2(0, 60);
    for (int i = 0; i < N; i++)
    {
        int length = length0 + distrib2(gen);
        std::vector<int> V;
        for (int j = 0; j < length; j++)
        {
            V.push_back(distrib1(gen));
        }
        VN.insert(V);
    }
    std::cout << "Done.\n";
    int ai = 0;
    for (std::set<std::vector<int>>::iterator iter2 = VN.begin(); ai < N; ai++, iter2++)
    {
        std::cout << "V" << ai+1 << ": ";
        int oi = 0;
        std::vector<int> V = *iter2;
        for (std::vector<int>::iterator iter1 = V.begin(); iter1 != V.end(); iter1++)
        {
            if (oi == 0)
                oi = 1;
            else
                std::cout << ", ";
            std::cout << *iter1;
        }
        std::cout << ".\n";
    }

    std::cout << "Counting the number of vectors containing elements of V0...\n";
    int count = 0;
    std::multiset<int> V0m;
    for (std::vector<int>::iterator iter1 = V0.begin(); iter1 != V0.end(); iter1++)
    {
        V0m.insert(*iter1);
    }
    for (std::set<std::vector<int>>::iterator iter2 = VN.begin(); iter2 != VN.end(); iter2++)
    {
        std::vector<int> V = *iter2;
        std::multiset<int> VI;
        for (std::vector<int>::iterator iter1 = V.begin(); iter1 != V.end(); iter1++)
        {
            VI.insert(*iter1);
        }
        if (std::includes(VI.begin(), VI.end(), V0m.begin(), V0m.end()))
        {
            count++;
        }
    }
    std::cout << "Done.\nThe number: " << count << ".\n";
}