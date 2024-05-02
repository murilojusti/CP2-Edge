#include <LiquidCrystal.h>
#include <dht.h>

LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

int redPin = 13;
int yellowPin = 12;
int greenPin = 11;
int ldrPin = A0;
int buzzPin = 10;
bool emAlerta = false;
int luminosidade;
int dhtPin = 9;
int contador = 0;
int botao = 8;
int temperatura = 0;
int umidade = 0;

dht  my_dht;

byte cima1[8] = { 
  B00000, 
  B01000, 
  B01111, 
  B01011, 
  B01011, 
  B00011, 
  B00011, 
  B00011 
};

byte cima2[8] = { 
  B00000, 
  B01011, 
  B11011, 
  B01011, 
  B01101, 
  B00101, 
  B00001, 
  B00001
};

byte cima3[8] = { 
  B00000, 
  B00000, 
  B10000, 
  B11000, 
  B11101, 
  B10101, 
  B10101, 
  B10111 
};

byte cima4[8] = { 
  B00000, 
  B00110, 
  B01110, 
  B11110, 
  B11100, 
  B01100, 
  B01100, 
  B01100 
};

byte baixo1[8] = { 
  B00011, 
  B00011, 
  B00011, 
  B01011, 
  B01011, 
  B01111, 
  B01000, 
  B00000 
};

byte baixo2[8] = { 
  B00001, 
  B00001, 
  B00101, 
  B01101, 
  B01001, 
  B11011, 
  B00110, 
  B00000 
};

byte baixo3[8] = { 
  B10111, 
  B10010, 
  B10010, 
  B10000, 
  B10000, 
  B11000, 
  B00000, 
  B00000 
};

byte baixo4[8] = { 
  B01100, 
  B01100, 
  B01100, 
  B01100, 
  B01100, 
  B11110, 
  B00011, 
  B00000 
};

void aparecerLogo() {
  lcd.createChar(1, cima1);
  lcd.setCursor(6, 0);
  lcd.write(byte(1));
  lcd.createChar(2, cima2);
  lcd.setCursor(7, 0);
  lcd.write(byte(2));
  lcd.createChar(3, cima3);
  lcd.setCursor(8, 0);
  lcd.write(byte(3));
  lcd.createChar(4, cima4);
  lcd.setCursor(9, 0);
  lcd.write(byte(4));
  lcd.createChar(5, baixo1);
  lcd.setCursor(6, 1);
  lcd.write(byte(5));
  lcd.createChar(6, baixo2);
  lcd.setCursor(7, 1);
  lcd.write(byte(6));
  lcd.createChar(7, baixo3);
  lcd.setCursor(8, 1);
  lcd.write(byte(7));
  lcd.createChar(0, baixo4);
  lcd.setCursor(9, 1);
  lcd.write(byte(0)); 
  delay(5000);
  lcd.clear();
  lcd.setCursor(3,0);
  lcd.print("Innovation");
  lcd.setCursor(4,1);
  lcd.print("Masters");
  delay(2000);
  lcd.clear();
}

void setup() {
  lcd.begin(16, 2);
  aparecerLogo();
  pinMode(redPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(ldrPin, INPUT);
  pinMode(buzzPin, OUTPUT);
  pinMode(botao, INPUT_PULLUP);
  Serial.begin(9600); 
}

void loop() {

  if (digitalRead(botao) == 0){
    contador++;
    delay(400);
  }

  my_dht.read22(dhtPin);

  temperatura = my_dht.temperature;
  umidade = my_dht.humidity;

  Serial.print("|Temperatura: ");
  Serial.print(temperatura);
  Serial.print("°C |");
  Serial.print("Umidade ");
  Serial.print(umidade);
  Serial.print("%| ");
  luminosidade = analogRead(ldrPin);
  int IntensidadeLuz = map(luminosidade,1015, 8, 0, 100);
  Serial.print("Luminosidade ");
  Serial.print(IntensidadeLuz);
  Serial.println("%|");
  delay(500);

  Serial.println(contador);

  switch (contador) {

  case 0:
    lcd.clear();
    lcd.print("Bem vindo!");
    lcd.setCursor(0,2);
    lcd.print("Aperte o botao!");
    break;

    case 1:
    case 4:
    case 7:
    case 10:
    case 13:
    case 16:
    case 19:
    case 22:
    case 25:
    case 28:
    case 31:
    case 34:
    case 37:
    case 40:
    case 43:
    case 46:
    case 49:
    case 52:
    case 55:
    case 58:

    if (IntensidadeLuz > 70) {
    digitalWrite(buzzPin, HIGH);
    digitalWrite(redPin, HIGH);
    digitalWrite(yellowPin, LOW);
    digitalWrite(greenPin, LOW);
    emAlerta = true;
    tone(buzzPin, 700, 1000);

    lcd.clear();
    lcd.print("Ambiente ");
    lcd.setCursor(0,2);
    lcd.print("muito claro");
  }

  else if (IntensidadeLuz > 40 && IntensidadeLuz < 70) {
    digitalWrite(buzzPin, LOW);
    digitalWrite(redPin, LOW);
    digitalWrite(yellowPin, HIGH);
    digitalWrite(greenPin, LOW);
    emAlerta = true;
    tone(buzzPin, 1000, 500);
    delay(500);

    lcd.clear();
    lcd.print("Ambiente a");
    lcd.setCursor(0,2);
    lcd.print("meia luz");
  }

  else {
    digitalWrite(buzzPin, LOW);
    digitalWrite(redPin, LOW);
    digitalWrite(yellowPin, LOW);
    digitalWrite(greenPin, HIGH);
    emAlerta = false;
    noTone(buzzPin);

    lcd.clear();
    lcd.setCursor(1,0);
    lcd.print("Luminosidade:");
    lcd.setCursor(5,1);
    lcd.print(IntensidadeLuz);
    lcd.setCursor(10,1);
    lcd.write(byte(37));

    lcd.setCursor(16,2);
    lcd.write(byte(2));
    delay(500);

  }
    break;
    
    case 2:
    case 5:
    case 8:
    case 11:
    case 14:
    case 17:
    case 20:
    case 23:
    case 26:
    case 29:
    case 32:
    case 35:
    case 38:
    case 41:
    case 44:
    case 47:
    case 50:
    case 53:
    case 56:
    case 59:

    if (temperatura > 15) {
      digitalWrite(buzzPin, HIGH);
      digitalWrite(redPin, LOW);
      digitalWrite(yellowPin, HIGH);
      digitalWrite(greenPin, LOW);
      emAlerta = true;
      tone(buzzPin, 700, 1000);

      lcd.clear();
      lcd.print("Temperatura alta ");
      lcd.setCursor(0,2);
      lcd.print(temperatura);
      lcd.setCursor(2,2);
      lcd.print("C");
      }

    else if (temperatura >= 10 && temperatura <= 15) {
      digitalWrite(buzzPin, LOW);
      digitalWrite(redPin, LOW);
      digitalWrite(yellowPin, LOW);
      digitalWrite(greenPin, HIGH);

      lcd.clear();
      lcd.print("Temperatura");
      lcd.setCursor(0,2);
      lcd.print("OK");
    }

    else {
      digitalWrite(buzzPin, HIGH);
      digitalWrite(redPin, LOW);
      digitalWrite(yellowPin, HIGH);
      digitalWrite(greenPin, LOW);
      emAlerta = true;
      tone(buzzPin, 1000, 700);

      lcd.clear();
      lcd.print("Temp baixa ");
      lcd.setCursor(0,2);
      lcd.print(temperatura);
      lcd.setCursor(2,2);
      lcd.print("C");

      break;

    case 3:
    case 6:
    case 9:
    case 12:
    case 15:
    case 18:
    case 21:
    case 24:
    case 27:
    case 30:
    case 33:
    case 36:
    case 39:
    case 42:
    case 45:
    case 48:
    case 51:
    case 54:
    case 57:
    case 60:

    if (umidade > 70) {
      digitalWrite(buzzPin, HIGH);
      digitalWrite(redPin, HIGH);
      digitalWrite(yellowPin, LOW);
      digitalWrite(greenPin, LOW);
      emAlerta = true;
      tone(buzzPin, 700, 1000);

      lcd.clear();
      lcd.print("Umidade alta ");
      lcd.setCursor(0,2);
      lcd.print(umidade);
      lcd.setCursor(2,2);
      lcd.print("%");
      }

    else if (umidade >= 50 && umidade <= 70) {
      digitalWrite(buzzPin, LOW);
      digitalWrite(redPin, LOW);
      digitalWrite(yellowPin, LOW);
      digitalWrite(greenPin, HIGH);

      lcd.clear();
      lcd.print("Umidade");
      lcd.setCursor(0,2);
      lcd.print("OK");
    }

    else {
      digitalWrite(buzzPin, HIGH);
      digitalWrite(redPin, HIGH);
      digitalWrite(yellowPin, LOW);
      digitalWrite(greenPin, LOW);
      emAlerta = true;
      tone(buzzPin, 1000, 700);

      lcd.clear();
      lcd.print("Umidade baixa ");
      lcd.setCursor(0,2);
      lcd.print(umidade);
      lcd.setCursor(2,2);
      lcd.print("%");

}
}
}
}
