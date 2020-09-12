#include "Arduino.h"
#include "RPC_internal.h"
#include "mbed.h"


using namespace arduino;

class VirtualSerial
{
private:
    rtos::Thread _dataPollingThread;
    RPC* _rpc;
    RPC* getRPC();    
public:
    VirtualSerial();
    ~VirtualSerial();
    void begin(unsigned long baudrate = 1);
    void poll();
    void end();
    /*
    int available(void);
    int peek(void);
    int read(void);
    void flush(void);    
    size_t write(const uint8_t*, size_t);
    */
    size_t write(uint8_t c);
    void print(String message);
    operator bool();
};

extern VirtualSerial VirtualSerial1;
