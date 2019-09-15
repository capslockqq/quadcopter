    
#pragma once
#include "Input.hpp"
#include "Component.hpp"
#ifdef PC
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
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
	bool first_time = true;
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
	*_value = value;
	#ifdef PC
	if (first_time) {
		first_time = false;
		_fileName = "";
		Component *compo = this;
		Component *last_component;
		int max_number_of_parents = 9
		;
		int number_of_parents = 0;
		while(true) {
			number_of_parents++;
			if (number_of_parents > max_number_of_parents) break;
			if (!compo || compo == last_component) {
				break;
			}
			std::cout << "compo: " << compo->GetName() << std::endl;
			_fileName += (string)compo->GetName() + (string)"_";
			last_component = compo;
			compo = compo->GetParent();
			if (!compo) std::cout << "NULL" << std::endl;
		}
		//std::reverse(_fileName.begin(), _fileName.end());
		_fileName += ".txt";
		std::cout << "filename" << _fileName << std::endl;

		ofstream myfile;
		myfile.open(_fileName);
		myfile.close();
	}
	ofstream myfile1;
  	myfile1.open (_fileName, std::ios_base::app);
  	myfile1 << *_value;
	myfile1 << "\n";
  	myfile1.close();
	#endif
}