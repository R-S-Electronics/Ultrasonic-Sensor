/* 
   
 *  Interfacing Ultrasonic Sensor with Arduino
 * ~~~ R. S. Electronics ~~~
 * https://www.youtube.com/channel/UC_Jm37Vgb58krva8AG1ByMg
  
*/

//defining pins and variables
#define trigPin 7
#define echoPin 8
 
float duration, distance;
 
void setup() {
  Serial.begin (9600);              //declaring serial monitor
  pinMode(trigPin, OUTPUT);         // declaring trigPin for Output
  pinMode(echoPin, INPUT);          // declaring echoPin for Input
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
  Serial.print("Distance = ");
  Serial.println(distance);
    
  delay(100);
}
