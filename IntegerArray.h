#pragma once
#include <exception>
#include <cstddef>

class bad_range : public std::exception 
{
public:
	virtual const char* what() const noexcept override
	{
		return "Out of bounds";
	}
};
class bad_length : public std::exception
{
public:
	virtual const char* what() const noexcept override
	{
		return "Invalid length";
	}
};
class IntegerArray
{
private:
	int* data;
	size_t size;
public:
	IntegerArray(size_t size);
	IntegerArray(const IntegerArray& other);
	~IntegerArray();
	int& operator[](size_t index);
	size_t getSize() const;
	void resize(size_t new_size);
	void insert(size_t index, int value);
	void remove(size_t index);
	void pushFront(int value);
	void pushBack(int value);
	int find(int value) const;
	};