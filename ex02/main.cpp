#include <iostream>
#include "Array.hpp"
#include "Log.hpp"

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));

    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }

	Log::nl("Assingment operator and copy constructor test", CYAN);
	Log::nl("Copy the instance with assingment operator and copy constructor", YELLOW);
    Array<int> tmp = numbers;
    Array<int> test(tmp);

	Log::nl("Then, compare the value in each element", YELLOW);
    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i] || tmp[i] != numbers[i] || test[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
	Log::nl(" -> All the values are copied prorperly");

	Log::nl("Change a value of original array", YELLOW);
	Log::out(" -> ");
	numbers[0] += 1;
    if (mirror[0] == numbers[0] || tmp[0] == numbers[0] || test[0] == numbers[0])
		Log::nl("The copy arrays are affected", YELLOW);
	else
		Log::nl("The copy arrays are not affected");
	Log::nl();

	Log::nl("Subscript operator[] test", CYAN);
	Log::nl("index = -2", YELLOW);
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
		Log::out(" -> ");
		Log::nl(e.what(), RED);
    }

	Log::nl("index = MAX_VAL(= size of the array)", YELLOW);
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

	Log::nl("Non const Array write and read", YELLOW);
	Array<int> arr(5);
	for (int i = 0; i < 5; i++)
		arr[i] = i;
	for (int i = 0; i < 5; i++)
		std::cout << arr[i] << "\n";

	Log::nl("Const Array read", YELLOW);
	Array<int> const constarr(5);
	//for (int i = 0; i < 5; i++)
	//	constarr[i] = i;			// -> compile error
	for (int i = 0; i < 5; i++)
		std::cout << constarr[i] << "\n";
    return 0;
}
