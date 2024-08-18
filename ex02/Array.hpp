#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template <class T>
class	Array
{
public:
	Array();
	~Array();
	Array(const Array<T> &rhs);
	Array &operator=(const Array &rhs);
	Array(const unsigned int n);
	T &operator[](std::size_t index);
	T const &operator[](std::size_t index) const;
	std::size_t	size() const;

private:
	std::size_t	_size;
	T			*_ptr;
	void		clear();
};

# include "Array.tpp"

#endif
