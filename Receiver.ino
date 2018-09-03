// RF24 - Version: Latest 
#include <RF24.h>
#include <RF24_config.h>
#include <nRF24L01.h>
#include <printf.h>

#define RF_ENABLE 8
#define RF_SELECT 9

/* define the output pins for the RC
#define CONTROL_PAD0 A0
#define CONTROL_PAD0 A1
*/


RF24 radio(RF_ENABLE,RF_SELECT);

//values for receiver
uint8_t output_address=256;
uint8_t input_address=255;


void setup(){
  Serial.begin(9600);
  
  /*
  pinMode(CONTROL_PAD0, INPUT);
  pinMode(CONTROL_PAD1, INPUT);
  */
  
  radio.begin();
  
  radio.setPAlevel(RF24_PA_LOW);
  
  radio.openWritingPipe(output_address);
  radio.openReadingPipe(input_address);
  
  radio.startListening();
}

void loop(){
  while(!radio.available()); //wait for input
  
  
  uint8_t buffer=0b00000000;
  
  radio.read(&buffer,sizeof(uint8_t));
  
  
  /*
  by checking if a value is less than X
  if a bit is flipped during communication it
  has a better chance to activate the correct pin
  */
  if(buffer<0b00000010){
    //enable a pin
  }else if(buffer<0b00000100){

  }else if(buffer<0b00001000){

  }else if(buffer<0b00010000){

  }else if(buffer<0b00100000){

  }else if(buffer<0b01000000){

  }else if(buffer<0b10000000){

  }else if(buffer>=0b10000000){

  }

  
}
