#ifndef _TEENSYDUCK_H
#define _TEENSYDUCK_H

#define DELAY delay(1500)
#define PASSWD "passwd"

const int ledPin = 13;
const int noExecPin = 23;
const int passwdPin = 1;

void resetKey();
void pressModifier(long mod);
void pressKey(long key);

void pauseScript();
void ledBlinker(int inc);
void enterPass();

#endif
