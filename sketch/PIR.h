#define timeSeconds 10

// Set GPIOs for LED and PIR Motion Sensor
const int led = 26;
const int motionSensor = 27;

// Timer: Auxiliary variables
unsigned long now = millis();
unsigned long lastTrigger = 0;
boolean startTimer = false;
boolean motion = false;
String pir_status = "N0";

// Checks if motion was detected, sets LED HIGH and starts a timer
void IRAM_ATTR detectsMovement() {
  digitalWrite(led, HIGH);
  startTimer = true;
  lastTrigger = millis();
}

void PIRsetup() { 
  // PIR Motion Sensor mode INPUT_PULLUP
  pinMode(motionSensor, INPUT_PULLUP);
  // Set motionSensor pin as interrupt, assign interrupt function and set RISING mode
  attachInterrupt(digitalPinToInterrupt(motionSensor), detectsMovement, RISING);

  // Set LED to LOW
  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);
}

void mov() {
  // Current time
  now = millis();
  if((digitalRead(led) == HIGH) && (motion == false)) {
    Serial.println("MOTION DETECTED!!!");
    motion = true;
    pir_status = "SI";
  }
  // Turn off the LED after the number of seconds defined in the timeSeconds variable
  if(startTimer && (now - lastTrigger > (timeSeconds*500))) {
    Serial.println("Motion stopped...");
    digitalWrite(led, LOW);
    startTimer = false;
    motion = false;
    pir_status = "NO";
  }
}
