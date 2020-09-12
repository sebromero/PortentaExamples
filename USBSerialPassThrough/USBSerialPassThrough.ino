#include "Arduino.h"
#include "RPC_internal.h"

void setup() {      
#ifdef CORE_CM7
  bootM4();
  //while (!Serial) {}
  Serial.begin(115200);
#endif
  RPC1.begin();  
}

void loop() {
#ifdef CORE_CM7
  while (RPC1.available()) {
    Serial.write(RPC1.read());
  }
#endif

#ifdef CORE_CM4
  RPC1.print("Hello from M4\n");
  delay(1000);
#endif

}
