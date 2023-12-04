#include <Wire.h>               /*~ Librería I2C ~*/
#include <LiquidCrystal_I2C.h>  /*~ Librería LCD ~*/
String DISTANCIA_S;
String tem_S;

/*~ Página para crear iconos personalizados ~*/
/*~ https://maxpromer.github.io/LCD-Character-Creator/ ~*/
/*~ Los siguientes arrays contienen un caracter, es decir se indica que pixel se enciendo o apaga dependiendo si es 1 o 0 ~*/
/*~ gota de agua 1 ~*/
byte caracter1 [ ] = {
    B00010,
  B00110,
  B01010,
  B11111,
  B11111,
  B01110,
  B00000,
  B00000
};

/*~ bombilla ~*/
byte caracter2 [ ] = {
  B00000,
  B01110,
  B10001,
  B10001,
  B10001,
  B01110,
  B01110,
  B00100							
};

byte caracter3 [ ] = {
  B01110,
  B01110,
  B00100,
  B11111,
  B00100,
  B00100,
  B01010,
  B10001						
};

byte caracter4 [ ] = {
  B01110,
  B11111,
  B10001,
  B10001,
  B11111,
  B11111,
  B11111,
  B11111							
};

byte caracter5[] = {
  B11111,
  B10101,
  B10101,
  B11111,
  B11111,
  B10101,
  B10101,
  B11111
};

 
LiquidCrystal_I2C lcd ( 0x27, 16, 2 );  /*~ Instancia de la clase para el manejo de la pantalla ( Dirección I2C, columnas, filas ) ~*/

void LCDsetup ( void ) {
  
  lcd.init ( ); 					 	/*~ Inicializar la pantalla LCD ~*/
  
  lcd.createChar ( 0, caracter1 );   	/*~ Indicar al programa que genere un caracter a partir del array de bits. ~*/
  lcd.createChar ( 1, caracter2 );
  lcd.createChar ( 2, caracter3 ); 
  lcd.createChar ( 3, caracter4 );
  lcd.createChar ( 4, caracter5 );  	/*~ Indicar al programa que genere otro un caracter. ~*/
  
}

void LCD ( void ) {
  DISTANCIA_S=DISTANCIA;
  lcd.backlight ( );     		/*~ Encender la luz de fondo. ~*/
  
   DS1307_RTC RTC;
   RTC.show_time ( );  
   lcd.setCursor ( 0, 0 );   	/*~ ( columnas, filas) Ubicamos el cursor en la primera posición(columna:0) de la primera línea(fila:0) ~*/
   lcd.write ( 0 );		  		/*~ Mostramos nuestro primer icono o caracter ~*/
   lcd.print (DISTANCIA );
   if (DISTANCIA_S.length()<3){
    lcd.setCursor ( 3, 0);
    lcd.print ("  " );
   }
   lcd.setCursor ( 5, 0 );
   lcd.write ( 1 );		  		/*~ Mostramos nuestro primer icono o caracter ~*/
   lcd.print (luz );
   lcd.print (" " );
   lcd.write ( 2 );		  		/*~ Mostramos nuestro primer icono o caracter ~*/
   lcd.print (pir_status );
   lcd.print (" " );
   lcd.write ( 3 );		  		/*~ Mostramos nuestro primer icono o caracter ~*/
   lcd.print (puerta );
   lcd.setCursor ( 0, 1 );
   lcd.write ( 4 );		  		/*~ Mostramos nuestro primer icono o caracter ~*/
   lcd.print (ventana );
   lcd.setCursor ( 5, 1 );
   RTC.get_time ( ); 
   RTC.format_time ( );                 
   lcd.print ( RTC.tiempo );
  
}