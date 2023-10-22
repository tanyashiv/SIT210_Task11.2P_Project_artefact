#include <WiFiNINA.h>
// #include <ESP8266WiFiMulti.h>

const char* ssid = "ryan.n";
const char* password = "12345678";

WiFiServer server(8080);  // Port number to listen on


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
  }
  else {
    Serial.println("Connection failed.");
  }
  Serial.println("Connected to WiFi");
  server.begin();

  lcd.begin();
  lcd.backlight();  // Turn on the backlight
  lcd.setCursor(0, 0);  // Set the cursor to the first column and first row
  lcd.print("Hello, Arduino!");

}

void loop() {
  WiFiClient client = server.available();
  Serial.println("strt");
  delay(100);
  if (client) {
    String s="";
    while (client.connected()) {
      
      if (client.available()) {
        char c = client.read();
        Serial.print(c);
        s = s+c;
      }
      //lcd.print(s);
    }
    lcd.print(s);
    client.stop();
  }
}