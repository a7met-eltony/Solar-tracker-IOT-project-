#include <Servo.h>

Servo sg90;
int servoPos = 90;

int LDR1 = A0;
int LDR2 = A1;

int servoPin = 4;

int error = 5;

void setup()
{
  Serial.begin(9600);
  sg90.attach(servoPin);

  pinMode(LDR1, INPUT);
  pinMode(LDR2, INPUT);

  sg90.write(servoPos);
  delay(1000);
}

void loop()
{
  int R1 = analogRead(LDR1);
  int R2 = analogRead(LDR2);

  int diff = abs(R1 - R2);

  Serial.print("LDR1: ");
  Serial.print(R1);

  Serial.print("   ");

  Serial.print("LDR2: ");
  Serial.print(R2);

  Serial.print("   ");

  Serial.print("Diff: ");
  Serial.println(diff);

  if (diff > error)
  {
    if (R1 > R2)
    {
      servoPos-=10;
    }

    else if (R2 > R1)
    {
      servoPos +=10;
    }

    servoPos = constrain(servoPos, 0, 180);

    sg90.write(servoPos);
  }

  delay(15);
}