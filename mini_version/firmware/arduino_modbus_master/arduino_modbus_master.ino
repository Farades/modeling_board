#include <SoftwareSerial.h>

#include "ModbusRtu.h"

#define  ID  2
Modbus slave(ID, 11, 9, 10);
int8_t state = 0;
uint16_t au16data[9];

void setup() {
  slave.begin(19200);
}

void loop() {
  io_setup(); // I/O settings
  state = slave.poll( au16data, 9 );
  io_poll();
}

void io_setup() {
  // define i/o
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(A5, INPUT);
  pinMode(A4, INPUT);
  pinMode(A3, INPUT);

}

void io_poll() {
//  // get digital inputs -> au16data[0]
  bitWrite( au16data[0], 0, digitalRead( 2 ));
  bitWrite( au16data[0], 1, digitalRead( 3 ));
  bitWrite( au16data[0], 2, digitalRead( 4 ));
  bitWrite( au16data[0], 3, digitalRead( A5 ));
  bitWrite( au16data[0], 4, digitalRead( A4 ));
  bitWrite( au16data[0], 5, digitalRead( A3 ));
//
//  // set digital outputs -> au16data[1]
//  digitalWrite( 6, bitRead( au16data[1], 0 ));
//  digitalWrite( 7, bitRead( au16data[1], 1 ));
//  digitalWrite( 8, bitRead( au16data[1], 2 ));
//  digitalWrite( 9, bitRead( au16data[1], 3 ));
//
//  // set analog outputs
//  analogWrite( 10, au16data[2] );
//  analogWrite( 11, au16data[3] );

  // read analog inputs
  au16data[1] = analogRead( A0 );
  au16data[2] = analogRead( A1 );
  au16data[3] = analogRead( A2 );

  // diagnose communication
//  au16data[6] = slave.getInCnt();
//  au16data[7] = slave.getOutCnt();
//  au16data[8] = slave.getErrCnt();
}
