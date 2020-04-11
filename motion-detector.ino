/**************************************************************
 * IoT Motion Detector with Blynk
 **************************************************************/
#include <ESP8266WiFi.h>

#define BLYNK_PRINT Serial // Comment this out to disable prints and save space
#include <BlynkSimpleEsp8266.h>
// Authentication String from Blynk
char auth[] = "string-from-blynk";

/* WiFi credentials */
char ssid[] = "your-ssid-here";
char pass[] = "wifi-password";

/* HC-SR501 Motion Detector */
#define ledPin D7
#define pirPin D1 // Input for HC-S501
int pirValue;     // Place to store read PIR Value

void setup()
{
  Serial.begin(115200);
  delay(10);
  Blynk.begin(auth, ssid, pass);
  pinMode(ledPin, OUTPUT);
  pinMode(pirPin, INPUT);
  digitalWrite(ledPin, LOW);
}

void loop()
{
  getPirValue();
  Blynk.run();
}

/***************************************************
 * Get PIR data
 **************************************************/
void getPirValue(void)
{
  pirValue = digitalRead(pirPin);
  if (pirValue)
  {
    Serial.println(">>>> Motion detected");
    Blynk.notify(">>>> Motion detected");
  }
  digitalWrite(ledPin, pirValue);
}
