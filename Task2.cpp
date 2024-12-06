#include <iostream>
#include <deque>
#include <random>

void insertion()
{
	std::cout << "Generating a deque...\n";

	std::random_device rd;
	std::mt19937 gen(rd());

	std::uniform_int_distribution<> distrib(6, 20);
	int length = distrib(gen);
	if (length % 2 != 0)
		length--;

	std::uniform_int_distribution<> distrib2(-99, 100);

	std::deque<int> D;
	for (int i = 0; i < length; i++)
		D.push_back(distrib2(gen));

	std::cout << "Generated the deque.\n";

	std::cout << "The deque: ";
	int oi = 0;
	for (std::deque<int>::iterator iter = D.begin(); iter != D.end(); iter++)
	{
		if (oi == 0)
			oi = 1;
		else
			std::cout << ", ";
		std::cout << *iter;
	}
	std::cout << ".\n";

    std::deque<int>::iterator i = D.begin();
    for (int j = 0; j < length/2; j++)
    {
        i++;
    }

    std::cout << "Inserting -1s into the deque...\n";
    for (int j = 0; j < length/2; j++, i--)
    {
        D.insert(--i, -1);
    }
    std::cout << "Inserted -1s into the deque.\n";

    std::cout << "The new deque: ";
    oi = 0;
    for (std::deque<int>::iterator iter = D.begin(); iter != D.end(); iter++)
    {
        if (oi == 0)
            oi = 1;
        else
            std::cout << ", ";
        std::cout << *iter;
    }
    std::cout << ".\n";
}