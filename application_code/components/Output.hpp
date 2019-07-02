    
#pragma once
#include "Input.hpp"
template <class T>
class Output 
{
public:
	Output();
	~Output();
	T GetValue();
	T* GetValueAddress();
	void SetValue(T value);

private:
	T* _value = new T();
};
template <class T>
inline Output<T>::Output()
{
}

template <class T>
inline Output<T>::~Output()
{
}
template <class T>
inline T Output<T>::GetValue() {
	return *_value;
}

template <class T>
T* Output<T>::GetValueAddress() {
	return _value;
}

template <class T>
void Output<T>::SetValue(T value) {
	if (!_value) {
		return;
	}
	*_value = value;
}