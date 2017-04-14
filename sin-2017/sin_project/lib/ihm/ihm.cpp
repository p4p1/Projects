#include "ihm.h"

EthernetServer server(PORT);
String buf;

int ihm_setup()
{
	byte mac [] = MAC;
	byte ip[] = IP;
	byte gateway[] = GATEWAY;
	byte subnet[] = SUBNET;

	#if defined(DEBUG_ETHERNET)
		DEBUG_ETHERNET
	#endif
	Ethernet.begin(mac, ip, gateway, subnet);
	server.begin();
	#if defined(DEBUG_ETHERNET)
		Serial.print("Server is at ");
		Serial.println(Ethernet.localIP());
		Serial.print("On port ");
		Serial.println(PORT);
	#endif
	return 0;
}

int ihm_loop(float eau, float lumi, float humidite, float Temp)
{
	EthernetClient client = server.available();
	char c;

	c = 0;
	if(client){
		while(client.connected()){
			if(client.available()) {
				c = client.read();
				if(buf.length() < 100) {
					buf += c;
				}
				if(c == '\n') {
					#if defined(DEBUG_ETHERNET)
						Serial.println(buf);
					#endif
					if (buf.indexOf("?DEBUG_ETHERNET") > 0) {
						#if defined(DEBUG_ETHERNET)
							Serial.println("DEBUG_ETHERNET mode activated");
						#else
							client.print("no DEBUG_ETHERNET mode");
						#endif
					}
					WEB_PAGE(eau, lumi, humidite, Temp);
					delay(1);
					buf = "";
					client.stop();
				}
			}
		}
		return 0;
	} else {
		return 1;
	}
}
