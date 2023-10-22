

int output_Pin = A0;
double alpha = 0.65;
int period = 200;

void setup() {
  // put your setup code here, to run once:

Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
int rawValue = analogRead (output_Pin);
int value = (alpha / rawValue) * 60.0 * 1000;         

Serial.print ("BPM: ");                                                                                          
Serial.println (value);     
delay (period);


}
