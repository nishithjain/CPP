#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class MemoryBlock
{
private:
	size_t _length;		// The length of the resource.
	int* _data;			// The resource.

public:
	// Simple constructor that initializes the resource.
	explicit MemoryBlock(size_t length)	: _length(length), _data(new int[length])
	{
		cout << "In MemoryBlock(size_t).length = " << _length << "." << endl;
	}

	// Destructor.
	~MemoryBlock()
	{
		cout << "In ~MemoryBlock().length = "  << _length << ".";

		if (_data != nullptr)
		{
			cout << " Deleting resource.";
			// Delete the resource.
			delete[] _data;
		}
		cout << endl;
	}

	// Copy constructor.
	MemoryBlock(const MemoryBlock& other) : _length(other._length) , _data(new int[other._length])
	{
		cout << "In MemoryBlock(const MemoryBlock&). length = " << other._length << ". Copying resource." << endl;
		std::copy(other._data, other._data + _length, _data);
	}

	// Copy assignment operator.
	MemoryBlock& operator=(const MemoryBlock& other)
	{
		cout << "In operator=(const MemoryBlock&). length = " << other._length << ". Copying resource." << endl;
		if (this != &other)
		{
			// Free the existing resource.
			delete[] _data;

			_length = other._length;
			_data = new int[_length];
			std::copy(other._data, other._data + _length, _data);
		}
		return *this;
	}

	// Move Constructor
	MemoryBlock(MemoryBlock&& other) : _data(NULL), _length(0)
	{
		*this = std::move(other);
	}
	/*MemoryBlock(MemoryBlock&& other) : _data(nullptr), _length(0)
	{
		cout << "In MemoryBlock(MemoryBlock&&). length = " << other._length << ". Moving resource." << endl;
		_data = other._data;
		_length = other._length;
		other._data = nullptr;
		other._length = 0;
	}*/

	MemoryBlock& operator=(MemoryBlock&& other)
	{
		cout << "In operator=(MemoryBlock&&). length = " << other._length << "." << endl;
		if(this != &other)
		{
			// Free the existing resource.
			delete[] _data;
			// Copy the data pointer and its length from the source object.
			_data = other._data;
			_length = other._length;

			// Release the data pointer from the source object so that
			// the destructor does not free the memory multiple times.
			other._data = NULL;
			other._length = 0;
		}
		return *this;
	}

	// Retrieves the length of the data resource.
	size_t getLength() const { return _length; }
};

int main(void)
{
	// Create a vector object and add a few elements to it.
	vector<MemoryBlock> v;
	v.push_back(MemoryBlock(25));
	v.push_back(MemoryBlock(75));

	// Insert a new element into the second position of the vector.
	v.insert(v.begin() + 1, MemoryBlock(50));

	return 0;
}