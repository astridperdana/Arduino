//Constractor
int led = 13;
int s = 150;
int o = 500;

void setup() {
  // put your setup code here, to run once:
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);  
}
void huruf(int speed) {
  digitalWrite(led, HIGH);
  delay(speed);
  digitalWrite(led, LOW);
  delay(300); //delay per huruf
}

void loop() {
  // put your main code here, to run repeatedly: 
  for (int x = 1; x <= 3; x++) {
    huruf(s);
  }
  for (int x = 1; x <= 3; x++) {
    huruf(o);
  }
  for (int x = 1; x <= 3; x++) {
    huruf(s);
  }
  delay(2000); //delay per SOS
}
