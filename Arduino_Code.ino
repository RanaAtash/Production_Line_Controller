// Import servo library
#include <Servo.h>
// Create servo motor object
Servo servoMotor;
// Initialze the servo position as zero
int pos = 0; 
// Intialize the sensor reading as zero
int sensorValue = 0;


void setup()
{
  // Attache servo motor to Arduino pin 5
  servoMotor.attach(5);
  // Intialize the analog input pin(A0) to recieve the sensor reading
  pinMode(A0, INPUT);
  // Initilize the serial monitor
  Serial.begin(9600);
}

void loop()
{
  // Read and print the sensor reading
  sensorValue = analogRead(A0);
  Serial.print("LDR Reading = ");
  Serial.println(sensorValue);
  
  if (sensorValue<=1023 && sensorValue>=800)
  {
    // Light
    Serial.println("Small Box");
    // Move motor to 0 degrees 
    servoMotor.write(93);   
  }
  
  else if(sensorValue<800 && sensorValue>=251)
  {
    // Medium light
    Serial.println("Midium Box");
    // Move motor to 45 degrees 
    servoMotor.write(117);      
  }
  
  else if (sensorValue<251)
  {
    // Dark
    Serial.println("Large Box");
    // Move motor to 135 degrees 
    servoMotor.write(68);   
  }
  
  // Wait for 4 seconds
  delay(4000); 
}
