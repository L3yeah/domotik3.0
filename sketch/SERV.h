//Agregamos las libreriras del servo
#include <ESP32Servo.h>
//Instanciamos nuestro servo
Servo servo;
int pinServo=2;
void SERVsetup()
{
  //Inicializamos la posicion del servo
  servo.attach(pinServo, 500, 2500);
}
//Inicializamos la posicion (en grados) del servo
int pos = 0;
bool i = true;
String puerta = "CE";
void gir() {
  
  //Ciclo que posicionara el servo desde 0 hsta 180 grados
  if (i){
    for (pos = 0; pos <= 180; pos += 1) {
      //Movemos el servo a los grados que le entreguemos
      servo.write(pos);
      //Esperamos 15 milisegundos
      delay(5);
    }
    i = false;
    puerta = "AB";
  }
  
  else {
    //Ciclo que posicionara el servo desde 180 hsta 0 grados
    for (pos = 180; pos >= 0; pos -= 1) {
      //Movemos el servo a los grados que le entreguemos
      servo.write(pos);
      //Esperamos 15 milisegundos
      delay(5);
    }
    i = true;
    puerta = "CE";
  }
  
}