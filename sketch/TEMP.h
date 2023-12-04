int reedswitch = 25;
int buzzer = 2;
int val;
String ventana;

void vensetup() {
  pinMode(reedswitch, INPUT_PULLUP);
  pinMode (buzzer, OUTPUT);
   Serial.begin(115200);
}

void VEN() {
  val = digitalRead(reedswitch);
  if (val) {
    digitalWrite(buzzer, HIGH);
    delay(200);
    digitalWrite(buzzer, LOW);
    delay(200);
    ventana=("AB");
  }
  else{
    digitalWrite(buzzer,LOW);
    ventana=("CE");
  }
}