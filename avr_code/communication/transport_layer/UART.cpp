#include "UART.hpp"

UART::UART()
{
}

void UART::Send_Data(const char * data) {
    int i = 0;
    this->op_data.SetValue(data);
	while(this->op_data.GetValue()[i] != '\0') {
		while ( !( UCSR0A & (1<<UDRE0)));
        /* Put data into buffer, sends the data */
        UDR0 = this->op_data.GetValue()[i];
		i++;
	}
}

void UART::Receive_Data(const char * data) {

}
