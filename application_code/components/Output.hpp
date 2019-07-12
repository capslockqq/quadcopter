    
#pragma once
#include "Input.hpp"
#include "Component.hpp"
#ifdef PC
#include <iostream>
#include <fstream>
using namespace std;
#endif
template <class T>
class Output : public Component
{
public:
	Output(Component *parent, const char *name, const char *id);
	~Output();
	T GetValue();
	T* GetValueAddress();
	void SetValue(T value);

private:
	T* _value = new T();
};
template <class T>
inline Output<T>::Output(Component *parent, const char *name, const char *id) :
Component(parent, name, id)
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
	#ifdef PC
	ofstream myfile;
  	myfile.open ("example.txt", std::ios_base::app);
  	myfile << "Writing this to a file.\n";
  	myfile.close();
	#endif
	*_value = value;
}