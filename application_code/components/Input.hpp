
#pragma once
#include "Output.hpp"
template <class T>
class Input
{
public:
	Input();
	~Input();
	T GetValue();
	T* GetValueAddress();
	void operator=(Output<T> output) {
		_value = output.GetValueAddress();
	}    
private:
	T* _value;
};

template <class T>
inline Input<T>::Input()
{
}

template <class T>
inline Input<T>::~Input()
{
}
template <class T>
inline T Input<T>::GetValue() {
	return *_value;
}

template <class T>
T* Input<T>::GetValueAddress() {
	return _value;
}