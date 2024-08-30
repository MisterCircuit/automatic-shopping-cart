//#define MS A2        // Middle Sensor
//#define LSM 7        // Left Middle Sensor
//#define RSM 8        // Right Middle Sensor
//#define LS A3        // Left Sensor
//#define RS 6         // Right Sensor

#define LM1 2       // Left Motor
#define LM2 3        // Left Motor
#define RM1 A5       // Right Motor
#define RM2 5        // Right Motor
int count = 0;

#define ULTRASONIC_TRIG 6  // Ultrasonic sensor trig pin
#define ULTRASONIC_ECHO 7 // Ultrasonic sensor echo pin

const int minDistance = 20; // Minimum distance to follow in cm
bool trolleyActive = false;
void setup()
{
  Serial.begin(9600);
  //  pinMode(MS, INPUT);
  //  pinMode(LSM, INPUT);
  //  pinMode(RSM, INPUT);
  //  pinMode(LS, INPUT);
  //  pinMode(RS, INPUT);
  pinMode(LM1, OUTPUT);
  pinMode(LM2, OUTPUT);
  pinMode(RM1, OUTPUT);
  pinMode(RM2, OUTPUT);
  //   analogWrite(LM1, 0);
  //    analogWrite(LM2, 0);
  //    analogWrite(RM1, 0);
  //    analogWrite(RM2, 0);
  //       analogWrite(LM1, 255);
  //    analogWrite(LM2, 0);
  //    analogWrite(RM1, 0);
  //    analogWrite(RM2, 255);
  //    delay(5000);
  analogWrite(LM1, 0);
  analogWrite(LM2, 0);
  analogWrite(RM1, 0);
  analogWrite(RM2, 0);

  pinMode(ULTRASONIC_TRIG, OUTPUT);
  pinMode(ULTRASONIC_ECHO, INPUT);

  pinMode(8, OUTPUT);
   pinMode(9, INPUT);
  digitalWrite(8, HIGH);
}

void loop()
{
//  Serial.println("Vals:");
//  Serial.println(analogRead(A0));
//  Serial.println(analogRead(A1));
//  Serial.println(analogRead(A2));
//  Serial.println(analogRead(A3));
//  Serial.println(analogRead(A4));
  //delay(1000);
Serial.println(digitalRead(9));

   if (trolleyActive) {
    Serial.println("Active");

 int distance = getDistance();
  Serial.println(distance);

 if (distance > minDistance) {
  if (analogRead(A2) > 500) {
    analogWrite(LM1, 0);
    analogWrite(LM2, 150);
    analogWrite(RM1, 0);
    analogWrite(RM2, 150);
    delay(200);
    analogWrite(LM1, 0);
    analogWrite(LM2, 0);
    analogWrite(RM1, 0);
    analogWrite(RM2, 0);
    delay(200);
    Serial.println("forward");
    count++;
  }
  else if ((analogRead(A1) > 500) && (analogRead(A1) > (analogRead(A2) + analogRead(A3)))) {
    analogWrite(LM1, 0);
    analogWrite(LM2, 0);
    analogWrite(RM1, 0);
    analogWrite(RM2, 0);
    digitalWrite(LM1, 1);
    digitalWrite(LM2, 0);
    digitalWrite(RM1, 0);
    digitalWrite(RM2, 1);
    delay(100);
    analogWrite(LM1, 0);
    analogWrite(LM2, 0);
    analogWrite(RM1, 0);
    analogWrite(RM2, 0);
    delay(50);
    Serial.println("right");
    count += 10;

  }
  else if ((analogRead(A0) > 500) && (analogRead(A0) > (analogRead(A2) + analogRead(A3)))) {
    analogWrite(LM1, 0);
    analogWrite(LM2, 0);
    analogWrite(RM1, 0);
    analogWrite(RM2, 0);
    digitalWrite(LM1, 1);
    digitalWrite(LM2, 0);
    digitalWrite(RM1, 0);
    digitalWrite(RM2, 1);
    delay(100);
    analogWrite(LM1, 0);
    analogWrite(LM2, 0);
    analogWrite(RM1, 0);
    analogWrite(RM2, 0);
    delay(50);
    Serial.println("right");
    count += 10;

  }
  else if ((analogRead(A3) > 500) && (analogRead(A3) > (analogRead(A2) + analogRead(A1)))) {
    analogWrite(LM1, 0);
    analogWrite(LM2, 255);
    analogWrite(RM1, 255);
    analogWrite(RM2, 0);
    delay(100);
    analogWrite(LM1, 0);
    analogWrite(LM2, 0);
    analogWrite(RM1, 0);
    analogWrite(RM2, 0);
    delay(50);
    Serial.println("left");

  }
  else if ((analogRead(A4) > 500) && (analogRead(A4) > (analogRead(A2) + analogRead(A1)))) {
    analogWrite(LM1, 0);
    analogWrite(LM2, 255);
    analogWrite(RM1, 255);
    analogWrite(RM2, 0);
    delay(100);
    analogWrite(LM1, 0);
    analogWrite(LM2, 0);
    analogWrite(RM1, 0);
    analogWrite(RM2, 0);
    delay(50);
    Serial.println("left");
   }
   else {
    analogWrite(LM1, 150);
  analogWrite(LM2, 0); // Left motor backward
  analogWrite(RM1, 150); // Right motor backward
  analogWrite(RM2, 0);

//  
//                  analogWrite(LM1, 100);
//    analogWrite(LM2, 0);
//    analogWrite(RM1, 100);
//    analogWrite(RM2, 0);
    delay(50);
    //
    //                  analogWrite(LM1, 100);
    //    analogWrite(LM2, 0);
    //    analogWrite(RM1, 100);
    //    analogWrite(RM2, 0);
    //    delay(200);
    analogWrite(LM1, 0);
    analogWrite(LM2, 0);
    analogWrite(RM1, 0);
    analogWrite(RM2, 0);
    delay(200); 
   
 }
 }
 
  else {
    //
    //                  analogWrite(LM1, 100);
    //    analogWrite(LM2, 0);
    //    analogWrite(RM1, 100);
    //    analogWrite(RM2, 0);
    //    delay(200);
    analogWrite(LM1, 0);
    analogWrite(LM2, 0);
    analogWrite(RM1, 0);
    analogWrite(RM2, 0);
    //delay(200);
    //    if(count>60){
    //                  analogWrite(LM1, 0);
    //    analogWrite(LM2, 100);
    //    analogWrite(RM1, 0);
    //    analogWrite(RM2, 100);
    //    delay(2000);
    //          analogWrite(LM1, 0);
    //    analogWrite(LM2, 0);
    //    analogWrite(RM1, 0);
    //    analogWrite(RM2, 0);
    //     delay(200);
    //    count=0;
    //    }
  }
  delay(100);
   }


  
    if (digitalRead(9) == 0) {
    trolleyActive = !trolleyActive;  // Toggle trolley state
    delay(1000);  // Debounce delay
  }
 
   
}
int getDistance() {
  digitalWrite(ULTRASONIC_TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(ULTRASONIC_TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(ULTRASONIC_TRIG, LOW);

  long duration = pulseIn(ULTRASONIC_ECHO, HIGH);
  int distance = duration * 0.034 / 2;  // Convert duration to distance

  return distance;
}
