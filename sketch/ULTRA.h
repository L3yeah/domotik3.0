long DISTANCIA = 0;
int pinEco=12;
int pinGatillo=13;
long readUltrasonicDistance(int triggerPin, int echoPin){
  //Iniciamos el pin del emisor de reuido en salida
  pinMode(triggerPin, OUTPUT);
  //Apagamos el emisor de sonido
  digitalWrite(triggerPin, LOW);
  //Retrasamos la emision de sonido por 2 milesismas de segundo
  delayMicroseconds(2);
  // Comenzamos a emitir sonido
  digitalWrite(triggerPin, HIGH);
  //Retrasamos la emision de sonido por 2 milesismas de segundo
  delayMicroseconds(10);
  //Apagamos el emisor de sonido
  digitalWrite(triggerPin, LOW);
  //Comenzamos a escuchar el sonido
  pinMode(echoPin, INPUT);
  // Calculamos el tiempo que tardo en regresar el sonido
  return pulseIn(echoPin, HIGH);
}


void data() {
  //Calculamos la distancia en cm
  DISTANCIA = 0.01723 * readUltrasonicDistance(pinGatillo, pinEco);
  DISTANCIA = DISTANCIA-2;
  DISTANCIA = (DISTANCIA * 100)/7;
  DISTANCIA = DISTANCIA - 100;
  DISTANCIA = abs(DISTANCIA);
  //Mostramos la disstancia

  //Si la distancia es menor a 20 encendemos el led
  delay(10);
}