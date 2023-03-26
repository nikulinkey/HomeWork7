#include <iostream>
#include "Container.h"
using namespace std;

    Array::Array() = default;
	Array :: Array(int length) : _length(length)
	{
		if (_length <= 0)
		{
			throw "wrong length of array create";
		}
		else
		{
			_data = new int[_length]{};
		}
	}
	Array::Array(const Array& a)
	{
		reallocate(a.getLength());

		for (int index = 0; index < _length; ++index)
		{
			_data[index] = a._data[index];
		}
	}
	Array :: ~Array()
	{
		delete[] _data;
	}
	
	void Array :: clean()
	{
		delete[] _data;
		_data = nullptr;
		_length = 0;
	}
	int& Array :: operator[](int index)
	{
		return _data[index];
	}
	int Array :: getLength() const
	{
		return _length;
	}

	void Array:: reallocate(int newLength)
	{
		clean();
		if (newLength <= 0)
			return;
		else
		{
			_data = new int[newLength];
			_length = newLength;
		}
	}

	void Array:: resize(int newLength)
	{
		if (newLength == _length)
			return;
		if (newLength <= 0)
		{
			throw "wrong length of array resize";
		}
		else {


			int* data = new int[newLength];

			int elementsToCopy = (newLength > _length) ? _length : newLength;
			
				for (int index = 0; index < elementsToCopy; ++index)
					data[index] = _data[index];
				if (newLength > _length)
				{
					for (int index = elementsToCopy; index < newLength; ++index)
						data[index] = 0;
				}

			delete[] _data;
			_data = data;
			_length = newLength;
		}
	}
	

	Array& Array :: operator=(const Array& a)
	{
		if (&a == this)
			return *this;
		else
		{
			reallocate(a.getLength());
			
				for (int index = 0; index < _length; ++index)
				{
					_data[index] = a._data[index];
				}
		
			return *this;
		}
	}
	void Array :: insertAfter(int value, int index)
	{

		if (index < 0 || index > _length)
		{
			throw "wrong index insert";
		}
		
			int* data = new int[_length + 1];
			
				for (int before = 0; before < index; ++before)
				{
					data[before] = _data[before];
				}

				data[index] = value;

				for (int after = index; after < _length; ++after)
				{
					data[after + 1] = _data[after];
				}
			
			delete[] _data;
			_data = data;
			++_length;
	}

	void Array::remove(int index)
	{
		if (index <= 0 || index > _length)
		{
			throw "wrong index remove";
		}
		else if (_length == 1)
		{
			clean();
			return;
		}
		else {

			int* data = new int[_length - 1];
			
				for (int before = 0; before < index; ++before)
				{
					data[before] = _data[before];
				}
				for (int after = index; after < _length; ++after)
				{
					data[after - 1] = _data[after];
				}
			
			delete[] _data;
			_data = data;
			--_length;
		}
	}

	void Array::insertAtBeginning(int value) { insertAfter(value, 0); }
	void Array::insertAtEnd(int value) { insertAfter(value, _length); }
	void Array::search(int value)
	{
		for (int index = 0; index < _length; ++index)
		{
				if (value == _data[index])
				{
					cout << "Number " << value << "is in the cell: " << index + 1 << endl;
				}
		}
	}
	

