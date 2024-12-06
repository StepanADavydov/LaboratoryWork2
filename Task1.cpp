#include <vector>
#include <iostream>
#include <fstream>
#include <string>

void fillAndAccess()
{
	std::string line;
	std::vector<int> vector;

	std::cout << "Filling the vector with the content of the file \"name\"..." << std::endl;
	std::ifstream f;
    f.open("/home/student/CLionProjects/LabWork2/name", std::ios::in);

	if (f.is_open())
	{
		try
		{
			while (std::getline(f, line))
			{
				vector.push_back(stoi(line));
			}
		}
		catch (std::exception)
		{
			std::cout << "ERROR!!! Check that the file \"name\" contains only whole numbers!" << std::endl;
			return;
		}
	}
    else
    {
        std::cout << "ERROR: Could not open file \"name\".\n";
        return;
    }
	std::cout << "Successfully filled the vector with the content of the file \"name\".\n";
    f.close();
	
	std::cout << "The vector: ";
	int i = 0;
	for (std::vector<int>::iterator iter = vector.begin(); iter != vector.end(); iter++)
	{
		if (i == 0)
		{
			i = 1;
		}
		else
		{
			std::cout << ", ";
		}
		std::cout << *iter;
	}
	std::cout << ".\n";
}