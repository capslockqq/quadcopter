#pragma once
template<class implementation>
class interface {
public:
    void some_function() {
        static_cast<implementation*>(this)->some_function();
    }
};
