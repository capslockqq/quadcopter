#include "UART.hpp"

UART::UART()
{
}

void UART::Send_Data(const char * data) {
    /*int i = 0;
    this->op_data.SetValue(data);
	while(data[i] != '\0') {
		while ( !( UCSR0A & (1<<UDRE0)));
        /* Put data into buffer, sends the data */
        /*UDR0 = data[i];
		i++;
	}*/
    while ( !( UCSR0A & (1<<UDRE0)));
    /* Put data into buffer, sends the data */
    UDR0 = 'c';
    
}

void UART::Receive_Data(const char * data) {

}
