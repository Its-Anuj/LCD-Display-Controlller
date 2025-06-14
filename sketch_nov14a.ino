
// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("hello, world!");
  Serial.begin(9600);
}

int Print(String Input)
{
  lcd.clear();
  if(Input.length() > 32)
    return -1;
 
  if(Input.length() > 16)
  {
    //Since input is greater than the row size 16 
    //we print in both lines
    lcd.setCursor(0,0);
    String SubStr = Input.substring(0, 15);
    lcd.print(SubStr);
    
    lcd.setCursor(0,1);
    SubStr = Input.substring(15, Input.length());
    lcd.print(SubStr);
  }
  
  lcd.setCursor(0,0);
  lcd.print(Input);
}

void loop() {
  
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  
  if(Serial.available())
  {
    lcd.clear();
    String Input = Serial.readString();
    if(Print(Input) == -1)
    {
      Print("Error: 101");
    }
  }
  
}