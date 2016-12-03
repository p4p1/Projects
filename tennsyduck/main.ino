/*
 * Made by papiii
 * teensyduck.ino
 * 
 * Rubberducky Remake with a teensy by papiii
 * It has a builtin password typer. Executes Basic rubber-ducky
 * scripts.
 */

#define PASSWD "HelloWorld"

const int ledPin = 13;
const int noExecPin = 23;
const int passwdPin = 1;
const int secScript = 2;

void enterPass();
void pauseScript();
void script();
void sscript();
void ledBlinker(int inc);

void setup() {
  delay(1000);
  
  pinMode(ledPin, OUTPUT);
  pinMode(noExecPin, INPUT);
  pinMode(passwdPin, INPUT);
  pinMode(secScript, INPUT);

  // enable internal pull-ups
  digitalWrite(noExecPin, 1);
  digitalWrite(passwdPin, 1);
  digitalWrite(secScript, 1);

  if(digitalRead(noExecPin) != HIGH){
   pauseScript();
  } else if(digitalRead(passwdPin) != HIGH){
    enterPass();
  } else if(digitalRead(secScript) != HIGH){
    sscript();
  } else {
    script();
  }
}

void loop() {
  // This code can be re-executed if needed
  // eg: Re type password.
  if(digitalRead(noExecPin) != HIGH){
   setup();
  }else if(digitalRead(passwdPin) != HIGH){
    enterPass();
  }
}

void pauseScript()
{
  ledBlinker(1);
  while(1) {
    delay(1000);
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
  }
}

void enterPass()
{
  Keyboard.print(PASSWD);
  delay(500);
  Keyboard.set_key1(KEY_ENTER);
  Keyboard.send_now();
  delay(300);
  Keyboard.set_key1(0);
  Keyboard.send_now();
}

// Rubber ducky 
//Main script:
//  install p4p1 bot
void script()
{

  
}

//Second script: 
// Wallpaper breaker :)
void sscript()
{

}

