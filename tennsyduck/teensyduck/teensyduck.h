#ifndef _TEENSYDUCK_H
#define _TEENSYDUCK_H

#define DELAY delay(1500)
#define PASSWD "52!@6!86247205102bb82f@94!0rez"

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
