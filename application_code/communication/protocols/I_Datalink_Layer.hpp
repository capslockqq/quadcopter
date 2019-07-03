class I_Datalink_Layer {
public:
    virtual void Send_Data(const char *)      = 0;
    virtual void Receive_Data(const char *)   = 0;
};