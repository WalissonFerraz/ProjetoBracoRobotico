/*-------------------------------------------------------------------
 Use esse programa para te ajudar a definir as posições dos servos.
--------------------------------------------------------------------*/

#include <Servo.h>  // Inclusão da biblioteca com recursos para controlar os servos.

// Portas analógica.
#define pPotenc1 A0
#define pPotenc2 A1
#define pPotenc3 A2
#define pPotenc4 A3

// Porta no modo PWM (se comporta como uma porta analógica).
#define pS1 3
#define pS2 5
#define pS3 6
#define pS4 9

/*-------------------------------------------------------------------
                      << LIMITES DOS SERVOS >>
--------------------------------------------------------------------*/
/*
Base: 0-180, direita-esquerda
FrenteAtras: 179-55, frente-atrás
CimaBaixo: 148-175, cima-baixo
Garra: 60-110, aberta-fechada
*/

// Variável
int angulo1 = 0;
int angulo2 = 0;
int angulo3 = 0;
int angulo4 = 0;

// Criação dos objetos da biblioteca "<Servo.h>".
Servo s1;
Servo s2;
Servo s3;
Servo s4;

void setup() {
  // Inicialização das portas dos servos.
  s1.attach(pS1);
  s2.attach(pS2);
  s3.attach(pS3);
  s4.attach(pS4);

  Serial.begin(9600);
}

void loop() {
  // Conversão das métricas do potenciômetro para as do servo.
  angulo1 = map(analogRead(pPotenc1), 0, 1023, 0, 180);
  angulo2 = map(analogRead(pPotenc2), 0, 1023, 0, 180);
  angulo3 = map(analogRead(pPotenc3), 0, 1023, 0, 180);
  angulo4 = map(analogRead(pPotenc4), 0, 1023, 60, 90);

  s1.write(angulo1);
  s2.write(angulo2);
  s3.write(angulo3);
  s4.write(angulo4);

  // Apresenta na tela os valores em graus do servo no presente instante.
  Serial.print("Base: ");
  Serial.print(s1.read());

  Serial.print("  FrenteAtras: ");
  Serial.print(s2.read());

  Serial.print("  CimaBaixo: ");
  Serial.print(s3.read());

  Serial.print("  Garra: ");
  Serial.println(s4.read());

  delay(100);
}
