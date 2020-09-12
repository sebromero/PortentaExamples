#include "VirtualSerial.h"

RPC* VirtualSerial::getRPC(){
     if(!_rpc){
         _rpc = new RPC;         
     }
     return _rpc;
 }

void VirtualSerial::poll(){    
    #ifdef CORE_CM7
      while (getRPC()->available()) {
        Serial.write(getRPC()->read());
      }
    #endif
}

void VirtualSerial::begin(unsigned long baudrate){
  getRPC()->begin();
  
  #ifdef CORE_CM7    
    _dataPollingThread.start([this]() {
      while(true){
        this->poll();
        rtos::ThisThread::sleep_for(20);
      }  
    });    
    _dataPollingThread.set_priority(osPriority_t::osPriorityLow);
   #endif                  
}

size_t VirtualSerial::write(uint8_t c){
  getRPC()->print(c);
}

void VirtualSerial::print(String message){
  getRPC()->print(message);
}

void VirtualSerial::end(){
  _dataPollingThread.terminate();
  getRPC()->end();
}

VirtualSerial::VirtualSerial(){}

VirtualSerial::~VirtualSerial(){
  delete _rpc;
}

VirtualSerial::operator bool() {
 return 1;
}

VirtualSerial VirtualSerial1;
