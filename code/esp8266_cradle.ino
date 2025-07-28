#define BLYNK_TEMPLATE_ID "TMPL3pIKAI8yq"
#define BLYNK_TEMPLATE_NAME "dfnew"
#define BLYNK_AUTH_TOKEN "DIc6EZMMm_Tf2Av3N0DI9yA4RpV3htHP"

#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"
SoftwareSerial communication(D2,D3);//RX=10,TX=11(res)
DFRobotDFPlayerMini dfplayer;

char auth[] = BLYNK_AUTH_TOKEN;

char ssid[] = " "; // type your wifi name
char pass[] = " "; // type your wifi password

#define sensorPin A0
const int dirPin = 16;
const int stepPin = 2;
const int stepsPerRevolution = 50;
// Variable to store the time when last event happened
unsigned long lastEvent = 0;
#define POWER_PIN D7 // The ESP8266 pin that provides the power to the rain sensor
#define DO_PIN D1
BLYNK_WRITE(V0){
int pinvalue=param.asInt();



if(pinvalue==HIGH){
dfplayer.play(3);
}else{
dfplayer.pause();
}
}

void wet();
BlynkTimer timer;
void wet(){
digitalWrite(POWER_PIN, HIGH); // turn the rain sensor's power ON
delay(10); // wait 10 milliseconds

int rain_state = digitalRead(DO_PIN);

digitalWrite(POWER_PIN, LOW); // turn the rain sensor's power OFF

if (rain_state == LOW){
Serial.println("The rain is detected");
Blynk.logEvent("wet_alert","WETNESS DETECTED");
}
delay(1000); // pause for 1 sec to avoid reading sensors frequently to prolong the sensor lifetime

}

void setup() {
// initialize the ESP8266's pin as an input
pinMode(POWER_PIN, OUTPUT); // Configure the power pin pin as an OUTPUT
pinMode(DO_PIN, INPUT);
// Declare pins as Outputs
pinMode(stepPin, OUTPUT);
pinMode(dirPin, OUTPUT);


pinMode(sensorPin, INPUT); // Set sensor pin as an INPUT
communication.begin(9600);
Serial.begin(9600);
Blynk.begin(auth, ssid, pass);
dfplayer.begin(communication);
timer.setInterval(2500L, wet);
}

void loop() {
int sensorData = analogRead(sensorPin);

// If pin goes LOW, sound is detected
if (sensorData >=100) {

// If 25ms have passed since last LOW state, it means that
// the clap is detected and not due to any spurious sounds

Serial.println("Cry detected!");
motor();
}
Blynk.run();
timer.run();
// Remember when last event happened

}
void motor(){
{
// Set motor direction clockwise
digitalWrite(dirPin, HIGH);

// Spin motor slowly
for(int x = 0; x < stepsPerRevolution; x++)

16

{
digitalWrite(stepPin, HIGH);
delayMicroseconds(8000);
digitalWrite(stepPin, LOW);
delayMicroseconds(8000);
}
delay(1000); // Wait a second

// Set motor direction counterclockwise
digitalWrite(dirPin, LOW);

// Spin motor quickly
for(int x = 0; x < stepsPerRevolution; x++)
{
digitalWrite(stepPin, HIGH);
delayMicroseconds(8000);
digitalWrite(stepPin, LOW);
delayMicroseconds(8000);
}
delay(1000); // Wait a second
}
}
