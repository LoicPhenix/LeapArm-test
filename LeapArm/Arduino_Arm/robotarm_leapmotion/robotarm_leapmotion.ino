//#include<Servo.h>
#include "MeOrion.h"

int incomingByte = 0;

//pince [-150,150]
MeDCMotor motor1_pince(PORT_1);
//bras [-200,250]
MeDCMotor motor2_bras(PORT_2); //+ monté / - descendre (correctif negatif +50)
//Chenilles [-255,255]
MeDCMotor motor3_gauche(M1);
MeDCMotor motor4_droit(M2);


void setup() {
  Serial.begin(9600);
  Serial.println("Hello Arduino");
}

void loop() {
  
}

void serialEvent(){
  char buffer[7] = {};
  char pin[2] = {};
  char angle[6] = {};
  int angle_int;
  int pin_int;
  
  //Reception Trame
  Serial.readBytes(buffer,6);

  //Traitement de la trame
  strcpy(pin,buffer);
  strcpy(angle,buffer);  
  angle[0] = ' '; 
  angle[1] = ' ';
  pin[1] = ' ';
  angle_int = atoi(angle);
  pin_int = atoi(pin);

  //Return Message
  Serial.print(pin_int);
  Serial.print(angle_int);

  //Gestion Pince (pin = 1) (moteur_1)
  /*if(atoi(pin) == 1) {
    motor1_pince.run(angle_int);
    Serial.print(angle_int + " | OK");
  }*/

  //Gestion Bras (pin = 2) (moteur_2)
  /*if(atoi(pin) == 2) {
    motor2_bras.run(angle_int);
    Serial.print(angle_int + " | OK");
  }*/

  //Gestion Drive (pin = 3)(moteur_3/4)
  //if(atoi(pin) == 3) {
    if (angle_int == 0) {
      motor3_gauche.stop();
      motor4_droit.stop();
    } else {
      // correction de rotation des moteurs 
      // moteur gauche + faible (correctif : - 15)
      if(angle_int < 0)
        motor3_gauche.run(angle_int-15); 
      else
        motor3_gauche.run(angle_int);
       motor4_droit.run(-angle_int);
    }
  //}

  //Gestion Turn (pin = 4)(moteur_3/4)
  /*if(pin_int == 4) {
    motor3_gauche.run(angle_int);
    motor4_droit.run(angle_int);
    //Serial.print(angle_int);
  }*/
  
  Serial.flush();  
}
