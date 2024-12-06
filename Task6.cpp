#include <iostream>
#include <deque>
#include <algorithm>
#include <random>

int currentInt = 1;
int nextInt() { return currentInt++; }
int prevInt() { return currentInt--; }

void basicModifyingAlgorithmsAndIteratorsOfInsertions()
{
    int N;
    std::deque<int> D;

    std::cout << "Generating N...\n";
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(1, 20);
    N = distrib(gen);
    std::cout << "Generated N.\nN = " << N << ".\n";

    std::cout << "Generating D...\n";
    std::uniform_int_distribution<> distrib1(-20, 20);
    std::uniform_int_distribution<> distrib2(0, 20);
    int length = 2 * N + distrib2(gen);
    for (int i = 0; i < length; i++)
    {
        D.push_back(distrib1(gen));
    }
    std::cout << "Done.\nD: ";
    int oi = 0;
    for (std::deque<int>::iterator iter = D.begin(); iter != D.end(); iter++) {
        if (oi == 0)
            oi = 1;
        else
            std::cout << ", ";
        std::cout << *iter;
    }
    std::cout << ".\n";

    std::cout << "Filling D with 1, ..., N at start...\n";
    currentInt = 1;
    std::generate(D.begin(), D.begin()+N, nextInt);

    std::cout << "Done.\nFilling D with N, ..., 1 at end...\n";
    currentInt = N;
    std::generate(D.end()-N, D.end(), prevInt);

    std::cout << "Done.\nThe new D: ";
    oi = 0;
    for (std::deque<int>::iterator iter = D.begin(); iter != D.end(); iter++) {
        if (oi == 0)
            oi = 1;
        else
            std::cout << ", ";
        std::cout << *iter;
    }
    std::cout << ".\n";
}