#include "Servotor32.h" // call the servotor32 Library
Servotor32 hexy; // create a servotor32 object

void setup() {
  //setup PC serial port
  Serial.begin(9600);

  // Don't setup Serial1 for Uno
  // reconfigure bluetooth module to 9600 baud id needed
  // Serial1.begin(115200);     // Changed from 9600 baud
  // Serial1.print("AT+BAUD4"); // Tell the module to change the baud rate to 9600
  delay(1100); // Wait a notch over 1 second to make sure the setting "sticks"
  // Serial1.begin(9600);     // Changed from 9600 baud

  hexy.begin();
}

void loop() {
  // blink the status led
  digitalWrite(STATUS_LED, HIGH);
  hexy.delay_ms(500); // wait 500mS
  digitalWrite(STATUS_LED, LOW);
  hexy.delay_ms(500); // wait 500mS
  
  // kill all servos
  for(int i=0; i<32; i++){
    hexy.changeServo(i,-1);
  }
  
  // center servos 0,1,2,3
  hexy.changeServo(0,1500);
  hexy.changeServo(1,1500);
  hexy.changeServo(2,1500);
  hexy.changeServo(3,1500);
  
  hexy.delay_ms(100); // wait 100mS
 
  while(true){
    // get a ping from the ultrasonic sensor in CM
    //Serial.print("CM: ");
    //Serial.println(hexy.ping());
    //hexy.delay_ms(200); // wait 200mS
    
    hexy.process(&Serial); //process input from the USB
    // Don't use serial 1 for Uno
    // hexy.process(&Serial1); //process input from the board serial (i.e. bluetooth)
  }
  
}




