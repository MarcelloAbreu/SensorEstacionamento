// Sensor De Estacionamento
// Marcello Henrique

#include <TimeLib.h>
//constantes 
#define echoPin 2 // pino Echo
#define trigPin 3 // pino Trig 
#define ledVermelho 13 
#define ledAmarelo 12
#define ledVerde 11

#define TIME_HEADER  'T'  
#define TIME_REQUEST  7    

//definindo variaveis
int buzzer = 6;

void setup() {
  Serial.begin(9600);
  inicializa_componente(buzzer,OUTPUT);
  inicializa_componente(trigPin, OUTPUT); // Define o trigPin como uma SAÍDA
  inicializa_componente(echoPin, INPUT); // Define o echoPin como INPUT
  inicializa_componente(ledVermelho, OUTPUT); 
  inicializa_componente(ledAmarelo,OUTPUT); 
  inicializa_componente(ledVerde,OUTPUT); 
  Serial.println("Sensor de Estacionamento Feito Por Marcello");
}

void loop() {
  controla_distancia();

}

int distancia(){
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  return pulseIn(echoPin,HIGH)/58;
}

void inicializa_componente(int comp,int operacao){
  pinMode(comp, operacao);
}

void controla_distancia(){
  int dist = distancia();
  if(dist < 15){
    Serial.print("Perigo: ");
    Serial.print(dist);
    Serial.println(" cm");
    controla_led(1, ledVermelho);
    controla_led(0, ledAmarelo);
    controla_led(0, ledVerde);
    Serial.println("Horario: "); 
    tone(buzzer,400,1000);
    delay(200);
  }
  else if(dist >= 15 && dist <30){
    Serial.print("Atenção: ");
    Serial.print(dist);
    Serial.println(" cm");
    controla_led(1,ledAmarelo);
    controla_led(0,ledVermelho);
    controla_led(0,ledVerde);
    tone(buzzer,300,650);
    delay(200);  
  }
  else if(dist >= 30 && dist <45){
    Serial.print("Distância: ");
    Serial.print(dist);
    Serial.println(" cm");
    controla_led(1,ledVerde);
    controla_led(0,ledAmarelo);
    controla_led(0,ledVermelho);
    tone(buzzer,100,200);
    delay(200);
  }
  else{
    noTone(buzzer);
  }
}

void controla_led(int instrucao, int led){
  if(instrucao == 1){
    digitalWrite(led,HIGH);
  }else{
    digitalWrite(led,LOW);
  }
}
