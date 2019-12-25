#pragma once
#include "Input.hpp"
#include "Component.hpp"
#ifdef PC
#include "OutputObserver.hpp"
#include "Singleton.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include "type_name.hpp"
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
	static int number_of_outputs;
	#ifdef PC
	#include <string>
	void Update_Log();
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
class Input : public Component
{
public:
	Input(Component *parent, const char *name, const char *id);
	~Input();
	ComponentType type() { return ComponentType::input;}
	T GetValue();
	T* GetValueAddress();
	void SetValue(T value);
	void operator=(Output<T> output) {
		_value = output.GetValueAddress();
	}    
private:
	T* _value = new T();
};
template <class T>
inline Input<T>::Input(Component *parent, const char *name, const char *id) :
Component(parent, name, id, input)
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

template <class T>
void Input<T>::SetValue(T value) {
	*_value = value;
}

template <typename T> int Output<T>::number_of_outputs(0);

template <class T>
inline Output<T>::Output(Component *parent, const char *name, const char *id) :
Component(parent, name, id, output)
{
	#ifdef PC
	number_of_outputs++;

	SingletonLogging *S = SingletonLogging::GetInstance();
	S->count();

    auto v = S->GetData();
	if (v.size() > 1) {
		for(auto t=v.begin(); t!=v.end(); ++t) {
			if (*t == std::string(this->GetUniqueId())) {
				logging = true;
			}
		}
	}
	else if (v.size() > 0) {
		if (v.at(0) == std::string(this->GetUniqueId())) {
			logging = true;
		}
	}
   	
	if (logging) {
		OutputObserver *L = OutputObserver::GetInstance();
		int* ptr_to_obj = (int*)this;
		L->Add_Output(ptr_to_obj, type_name<decltype(GetValue())>());
		_fileName = std::string(this->GetUniqueId());
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
}
#ifdef PC
template <class T>
void Output<T>::Update_Log() {
	if (logging) {
		output_file << *_value;
		output_file << ";\n";
	}
}
#endif