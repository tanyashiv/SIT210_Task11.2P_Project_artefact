#include <WiFiNINA.h>

#include <LiquidCrystal_I2C.h>


const char* ssid = "ryan.n";
const char* password = "12345678";

WiFiClient client;

LiquidCrystal_I2C lcd(0x27, 16, 2);

int first[] = { 1, 1 };
int second[] = { 1, 1 };
int i = 0;
int j = 0;
int capacity = 0;
WiFiServer server(80);

int LED1 = 2;
int LED2 = 3;
String data;

void setup() {
  // Initialize serial communication for debugging
  Serial.begin(9600);

  pinMode(3, INPUT);
  pinMode(4, INPUT);

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


  lcd.begin();
  lcd.backlight();      // Turn on the backlight
  lcd.setCursor(0, 0);  // Set the cursor to the first column and first row
  lcd.print("Hello, Arduino!");

  Serial.println("Connected to WiFi");
}

void loop() {
  // Serial.println(first[0]);
  lcd.setCursor(0, 0); 
  lcd.clear();
  lcd.print("Hello, Arduino!");
  Serial.print("1st: ");
  int u = digitalRead(2);
  int v = digitalRead(3);

  // Serial.print("2st: "+ digitalRead(3));
  // Serial.println( digitalRead(3));
  // first[  i++ ]= digitalRead(2);
  // Serial.println(first[i-1]);
  // second[ j++ ] = digitalRead(3);
  // Serial.println(second[j -1]);
  // if(i > 3 )
  // {
  //   i=0;
  //   j=0;
  // first[i++] = u;
  // second[j++] = v;

  // }
  // else
  // {
  //    first[i++] = u;
  // second[j++] = v;
  // }
  // first[3] = u;
  // second[3] = v;
  // first[1] = first[2];
  // first[2] = first[3];
  // second[1] = second[2];
  // second[2] = second[3];

  // if( first[0] == 0 || first[1] == 0 || first[2] == 0 && second[0] == 0 || second[1] == 0|| second[2] == 0 )
  // {
  //   capacity++;
  // }
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
  Serial.print("cCAPACIRY:  ");
  Serial.println(capacity);
  //  Serial.println( digitalRead(3);
  lcd.print("HELO ");
  delay(500);
  
  //  data = Receivedata();
  lcd.print(data);
  if(data == "a")
  {  
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
  } 
  else if(data == "c" )
  {
    digitalWrite(LED2, HIGH);
  }
  else if(data == "d")
  {
    digitalWrite(LED2, LOW);
  }
  else if(data == "b")
  {
    digitalWrite(LED1, LOW);
  }
  //scrollText(data, 3);
  data="";
}



String Receivedata() {
  WiFiClient client = server.available();
  Serial.println("strt");
  delay(100);
  if (client) {
    String s = "";
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        Serial.print(c);
        s = s + c;
      }
    }
    //
    // if (client.connected()) {
    //   if (client.available()) {
    //     String c = client.readStringUntil('\n');
    //     Serial.print(c);
    //     s = s + c;
    //   }
    // }
    //
    client.stop();
    return s;
  }
}
