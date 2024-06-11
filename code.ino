const int trigger_pin = 2;
const int echo_pin = 3;
const int buzzer_pin = 10;
const int relay_pin = 11;

void setup() {
  Serial.begin(9600);
  pinMode(trigger_pin, OUTPUT);
  pinMode(echo_pin, INPUT);
  pinMode(buzzer_pin, OUTPUT);
  pinMode(relay_pin, OUTPUT);
}

void loop() {
  digitalWrite(trigger_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger_pin, LOW);
  
  unsigned long duration = pulseIn(echo_pin, HIGH);
  int distance = duration * 0.034 / 2;

  if (distance <= 3) {
    Serial.println("Dustbin is Full");
    Serial.print("Distance: ");
    Serial.println(distance);
    
    digitalWrite(buzzer_pin, HIGH);
    digitalWrite(relay_pin, HIGH); // Activate relay
    delay(60000); // Pause for 1 minute
    
    digitalWrite(buzzer_pin, LOW);
    digitalWrite(relay_pin, LOW); // Deactivate relay
  } else {
    Serial.println("Dustbin is Empty");
    Serial.print("Distance: ");
    Serial.println(distance);
    
    digitalWrite(buzzer_pin, LOW);
    digitalWrite(relay_pin, LOW); // Deactivate relay
  }
  delay(500);
}
