#include <Firebase.h>
#include <FirebaseArduino.h>
#include <FirebaseCloudMessaging.h>
#include <FirebaseError.h>
#include <FirebaseHttpClient.h>
#include <FirebaseObject.h>

int TouchSensor = D6;
int led = LED_BUILTIN;
int n,p,q,l,out,flag;
unsigned long StartTime;
#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

// Set these to run example.
#define FIREBASE_HOST "tara888.firebaseio.com"
#define FIREBASE_AUTH "orzRRWYHL7mbq89EOkcYcjoOOHv5IAfYfrPLIiqP"
#define WIFI_SSID "Pb Desktop"
#define WIFI_PASSWORD "123456778"


void setup(){
  Serial.begin(9600);
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
  StartTime = millis();
  //Serial.println(StartTime);
  if((q-p)>-1000)
  {
    flag=1;
  }
  else
  {
    flag=0;
  }
  if(digitalRead(TouchSensor)==LOW)   
   { 
    digitalWrite(led, HIGH);
    p=StartTime;  
    //Serial.println(p);
    n=1;
   }
  else
   {
    digitalWrite(led, LOW);    
    //Serial.println("Led OFF");
    q=StartTime;
    //Serial.println(q);
   }
   //Serial.println(q-p);
   if((q-p)>1500)
   {
      out=3;
      //Serial.println(out);
   }
   else if((q-p)<150 && flag==0 && (q-p)>0)
   {
      out=1;
      //Serial.println(out);
   }
   else if((q-p)<150 && flag==1 && (q-p)>0)
   {
      out=2;
      //Serial.println(out);
   }
  //Serial.println(q-p);
  //Serial.println(flag);
  Serial.println(out);
  Firebase.setFloat("value", out);
   
 
  if (Firebase.failed()) {
      Serial.print("setting /number failed:");
      Serial.println(Firebase.error());  
      return;
  }
  
  Firebase.setFloat("value", out);
  
  if (Firebase.failed()) {
      Serial.print("setting /number failed:");
      Serial.println(Firebase.error());  
      return;
  }
  delay(50); 
}
