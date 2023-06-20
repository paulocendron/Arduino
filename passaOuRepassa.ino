
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#define LedAmarelo 2
#define LedVermelho 3
#define LedAzul 4
#define BotaoA 5
#define BotaoB 7
#define BotaoZ 6
#define Piezo 8
#define Ponto 9

int pontoAmarelo=0;
int pontoAzul=0;

LiquidCrystal_I2C lcd(0x20, 16, 2);

bool ledAmareloAceso = false;
bool ledAzulAceso = false;


void setup()
{
  pinMode (LedAmarelo, OUTPUT);
  pinMode (LedVermelho, OUTPUT);
  pinMode (LedAzul, OUTPUT);
  pinMode (BotaoA, INPUT_PULLUP);
  pinMode (BotaoB, INPUT_PULLUP);
  pinMode (BotaoZ, INPUT_PULLUP); 
  pinMode (Piezo, OUTPUT);
  pinMode (Ponto, INPUT_PULLUP);

   digitalWrite(LedAmarelo, LOW);
   digitalWrite(LedAzul, LOW);
   digitalWrite(LedVermelho, LOW);
   digitalWrite(Piezo, LOW);
  
   lcd.init();
   lcd.clear();
   lcd.backlight();
  
}

void loop()
{

  if (digitalRead(BotaoA) == LOW) {
  
    digitalWrite(LedAmarelo, HIGH);
    digitalWrite(LedAzul, LOW);
    tone(Piezo, 500);
    delay(100); 
    noTone(Piezo);
    ledAmareloAceso = true;
    ledAzulAceso = false;
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Amarelo");
    lcd.setCursor(0, 1);
    lcd.print("Respondendo");
 	    
    if (digitalRead(Ponto) == HIGH){
            pontoAmarelo++;
    }
       
}
  if (digitalRead(BotaoB) == LOW) {
  
    digitalWrite(LedAzul, HIGH);
    digitalWrite(LedAmarelo, LOW);
    tone(Piezo, 500); 
    delay(100);
    noTone(Piezo);
    ledAzulAceso = true;
    ledAmareloAceso = false;
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Azul responde");
    lcd.setCursor(0, 1);
    lcd.print("Respondendo");
    if (digitalRead(Ponto) == HIGH){
            pontoAzul++;
    }
      
  }
  
  if (digitalRead(BotaoZ) == LOW) {
    
    digitalWrite(LedAmarelo, LOW);
    digitalWrite(LedAzul, LOW);
    digitalWrite(LedVermelho, HIGH);
    tone(Piezo, 1000);
    delay(200);
    noTone(Piezo);
    delay(200);
    tone(Piezo, 1000);
    delay(200);
    noTone(Piezo);
    delay(200);
    digitalWrite(LedVermelho, LOW);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("AMARELO");
    lcd.setCursor(8, 0);
    lcd.print(pontoAmarelo);
    lcd.setCursor(0, 1);
    lcd.print("AZUL:");
    lcd.setCursor(8, 1);
    lcd.print(pontoAzul);
  }
}


