#define Buzzer 4 //mendefinisikan pin 4 Arduino sebagai pin Output Buzzer

#define trigPin 5 //mendefinisikan pin 5 arduino sebagai trigger pin sensor ultrasonic

#define echoPin 6 //mendefinisikan pin 6 arduino sebagai echoPin sensor ultrasonic

#define LED 7 // LED

long duration; // variabel durasi sensor ultrasonic

int distance = 0; // jarah dalam centimeter

void setup()

{

pinMode(LED, INPUT);

pinMode(trigPin, OUTPUT); // setting triggerpin sebagai output

pinMode(echoPin, INPUT); // setting echopin sebagai Input

pinMode(Buzzer, OUTPUT); // setting Buzzer sebagai Output

Serial.begin(9600); // setting kecepatan pengiriman serial monitor

}

void loop()

{

  digitalWrite(trigPin, LOW);
  delayMicroseconds(8);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(8);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(8);

  duration = pulseIn(echoPin, HIGH); // menerima suara ultrasonic
  distance = (duration / 2) / 29.1;  // mengubah durasi menjadi jarak (cm)

  if(distance<=30){
  tone(Buzzer, 500,100);
  Serial.print(distance);
  Serial.println(" Peringatan!");
  digitalWrite(LED,HIGH);
  delay(10);
  }
  if(distance<=20){
  tone(Buzzer, 900,100);
  Serial.print(distance);
  Serial.println(" Bahaya!");
  delay(10);
  }
  else{
  Serial.println(distance);
  digitalWrite(LED,LOW);
  delay(10);
  }
}
