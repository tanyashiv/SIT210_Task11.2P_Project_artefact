#include <WiFiNINA.h>  
#include <ThingSpeak.h>  


unsigned long Channel = 2300312;   
const char* API_Key = "YQZUMF59BKKJ9AWI";   

WiFiClient myclient;    //Initialize a WiFi client object and use it to communicate over a network.

int output_Pin = A0;
double alpha = 0.65;


void setup() {
  Serial.begin(9600);   // Initialize the serial communication at 9600 baud rate.
Serial.println("Establishing WiFi connection....");

  //Establish WiFi
  while (WiFi.status() != WL_CONNECTED) {
    Serial.println("Establishing WiFi connection....");   //Show message for connection attempt
    //Serial.println(SSID);
    WiFi.begin(SSID, PASS);    //Configure a WiFi connection using the specified credentials.
    delay(2000);    //Prior to the subsequent connection attempt, wait for a moment
  } 
  Serial.println("WiFi connection achieved.."); 
  ThingSpeak.begin(myclient);  
  
}

void loop() {
  int rawValue = analogRead (output_Pin);
int value = (alpha / rawValue) * 60.0 * 1000+30;         

 ThingSpeak.writeField(Channel, 1, value, API_Key);   
 Serial.println("Data transfer was successfully completed");   

Serial.print ("BPM: ");                                                                                          
Serial.println (value);     
delay (1200);
}


void scrollText(String text, int duration) {
  int textLength = text.length();
  int lcdCols = 16;
  for (int i = 0; i < textLength - lcdCols; i++) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(text.substring(i, i + lcdCols));
    delay(duration);
  }
}

