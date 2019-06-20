class I_Serial_Communication {
public:
    virtual void Send_Data(const char *)      = 0;
    virtual void Receive_Data(const char *)   = 0;
};