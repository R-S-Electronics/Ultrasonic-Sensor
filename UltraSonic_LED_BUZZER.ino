/* 
   
 *  Interfacing Ultrasonic Sensor with Arduino
 * ~~~ R. S. Electronics ~~~
 * https://www.youtube.com/channel/UC_Jm37Vgb58krva8AG1ByMg
  
*/

//defining pins and variables
#define trigPin 7
#define echoPin 8
#define led 13
#define bzr 10
 
float duration, distance;
 
void setup() {
  Serial.begin (9600);              //declaring serial monitor
  pinMode(trigPin, OUTPUT);         // declaring trigPin for Output
  pinMode(echoPin, INPUT);          // declaring echoPin for Input
  pinMode(led, OUTPUT);
  pinMode(bzr, OUTPUT);
}
 
void loop() {
   
  // Write a pulse to the HC-SR04 Trigger Pin
  
  digitalWrite(trigPin, LOW);         // no emission for 2 microseconds
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);        // emitting ultrasonic waves for 10 microseconds
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);         // then stop emitting
  
  
  // Measure the response from the HC-SR04 Echo Pin
 
  duration = pulseIn(echoPin, HIGH);        // this returns the time 
  
  // Determine distance from duration
  // Use 343 metres per second as speed of sound
  
  distance = (duration / 2) * 0.0343;           // calculating distance
  distance = (int)distance;                     // converting distance to integer type value
  
  // Send results to Serial Monitor
                                // Maximum range of ultrasonic sensor is 400 cm or 4 m 
                                // it can not detect object away 400 cm or 4 m
  if(distance <= 50 )
  {
    Serial.print("Distance = ");
    Serial.println(distance);
    digitalWrite(led, HIGH);
    digitalWrite(bzr, HIGH);
  }
  // NOW if sensor detect object under 50 cm then the buzzer will ring and led will glow
  else
  {
    Serial.println("No object");    
    digitalWrite(led, LOW);
    digitalWrite(bzr, LOW);
  }
  
  delay(100);
}
