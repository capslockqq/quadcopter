    
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
	#ifdef PC
	#include <string>
	std::string _fileName;
	#endif

private:
	T* _value = new T();
};
template <class T>
inline Output<T>::Output(Component *parent, const char *name, const char *id) :
Component(parent, name, id)
{
	#ifdef PC
	_fileName = (string)this->GetParent()->GetName()+" "+(string)this->GetName()+(string)".txt";
	ofstream myfile;
  	myfile.open (_fileName);
	#endif
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
	#ifdef PC
	#include <string>
	ofstream myfile;
  	myfile.open (_fileName, std::ios_base::app);
  	myfile << *_value;
	myfile << "\n";
  	myfile.close();
	#endif
}