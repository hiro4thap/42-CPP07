#include "iter.hpp"
#include "Log.hpp"

template<typename T> void	increment(T &i)
{
	i += 1;
}

int	main()
{
	std::size_t	size = 5;
	int	int_array[5] = {1, -3, 15, 10, 2};

	Log::nl("Int Array", CYAN);
	Log::nl("Before increment", YELLOW);
	for (std::size_t i = 0 ; i < size; i++)
		std::cout << int_array[i] << "\n";

	iter(int_array, size, &increment);

	Log::nl();
	Log::nl("After increment", YELLOW);
	for (std::size_t i = 0 ; i < size; i++)
		std::cout << int_array[i] << "\n";

	Log::nl();
	char	char_array[5] = {'a', 't', 'M', '/', '9'};

	Log::nl("Char Array", CYAN);
	Log::nl("Before increment", YELLOW);
	for (std::size_t i = 0 ; i < size; i++)
		std::cout << char_array[i] << "\n";

	iter(char_array, size, &increment);

	Log::nl();
	Log::nl("After increment", YELLOW);
	for (std::size_t i = 0 ; i < size; i++)
		std::cout << char_array[i] << "\n";


	return 0;
}
