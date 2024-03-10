#include <iostream>
#include "IntegerArray.h"
using namespace std;

IntegerArray::IntegerArray(size_t size) : size(size), data(new int[size])
{
	if (size == 0)
	{
		throw bad_length();
	}
	for (size_t i = 0; i < size; ++i)
	{
		data[i] = 0;
	}
}
IntegerArray::IntegerArray(const IntegerArray& other) : size(other.size), data(new int[other.size]) 
{
	for (size_t i = 0; i < other.size; ++i) 
	{
		data[i] = other.data[i];
	}
}
IntegerArray::~IntegerArray()
{
	delete[] data;
}
int& IntegerArray::operator[](size_t index) 
{
	if (index >= size) 
	{
		throw bad_range(); 
	}
	return data[index]; 
}
size_t IntegerArray::getSize() const
{
	return size;
}
void IntegerArray::resize(size_t new_size) 
{
	if (new_size == 0)
	{
		throw bad_length();
	}
	int* new_data = new int[new_size];
	for (size_t i = 0; i < size && i < new_size; ++i)
	{
		new_data[i] = data[i];
	}
	delete[] data;
	data = new_data;
	size = new_size;
}
void IntegerArray::insert(size_t index, int value)
{
	if (index > size)
	{
		throw bad_range();
	}
	int* new_data = new int[size + 1];
	for (size_t i = 0; i < index; ++i)
	{
		new_data[i] = data[i];
	}
	new_data[index] = value;
	for (size_t i = index; i < size; ++i)
	{
		new_data[i + 1] = data[i];
	}
	delete[] data;
	data = new_data;
	size += 1;
}
void IntegerArray::remove(size_t index)
{
	if (index >= size)
	{
		throw bad_range();
	}
	int* new_data = new int[size - 1];
	for (size_t i = 0; i < index; ++i) 
	{
		new_data[i] = data[i];
	}
	for (size_t i = index + 1; i < size; ++i) 
	{
		new_data[i - 1] = data[i];
	}
	delete[] data;
	data = new_data;
	size -= 1;
}
void IntegerArray::pushFront(int value)
{
	insert(0, value);
}
void IntegerArray::pushBack(int value)
{
	insert(size, value);
}
int IntegerArray::find(int value) const
{
	for (size_t i = 0; i < size; ++i)
	{
		if (data[i] == value)
		{
			return i;
		}
	}
	return -1;
}