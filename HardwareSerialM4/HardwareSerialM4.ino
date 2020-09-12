void setup() {  
  #ifdef CORE_CM7
  bootM4();      
  #endif

  #ifdef CORE_CM4
  
  _UART1_.begin(115200);
  _UART1_.println("Hello from M4");

  //Serial is mapped to _UART1_ on M4 so the following is equivalent:
  //Serial.begin(115200);  
  //Serial.println("Hello from M4");
  
  #endif
  
}

void loop() {
  delay(500);
}
