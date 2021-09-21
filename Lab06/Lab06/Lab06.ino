
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
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600); 
  // make the on-board pushbutton's pin an input pullup:
  pinMode(player1, INPUT_PULLUP);
  pinMode(player2, INPUT_PULLUP);

  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);

  pinMode(J1_1, OUTPUT);
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
  int button1 = digitalRead(player1);
  int button2 = digitalRead(player2);

  if (start == 0) {
    if (button1 == LOW || button2 == LOW) {
      digitalWrite(red, LOW);
      digitalWrite(green, LOW);
      digitalWrite(blue, LOW);
      
      digitalWrite(red, HIGH);
      delay(1000);

      digitalWrite(green, HIGH);
      delay(1000);

      digitalWrite(red, LOW);
      delay(1000);
      
      start = 1;
      digitalWrite(green, LOW); 
    }

    else {
      digitalWrite(red, LOW);
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
        counter1 = counter1 + 1;
        flag1 = 1;
      }
      else {
      }
    }

    if (flag1 == 1) {
      if ( button1 == HIGH) {
        flag1 = 0;
      }
      else {
      }
    }

    if (flag2 == 0) { //Boton del jugador 2
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

    switch (counter1) {
      case 1: 
        digitalWrite(J1_1, HIGH); 
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
        digitalWrite(J1_7, LOW);
        digitalWrite(J1_8, HIGH);
        counter1 = counter1 + 1; 
        break;
      case 9:
        digitalWrite(J1_8, LOW);
        digitalWrite(red, HIGH); 
        start = 0;
        counter1 = 0;
        delay(1000);
        break;
    }

    switch (counter2) {
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

  
  

/*
  if (flag1 == 0) {
    if (button1 == LOW) {
      counter1 = counter1 + 1;
      flag1 = 1;
    }
    else {
    }
  }

  if (flag1 == 1) {
    if ( button1 == HIGH) {
      flag1 = 0;
    }
    else {
    }
  }

  if (counter1 < 255) {
    counter1 = 0;
  } */

  /*Serial.print("Player 1: ");
  delay(100);*/
  Serial.println(start);
  delay(100);        // delay in between reads for stability
  /*Serial.print("\r");
  delay(100);
  Serial.print("Player 2: ");
  delay(100);
  Serial.println(counter2);
  delay(100);
  Serial.print("\r");
  delay(100);*/
  
}
