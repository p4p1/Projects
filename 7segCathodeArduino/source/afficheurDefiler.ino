#include <LiquidCrystal.h>

const int COL = 16;
const int ROW = 2;

void defiler(String text, int sizText);
LiquidCrystal lc(12, 11, 5, 4, 3, 2);

void setup() {
  lcd.begin(COL, ROW);
  lcd.print
}

void loop() {
  defiler("TEXT", 5);
}

void defiler(String text, int sizText)
{
  lcd.noAutoscroll();
  for(int i = 0; i < COL; i++){
    lcd.setCursor(0, i);
    lcd.print(text);
    delay(500);
    lcd.clear();
  }
}

