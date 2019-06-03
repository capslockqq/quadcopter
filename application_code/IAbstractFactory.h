/*/#include <memory>
#include <iostream>
#include "ITransportLayerFactory.h"
template <class T>
class IAbstractFactory {
public:
    std::unique_ptr<T> GetFactory();
};
template <class T>
std::unique_ptr<T> IAbstractFactory<T>::GetFactory() {
    if (T == ITransportLayerFactory) {
        std::cout << "Transportlayer" << std::endl;
    }
}*/