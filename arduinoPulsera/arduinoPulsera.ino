/*
PROGRAMA PARA LA IMPLEMENTACIÓN DE UNA PULSERA INTELIGENTE QUE AYUDE A ENFERMOS DE SALUD MENTAL PARA SU SEGUIMIENTO 
@author Jesús Escribano Serena
@author Rafael Emilio Pérez López
*/

#include "SoftwareSerial.h"

const int idPaciente = 1001;

const int botonMedicacion = 1;
const int botonSOS = 2;
const int botonCrisis = 3;

int estaMedicacion = HIGH;
int estaSOS = HIGH;
int estaCrisis = HIGH;

SoftwareSerial mySerial(3, 2); //SIM800L Tx & Rx is connected to Arduino #3 & #2

void setup() {
  pinMode(botonMedicacion, INPUT);
  pinMode(botonSOS, INPUT);
  pinMode(botonCrisis, INPUT);
  mySerial.begin(9600);
  delay(1000);

}

void loop() {
  estaMedicacion = digitalRead(botonMedicacion);
  estaSOS = digitalRead(botonSOS);
  estaCrisis = digitalRead(botonCrisis);

  if (estaCrisis == LOW){
    String Mensaje = "PACIENTE ID: "+String(idPaciente)+ " ESTADO: Crisis";
    enviarMensaje(Mensaje);
  }
  else if(estaSOS == LOW){
    String Mensaje = "PACIENTE ID: "+String(idPaciente)+ " ESTADO: PensamientosSuicidas";
  }
  else if(estaMedicacion == LOW){
    String Mensaje = "PACIENTE ID: "+String(idPaciente)+ " ESTADO: FalloMedicación";
  }

}

void enviarMensaje(String mensaje){
  mySerial.print("AT");
  updateSerial();
  mySerial.print("AT+CMGF=1");
  updateSerial();
  mySerial.print("AT+CMGS=\"+34682479236\"");
  updateSerial();
  mySerial.print(mensaje);
  updateSerial();
  mySerial.write(26);
}

void updateSerial(){
  delay(500);
  while (Serial.available()){
    mySerial.write(Serial.read());
  }
  while(mySerial.available()){
    Serial.write(mySerial.read());
  }
}