
#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

#include "teensyduck.h"

/*
 * The kb library shortened.
 */

void resetKey()
{
  Keyboard.set_modifier(0);
  Keyboard.set_key1(0);
  Keyboard.send_now();
}

void pressModifier(long mod)
{
  Keyboard.set_modifier(mod);
  Keyboard.send_now();
}

void pressKey(long key)
{
  Keyboard.set_key1(key);
  Keyboard.send_now();
  Keyboard.set_key1(0);
  Keyboard.send_now();
  delay(50);
}

/*
 * Part of the core functions.
 */

void pauseScript()
{ 
  ledBlinker(1);
  while(1) {
    delay(1);
    if(digitalRead(noExecPin) != HIGH){
      break;
    }
  }
  ledBlinker(2);
}

void ledBlinker(int inc)
{ 
  for(int i = 0; i < inc; i++){
    digitalWrite(ledPin, (i % 2)? LOW: HIGH);
    delay(70);
  }
}

void enterPass()
{ 
  Keyboard.print(PASSWD);
  ledBlinker(8);
  Keyboard.set_key1(KEY_ENTER);
  Keyboard.send_now();
  delay(300);
  Keyboard.set_key1(0);
  Keyboard.send_now();

}
