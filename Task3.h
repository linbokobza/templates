#pragma once
#include <iostream>
#include <string>
using namespace std;

template <class T>
class Array {
private:
	T* arrayVal;
	int sizeArray;
public:
	Array( int = 1);
	~Array() { delete arrayVal; }

	//function
	void printType();
	int findIndex(T value);
	void operator [] (int index);
	T findMax();
	T findMin();
	void operator += (T value);
	void operator -= (T value);
	T operator + (Array arr);
	bool operator = (Array arr);
	bool isSorted();
	void setArray(int elem, T val);

	//getters
	int GetSize() { return sizeArray; }
	T* GetValues() {return arrayVal;}

	friend ostream& operator << (ostream& output, const Array<T>& object) {
		cout << endl << "---------Array info---------" << endl;

		cout << "Size: ";
		output << object.sizeArray << ' ' << endl;

		if (object.arrayVal) {
			cout << "Array values: " << endl;
			for (size_t i = 0; i < object.sizeArray; i++)
				output << object.arrayVal[i] << ",";

			cout << endl;
		}
		return output;
	}

	void printArray() {

		for (size_t i = 0; i < sizeArray; i++)
		{
			cout << arrayVal[i] << ",";
		}
		cout << endl;

	}
};



template <class T>
void  Array<T>::setArray(int index, T value) {
	arrayVal[index] = value;
}
template <class T>
Array<T>::Array(int size) : sizeArray(size) {
	arrayVal = new T[sizeArray];
}

template <class T>
int Array<T>::findIndex(T value) {
	for (size_t i = 0; i < sizeArray; i++)
		if (arrayVal[i] == value)
			return i;

	throw "The value dosen't exist in the array";
}

template <class T>
void Array<T>::operator [] (int index) {
	if (index >= 0 && index < sizeArray)
		return *arrayVal[index];
	else {
		throw "Out of boundary of the array " ;
	}
}

template <class T>
T Array<T>::findMax() {
	if (arrayVal == NULL)
		return NULL;

	T max = arrayVal[0];
	for (int i = 1; i < sizeArray; i++)
		if (arrayVal[i] > max)
			max = arrayVal[i];
	return max;
}

template <class T>
T Array<T>::findMin() {
	if (arrayVal == NULL)
		return NULL;

	T min = arrayVal[0];
	for (int i = 1; i < sizeArray; i++)
		if (arrayVal[i] < min)
			min = arrayVal[i];
	return min;
}

template <class T>
void Array<T>::operator += (T value) {
	if (!arrayVal) {
		T* temp = new T[++sizeArray];
		temp[0] = value;
		return;
	}
	T* temp = new T[++sizeArray];
	temp[0] = value;
	int j = 0;
	for (size_t i = 1; i < sizeArray; i++)
	{
		temp[i] = arrayVal[j];
		j++;
	}
	delete[] arrayVal;
	arrayVal = temp;
	cout << "added!" << endl;

}

template <class T>
void Array<T>::operator -= (T value) {
	if (!arrayVal) {
		cout << "The array is empty" << endl;
		return;
	}

	int count = 0;
	for (size_t i = 0; i < sizeArray; i++)
	{
		if (arrayVal[i] == value)
			count++;
	}

	if (count == 0)
	{
		cout << "This value dosen't exist in the array" << endl;
		return;
	}

	T* temp = new T[sizeArray-count];
	int j = 0;

	for (size_t i = 0; i < sizeArray; i++)
	{
		if (arrayVal[i] != value) {
			temp[j] = arrayVal[i];
			j++;
		}
	}
	delete[] arrayVal;
	sizeArray = sizeArray - count;
	arrayVal = new T[sizeArray];
	arrayVal = temp;
	cout << "removed!" << endl;
}

template <class T>
T Array<T>::operator + (Array arr) {
	sizeArray = sizeArray + arr.GetSize();
	T* temp = new T[sizeArray];
	for (size_t i = 0; i < sizeArray; i++)
		temp[i] = arrayVal[i];
	
	T* arr1= arr.GetValues();
	for (size_t i = sizeArray; i < arr.GetSize(); i++)
		temp[i] = arr1[i];

	delete[] arrayVal;
	return *temp;
}

template <class T>
bool Array<T>::operator = (Array arr) {

	if (arr.GetSize() == 0 || sizeArray == 0)
		throw "The array is empty";

	T* arr1 = arr.GetValues();
	for (size_t i = 0; i < sizeArray; i++)
		if (arr1[i] != arrayVal[i])
			return false;
	return true;
}

template <class T>
bool Array<T>::isSorted() {
	if (sizeArray == 0 || sizeArray == 1)
		return true;

	for (size_t i = 1; i < sizeArray; i++)
		if (arrayVal[i-1] >= arrayVal[i])
			return false;
	return true;
}

template <class T>
void Array<T>::printType() {
	cout << "The type of Array are: ";
	cout << typeid(T).name() << endl;
	cout << endl;
}

