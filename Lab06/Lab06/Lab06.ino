//Creamos las variables a utilizar en el circuito
int player1 = 31;
int player2 = 17;

int J1_1 = 3;
int J1_2 = 4;
int J1_3 = 5;
int J1_4 = 6;
int J1_5 = 7;
int J1_6 = 8;
int J1_7 = 9;
int J1_8 = 10;

int J2_1 = 2;
int J2_2 = 23;
int J2_3 = 24;
int J2_4 = 25;
int J2_5 = 26;
int J2_6 = 27;
int J2_7 = 28;
int J2_8 = 29;

int red = 30;
int green = 39;
int blue = 40;

int counter1 = 0;
int counter2 = 0;
int start = 0;

int flag1 = 0;
int flag2 = 0;

void setup() {
  // put your setup code here, to run once:
  // make the on-board pushbutton's pin an input pullup:
  pinMode(player1, INPUT_PULLUP); //Configuración de los botones
  pinMode(player2, INPUT_PULLUP);

  pinMode(red, OUTPUT);   //Configuración de la led RGB incluida en la placa
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);

  pinMode(J1_1, OUTPUT);  //Configuración de los leds de ambos jugadores
  pinMode(J1_2, OUTPUT);
  pinMode(J1_3, OUTPUT);
  pinMode(J1_4, OUTPUT);
  pinMode(J1_5, OUTPUT);
  pinMode(J1_6, OUTPUT);
  pinMode(J1_7, OUTPUT);
  pinMode(J1_8, OUTPUT);

  pinMode(J2_1, OUTPUT);
  pinMode(J2_2, OUTPUT);
  pinMode(J2_3, OUTPUT);
  pinMode(J2_4, OUTPUT);
  pinMode(J2_5, OUTPUT);
  pinMode(J2_6, OUTPUT);
  pinMode(J2_7, OUTPUT);
  pinMode(J2_8, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly: 
  // read the input pin:
  int button1 = digitalRead(player1); //Leemmos los botones constantemente y lo guardamos en una variable
  int button2 = digitalRead(player2);

  if (start == 0) { //Condición de comienzo
    if (button1 == LOW || button2 == LOW) { //Cuando no ha comenzado el juego los botones activan la secuencia de inicio
      digitalWrite(red, LOW);
      digitalWrite(green, LOW);
      digitalWrite(blue, LOW);  //Limpiamos la led RGB
      
      digitalWrite(red, HIGH);
      delay(1000);

      digitalWrite(green, HIGH);
      delay(1000);

      digitalWrite(red, LOW);
      delay(1000);
      
      start = 1;  //Termina la secuencia y comienza el juego
      digitalWrite(green, LOW); 
    }

    else {
      digitalWrite(red, LOW);   //Si no se presionan los botones se limpian todas las leds y se reinician los contadores
      digitalWrite(green, LOW);
      digitalWrite(blue, LOW);

      digitalWrite(J1_1, LOW);
      digitalWrite(J1_2, LOW);
      digitalWrite(J1_3, LOW);
      digitalWrite(J1_4, LOW);
      digitalWrite(J1_5, LOW);
      digitalWrite(J1_6, LOW);
      digitalWrite(J1_7, LOW);
      digitalWrite(J1_8, LOW);

      digitalWrite(J2_1, LOW);
      digitalWrite(J2_2, LOW);
      digitalWrite(J2_3, LOW);
      digitalWrite(J2_4, LOW);
      digitalWrite(J2_5, LOW);
      digitalWrite(J2_6, LOW);
      digitalWrite(J2_7, LOW);
      digitalWrite(J2_8, LOW);

      counter1 = 0;
      counter2 = 0;
    
    }
  }

  else {  
    
    if (flag1 == 0) { //Boton del jugador 1 
      if (button1 == LOW) {
        counter1 = counter1 + 1;  //incrementamos el contador al presionar el boton
        flag1 = 1;  //Encendemos la bandera y si no dejamos de presionar no volvemos a aumentar el contador
      }
      else {
      }
    }

    if (flag1 == 1) {
      if ( button1 == HIGH) {
        flag1 = 0;    //Cuando dejamos de presionar bajamos la bandera
      }
      else {
      }
    }

    if (flag2 == 0) { //Boton del jugador 2, el cual tiene el mismo funcionamiento que el boton del jugador uno
      if (button2 == LOW) {
        counter2 = counter2 + 1;
        flag2 = 1;
      }
      else {
      }
    }

    if (flag2 == 1) {
      if ( button2 == HIGH) {
        flag2 = 0;
      }
      else {
      }
    }

    switch (counter1) { //Aqui realizamos el contador de decadas del jugador 1
      case 1: 
        digitalWrite(J1_1, HIGH);   //Al incrementarse el contador encendemos la led correspondiente y apagamos la led anterior
        break;
      case 2:
        digitalWrite(J1_1, LOW);
        digitalWrite(J1_2, HIGH); 
        break;
      case 3:
        digitalWrite(J1_2, LOW);
        digitalWrite(J1_3, HIGH); 
        break;
      case 4:
        digitalWrite(J1_3, LOW);
        digitalWrite(J1_4, HIGH); 
        break;
      case 5:
        digitalWrite(J1_4, LOW);
        digitalWrite(J1_5, HIGH); 
        break;
      case 6:
        digitalWrite(J1_5, LOW);
        digitalWrite(J1_6, HIGH); 
        break;
      case 7:
        digitalWrite(J1_6, LOW);
        digitalWrite(J1_7, HIGH); 
        break;
      case 8:
        digitalWrite(J1_7, LOW);  //Al llegar a 8 en el contador incrementamos la variable para pasar a otro caso
        digitalWrite(J1_8, HIGH);
        counter1 = counter1 + 1; 
        break;
      case 9:
        digitalWrite(J1_8, LOW);  //en donde prendemos la RGB de un color y limpiamos las variables de juego y contador
        digitalWrite(red, HIGH); 
        start = 0;
        counter1 = 0;
        delay(1000);
        break;
    }

    switch (counter2) {   //El switch del jugador dos funciona igual que el del jugador 1
      case 1: 
        digitalWrite(J2_1, HIGH); 
        break;
      case 2:
        digitalWrite(J2_1, LOW);
        digitalWrite(J2_2, HIGH); 
        break;
      case 3:
        digitalWrite(J2_2, LOW);
        digitalWrite(J2_3, HIGH); 
        break;
      case 4:
        digitalWrite(J2_3, LOW);
        digitalWrite(J2_4, HIGH); 
        break;
      case 5:
        digitalWrite(J2_4, LOW);
        digitalWrite(J2_5, HIGH); 
        break;
      case 6:
        digitalWrite(J2_5, LOW);
        digitalWrite(J2_6, HIGH); 
        break;
      case 7:
        digitalWrite(J2_6, LOW);
        digitalWrite(J2_7, HIGH); 
        break;
      case 8:
        digitalWrite(J2_7, LOW);
        digitalWrite(J2_8, HIGH);
        counter2 = counter2 + 1; 
        break;
      case 9:
        digitalWrite(J2_8, LOW);
        digitalWrite(blue, HIGH); 
        start = 0;
        counter2 = 0;
        delay(1000);
        break;
    }
    
  }
  
}
