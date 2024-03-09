#include <Servo.h>  // Inclusão da biblioteca com recursos para controlar os servos

/*-------------------------------------------------------------------
                           << CONSTANTES >>
--------------------------------------------------------------------*/
//As constantes estão guardando os números das portas do Arduino que não mudam.

// *Portas usadas no modo PWM.
#define pBase 3
#define pFrenteAtras 5
#define pCimaBaixo 6
#define pGarra 9

// Porta digital.
// #define pBtn 1

/*-------------------------------------------------------------------
                           << VARIÁVEL >>
--------------------------------------------------------------------*/
//Variável de tipo lógico.
// bool estado = false;

/*-------------------------------------------------------------------
                      << LIMITES DOS SERVOS >>
--------------------------------------------------------------------*/
/*
Base: 0-180, direita-esquerda
FrenteAtras: 179-55, frente-atrás
CimaBaixo: 148-175, cima-baixo
Garra: 60-110, aberta-fechada
*/

/*-------------------------------------------------------------------
                           << OBJETOS >>
--------------------------------------------------------------------*/
// Esses são objetos criados da biblioteca "<Servo.h>".
Servo s1, s2, s3, s4;

/*-------------------------------------------------------------------
                         << SUBPROGRAMA >>
--------------------------------------------------------------------*/
/*
Esse subprograma possui uma rotina para movimentar os servos do braço robótico.
                         >> PARÂMETROS <<
- objServo: objeto do tipo Servo o qual deseja-se controlar;
- numServo: número do servo. O servo deseja-se controlar;
    § 1: Base
    § 2: Frente e Trás
    § 3: Cima e Baixo
    § 4: Garra
- angulo: determina a posição do servo em ângulos, que pode ser entre 0 e 180;
- tempo: atraso em milissegundo para o incremento ou decremento dos ângulos.
*/
void MudaPosicao(Servo objServo, int numServo, int angulo, int tempo) {
  int pos;
  int posicao[4];

  switch (numServo) {
    case 1:
      pos = 0;
    case 2:
      pos = 1;
    case 3:
      pos = 2;
    case 4:
      pos = 3;
  }

  posicao[pos] = angulo;

  // BotaoControla();

  // if (estado == true) {
    if (objServo.read() < posicao[pos]) {
      for (int i = objServo.read(); i < posicao[pos]; i++) {
        objServo.write(i);
        delay(tempo);
        // BotaoControla();
      }
    } else {
      for (int i = objServo.read(); i > posicao[pos]; i--) {
        objServo.write(i);
        delay(tempo);
        // BotaoControla();
      }
    }
  // }
}

// void TrocaEstado() {
//   if (estado == true) {
//     estado = false;
//   } else {
//     estado = true;
//   }
// }

// void BotaoControla() {
//   if (digitalRead(pBtn) == HIGH) {
//     TrocaEstado();
//   }
// }

/*-------------------------------------------------------------------
                  << CONFIGURAÇÃO INICIAL >>
--------------------------------------------------------------------*/
void setup() {
  //Passando para cada objeto qual é a porta que vai controlar.
  s1.attach(pBase);
  s2.attach(pFrenteAtras);
  s3.attach(pCimaBaixo);
  s4.attach(pGarra);

  //Configurando o modo da porta como entrada.
  // pinMode(pBtn, INPUT);

  //Posição inicial do braço robótico
  MudaPosicao(s1, 1, 105, 25);  //BASE
  MudaPosicao(s2, 2, 67, 25);   //FRENTE E TRÁS
  MudaPosicao(s3, 3, 160, 25);  //CIMA E BAIXO
  MudaPosicao(s4, 4, 60, 25);   //GARRA-abre
}

/*-------------------------------------------------------------------
                  << PROGRAMA PRINCIPAL >>
--------------------------------------------------------------------*/
void loop() {
  MudaPosicao(s1, 1, 105, 25);  //BASE
  MudaPosicao(s2, 2, 67, 25);   //FRENTE E TRÁS
  MudaPosicao(s3, 3, 170, 25);  //CIMA E BAIXO
  MudaPosicao(s4, 4, 60, 25);   //GARRA-abre

  MudaPosicao(s2, 2, 103, 25);  //FRENTE E TRÁS
  MudaPosicao(s3, 3, 160, 25);  //CIMA E BAIXO

  MudaPosicao(s4, 4, 91, 25);  //GARRA-fecha

  MudaPosicao(s2, 2, 77, 25);   //FRENTE E TRÁS
  MudaPosicao(s3, 3, 179, 25);  //CIMA E BAIXO

  MudaPosicao(s1, 1, 10, 25);  //BASE

  MudaPosicao(s3, 3, 165, 25);  //CIMA E BAIXO

  MudaPosicao(s4, 4, 60, 25);   //GARRA-abre
  MudaPosicao(s3, 3, 179, 25);  //CIMA E BAIXO
}