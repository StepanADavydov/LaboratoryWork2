// this one doesn't work



#include <iostream>
#include <list>
#include <string>
#include <random>
#include <algorithm>
#include <deque>

char current = 'A';
char next() { return current++; };

char letters[52];

std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<> distrib2(0, 51);

char random_char() { return letters[distrib2(gen)]; }

void numberAlgorithms()
{
    for (int i = 0; i < 26; i ++)
    {
        letters[i] = next();
    }
    current = 'a';
    for (int i = 26; i < 52; i ++)
    {
        letters[i] = next();
    }

    std::cout << "Generating L...\n";
    std::list<std::string> L;
    std::uniform_int_distribution<> distrib(1, 200);
    int length = distrib(gen);
    std::uniform_int_distribution<> distrib1(1, 20);
    //int length0 = 1;
    for (int i = 0; i < length; i++)
    {
        int word_length = distrib1(gen);
        std::string word;
        for (int k = 0; k < word_length; k ++)
            word += random_char();
        L.push_back(word);
    }
    std::cout << "Done.\nV: ";
    int oi = 0;
    for (std::list<std::string>::iterator iter1 = L.begin(); iter1 != L.end(); iter1++)
    {
        if (oi == 0)
            oi = 1;
        else
            std::cout << ", ";
        std::cout << *iter1;
    }
    std::cout << ".\n";

    std::cout << "Calculating deque D...\n";
    std::deque<std::string> D;
    //std::adjacent_difference(L.begin(), L.end(), D);
}