    
#pragma once
#include "Input.hpp"
#include "Component.hpp"
#ifdef PC
#include "Singleton.hpp"
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
	ComponentType type() { return ComponentType::output; }
	T GetValue();
	T* GetValueAddress();
	void SetValue(T value);
	#ifdef PC
	#include <string>
	std::string _fileName;
	std::string _logging_ids;
	ofstream output_file;
	bool logging = false;
	#endif

private:
	T* _value = new T();
	bool first_time = true;
};
template <class T>
inline Output<T>::Output(Component *parent, const char *name, const char *id) :
Component(parent, name, id, output)
{
	#ifdef PC
	
	SingletonLogging *S = SingletonLogging::GetInstance();
    auto v = S->GetData();
	if (v.size() > 1) {
		for(auto t=v.begin(); t!=v.end(); ++t) {
			if (*t == this->str_id) {
				logging = true;
			}
		}
	}
	else if (v.size() > 0) {
		if (v.at(0) == this->str_id) {
			logging = true;
		}
	}
   	
	if (logging) {
		_fileName = "";
		Component *compo = this;
		Component *last_component;
		int max_number_of_parents = 9;
		int number_of_parents = 0;
		while(true) {
			number_of_parents++;
			if (number_of_parents > max_number_of_parents) break;
			if (!compo || compo == last_component) {
				break;
			}
			_fileName += (string)compo->GetName() + (string)"_";
			last_component = compo;
			compo = compo->GetParent();
			if (!compo) std::cout << "NULL" << std::endl;
		}
		//std::reverse(_fileName.begin(), _fileName.end());
		_fileName += ".txt";

		output_file.open(_fileName);
		output_file.close();
		output_file.open(_fileName, std::ios_base::app);
	}
	
	#endif
}

template <class T>
inline Output<T>::~Output()
{
	#ifdef PC
	output_file.close();
	#endif
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
	if (logging) {
		output_file << *_value;
		output_file << ";\n";
	}
  	
	#endif 
}