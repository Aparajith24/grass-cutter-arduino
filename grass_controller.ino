// Motor A connections
int enA = 9;
int in1 = 8;
int in2 = 7;

// Motor B connections
int enB = 3;
int in3 = 5;
int in4 = 4;

// Ultrasonic sensor connections
const int trigPin = 11;
const int echoPin = 10;

// Variables for ultrasonic sensor
long duration;
int distance;

// Distance threshold for stopping the motors (in centimeters)
const int distanceThreshold = 20;

void setup() {
  // Motor setup
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  // Ultrasonic sensor setup
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Start serial communication for debugging
  Serial.begin(9600);
}

void loop() {
  // Measure distance
  distance = measureDistance();

  // Check if an object is within the threshold distance
  if (distance > 0 && distance < distanceThreshold) {
    stopMotors();  // Stop the motors if an object is detected within range
    Serial.println("Object detected, stopping motors.");
  } else {
    moveMotorsForward();  // Otherwise, keep moving forward
    Serial.println("No object detected, moving forward.");
  }

  // Print distance for debugging
  Serial.print("Distance: ");
  Serial.println(distance);

  delay(100);  // Small delay to avoid excessive readings
}

int measureDistance() {
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  // Sets the trigPin on HIGH state for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  
  // Calculate the distance in centimeters
  int distance = duration * 0.034 / 2;
  return distance;
}

void moveMotorsForward() {
  analogWrite(enA, 255);  // Motor A at full speed
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);

  analogWrite(enB, 255);  // Motor B at full speed
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void stopMotors() {
  // Stop Motor A
  analogWrite(enA, 0);
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);

  // Stop Motor B
  analogWrite(enB, 0);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}
