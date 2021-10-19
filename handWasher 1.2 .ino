

#define echoPin 2
#define trigPin 3 
#define relay1 4
#define relay2 5

long duration;
int distance;
int jarak; //jarak terjauh, ketika tidak ada objek
long durasi;
bool state;

void setup() {
  state = LOW;
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
  pinMode(relay1,OUTPUT);
  pinMode(relay2,OUTPUT);
  //Serial.begin(9600); // // Serial Communication is starting with 9600 of baudrate speed
  //Serial.println("Ultrasonic Sensor HC-SR04 Test"); // print some text in Serial Monitor
  //Serial.println("with Arduino UNO R3");
  for( int a=0; a<=5 ;a++){ //kalibrasi jarak jika standby (jarak sensor ke background jika tidak terhalang tangan)
    // Clears the trigPin condition
  digitalWrite(relay2, HIGH);
  digitalWrite(relay1, HIGH);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  durasi = pulseIn(echoPin, HIGH);
  // Calating the distance
  
  jarak = durasi * 0.034 / 2; //jarak berisikan  nilai, brp jauh objek terjauh saat sensor dipasang, yang kemudian dijadikan acuan
  delay(1000);

  }
}
void loop() {
  // Clears the trigPin condition
  digitalWrite(trigPin, LOW);
  // digitalWrite(relay1, HIGH);
  // digitalWrite(relay2, HIGH);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial MonitorM
  state = digitalRead(relay2);

  if(distance <= 25 and distance != jarak){//banyu mekan
   //Serial.print("AIR\n");
   digitalWrite(relay2, HIGH);
   digitalWrite(relay1, LOW);
   state = HIGH;
   delay(500); 
  
  }
  else if(distance <= 12 and state == HIGH){//sabun mekan
   //Serial.print("SABUN\n");
   digitalWrite(relay1, HIGH);
   digitalWrite(relay2, LOW);
   state = LOW;
   delay(500); 
  }
  
  else if(distance >= jarak){//mati kabeh
   digitalWrite(relay2, LOW);
   digitalWrite(relay1, LOW);
   //Serial.print("Mati\n");
   delay(200); 
  }
 
}
