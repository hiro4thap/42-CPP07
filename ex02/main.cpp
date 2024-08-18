#include <iostream>
#include "Array.hpp"
#include "Log.hpp"

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));

	Log::nl("Copy the instance and compare values", CYAN);
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }

    Array<int> tmp = numbers;
    Array<int> test(tmp);

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i] || tmp[i] != numbers[i] || test[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
	Log::nl(" -> All the values are copied prorperly");
	Log::nl();

	Log::nl("Change a value of original array", CYAN);
	Log::out(" -> ");
	numbers[0] += 1;
    if (mirror[0] == numbers[0] || tmp[0] == numbers[0] || test[0] == numbers[0])
		Log::nl("The copy arrays are affected", YELLOW);
	else
		Log::nl("The copy arrays are not affected");
	Log::nl();

	Log::nl("Pass index as -2", CYAN);
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
		Log::out(" -> ");
		Log::nl(e.what(), RED);
    }
	Log::nl();

	Log::nl("Pass index as MAX_VAL(= size of the array)", CYAN);
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
		Log::out(" -> ");
		Log::nl(e.what(), RED);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;
    return 0;
}
