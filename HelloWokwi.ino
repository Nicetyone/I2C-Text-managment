/* Hello Wokwi! */

//----------------------------------
int Li          = 16;
int Lii         = 0; 
int Ri          = -1;
int Rii         = -1;
//----------------------------------
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);

void setup() {
  lcd.init();
  lcd.backlight();
  displayTextOnce("Snickers", "eating bananas is great");
}

void loop() {
}


//----------------------------------
boolean isUsed = false;
void displayTextOnce(String Header, String longText){
  if (!isUsed && (longText.length() > 16)) {
    int headerLength = Header.length();
    String stringAddition = "";
    for (int i=0; i < ((16-headerLength)/2); i++){
      stringAddition = stringAddition + " ";
    }
    Header = stringAddition + Header;

    isUsed = true;
    lcd.clear();

    lcd.setCursor(0, 0);
    lcd.print(Header);
    lcd.setCursor(0, 1);
    lcd.print(Scroll_LCD_Left(longText));
    
    double second = 0;
    unsigned long time_now = 0;

    while (true) {
      //wait 1 sec
      if ((unsigned long)(millis() - time_now)>3000) {
        break;
      } 
    }
    
    while (true){

      if ((unsigned long)(millis() - time_now)>150) {
        time_now = millis();
        second = second + 0.15;
        lcd.setCursor(0, 1);
        lcd.print(Scroll_LCD_Left(longText));
      } 

      if (Lii >= longText.length()) {
        lcd.clear();
        isUsed = false;
        break;
      }
    }
    Clear_Scroll_LCD_Left();
  } else if (!isUsed) {
    int headerLength = Header.length();
    String stringAddition = "";
    for (int i=0; i < ((16-headerLength)/2); i++){
      stringAddition = stringAddition + " ";
    }
    Header = stringAddition + Header;

    int longLength = longText.length();
    String stringAddition2 = "";
    for (int i=0; i < ((16-longLength)/2); i++){
      stringAddition2 = stringAddition2 + " ";
    }
    longText = stringAddition2 + longText;

    isUsed = true;
    lcd.clear();

    lcd.setCursor(0, 0);
    lcd.print(Header);
    lcd.setCursor(0, 1);
    lcd.print(longText);
    
    double second = 0;
    unsigned long time_now = 0;

    while (true) {
      //wait 1 sec
      if ((unsigned long)(millis() - time_now)>5000) {
        lcd.clear();
        break;
      } 
    }
  }
}



String Scroll_LCD_Left(String StrDisplay){
  String result;
  String StrProcess = "" + StrDisplay + "                ";
  result = StrProcess.substring(Li,Lii);
  Li++;
  Lii++;
  if (Li>StrProcess.length()){
    Li=16;
    Lii=0;
  }
  return result;
}

void Clear_Scroll_LCD_Left(){
  Li=16;
  Lii=0;
}