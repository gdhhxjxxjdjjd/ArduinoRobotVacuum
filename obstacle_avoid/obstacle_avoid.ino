int trigPin = 10;
int echoPin = 13;

int pwm_a = 3;  //PWM control for motor outputs 1 and 2 
int pwm_b = 9;  //PWM control for motor outputs 3 and 4 
int dir_a = 2;  //direction control for motor outputs 1 and 2 
int dir_b = 8;  //direction control for motor outputs 3 and 4 

float duration, distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(pwm_a, OUTPUT);
  pinMode(pwm_b, OUTPUT);
  pinMode(dir_a, OUTPUT);
  pinMode(dir_b, OUTPUT);

}

void loop() {
  if (get_distance() > 20) {
    forward();
  }
  else {
    back_up();
  }
}

float get_distance() {
  //Write a pulse to the HC-SR04 Trigger Pin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  //Measure the response time
  duration = pulseIn(echoPin, HIGH);

  //Determine distance
  distance = (duration / 2) * 0.0343;

  return distance;
}

void forward() {
  digitalWrite(dir_a, HIGH); 
  digitalWrite(dir_b, HIGH);

  analogWrite(pwm_a, 150);  
  analogWrite(pwm_b, 150);
}

void backward() {
  digitalWrite(dir_a, LOW); 
  digitalWrite(dir_b, LOW); 

  analogWrite(pwm_a, 150);  
  analogWrite(pwm_b, 150);
  
}

void halt() {
  analogWrite(pwm_a, 0);  
  analogWrite(pwm_b, 0);
}

void back_up() {
  halt();
  backward();
  delay(1000);
  turn_right();
  halt();
}

void turn_left() {
  digitalWrite(dir_a, LOW); 
  digitalWrite(dir_b, HIGH);

  analogWrite(pwm_a, 150);  
  analogWrite(pwm_b, 150);

  delay(500);
}

void turn_right() {
  digitalWrite(dir_a, HIGH); 
  digitalWrite(dir_b, LOW);

  analogWrite(pwm_a, 150);  
  analogWrite(pwm_b, 150);

  delay(500);
}