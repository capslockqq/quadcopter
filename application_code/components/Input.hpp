
#pragma once
#include "Component.hpp"
#include "Output.hpp"
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