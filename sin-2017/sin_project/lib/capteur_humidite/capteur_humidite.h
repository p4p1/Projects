#ifndef _CAP_H_
#define _CAP_H_

#include "dht11/dht11.h"

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

#define DHT11PIN 22
static dht11 DHT11;

int readHumidityCapteur(float *, float *);

#endif
