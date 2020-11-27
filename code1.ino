int soundSensor = A0;
int relay = 7;
int claps = 0;
int ledred = 8;
int ledgreen = 9;
long detectionSpanInitial = 0;
long detectionSpan = 0;
boolean lightState = false;
 
void setup() {
  pinMode(soundSensor, INPUT);
  pinMode(relay, OUTPUT);
  pinMode(ledred, OUTPUT);
  pinMode(ledgreen, OUTPUT);
  digitalWrite(ledred, HIGH);
  digitalWrite(ledgreen, LOW);
}
 
void loop() {
 
  int sensorState = digitalRead(soundSensor);
 
  if (sensorState == 0)
  {
    if (claps == 0)
    {
      detectionSpanInitial = detectionSpan = millis();
      claps++;
      //delay(100);
    }
    else if (claps > 0 && millis()-detectionSpan >= 64)
    {
      detectionSpan = millis();
      claps++;
      delay(100);
    }
  }
 
  if (millis()-detectionSpanInitial >= 600)
  {
    if (claps == 2)
    {
      if (!lightState)
        {
          lightState = true;
          digitalWrite(relay, HIGH);
          digitalWrite(ledgreen, LOW);
        }
        else if (lightState)
        {
          lightState = false;
          digitalWrite(relay, LOW);
          digitalWrite(ledgreen, HIGH);
        }
    }
    claps = 0;
  }
}
