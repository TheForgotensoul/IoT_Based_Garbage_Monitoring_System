//CODE FOR BIN 01
#include <FirebaseNode-MCU.h>
#include <ESP8266WiFi.h>
//needed for library
#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <WiFiManager.h> //https://github.com/tzapu/WiFiManager

#define FIREBASE_HOST "your_project.firebaseio.com"
#define FIREBASE_AUTH "AUTH_TOKEN"
const int trigPin = 0; // D3
const int echoPin = 2; // D4

// defining two variable for measuring the distance
long duration;
int distance;

void setup()
{
    Serial.begin(115200);
    WiFiManager wifiManager;
    wifiManager.autoConnect("IOT");
    Serial.println("connected...");
    pinMode(trigPin, OUTPUT); // Setting the trigPin as Output pin
    pinMode(echoPin, INPUT);  // Setting the echoPin as Input pin
    Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}

void loop()
{

    digitalWrite(trigPin, LOW);  // Making the trigPin as low
    delayMicroseconds(2);        // delay of 2us
    digitalWrite(trigPin, HIGH); // making the trigPin high for 10us to send the signal
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH); // reading the echoPin which will tell us that how much time the signal takes to come back

    distance = duration * 0.034 / 2; // Calculating the distance and storing in the distance variable

    // Sending data to firebase
    if (distance < 10)
    {
        Firebase.setString("bins/bins 01/STATUS 01", "<p style=\"color : red\" >FULL</p>");
    }
    else
    {
        Firebase.setString("bins/bins 01/STATUS 01", "EMPTY");
    }
}
