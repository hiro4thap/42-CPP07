#ifndef ARRAY_TPP
# define ARRAY_TPP

# include "Array.hpp"

template<typename T>
Array<T>::Array():
	_size(0), _ptr(NULL)
{
}

template<typename T>
Array<T>::~Array()
{
	if (_ptr)
		this->clear();
}

template<typename T>
Array<T>::Array(const Array<T> &rhs):
	_size(0), _ptr(NULL)
{
	*this = rhs;
}

template<typename T>
Array<T> &Array<T>::operator=(const Array &rhs)
{
	if (this != &rhs)
	{
		if (_ptr)
			this->clear();
		_size = rhs.size();
		_ptr = new T[_size];
		for (std::size_t i = 0; i < _size; i++)
			(*this)[i] = rhs[i];
	}
	return *this;
}

template<typename T>
Array<T>::Array(const unsigned int n):
	_size(n), _ptr(new T[n])
{
	for (std::size_t i = 0; i < _size; i++)
		(*this)[i] = T();
}
		
template<typename T>
T &Array<T>::operator[](std::size_t index)
{
	if (_size <= index)
		throw std::exception();
	return _ptr[index];
}

template<typename T>
T const &Array<T>::operator[](std::size_t index) const
{
	if (_size <= index)
		throw std::exception();
	return _ptr[index];
}

template<typename T>
std::size_t	Array<T>::size() const
{
	return _size;
}

template<typename T>
void	Array<T>::clear()
{
	for (std::size_t i = 0; i < _size; i++)
		(*this)[i] = T();
	if (_ptr)
		delete[] _ptr;
	_ptr = NULL;
}

#endif
