#include "MQTT.h"
#include <ArduinoJson.h>
#include "MicroSD.h"
#include "RTC.h"
#include "ULTRA.h"
#include "PIR.h"
#include "SERV.h"
#include "RELAY.h"
#include "TEMP.h"
#include "LCD.h"



DS1307_RTC RTC;
MicroSD MSD;
MQTT mqtt;


long lastMsg = 0;

void setup (void) {
  Serial.begin(115200);
  vensetup();
  mqtt.setup_WiFi();
  mqtt.set_MQTT_server();
  mqtt.set_MQTT_callback();
  MSD.MicroSD_init( );
  PIRsetup();
 // SERVsetup();
  RELAYsetup();
  LCDsetup();
  DS1307_RTC();
  
  Serial.println(F("Ha iniciado el sistema"));

  Serial.begin ( 115200 );        /* Inicializar baudrate a 115200 */
  RTC.RTC_init ( );             /* Inicializar configuración del reloj */

  Serial.println ( F ( "El DS-1307 ha sido configurado exitosamente." ) );
}

void loop (void) {

  data();
  mov();
  gir();
  REL();
  VEN();
  LCD();
  

  
  RTC.get_time ( );               /* Actualizar fecha y hora en formato RAW */
  RTC.show_time ( );              /* Dar formato y mostrar por consola serial */
  String SalidaString = "";
  DynamicJsonDocument JSON ( 1024 ); 
  RTC.format_time ( );          /* Objeto donde se alamcenará el JSON */            /* Almacena números enteros o flotantes */         
  JSON [ F ( "Hora" ) ] = ( RTC.tiempo );
  RTC.format_date ( );                 
  JSON [ F ( "Fecha" ) ] = ( RTC.fecha );
  JSON [ F ( "Agua" ) ] = (DISTANCIA);
  JSON [ F ( "Puerta" ) ] = (puerta);
  JSON [ F ( "Movimiento" ) ] = (pir_status);
  JSON [ F ( "Luz" ) ] = (luz);
  JSON [ F ( "Ventana" ) ] = (ventana);
  serializeJsonPretty( JSON, SalidaString ); 
  mqtt.reconnect_MQTT();
  mqtt.publish_MQTT(SalidaString.c_str());
  
  String fichero = "test.txt";
  File myFile;
  MicroSD_File = SD.open ( "Test.txt", FILE_APPEND );
    if ( MicroSD_File ) {
        MicroSD_File.println ( SalidaString );
        MicroSD_File.close ( );
      
    } else {
        // if the file didn't open, print an error:
        Serial.print ( F ( "Error opening " ) );
        Serial.println ( "Test.txt" );
       
    }
  Serial.println("Leyendo MicroSD...");
  MSD.ReadFile ( );
  delay ( 1000 ); 
}
