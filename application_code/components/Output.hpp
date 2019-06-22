    
#pragma once
template <class T>
class Output {
public:
	Output();
	T GetValue();
	T* GetValueAddress();
	void SetValue(T value);
private:
	T dummyadress;
	T* _value;
};
template <class T>
inline Output<T>::Output()
{
    T tmp = false;
	_value = &tmp;
}

template <class T>
T Output<T>::GetValue() {
	return *_value;
}

template <class T>
T* Output<T>::GetValueAddress() {
	return _value;
}

template <class T>
void Output<T>::SetValue(T value) {
	if (!_value) {
		_value = &dummyadress;
	}
	*_value = value;
}