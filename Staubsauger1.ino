
#include <IRremote.h>


int remote;
int back ;
const int RECV_PIN = 13;
unsigned long lastCode;
IRrecv irrecv(RECV_PIN);
decode_results results;


void setup() {

  pinMode(8, OUTPUT); //links rückwärts
  pinMode(9, OUTPUT); //rechts rückwärts
  pinMode(10, OUTPUT); //rechts vorwärts
  pinMode(11, OUTPUT); //saugen
  pinMode(12, OUTPUT); //links vorwärts
  pinMode (4, INPUT); //Sensor
  Serial.begin(9600);
  pinMode(2, OUTPUT); //LED
  pinMode(3, OUTPUT); //LED
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(11, HIGH);
  irrecv.enableIRIn();
  remote = 0 ;



}
void loop () {
  Serial.println(digitalRead(4))
  ;

  if (digitalRead(4) >= 1 & back == 0 & remote == 0) {
    digitalWrite(10, HIGH);
    digitalWrite(12, HIGH);

  }

  if (digitalRead(4) < 1 & back == 0 & remote == 0) {
    back = 1 ;
    digitalWrite(10, LOW);
    digitalWrite(12, LOW);
    delay(40);
    digitalWrite(8, HIGH);
    digitalWrite(9, HIGH);
    delay (274);
    digitalWrite(9, LOW);
    delay (random(1000, 2500));
    digitalWrite(8, LOW);
    back = 0 ;
  }
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    irrecv.resume();
    switch (results.value) {
      case 0xFFA25D:         //Taste 1
        remote = 1;
        digitalWrite(11, LOW);

        irrecv.enableIRIn();
        break;                 //Taste 2
      case 0xFF629D
          :
        remote = 1 ;
        digitalWrite(10, HIGH);
        digitalWrite(12, HIGH);

        irrecv.enableIRIn();
        break;
      case 0xFFE21D:         //Taste 3
        remote = 0;

        irrecv.enableIRIn();
        break;
      case 0xFF22DD :              //Taste 4
        remote = 1 ;
        digitalWrite(10, HIGH);
        digitalWrite(8, HIGH);

        irrecv.enableIRIn();
        break;
      case 0xFF02FD
          :              //Taste 5
        remote = 1 ;
        digitalWrite(8, LOW);
        digitalWrite(9, LOW);
        digitalWrite(10, LOW);
        digitalWrite(12, LOW);



        break;
      case 0xFFC23D
          :              //Taste 6
        remote = 1 ;
        digitalWrite(9, HIGH);
        digitalWrite(12, HIGH);


        break;
      case 0xFFE01F
          : remote = 1; digitalWrite(11, HIGH);         //Taste 7

        break;
      case 0xFFA857
          :              //Taste 8
        remote = 1 ;
        digitalWrite(8, HIGH);
        digitalWrite(9, HIGH);

        break;

        //  case 0xFF906F :              //Taste 9

        //  break;


    }






  }
}
