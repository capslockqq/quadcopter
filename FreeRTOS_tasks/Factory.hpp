#include "../application_code/components/Component.hpp"
#include "../application_code/communication/transport_layer/I_Serial_Communication.hpp"

#ifdef PC
#include "../application_code/communication/transport_layer/UART_fake.hpp"
#include "../application_code/communication/transport_layer/I2C_fake.hpp"

#elif TARGET
#include "../avr_code/communication/hardware_layer/uart.h"

#endif
template <class Data_Com, class IMU_Com>

class Factory : public Component {
public:
    Factory(Component *, const char*, const char*);
    I_Serial_Communication<Data_Com>* get_data_com_to_computer();
    I_Serial_Communication<IMU_Com>*  get_data_com_to_IMU();

private:
    I_Serial_Communication<Data_Com> *data_com_to_computer;
    I_Serial_Communication<IMU_Com>  *data_com_to_IMU;

};
template <class Data_Com, class IMU_Com>
Factory<Data_Com, IMU_Com>::Factory(Component *parent, const char* name, const char* id) : 
Component(parent, name, id)
{
    #ifdef PC

    data_com_to_computer = new UART_fake(this, "Fake UART", "01");
    data_com_to_IMU      = new I2C_fake(this, "Fake I2C", "01");
    #elif TARGET
    data_com_to_computer = new UART(this, "UART", "01");
    #endif
}

template <class Data_Com, class IMU_Com>
I_Serial_Communication<Data_Com>* Factory<Data_Com, IMU_Com>::get_data_com_to_computer() {
    return data_com_to_computer;
}

template <class Data_Com, class IMU_Com>
I_Serial_Communication<IMU_Com>* Factory<Data_Com, IMU_Com>::get_data_com_to_IMU() {
    return data_com_to_IMU;
}