// RF24 - Version: Latest 
#include <RF24.h>
#include <RF24_config.h>
#include <nRF24L01.h>
#include <printf.h>

#define RF_ENABLE 8
#define RF_SELECT 9


#define CONTROL_PAD0 A0
#define CONTROL_PAD0 A1



RF24 radio(RF_ENABLE,RF_SELECT);

//values for transmitter
uint8_t output_address=255;
uint8_t input_address=256;


void setup(){
  Serial.begin(9600);
  
  pinMode(CONTROL_PAD0, INPUT);
  pinMode(CONTROL_PAD1, INPUT);
  
  radio.begin();
  
  radio.setPAlevel(RF24_PA_LOW);
  
  radio.openWritingPipe(output_address);
  radio.openReadingPipe(input_address);
  
  radio.stopListening();
}

void loop(){
  int pad0=analogRead(CONTROL_PAD0);
  
  int pad1=analogRead(CONTROL_PAD1);
  
  uint8_t buffer=0b00000000;
  
  if(pad0>128 && pad0<256){
    buffer=0b00000001;
    if( !radio.write(&buffer,sizeof(uint_8t)) ){
      Serial.println("write fail");
    }
  }else if(pad0>256 && pad0<512){
    buffer=0b00000010;
    if( !radio.write(&buffer,sizeof(uint_8t)) ){
      Serial.println("write fail");
    }
  }else if(pad0>512 && pad0<768){
    buffer=0b00000100;
    if( !radio.write(&buffer,sizeof(uint_8t)) ){
      Serial.println("write fail");
    }
  }else if(pad0>768){
    buffer=0b00001000;
    if( !radio.write(&buffer,sizeof(uint_8t)) ){
      Serial.println("write fail");
    }
  }
  
  buffer=0b00000000;
  if(pad1>128 && pad1<256){
    
    buffer=0b00010000;
    if( !radio.write(&buffer,sizeof(uint_8t)) ){
      Serial.println("write fail");
    }
    
  }else if(pad1>256 && pad1<512){
    
    buffer=0b00100000;
    if( !radio.write(&buffer,sizeof(uint_8t)) ){
      Serial.println("write fail");
    }
    
  }else if(pad1>512 && pad1<768){
    
    buffer=0b01000000;
    if( !radio.write(&buffer,sizeof(uint_8t)) ){
      Serial.println("write fail");
    }
    
  }else if(pad1>768){
    
    buffer=0b10000000;
    if( !radio.write(&buffer,sizeof(uint_8t)) ){
      Serial.println("write fail");
    }
    
  }
  
  // while(!radio.available()) run while package not received
}
