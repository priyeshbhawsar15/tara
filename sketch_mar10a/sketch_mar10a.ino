#include <Firebase.h>
#include <FirebaseArduino.h>
#include <FirebaseCloudMessaging.h>
#include <FirebaseError.h>
#include <FirebaseHttpClient.h>
#include <FirebaseObject.h>

int TouchSensor = D6;
int led = LED_BUILTIN;
int n=0;
#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

// Set these to run example.
#define FIREBASE_HOST "tara888.firebaseio.com"
#define FIREBASE_AUTH "orzRRWYHL7mbq89EOkcYcjoOOHv5IAfYfrPLIiqP"
#define WIFI_SSID "Pb Desktop"
#define WIFI_PASSWORD "123456778"


void setup(){
  Serial.begin(9600); // Communication speed
  pinMode(led, OUTPUT);
  pinMode(TouchSensor, INPUT);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(50);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
  
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}

void loop(){
  if(digitalRead(TouchSensor)==HIGH)   
   { 
    digitalWrite(led, HIGH);  
    n=1;
   }
  else
   {
    digitalWrite(led, LOW);    
    Serial.println("Led OFF");
    n=0;
   }
  
   Firebase.setFloat("value", n);
 
  if (Firebase.failed()) {
      Serial.print("setting /number failed:");
      Serial.println(Firebase.error());  
      return;
  }
  
  Firebase.setFloat("value", n);
  
  if (Firebase.failed()) {
      Serial.print("setting /number failed:");
      Serial.println(Firebase.error());  
      return;
  }
  delay(50); 
}
