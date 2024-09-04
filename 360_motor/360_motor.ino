# define LM1 A4       // Left Motor
#define LM2 3        // Left Motor
#define RM1 A5       // Right Motor
#define RM2 5        // Right Motor

void setup() {
  pinMode(LM1, OUTPUT);
  pinMode(LM2, OUTPUT);
  pinMode(RM1, OUTPUT);
  pinMode(RM2, OUTPUT);
}

void loop() {
  // Rotate the car 360 degrees in place
  digitalWrite(LM1, HIGH);  // Left motor forward
  digitalWrite(LM2, LOW);   // Left motor backward
  digitalWrite(RM1, LOW);   // Right motor backward
  digitalWrite(RM2, HIGH);  // Right motor forward

  delay(2000);  // Adjust this delay to control the speed of the turn

  // Stop the motors
  digitalWrite(LM1, LOW);
  digitalWrite(LM2, LOW);
  digitalWrite(RM1, LOW);
  digitalWrite(RM2, LOW);

//  while(1); // Keep the car stationary after the turn
}
