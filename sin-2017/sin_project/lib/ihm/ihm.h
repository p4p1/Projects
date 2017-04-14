#ifndef IHM_H
#define IHM_H

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

#include <SPI.h>
#include <Ethernet.h>

#define MAC { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED }
#define IP { 192, 168, , 2}
#define GATEWAY { }
#define SUBNET { 255, 255, 255, 0 }
#define PORT 80
/*#define DEBUG_ETHERNET Serial.begin(9600); \
	while(!Serial) \
			;*/

#define WEB_PAGE(conso_eau, luminosite, humidite, Temperature) do { \
	client.println("HTTP/1.1 200 OK"); \
	client.println("Content-Type: text/html"); \
	client.println(); \
	client.println("<html><head><title>mur vegetal</title><link rel=\"stylesheet\" href=\"https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css\" integrity=\"sha384-BVYiiSIFeK1dGmJRAkycuHAHRg32OmUcww7on3RYdg4Va+PmSTsz/K68vbdEjh4u\" crossorigin=\"anonymous\">"); \
	client.println("<style>body {position: absolute;top: 5px;left: 5px;right: 5px;bottom: 5px; }"); \
	client.println("#controls, #data { position: relative; width: 500px; display:inline-block; } #bottom_bar {position: absolute; bottom: 5px;}</style>"); \
	client.println("</head><body><div id=\"mainPage\"><div id=\"header\"><h1><span class=\"glyphicon glyphicon-leaf\" aria-hidden=\"true\"></span>Mur vegetal:</h1></div>"); \
	client.println("<div id=\"main-content\"><div id=\"data\"><div class=\"panel panel-default\"><div class=\"panel-heading\">Informations sur les plantes:</div>"); \
	client.println("<table class=\"table\"><tr><th>Consomation d'eau:</th><th><p><span id=\"conso_deau\"></span> L/H</p></th></tr><tr><th>Taux de luminosite:</th><th><p><span id=\"luminosite\"></span> lux</p></th>"); \
	client.println("</tr><tr><th>Humidite:</th><th><p><span id=\"humidite\"></spanp> \%</p></th></tr><tr><th>Temperature:</th><th><p><span id=\"Temperature\"></span> oC</p></th></tr></table></div>"); \
	client.println("</div><div id=\"controls\"><div class=\"panel panel-default\"><div class=\"panel-heading\">Controles:</div><table class=\"table\"><tr><th>Pompe:</th>" ); \
	client.println("<th><a href=\"/?pump_start\"><span class=\"glyphicon glyphicon-play\" aria-hidden=\"true\"></span>start</a></th>"); \
	client.println("<th><a href=\"/?pump_stop\"><span class=\"glyphicon glyphicon-stop\" aria-hidden=\"true\"></span>stop</a></th></tr><tr><th>Store:</th>"); \
	client.println("<th><a href=\"/?store_up\"><span class=\"glyphicon glyphicon-arrow-up\" aria-hidden=\"true\"></span>up</a></th>"); \
	client.println("<th><a href=\"/?store_down\"><span class=\"glyphicon glyphicon-arrow-down\" aria-hidden=\"true\"></span>down</a></th></tr><tr>"); \
	client.println("<th>Electro vanes:</th><th><a href=\"/?valve_open\"><span class=\"glyphicon glyphicon-play\" aria-hidden=\"true\"></span>open</a></th>"); \
	client.println("<th><a href=\"/?valve_close\"><span class=\"glyphicon glyphicon-stop\" aria-hidden=\"true\"></span>close</a></th></tr></table></div></div></div></div>"); \
	client.print("<div id=\"bottom_bar\"><img width=\"70px\" height=\"70px\" src=\"http://eiffel-cachan.fr/sites/default/files/logo-eiffel.png\"><b>Leo Smith, Remi Pantier, Felissia Erdogan</b></div><script>"); \
	client.print("document.getElementById(\"conso_deau\").innerHTML = "); \
	client.print(conso_eau); \
	client.print(";document.getElementById(\"luminosite\").innerHTML = "); \
	client.print(luminosite); \
	client.print(";document.getElementById(\"humidite\").innerHTML = "); \
	client.print(humidite); \
	client.print(";document.getElementById(\"Temperature\").innerHTML = "); \
	client.print(Temperature); \
	client.print("</script></body></html>"); \
							} while(0)

int ihm_setup();
int ihm_loop(float , float , float , float );

#endif /*end of ihm.h*/
