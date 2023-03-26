#pragma once

class Array
{
public:
	Array();
	Array(int length);
	Array(const Array& a);
	~Array();
	void clean();
	int& operator[](int index);
	int getLength() const;
	void reallocate(int newLength);
	void resize(int newLength);
	Array& operator=(const Array& a);
	void insertAfter(int value, int index);
	void remove(int index);
	void insertAtBeginning(int value);
	void insertAtEnd(int value);
	void search(int value);
	
private:
	int _length{};
	int* _data{};
};


