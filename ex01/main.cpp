#include "iter.hpp"
#include "Log.hpp"

void	double_int(int &i)
{
	i *= 2;
}

int	main()
{
	std::size_t	size = 5;
	int	array[5] = {1, -3, 15, 10, 2};

	Log::nl("Before double_int", YELLOW);
	for (std::size_t i = 0 ; i < size; i++)
		std::cout << array[i] << "\n";

	iter(array, size, &double_int);

	Log::nl();
	Log::nl("After double_int", YELLOW);
	for (std::size_t i = 0 ; i < size; i++)
		std::cout << array[i] << "\n";
	return 0;
}
