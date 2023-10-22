#include <WiFiNINA.h>
char ssid[] = "ryan.n";
char pass[] = "12345678";
WiFiClient client;
void setup() {
  // Initialize serial communication for debugging
  Serial.begin(9600);

  // Connect to Wi-Fi network
  while (WiFi.begin(ssid, pass) != WL_CONNECTED) {
    Serial.println("Attempting to connect to WiFi...");
    delay(1000);
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
}
void loop() {
 senddata("HELLO EVERYONE I AM HERE");
}

void senddata(String data)
{
 if (client.connect("192.168.151.251", 12345)) {
    // Connected to Raspberry Pi
    Serial.println("Connected to Raspberry Pi");

    // Data to send
    String dataToSend = data;;

    // Send the data
    client.println(dataToSend);

    // Close the connection
    client.stop();

    // Wait for a moment before sending more data
    delay(5000);
  } else {
    Serial.println("Connection failed");
  }
}

void receivedata()
{
  Serial.println("strt");
  delay(100);
  if (client) {
    while (client.connected()) {
       client.println("HELLO SEND DATA FOM ARDUINO");
       Serial.println("Data sent: data_to_send");
      if (client.available()) {
        String c = client.readStringUntil('\n');
        Serial.print(c);
      }
    }
    client.stop();
  }
}