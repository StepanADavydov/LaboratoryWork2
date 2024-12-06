#include <iostream>
#include <algorithm>
#include <random>
#include <fstream>

char currentChar = 'a';
char nextChar() { return currentChar++; }

void iteratorsAndAlgorithms()
{
    char name[26];
    int N;

    std::cout << "Generating N...\n";
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(1, 26);
    N = distrib(gen);
    std::cout << "Generated N.\nN = " << N << ".\n";

    std::cout << "Putting first " << N << " latin letters into string name...\n";
    std::generate_n(name, N, nextChar);
    std::cout << "Done.\nname: ";
    for (int i = 0; i < N; i++)
        std::cout << name[i];
    std::cout << ".\n";

    std::cout << "Putting string name into file name_1...\n";
    std::ofstream f;
    f.open("/home/student/CLionProjects/LabWork2/name_1.txt");

    if (f.is_open())
    {
        f.write(name, N);
    }
    else
    {
        std::cout << "ERROR: Could not open file \"name_1\".\n";
        return;
    }
    std::cout << "Successfully put string name into file name_1.\n";
    f.close();
}