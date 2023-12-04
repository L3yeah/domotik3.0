#define RELAY_PIN 4
bool j = true;
String luz = "NO";
void RELAYsetup(){
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW);

}
void REL (){
  if (i){
    digitalWrite(RELAY_PIN, HIGH);
    delay(500);
    j = false;
    luz = "SI";
  }
  
  else {
    //Ciclo que posicionara el servo desde 180 hsta 0 grados
    digitalWrite(RELAY_PIN, LOW);
    delay(500);
    j = true;
    luz = "NO";
  }

}