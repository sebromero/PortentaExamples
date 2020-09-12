#include "RPC_internal.h"
#include "VirtualSerial.h"

#ifdef CORE_CM4
  #define Serial VirtualSerial1
#endif

void setup() {
  while(!Serial){}
  Serial.begin(115200);
  
  #ifdef CORE_CM7  
    bootM4();      
    VirtualSerial1.begin();
  #endif
}

void loop() {
  delay(500);  
  
  #ifdef CORE_CM4
  Serial.print("Hello from M4\n");
  #endif
  
  #ifdef CORE_CM7
  Serial.print("Hello from M7\n");  
  #endif
}
