/*
PROGRAMA PARA LA IMPLEMENTACIÓN DE UNA PULSERA INTELIGENTE QUE AYUDE A ENFERMOS DE SALUD MENTAL PARA SU SEGUIMIENTO 
@author Jesús Escribano Serena
@author Rafael Emilio Pérez López
*/

const int idPaciente = 1001;

const int botonMedicacion = 1;
const int botonSOS = 2;
const int botonCrisis = 3;

int estaMedicacion = HIGH;
int estaSOS = HIGH;
int estaCrisis = HIGH;

void setup() {
  
  pinMode(botonMedicacion, INPUT);
  pinMode(botonSOS, INPUT);
  pinMode(botonCrisis, INPUT);

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
  Serial1.begin(9600);
  delay(1000);
  Serial1.print("AT");
  updateSerial();
  Serial1.print("AT+CMGF=1");
  updateSerial();
  Serial1.print("AT+CMGS=\"+15074485220\"");
  updateSerial();
  Serial1.print(mensaje);
  updateSerial();
  Serial1.write(26);
}

void updateSerial(){
  //TODO
}