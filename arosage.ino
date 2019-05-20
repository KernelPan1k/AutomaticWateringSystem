
#include <TimeLib.h>

bool isDebug = true;

int minRun = 400;
int maxRun = 1000;
int outputPin = 13;
int analogPin = 9;
int bottomCaptorPin = 7;
int nbrTimeRun = 3000;
long nbrTimePause = 300000;

void digitalClockDisplay();

void setup() {
  Serial.begin(9600);

  pinMode(outputPin, OUTPUT);
  // setTime(hr, min, sec, day, month, yr); 
}


void loop()
{  
  int analogCaptor = analogRead(9);
  int bottomCaptore = digitalRead(7);
  
  if (isInTimeRange() && analogCaptor > minRun && analogCaptor < maxRun && bottomCaptore == HIGH) {
    digitalWrite(outputPin, HIGH);
    delay(nbrTimeRun);
  }

  digitalWrite(outputPin, LOW);
  delay(nbrTimePause);
}

bool isInTimeRange() {
  int h = hour();
  return isDebug || h > 18 || h < 7;
}
