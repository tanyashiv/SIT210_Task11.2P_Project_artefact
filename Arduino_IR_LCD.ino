#include <WiFiNINA.h>
// #include <ESP8266WiFiMulti.h>

const char* ssid = "ryan.n";
const char* password = "12345678";

int first[] = { 1, 1 };
int second[] = { 1, 1 };
int i = 0;
int j = 0;
int capacity = 0;

WiFiServer server(8080);
//WiFiClient client(8080);
int LED1 = 2;
int LED2 = 3;
String data;  // Port number to listen on


#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Set the LCD address, number of columns, and number of rows
LiquidCrystal_I2C lcd(0x27, 16, 2);  // 0x27 is the default I2C address


void setup() {
  Serial.begin(9600);
  WiFi.begin(ssid, password);
  Serial.print("strt");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Connecting to WiFi...");
  }
  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("Connected to WiFi");
    Serial.print("IP Address: ");
    Serial.println(WiFi.localIP());
  } else {
    Serial.println("Connection failed.");
  }
  Serial.println("Connected to WiFi");
  server.begin();
 // client.connect("192.168.164.123", 8080);

  lcd.begin();
  lcd.backlight();      // Turn on the backlight
  lcd.setCursor(0, 0);  // Set the cursor to the first column and first row
  lcd.print("Hello, Arduino!");
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("1st: ");
  int u = digitalRead(2);
  int v = digitalRead(3);

  // first[3] = u;
  // second[3] = v;
  // first[1] = first[2];
  // first[2] = first[3];
  // second[1] = second[2];
  // second[2] = second[3];

  if (first[2] == 0 && second[3] == 1) {
    capacity++;
  }
  if (first[3] == 1 && second[2] == 0) {
    capacity--;
  }
  if (capacity == 0) {
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
  } else {
    digitalWrite(LED2, HIGH);
    digitalWrite(LED2, HIGH);
  }
  delay(500);
  Serial.print("cCAPACIRY:  ");
  Serial.println(capacity);
  //  Serial.println( digitalRead(3);
  // lcd.print("HELO ");
  // delay(500);

  data = RecieveData();
  //sendData(data);
  
  if (data == "a") {
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
  } else if (data == "c") {
    digitalWrite(LED2, HIGH);
  } else if (data == "d") {
    digitalWrite(LED2, LOW);
  } else if (data == "b") {
    digitalWrite(LED1, LOW);
  }

  data = "";
}


String RecieveData() {
  WiFiClient client = server.available();
  Serial.println("strt");


  String s = "";
  if (client.connected()) {

    if (client.available()) {
      String c = client.readStringUntil('\n');
      c.trim();
      Serial.print(c);
      s = s + c;
    }
    // lcd.print(s);
  }
  // lcd.print(s);
  client.stop();
  return s;
}
/*
void sendData(String s)
{    
if (client.connected()) {
    client.print(s);
    delay(10); // Send data every second
  } else { 
    Serial.println("Client not connected.");
    delay(10); // Wait and try to reconnect
    client.connect("192.168.164.123", 8080);     // Replace "ServerIPAddress" with the IP address of the server Arduino.
  }
 
}*/