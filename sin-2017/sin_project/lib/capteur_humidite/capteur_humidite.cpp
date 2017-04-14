#include "capteur_humidite.h"

int readHumidityCapteur(float *temp, float *humidity)
{
	int chk;
	int ret;

	ret = 0;
	chk = DHT11.read(DHT11PIN); // reading sensor
  	switch (chk) // does the sensor work?
	{
	  	case DHTLIB_OK:
                	ret = 0;
			break;
		case DHTLIB_ERROR_CHECKSUM: //checksum err = 2
                	ret = 2;
			break;
		case DHTLIB_ERROR_TIMEOUT: // time out err = -1
			ret = -1;
			break;
		default:
			return -5;
			break;
	}
	if(!ret){ // if there are no errors
		*humidity = (float)DHT11.humidity;
		*temp = (float)DHT11.temperature;
	}
	if(*humidity > (float)100 || *temp > (float)60)
		return -1;
	else
		return ret;
}
